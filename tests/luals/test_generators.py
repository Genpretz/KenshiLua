"""Regression tests for the LuaLS definition generators."""

import contextlib
import io
import json
import pathlib
import re
import sys
import tempfile
import unittest
from unittest import mock


PROJECT_ROOT = pathlib.Path(__file__).resolve().parents[2]
TOOLS_DIR = PROJECT_ROOT / "tools" / "luals"
sys.path.insert(0, str(TOOLS_DIR))

import container_contracts
import extract_enum_values
import generate_binding_inventory
import generate_coverage_report
import generate_definitions
import generate_type_audit


class EnumExtractionTests(unittest.TestCase):
    def test_missing_include_directory_fails(self):
        with tempfile.TemporaryDirectory() as temporary:
            missing = pathlib.Path(temporary) / "missing"
            with self.assertRaisesRegex(FileNotFoundError, "git submodule update"):
                extract_enum_values.parse_header_enums(missing)

    def test_empty_include_directory_fails(self):
        with tempfile.TemporaryDirectory() as temporary:
            with self.assertRaisesRegex(ValueError, "contains no headers"):
                extract_enum_values.parse_header_enums(pathlib.Path(temporary))

    def test_unmatched_registered_enum_fails(self):
        with mock.patch.object(generate_definitions, "parse_header_enums", return_value={}):
            with self.assertRaisesRegex(ValueError, "registered enum values"):
                generate_definitions.parse_enums()

    def test_all_registered_enum_values_are_resolved(self):
        global_enums, nested_enums = generate_definitions.parse_enums()
        resolved_count = sum(len(values) for values in global_enums.values())
        resolved_count += sum(
            len(values)
            for fields in nested_enums.values()
            for values in fields.values()
        )

        source = generate_definitions.ENUM_BINDING_PATH.read_text(encoding="utf-8")
        registration_count = len(re.findall(r"\bsetEnum\s*\(", source))
        self.assertEqual(registration_count, resolved_count)


class DefinitionGenerationTests(unittest.TestCase):
    def test_generation_failure_does_not_modify_outputs(self):
        output_before = generate_definitions.OUTPUT_PATH.read_bytes()
        addon_before = generate_definitions.ADDON_LIBRARY_PATH.read_bytes()

        with mock.patch.object(
            generate_definitions,
            "parse_enums",
            side_effect=ValueError("unmatched test enum"),
        ), mock.patch.object(sys, "argv", ["generate_definitions.py"]), contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(1, generate_definitions.main())

        self.assertEqual(output_before, generate_definitions.OUTPUT_PATH.read_bytes())
        self.assertEqual(addon_before, generate_definitions.ADDON_LIBRARY_PATH.read_bytes())

    def test_committed_definitions_are_reproducible(self):
        metadata = json.loads(generate_definitions.METADATA_PATH.read_text(encoding="utf-8"))
        global_enums, nested_enums = generate_definitions.parse_enums()
        generated = generate_definitions.generate(
            metadata,
            generate_definitions.read_version(),
            global_enums,
            nested_enums,
            generate_definitions.parse_event_names(),
        )

        self.assertEqual(generated, generate_definitions.OUTPUT_PATH.read_text(encoding="utf-8"))
        self.assertEqual(generated, generate_definitions.ADDON_LIBRARY_PATH.read_text(encoding="utf-8"))

    def test_kenshilib_documentation_is_emitted(self):
        descriptions = json.loads(
            generate_definitions.DESCRIPTION_PATH.read_text(encoding="utf-8")
        )
        self.assertEqual("KenshiLib-docs/docs", descriptions["source"])
        self.assertGreaterEqual(len(descriptions["classes"]), 90)
        self.assertGreaterEqual(
            sum(len(entry["methods"]) for entry in descriptions["classes"].values()),
            3000,
        )
        self.assertGreaterEqual(
            sum(len(entry["properties"]) for entry in descriptions["classes"].values()),
            1700,
        )

        generated = generate_definitions.OUTPUT_PATH.read_text(encoding="utf-8")
        self.assertIn(
            "Primary entity actor representing all humanoid and creature characters",
            generated,
        )
        self.assertIn(
            "Performs internal character operation `takeMoney`, synchronizing actor state",
            generated,
        )
        self.assertIn(
            "Override dispatch for `takeMoney`. Performs internal character operation",
            generated,
        )
        self.assertIn(
            "Inherited API from `Character`. Override dispatch for `giveBirth`",
            generated,
        )
        self.assertIn("---@class HavokCharacter", generated)
        self.assertIn("---@field havokCharacter HavokCharacter", generated)
        self.assertIn("Active sneaking stance toggle.", generated)


