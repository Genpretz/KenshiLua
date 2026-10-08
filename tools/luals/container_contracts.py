"""Reviewed Lua contracts for KenshiLua's generic container bindings.

Each container template in src/Bindings/Kenshi/Util registers the same Lua
surface for every element type, so it is declared once as a LuaLS generic
class named after the template (``Lektor<T>``, ``OgreUnorderedMap<K, V>``) and
every registered instance is typed as an instantiation
(``Lektor<Character>``).  Contracts are written with placeholders:

``K``  key type (maps)
``V``  element or value type

The contracts were checked against the template sources: front/back, pop of
a null pointer element, and out-of-range indexing push nil; StdSetBinding.insert
returns nothing while the other set inserts return whether the element was
added.  pop is declared ``T|nil`` for every list: the templates currently raise
on an empty pop, and returning nil there instead (like front/back and Lua's
table.remove) is part of the planned container binding redesign.

LuaLS 3.19 substitutes class type parameters in indexers, plain returns and
``table<K, V>``, but not inside ``T[]`` or an inline ``fun(): K, V``.  Array
results are therefore declared as ``table<integer, T>`` and iterators through
the ``ContainerIterator<K, V>`` alias.  The tests/luals/invalid/container_*.lua
fixtures fail if LuaLS stops typing elements through these forms.
"""

import re


ITERATOR_ALIAS = {"name": "ContainerIterator<K, V>", "definition": "fun(): K, V"}

# template -> (kind, generic class, C++ spellings of the container type)
FAMILIES = {
    "LektorPtrBinding": ("list", "Lektor", ["lektor<{0}>"]),
    "LektorValueBinding": ("list", "Lektor", ["lektor<{0}>"]),
    "LektorStringBinding": ("list", "Lektor", ["lektor<{0}>"]),
    "LektorIntBinding": ("list", "Lektor", ["lektor<{0}>"]),
    "LektorValueReadOnlyBinding": ("readonly_list", "LektorReadOnly", ["lektor<{0}>"]),
    "OgreFastArrayPtrBinding": ("list", "OgreFastArray", ["Ogre::FastArray<{0}>"]),
    "OgreFastArrayValueBinding": ("list", "OgreFastArray", ["Ogre::FastArray<{0}>"]),
    "OgreFastArrayPrimitiveBinding": ("list", "OgreFastArray", ["Ogre::FastArray<{0}>"]),
    "StdDequePtrBinding": ("list", "StdDeque", ["std::deque<{0}>"]),
    "StdDequeValueBinding": ("list", "StdDeque", ["std::deque<{0}>"]),
    "StdDequePrimitiveBinding": ("list", "StdDeque", ["std::deque<{0}>"]),
    "OgreVectorPtrBinding": ("list", "OgreVector", ["Ogre::vector<{0}>::type", "Ogre::vector<{0}>"]),
    "OgreVectorValueBinding": ("list", "OgreVector", ["Ogre::vector<{0}>::type", "Ogre::vector<{0}>"]),
    "OgreUnorderedSetBinding": (
        "set", "OgreUnorderedSet", ["ogre_unordered_set<{0}>::type", "ogre_unordered_set<{0}>"],
    ),
    "BoostUnorderedSetBinding": (
        "set", "BoostUnorderedSet", ["boost::unordered_set<{0}>", "boost::unordered::unordered_set<{0}>"],
    ),
    "StdSetBinding": ("set", "StdSet", ["std::set<{0}>"]),
    "OgreUnorderedMapBinding": (
        "map", "OgreUnorderedMap", ["ogre_unordered_map<{0}>::type", "ogre_unordered_map<{0}>"],
    ),
    "BoostUnorderedMapBinding": (
        "map", "BoostUnorderedMap", ["boost::unordered_map<{0}>", "boost::unordered::unordered_map<{0}>"],
    ),
    "StdMapBinding": ("map", "StdMap", ["std::map<{0}>"]),
}

_LIST = {
    "push": ([("value", "V")], []),
    "push_back": ([("value", "V")], []),
    "push_front": ([("value", "V")], []),
    "pop": ([], ["V|nil"]),
    "pop_back": ([], ["V|nil"]),
    "pop_front": ([], ["V|nil"]),
    "front": ([], ["V|nil"]),
    "back": ([], ["V|nil"]),
    "removeAt": ([("index", "integer")], []),
    "clear": ([], []),
    "empty": ([], ["boolean"]),
    "reserve": ([("count", "integer")], []),
    "size": ([], ["integer"]),
    "toTable": ([], ["table<integer, V>"]),
}
_SET = {
    "has": ([("value", "V")], ["boolean"]),
    "contains": ([("value", "V")], ["boolean"]),
    "add": ([("value", "V")], ["boolean"]),
    "insert": ([("value", "V")], ["boolean"]),
    "remove": ([("value", "V")], ["boolean"]),
    "erase": ([("value", "V")], ["boolean"]),
    "clear": ([], []),
    "size": ([], ["integer"]),
    "toTable": ([], ["table<V, boolean>"]),
    "items": ([], ["ContainerIterator<V, boolean>"]),
}
_MAP = {
    "has": ([("key", "K")], ["boolean"]),
    "contains": ([("key", "K")], ["boolean"]),
    "remove": ([("key", "K")], ["boolean"]),
    "erase": ([("key", "K")], ["boolean"]),
    "clear": ([], []),
    "size": ([], ["integer"]),
    "toTable": ([], ["table<K, V>"]),
    "pairs": ([], ["ContainerIterator<K, V>"]),
}
METHODS = {
    "list": _LIST,
    "readonly_list": {name: _LIST[name] for name in ("size", "toTable")},
    "set": _SET,
    "map": _MAP,
}
METHOD_OVERRIDES = {
    ("StdSetBinding", "insert"): ([("value", "V")], []),
}
INDEXERS = {
    "list": ("integer", "V|nil"),
    "readonly_list": ("integer", "V|nil"),
    "set": ("V", "boolean"),
    "map": ("K", "V|nil"),
}

# Non-generic container helpers keep a concrete class name.
NAME_OVERRIDES = {
    "FitnessSelector<CampaignTriggerData*>": "FitnessSelectorCampaignTriggerData",
}

_PRIMITIVE_NAMES = {
    "string": "String", "int": "Int", "float": "Float", "bool": "Bool",
    "double": "Double", "unsigned": "UInt",
}


def family(template):
    return FAMILIES.get(template)


def cpp_base_name(argument):
    """Readable name of a template argument: ``MyGUI::Button*`` -> ``Button``."""
    text = re.sub(r"\b(?:const|struct|class|typename)\b", "", argument)
    text = re.sub(r"<.*>", "", text).replace("*", "").replace("&", "").strip()
    last = text.split("::")[-1].strip()
    return _PRIMITIVE_NAMES.get(last, last[:1].upper() + last[1:])


def instance_name(template, metatable, args):
    """Concrete class name for a container helper without a generic contract."""
    if metatable in NAME_OVERRIDES:
        return NAME_OVERRIDES[metatable]
    return cpp_base_name(args[0]) + template.removesuffix("Binding")


def generic_parameters(template):
    return ("K", "V") if FAMILIES[template][0] == "map" else ("T",)


def generic_type(template, key_type, value_type):
    """LuaLS type of an instance: ``Lektor<Character>``."""
    kind, name, _ = FAMILIES[template]
    arguments = [key_type, value_type] if kind == "map" else [value_type]
    return name + "<" + ", ".join(arguments) + ">"


def substitute(text, key_type, value_type):
    text = re.sub(r"\bK\b", key_type, text)
    return re.sub(r"\bV\b", value_type, text)


def contract(template, name):
    kind = FAMILIES[template][0]
    return METHOD_OVERRIDES.get((template, name)) or METHODS[kind].get(name)


def method_signature(template, name, key_type, value_type):
    """Concrete signature of a registered container method for one instance."""
    found = contract(template, name)
    if not found:
        return None
    params, returns = found
    return {
        "params": [
            {"name": param_name, "type": substitute(param_type, key_type, value_type), "optional": False}
            for param_name, param_type in params
        ],
        "returns": [substitute(item, key_type, value_type) for item in returns],
        "type_source": "container",
    }


def indexer(template, key_type, value_type):
    key, value = INDEXERS[FAMILIES[template][0]]
    return {"key": substitute(key, key_type, value_type), "type": substitute(value, key_type, value_type)}


def generic_class(template, method_names):
    """Metadata class entry declaring the generic class for ``template``.

    ``method_names`` are the methods its registered instances expose.
    """
    kind, name, _ = FAMILIES[template]
    params = generic_parameters(template)
    key_type, value_type = ("K", "V") if kind == "map" else ("integer", "T")
    self_type = name + "<" + ", ".join(params) + ">"
    index_key, index_type = INDEXERS[kind]
    fields = [{
        "name": "[" + substitute(index_key, key_type, value_type) + "]",
        "type": substitute(index_type, key_type, value_type),
        "description": "Element access through the container's `__index` metamethod.",
    }]
    for method_name in method_names:
        found = contract(template, method_name)
        if not found:
            continue
        method_params, returns = found
        rendered = ["self: " + self_type] + [
            param_name + ": " + substitute(param_type, key_type, value_type)
            for param_name, param_type in method_params
        ]
        method_type = "fun(" + ", ".join(rendered) + ")"
        if returns:
            method_type += ": " + ", ".join(substitute(item, key_type, value_type) for item in returns)
        fields.append({"name": method_name, "type": method_type})
    return {
        "name": self_type,
        "description": "Lua view of the `{0}` container template.".format(template),
        "fields": fields,
    }