class BindingInventoryTests(unittest.TestCase):
    def test_commented_registrations_are_ignored(self):
        body = r'''
            static const luaL_Reg methods[] = {
                { "live", Binding::live },
                // { "lineComment", Binding::lineComment },
                /* { "blockComment", Binding::blockComment }, */
                { 0, 0 }
            };
            registerGetter(L, "liveProperty", Binding_get_liveProperty);
            // registerGetter(L, "lineProperty", Binding_get_lineProperty);
            /* registerSetter(L, "blockProperty", Binding_set_blockProperty); */
        '''
        self.assertEqual(
            [{"name": "live", "callback": "Binding::live", "static": False}],
            generate_binding_inventory.parse_methods(body),
        )
        self.assertEqual(
            [{"name": "liveProperty", "access": "readonly"}],
            generate_binding_inventory.parse_properties(body, body),
        )
        self.assertEqual(
            ["LiveBinding"],
            generate_binding_inventory.registration_calls(
                "LiveBinding::registerBinding(L); "
                "// HiddenBinding::registerBinding(L);"
            ),
        )

    def test_mygui_value_bindings_keep_distinct_types(self):
        inventory = generate_binding_inventory.build_inventory()
        types = {entry["binding"]: entry["lua_type"] for entry in inventory["classes"]}
        expected = {
            "IntPointBinding": "MyGUI.IntPoint",
            "IntSizeBinding": "MyGUI.IntSize",
            "IntCoordBinding": "MyGUI.IntCoord",
            "IntRectBinding": "MyGUI.IntRect",
            "FloatPointBinding": "MyGUI.FloatPoint",
            "FloatSizeBinding": "MyGUI.FloatSize",
            "FloatCoordBinding": "MyGUI.FloatCoord",
            "FloatRectBinding": "MyGUI.FloatRect",
            "ColourBinding": "MyGUI.Colour",
        }
        self.assertEqual(expected, {binding: types[binding] for binding in expected})

    def test_inventory_lua_types_are_unique(self):
        inventory = generate_binding_inventory.build_inventory()
        lua_types = [entry["lua_type"] for entry in inventory["classes"]]
        self.assertEqual(len(lua_types), len(set(lua_types)))

    def test_container_generics_are_declared_once(self):
        metadata = {"classes": [], "aliases": []}
        inventory = {"classes": [
            {"kind": "template_instance", "template": "LektorPtrBinding", "lua_type": "Lektor<Character>",
             "methods": [{"name": "pop"}, {"name": "toTable"}]},
            {"kind": "template_instance", "template": "LektorValueBinding", "lua_type": "Lektor<iVector2>",
             "methods": [{"name": "push"}]},
        ]}
        generate_definitions.add_container_generics(metadata, inventory, set())
        self.assertEqual(["Lektor<T>"], [entry["name"] for entry in metadata["classes"]])
        fields = {field["name"]: field["type"] for field in metadata["classes"][0]["fields"]}
        self.assertEqual("T|nil", fields["[integer]"])
        self.assertEqual("fun(self: Lektor<T>): T|nil", fields["pop"])
        self.assertEqual("fun(self: Lektor<T>): table<integer, T>", fields["toTable"])
        self.assertEqual("fun(self: Lektor<T>, value: T)", fields["push"])
        self.assertEqual([container_contracts.ITERATOR_ALIAS], metadata["aliases"])

    def test_factory_overloads_follow_runtime_name_resolution(self):
        classes = [
            {"kind": "template_instance", "template": "LektorPtrBinding",
             "lua_type": "Lektor<Character>", "metatable": "lektor<Character*>"},
            {"kind": "template_instance", "template": "LektorValueBinding",
             "lua_type": "Lektor<ModInfo>", "metatable": "lektor<ModInfo>"},
            {"kind": "template_instance", "template": "LektorPtrBinding",
             "lua_type": "Lektor<ModInfo>", "metatable": "lektor<ModInfo*>"},
            {"kind": "template_instance", "template": "LektorStringBinding",
             "lua_type": "Lektor<string>", "metatable": "lektor<std::string>"},
            {"kind": "template_instance", "template": "OgreUnorderedMapBinding",
             "lua_type": "OgreUnorderedMap<TutorialItem, TutorialGUILine>",
             "metatable": "ogre_unordered_map<TutorialItem*, TutorialGUILine*>"},
        ]
        overloads = container_contracts.factory_overloads(classes)
        lektor = {params[0][1]: lua_type for params, lua_type in overloads["lektor"]}
        self.assertEqual("Lektor<Character>", lektor["Character*"])
        self.assertEqual("Lektor<Character>", lektor["Character"])
        self.assertEqual("Lektor<Character>", lektor["lektor<Character*>"])
        self.assertEqual("Lektor<string>", lektor["string"])
        self.assertEqual("Lektor<ModInfo>", lektor["ModInfo"])
        maps = {tuple(value for _, value in params): lua_type for params, lua_type in overloads["ogre_unordered_map"]}
        self.assertIn(("TutorialItem*", "TutorialGUILine*"), maps)
        # The map factory appends "*" to one argument at a time, never both.
        self.assertIn(("TutorialItem", "TutorialGUILine*"), maps)
        self.assertIn(("TutorialItem*", "TutorialGUILine"), maps)
        self.assertNotIn(("TutorialItem", "TutorialGUILine"), maps)

    def test_static_method_tables_get_statics_classes(self):
        metadata = {"classes": [], "globals": [{"name": "Declared", "type": "X", "initialValue": "{}"}]}
        inventory = {"classes": [
            {"kind": "class", "lua_type": "CombatClass", "global_names": ["CombatClass"]},
            {"kind": "class", "lua_type": "Other", "global_names": ["Declared"]},
        ]}
        generate_definitions.add_static_tables(metadata, inventory)
        self.assertEqual(["CombatClassStatics"], [entry["name"] for entry in metadata["classes"]])
        self.assertEqual("CombatClass", metadata["classes"][0]["inventory_fields"])
        self.assertEqual(
            {"name": "CombatClass", "type": "CombatClassStatics", "initialValue": "{}"},
            metadata["globals"][-1],
        )

    def test_every_runtime_global_is_declared(self):
        report = generate_coverage_report.build_report()
        self.assertEqual({}, report["undeclared_runtime_globals"])
        self.assertIn("lektor", generate_coverage_report.runtime_globals())
        self.assertNotIn("_benchGcStore", generate_coverage_report.runtime_globals())

    def test_core_binding_signatures_are_inferred_from_lua_stack_checks(self):
        inventory = generate_binding_inventory.build_inventory()
        bindings = {entry["lua_type"]: entry for entry in inventory["classes"]}

        def signature(lua_type, method):
            entry = next(item for item in bindings[lua_type]["methods"] if item["name"] == method)
            return entry["signature"]["params"]

        self.assertEqual([{"name": "n", "type": "integer", "optional": False}], signature("Character", "takeMoney"))
        self.assertEqual(
            ["boolean"],
            next(item for item in bindings["Character"]["methods"] if item["name"] == "takeMoney")["signature"]["returns"],
        )
        self.assertEqual(
            [
                {"name": "item", "type": "Item", "optional": False},
                {"name": "dropOnFail", "type": "boolean", "optional": True},
                {"name": "destroyOnFail", "type": "boolean", "optional": True},
            ],
            signature("Character", "giveItem"),
        )
        self.assertEqual(
            [{"name": "what", "type": "integer", "optional": False}, {"name": "unmodified", "type": "boolean", "optional": True}],
            signature("CharStats", "getStat"),
        )
        # Header-derived types fill parameters the stack checks miss: the
        # dual-call static index and MyGUI readers.
        self.assertEqual(
            [{"name": "shift", "type": "table", "optional": False}],
            signature("CombatClass", "shiftEffects"),
        )
        self.assertEqual(
            [{"name": "value", "type": "MyGUI.Colour", "optional": False}],
            signature("ScreenLabel", "setColor"),
        )
        # lua_pushlightuserdata hands Lua a raw pointer whatever the declared
        # MyGUI::ScrollBar* type, so the header must not relabel it.
        self.assertEqual(
            "lightuserdata",
            next(
                item for item in bindings["DataPanelLine_SliderEditable"]["properties"]
                if item["name"] == "sliderBar"
            )["type"],
        )
        # Objects pushed with an explicit base metatable keep the base type;
        # the declared subclass's methods are not available.
        self.assertEqual(
            "MyGUI.Widget|nil",
            next(
                item for item in bindings["CraftingInventoryLayout"]["properties"]
                if item["name"] == "queueBtn"
            )["type"],
        )
        signature = lambda lua_type, name: next(
            item for item in bindings[lua_type]["methods"] if item["name"] == name
        )["signature"]
        # Static-style callback registered as a method: no self.
        self.assertTrue(signature("FarmBuilding", "getFertilityMultiplier").get("no_self"))
        self.assertEqual(
            ["number", "GameData"],
            [param["type"] for param in signature("FarmBuilding", "getFertilityMultiplier")["params"]],
        )
        # Dual-call `1 + offset` reads, arrays built with lua_rawseti, and
        # records built with lua_setfield.
        self.assertEqual(["string"], [p["type"] for p in signature("UtilityT", "makeSureGameFolderExists")["params"]])
        self.assertEqual(["ZoneMap[]"], signature("ZoneManager", "getAllActiveZones")["returns"])
        self.assertEqual(
            "{ height: integer, width: integer }",
            next(item for item in bindings["DialogueSpeechBubble"]["properties"] if item["name"] == "baseSize")["type"],
        )
        self.assertEqual(["Faction[]"], [p["type"] for p in signature("Dialogue", "isAtTownOf")["params"]])
        self.assertEqual("YesNoMaybeValue", bindings.get("YesNoMaybeValue", {}).get("lua_type"))

        # Directly registered containers are inventoried and typed as
        # instantiations of their template's generic class.
        lektor = bindings["Lektor<Character>"]
        self.assertEqual("lektor<Character*>", lektor["metatable"])
        self.assertEqual({"key": "integer", "type": "Character|nil"}, lektor["indexer"])
        methods = {item["name"]: item["signature"] for item in lektor["methods"]}
        self.assertEqual(["Character|nil"], methods["pop"]["returns"])
        self.assertEqual([{"name": "value", "type": "Character", "optional": False}], methods["push"]["params"])
        self.assertEqual(["table<integer, Character>"], methods["toTable"]["returns"])
        self.assertEqual(
            ["Lektor<Character>", "nil"],
            next(
                item for item in bindings["PlayerInterface"]["methods"]
                if item["name"] == "getAllPlayerCharacters"
            )["signature"]["returns"],
        )
        # lektor<ModInfo*> and lektor<ModInfo> are both writable lektors of
        # ModInfo in Lua; central registration makes lektor<ModInfo> writable.
        mod_info = bindings["Lektor<ModInfo>"]
        self.assertEqual(
            {"lektor<ModInfo*>", "lektor<ModInfo>"},
            {mod_info["metatable"]} | set(mod_info.get("metatable_aliases", [])),
        )
        self.assertEqual("LektorValueBinding", bindings["Lektor<hand>"]["template"])
        # Typedef aliases registering one metatable are one Lua type.
        self.assertEqual("ogre_unordered_set<hand>", bindings["OgreUnorderedSet<hand>"]["metatable"])
        self.assertEqual(
            1, sum(1 for entry in inventory["classes"] if entry["metatable"] == "std::set<hand>")
        )
        game_data_by_id = bindings["OgreUnorderedMap<integer, GameData>"]
        self.assertEqual({"key": "integer", "type": "GameData|nil"}, game_data_by_id["indexer"])
        self.assertEqual(
            ["ContainerIterator<integer, GameData>"],
            next(item for item in game_data_by_id["methods"] if item["name"] == "pairs")["signature"]["returns"],
        )
        self.assertEqual(
            ["Character"],
            next(item for item in bindings["ActivePlatoon"]["methods"] if item["name"] == "getSquadLeader")["signature"]["returns"],
        )
        self.assertEqual(
            ["OgreFastArray<lightuserdata>"],
            next(item for item in bindings["AppearanceManager"]["methods"] if item["name"] == "getCharacterIdleAnimations")["signature"]["returns"],
        )
        self.assertEqual(
            ["table"],
            next(item for item in bindings["Character"]["methods"] if item["name"] == "getPredictedPosition")["signature"]["returns"],
        )
        self.assertEqual(
            ["boolean", "integer", "integer"],
            next(
                item for item in bindings["InventorySection"]["methods"]
                if item["name"] == "getValidInventoryPosition"
            )["signature"]["return_values"],
        )
        self.assertEqual(
            ["integer", "number"],
            next(
                item for item in bindings["CombatClass"]["methods"]
                if item["name"] == "whoAttacksYouOrMe"
            )["signature"]["return_values"],
        )
        self.assertEqual(
            ["number", "Character|nil"],
            next(
                item for item in bindings["Character"]["methods"]
                if item["name"] == "getStealingSuccessChance"
            )["signature"]["return_values"],
        )
        self.assertEqual(
            ["boolean", "GameData|nil", "number", "number"],
            next(
                item for item in bindings["ZoneManager"]["methods"]
                if item["name"] == "getGroundEffect"
            )["signature"]["return_values"],
        )
        character_properties = {
            item["name"]: item
            for item in bindings["Character"]["properties"]
        }
        self.assertEqual("boolean", character_properties["stealthMode"]["type"])
        self.assertEqual("Inventory", character_properties["inventory"]["type"])
        editor_properties = {
            item["name"]: item
            for item in bindings["CharacterEditWindow"]["properties"]
        }
        self.assertEqual("MyGUI.Button|nil", editor_properties["importButton"]["type"])
        self.assertEqual(
            [],
            next(item for item in bindings["StdDeque<number>"]["methods"] if item["name"] == "push_back")["signature"]["returns"],
        )
        self.assertEqual(
            ["integer"],
            next(item for item in bindings["StdDeque<number>"]["methods"] if item["name"] == "size")["signature"]["returns"],
        )

    def test_bulk_binding_signature_inference_has_broad_coverage(self):
        inventory = generate_binding_inventory.build_inventory()
        methods = [method for entry in inventory["classes"] for method in entry["methods"]]
        signatures = [method for method in methods if "signature" in method]
        self.assertEqual(len(methods), len(signatures))
        inferred_returns = [
            method
            for method in signatures
            if method["signature"].get("returns")
        ]
        self.assertGreaterEqual(len(inferred_returns), 2800)
        properties = [prop for entry in inventory["classes"] for prop in entry["properties"]]
        typed_properties = [prop for prop in properties if prop.get("type")]
        self.assertGreaterEqual(len(typed_properties), 2600)

    def test_local_mygui_inheritance_is_inventoried(self):
        inventory = generate_binding_inventory.build_inventory()
        bindings = {entry["binding"]: entry for entry in inventory["classes"]}
        self.assertEqual("WidgetBinding", bindings["ButtonBinding"]["parent_binding"])
        self.assertEqual("EditBoxBinding", bindings["ComboBoxBinding"]["parent_binding"])
        self.assertEqual("TextBoxBinding", bindings["WindowBinding"]["parent_binding"])

    def test_custom_mygui_properties_are_inventoried(self):
        inventory = generate_binding_inventory.build_inventory()
        bindings = {entry["binding"]: entry for entry in inventory["classes"]}
        expected = {
            "ButtonBinding": {"selected", "stateSelected"},
            "ProgressBarBinding": {"position", "progressPosition", "progressRange", "range"},
            "WindowBinding": {"autoAlpha", "movable", "snap"},
        }
        for binding, property_names in expected.items():
            actual = {prop["name"] for prop in bindings[binding]["properties"]}
            self.assertTrue(property_names.issubset(actual), binding)

    def test_runtime_global_functions_are_inventoried(self):
        inventory = generate_binding_inventory.build_inventory()
        functions = {entry["name"] for entry in inventory["global_functions"]}
        expected = {
            "registerHandler",
            "unregisterHandler",
            "getGameWorld",
            "getPlayerInterface",
            "getInputHandler",
            "getSelectedCharacter",
            "getRootObjectFactory",
            "getGlobalConstants",
            "getOptionsHolder",
            "getForgottenGUI",
            "print",
        }
        self.assertEqual(expected, functions)

    def test_generic_container_instances_are_inventoried(self):
        inventory = generate_binding_inventory.build_inventory()
        bindings = {}
        for entry in inventory["classes"]:
            for binding in [entry["binding"]] + entry.get("binding_aliases", []):
                bindings.setdefault(binding, entry)
        animation_data = bindings["AnimationDataFastArrayBinding"]
        # Pointer arrays registered without an element metatable share one type.
        self.assertEqual("OgreFastArray<lightuserdata>", animation_data["lua_type"])
        self.assertIn(
            "Ogre::FastArray<AnimationData*>",
            [animation_data["metatable"]] + animation_data.get("metatable_aliases", []),
        )
        self.assertEqual("OgreFastArrayPtrBinding", animation_data["template"])
        self.assertIn("push_back", {method["name"] for method in animation_data["methods"]})
        self.assertIn("TownFacilitiesTagsBinding", bindings)
        self.assertEqual(
            {"clearAll", "setTag", "has"},
            {"clearAll", "setTag", "has"}.intersection(
                method["name"] for method in bindings["TownFacilitiesTagsBinding"]["methods"]
            ),
        )
        self.assertEqual(
            [{"name": "flags", "access": "readwrite", "type": "integer"}],
            bindings["TownFacilitiesTagsBinding"]["properties"],
        )
        lektor_methods = {
            method["name"]
            for method in bindings["CombatTechniqueDataLektorBinding"]["methods"]
        }
        self.assertTrue({"push", "pop", "removeAt", "toTable"}.issubset(lektor_methods))

    def test_similarly_named_template_aliases_keep_distinct_runtime_types(self):
        inventory = generate_binding_inventory.build_inventory()
        bindings = {}
        for entry in inventory["classes"]:
            for binding in [entry["binding"]] + entry.get("binding_aliases", []):
                bindings[binding] = entry
        state_maps = [bindings[name] for name in (
            "EventDeliveredStatesMapBinding",
            "RepetitionStatesMapBinding",
            "StatesMapBinding",
        )]
        self.assertEqual(3, len({entry["metatable"] for entry in state_maps}))
        self.assertEqual(
            {"StdMap<integer, hand>", "StdMap<integer, DialogState>", "OgreUnorderedMap<integer, GameData>"},
            {entry["lua_type"] for entry in state_maps},
        )