def unqualified(cpp_type):
    """Drop namespace and enclosing-class qualifiers: ``A::B::C*`` -> ``C*``."""
    return re.sub(r"\b(?:\w+::)+(?=\w)", "", re.sub(r"\s+", "", cpp_type))


def cpp_spellings(template, args):
    """C++ spellings of an instance's container type, for header type mapping.

    Headers qualify element types relative to their own scope
    (``lektor<ConstructionState::BuildMaterial*>`` inside ``Building``), so an
    unqualified spelling is registered too and matched by ``unqualified``.
    """
    joined = ",".join(re.sub(r"\s+", "", arg) for arg in args)
    spellings = [pattern.format(joined) for pattern in FAMILIES[template][2]]
    return spellings + [unqualified(spelling) for spelling in spellings]


# Lua factories that create Lua-owned containers (LektorBinding.h,
# OgreUnorderedBinding.h). Every registerBinding of these templates also
# registers its type names with the factory, so each inventoried instance is
# one accepted spelling.
FACTORIES = {
    "lektor": {
        "class": "LektorFactory",
        "templates": ("LektorPtrBinding", "LektorValueBinding", "LektorValueReadOnlyBinding",
                      "LektorStringBinding", "LektorIntBinding"),
        "prefix": "lektor",
        "fallback": "Lektor<any>",
        "extra": {"LektorStringBinding": ["string", "lektor<string>"]},
        "description": "Creates Lua-owned `lektor` lists; also callable as `lektor(typeName)`.",
    },
    "ogre_unordered_set": {
        "class": "OgreUnorderedSetFactory",
        "templates": ("OgreUnorderedSetBinding",),
        "prefix": "ogre_unordered_set",
        "fallback": "OgreUnorderedSet<any>",
        "extra": {},
        "description": "Creates Lua-owned `ogre_unordered_set` sets; also callable as `ogre_unordered_set(typeName)`.",
    },
    "ogre_unordered_map": {
        "class": "OgreUnorderedMapFactory",
        "templates": ("OgreUnorderedMapBinding",),
        "prefix": "ogre_unordered_map",
        "fallback": "OgreUnorderedMap<any, any>",
        "extra": {},
        "description": (
            "Creates Lua-owned `ogre_unordered_map` maps from key and value type names "
            "or one full type string; also callable as `ogre_unordered_map(...)`."
        ),
    },
}


def _template_arguments(spelling, prefix):
    """``lektor<GameData*>`` -> ``["GameData*"]``; splits top-level commas."""
    match = re.match(re.escape(prefix) + r"<(.*)>$", spelling)
    if not match:
        return None
    args, depth, current = [], 0, ""
    for char in match.group(1):
        if char == "," and depth == 0:
            args.append(current.strip())
            current = ""
            continue
        depth += {"<": 1, ">": -1}.get(char, 0)
        current += char
    args.append(current.strip())
    return args


def factory_overloads(inventory_classes):
    """global name -> list of (params, return type) for each accepted spelling.

    Exact registered spellings come first. A pointer argument written without
    its ``*`` (``"Character"`` for ``lektor<Character*>``) resolves through the
    factory's retry with ``*`` appended, so it is added only when no instance
    claims the spelling exactly.
    """
    result = {}
    for global_name, spec in FACTORIES.items():
        exact, bare = {}, {}
        for entry in inventory_classes:
            if entry.get("kind") != "template_instance" or entry.get("template") not in spec["templates"]:
                continue
            lua_type = entry["lua_type"]
            spellings = [entry["metatable"]] + entry.get("metatable_aliases", [])
            for spelling in spellings:
                args = _template_arguments(spelling, spec["prefix"])
                if not args:
                    continue
                exact.setdefault((spelling,), lua_type)
                exact.setdefault(tuple(args), lua_type)
                # The factories retry with "*" appended to one argument at a time.
                for index, arg in enumerate(args):
                    if arg.endswith("*"):
                        variant = list(args)
                        variant[index] = arg[:-1]
                        bare.setdefault(tuple(variant), lua_type)
            for name in spec["extra"].get(entry["template"], []):
                exact.setdefault((name,), lua_type)
        for key, lua_type in bare.items():
            exact.setdefault(key, lua_type)
        overloads = []
        for key, lua_type in exact.items():
            if global_name == "ogre_unordered_map" and len(key) == 2:
                params = [("keyType", key[0]), ("valueType", key[1])]
            elif len(key) == 1:
                params = [("typeName", key[0])]
            else:
                continue
            overloads.append((params, lua_type))
        result[global_name] = overloads
    return result