class CoverageReportTests(unittest.TestCase):
    def test_committed_coverage_report_is_reproducible(self):
        generated = generate_coverage_report.serialize(generate_coverage_report.build_report())
        self.assertEqual(
            generated,
            generate_coverage_report.OUTPUT_PATH.read_text(encoding="utf-8"),
        )

    def test_inventory_completion_gate_is_satisfied(self):
        report = generate_coverage_report.build_report()
        self.assertTrue(report["summary"]["complete"])
        self.assertEqual(report["summary"]["bindings"], report["summary"]["complete_bindings"])
        self.assertEqual(report["summary"]["methods"], report["summary"]["covered_methods"])
        self.assertEqual(100.0, report["summary"]["signature_percent"])
        self.assertGreaterEqual(report["summary"]["inferred_return_percent"], 98.0)
        self.assertGreaterEqual(report["summary"]["inferred_property_percent"], 90.0)
        self.assertGreaterEqual(report["summary"]["kenshilib_method_description_percent"], 50.0)
        self.assertGreaterEqual(report["summary"]["kenshilib_property_description_percent"], 30.0)

    def test_all_registration_calls_resolve(self):
        report = generate_coverage_report.build_report()
        self.assertEqual(0, report["summary"]["unresolved_registration_calls"])

    def test_first_mygui_expansion_batch_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        expected = {
            "MyGUI.Button",
            "MyGUI.Canvas",
            "MyGUI.ComboBox",
            "MyGUI.DDContainer",
            "MyGUI.EditBox",
            "MyGUI.ImageBox",
            "MyGUI.ItemBox",
            "MyGUI.ListBox",
            "MyGUI.MenuControl",
            "MyGUI.MenuItem",
            "MyGUI.MultiListBox",
            "MyGUI.ProgressBar",
            "MyGUI.ScrollView",
            "MyGUI.ScrollBar",
            "MyGUI.TabItem",
            "MyGUI.TabControl",
            "MyGUI.TextBox",
            "MyGUI.Widget",
            "MyGUI.Window",
        }
        self.assertTrue(all(bindings[lua_type]["complete"] for lua_type in expected))

    def test_runtime_global_functions_are_complete(self):
        report = generate_coverage_report.build_report()
        self.assertEqual(
            report["summary"]["functions"],
            report["summary"]["covered_functions"],
        )

    def test_root_opaque_bindings_are_declared(self):
        report = generate_coverage_report.build_report()
        opaque_roots = [
            entry
            for entry in report["bindings"]
            if entry["method_count"] == 0
            and entry["property_count"] == 0
            and not entry["expected_parent"]
        ]
        self.assertTrue(opaque_roots)
        self.assertTrue(all(entry["complete"] for entry in opaque_roots))

    def test_inventory_layout_foundations_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["BaseLayout"]["complete"])
        self.assertTrue(bindings["InventoryLayout"]["complete"])
        self.assertTrue(bindings["StdMap<string, InventorySectionGUI>"]["complete"])
        self.assertTrue(bindings["InventorySectionGUI"]["complete"])
        self.assertTrue(bindings["GameDataCopyStandalone"]["complete"])

    def test_small_inventory_layout_subclasses_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        expected = {
            "AnimalInventoryLayout",
            "BackpackInventoryLayout",
            "BuildingContainerInventoryLayout",
            "CharacterInventoryLayout",
            "FurnaceInventoryLayout",
            "GenericFixedInventoryLayout",
            "GenericInventoryLayout",
            "LimbsInventoryLayout",
            "ProductionInventoryLayout",
            "ResearchBuildingInventoryLayout",
            "TraderInventoryLayout",
        }
        self.assertTrue(all(bindings[lua_type]["complete"] for lua_type in expected))

    def test_build_inventory_layouts_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["BuildInventoryLayout"]["complete"])
        self.assertTrue(bindings["CraftingInventoryLayout"]["complete"])

    def test_inventory_support_types_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["SectionItem"]["complete"])
        self.assertTrue(bindings["OgreVector<SectionItem>"]["complete"])
        self.assertTrue(bindings["Inventory_HasRoomCache"]["complete"])

    def test_inventory_item_base_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["InventoryItemBase"]["complete"])

    def test_inventory_value_dependencies_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["iVector2"]["complete"])
        self.assertTrue(bindings["StringPair"]["complete"])

    def test_game_save_state_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["GameSaveState"]["complete"])
        self.assertTrue(bindings["OgreUnorderedMap<integer, GameData>"]["complete"])

    def test_game_data_container_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["GameDataContainer"]["complete"])

    def test_game_data_manager_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["GameDataManager"]["complete"])
        self.assertTrue(bindings["GameDataManager"]["inheritance_declared"])

    def test_game_data_value_types_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["GameDataGroup"]["complete"])
        self.assertTrue(bindings["GameDataValuePair"]["complete"])

    def test_dialogue_value_types_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["DialogAction"]["complete"])
        self.assertTrue(bindings["DialogChoiceList"]["complete"])

    def test_dialog_condition_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["DialogCondition"]["complete"])

    def test_dialog_line_data_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["DialogLineData"]["complete"])
        self.assertTrue(bindings["OgreUnorderedMap<GameData, integer>"]["complete"])

    def test_dialogue_support_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["CampaignTriggerData"]["complete"])
        self.assertTrue(bindings["TimeOfDay"]["complete"])
        self.assertTrue(bindings["WorldEventStateQueryList"]["complete"])

    def test_world_event_state_query_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["WorldEventStateQuery"]["complete"])

    def test_compact_value_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in (
            "AkSoundPosition",
            "CombatClass_AttackSlotManager_SlotData",
            "EdgeCache_Edge",
            "Faction_CharacteristicsData",
        ):
            self.assertTrue(bindings[name]["complete"])

    def test_ak_vector_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["AkVector"]["complete"])

    def test_small_record_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in (
            "ManagementScreen_TechItemViewData",
            "MapScreen_MapRoad",
            "NavMeshGenerator_TaskQueue",
            "TownBuildingsManager_BuildingInfo",
            "MessageQueue_Node",
            "MeshDataLookup",
        ):
            self.assertTrue(bindings[name]["complete"])

    def test_nav_mesh_generator_task_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["NavMeshGenerator_Task"]["complete"])

    def test_aabb_and_ai_options_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["AABB2D"]["complete"])
        self.assertTrue(bindings["AIOptions"]["complete"])

    def test_small_auxiliary_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in (
            "FactoryCallbackInterface",
            "NxBox",
            "TriggerCallback",
            "StatGroup",
            "StateT",
            "ZoneSpacialGrid_ZoneCell",
            "rendHit",
            "RobotLimbItem",
        ):
            self.assertTrue(bindings[name]["complete"])

    def test_perf_timer_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["CPerfTimer"]["complete"])
        self.assertTrue(bindings["CPerfTimerT"]["complete"])

    def test_dialog_state_records_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["FlagCondition"]["complete"])
        self.assertTrue(bindings["DialogState"]["complete"])

    def test_message_for_b_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["MessageForB"]["complete"])

    def test_level_editor_list_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("FactionListWindow", "ItemListWindow", "NpcListWindow", "TownListWindow"):
            self.assertTrue(bindings[name]["complete"])

    def test_havok_allocator_binding_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["hkContainerHeapAllocator_Allocator"]["complete"])

    def test_resource_load_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("ResourceLinePanel", "ResourceLoadRequestMesh", "ResourceLoadRequestTexture"):
            self.assertTrue(bindings[name]["complete"])

    def test_texture_and_message_box_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["Box"]["complete"])
        self.assertTrue(bindings["TextureArrayLoadData"]["complete"])

    def test_character_state_records_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("Character_CarryMsg", "Character_RagdollMsg", "TaskStateData", "Spot"):
            self.assertTrue(bindings[name]["complete"])

    def test_resource_data_records_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["MeshLoadData"]["complete"])
        self.assertTrue(bindings["ParticlePool_ParticleData"]["complete"])

    def test_editor_and_perception_records_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["GameDataEditorWindow_DataItem"]["complete"])
        self.assertTrue(bindings["WhoSeesMe"]["complete"])

    def test_building_and_timer_records_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("BuildingCategory", "BuildingGroup", "hkResult", "SimpleTimeStamper"):
            self.assertTrue(bindings[name]["complete"])

    def test_squad_list_window_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["SquadListWindow"]["complete"])

    def test_squad_and_message_box_manager_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("SquadItemBox", "SquadData", "MessageBoxManager"):
            self.assertTrue(bindings[name]["complete"])

    def test_portrait_and_map_marker_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["PortraitImage"]["complete"])
        self.assertTrue(bindings["MapMarkerCharacter"]["complete"])

    def test_data_panel_line_text_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["DataPanelLine_Text"]["complete"])

    def test_repetition_counter_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["RepetitionCounter"]["complete"])

    def test_shop_trader_inventory_section_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["ShopTraderInventorySection"]["complete"])

    def test_terrain_blood_queue_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["Terrain_BloodQueue"]["complete"])

    def test_utility_value_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("TripleInt", "hkBool", "TradeResult"):
            self.assertTrue(bindings[name]["complete"])

    def test_appearance_animal_is_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["AppearanceAnimal"]["complete"])

    def test_editor_window_and_portrait_box_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        self.assertTrue(bindings["GameDataEditorWindow"]["complete"])
        self.assertTrue(bindings["PortraitSquadItemBox"]["complete"])

    def test_core_character_building_town_and_stats_bindings_are_complete(self):
        report = generate_coverage_report.build_report()
        bindings = {entry["lua_type"]: entry for entry in report["bindings"]}
        for name in ("Character", "Building", "TownBase", "CharStats"):
            self.assertTrue(bindings[name]["complete"])


class TypeAuditTests(unittest.TestCase):
    def test_header_declaration_maps_out_params_to_returns(self):
        headers = generate_type_audit.HeaderIndex()
        with tempfile.TemporaryDirectory() as temporary:
            header = pathlib.Path(temporary) / "Zone.h"
            header.write_text(
                "class GameData;\n"
                "class ZoneManager : public Base\n{\npublic:\n"
                "    bool getGroundEffect(const Ogre::Vector3& pos, GameData*& effect, float& minSpeed);"
                "// public RVA = 0x1\n"
                "    float speed;\n};\n",
                encoding="utf-8",
            )
            headers.parse_file(header)
        decl = headers.classes["ZoneManager"]["methods"]["getGroundEffect"][0]
        self.assertEqual(["Base"], headers.classes["ZoneManager"]["bases"])
        self.assertEqual("float", headers.classes["ZoneManager"]["members"]["speed"])
        inventory = {"classes": [
            {"binding": "GameDataBinding", "lua_type": "GameData", "metatable": "KenshiLua.GameData", "kind": "class"},
        ]}
        mapper = generate_type_audit.TypeMapper(inventory, [], headers, set())
        params, returns = generate_type_audit.expected_signature(decl, mapper)
        self.assertEqual(["table"], [param["type"] for param in params])
        self.assertEqual(["boolean", "GameData|nil", "number"], returns)

    def test_compare_type_accepts_subclasses_and_reports_any(self):
        with mock.patch.dict(generate_type_audit.LUA_PARENTS, {"MyGUI.ImageBox": "MyGUI.Widget"}):
            self.assertIsNone(generate_type_audit.compare_type("MyGUI.ImageBox", "MyGUI.Widget|nil", set()))
        self.assertEqual("any_with_header_type", generate_type_audit.compare_type("any", "number", set()))
        self.assertEqual("type_mismatch", generate_type_audit.compare_type("lightuserdata", "MyGUI.Widget|nil", set()))

    def test_committed_audit_is_current(self):
        expected = generate_type_audit.serialize(generate_type_audit.build_report())
        self.assertEqual(expected, generate_type_audit.OUTPUT_PATH.read_text(encoding="utf-8"))


if __name__ == "__main__":
    unittest.main()
