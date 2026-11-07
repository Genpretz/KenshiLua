# Container binding catalog

For a plain-language walkthrough of how these files connect, start with [How container registration works](../../../docs/ContainerRegistrationExplained.md).

Concrete container bindings are defined and registered here. Class binding files keep their SDK methods, getters, and setters and consume these definitions. This includes specializations used by only one class.

`RegisterContainers.cpp` collects the family definitions, validates the complete catalog, installs their metatables and state-local factory lookup, and installs the factory globals. `RegisterBindings.cpp` then registers classes and inheritance before scripts run.

## Files

| Area | Definitions | Types |
| --- | --- | --- |
| lektor | [RegisterLektor.cpp](RegisterLektor.cpp) | [LektorTypes.h](LektorTypes.h) |
| Standard maps, sets, and deques | [RegisterStdContainers.cpp](RegisterStdContainers.cpp) | [StdContainersTypes.h](StdContainersTypes.h) |
| Ogre unordered maps and sets | [RegisterOgreUnordered.cpp](RegisterOgreUnordered.cpp) | [OgreUnorderedTypes.h](OgreUnorderedTypes.h) |
| Boost unordered containers | [RegisterBoostContainers.cpp](RegisterBoostContainers.cpp) | [BoostContainersTypes.h](BoostContainersTypes.h) |
| Arrays and TagsClass | [RegisterArrays.cpp](RegisterArrays.cpp) | [ArraysTypes.h](ArraysTypes.h) |
| Fitness selectors | [RegisterFitnessSelectors.cpp](RegisterFitnessSelectors.cpp) | [FitnessSelectorsTypes.h](FitnessSelectorsTypes.h) |

[CommonTypes.h](CommonTypes.h) holds complicated specializations shared with consumers without pulling every family's SDK dependencies into each class binding. Generic operations remain in `src/Bindings/Kenshi/Util/` and `FitnessSelectorBinding.h`.

## Adding or changing a specialization

1. Inspect the actual SDK declaration, including access, constness, allocator, comparator, hash, and predicate. Check the helper's element conversion and ownership behavior against the field or method being bound.
2. Declare the helper specialization once in the appropriate type header. Use a small shared header when consumers need a complicated specialization; separate dependencies when SDK headers cannot coexist.
3. Add a `KENSHILUA_DEFINE_CONTAINER` entry in the family source. It supplies the canonical metatable name, three helper-specific metadata slots, and a factory definition. Use `ContainerFactoryDefinition()` when the helper has no supported factory.
4. If a factory exists, give its aliases explicit, unambiguous destinations. Preserve existing aliases and keep compatibility aliases out of public examples. Removing one requires a release which warns on use and a review of likely script impact.
5. Add the definition to the family's `collect...` function and ensure that collector is reachable from `registerContainers`. Component metatable names, for example a fitness selector's maps, must identify the corresponding catalog entries.
6. Use the shared type and its `getMetatableName()` or fixed `metaName` in consumers where available. Keep property and method implementations with their declaring class.
7. Update the native project for new translation units, regenerate affected references, and run the build and relevant automated game checks.

Preserve an existing metatable name for its exact type. Names need not literally spell every C++ parameter, but one name cannot identify incompatible types or policies. For a new specialization, follow the family's readable naming convention. If different policy parameters would otherwise produce the same name, add a stable distinguishing suffix. Intentional writable and read-only views also require distinct binding identities and names.

Factory aliases are lookup keys, separate from canonical userdata identity. Lua factory entry points use `findExplicitContainerFactory` to verify the pointer depth of each requested string argument against the registered container type. An alias cannot turn a value request into a pointer request or vice versa. See the [factory type contract](../../../docs/ContainersReference.md#explicit-factory-types).

Class-table and userdata shortcuts use a separate state-local index built from the element conversion metatables and the factory's canonical type arguments. An index entry records one exact element type, or marks the shortcut ambiguous when multiple types share that metatable. For example, ModInfo userdata is ambiguous between value and pointer lektors. Map shortcuts are indexed separately for key and value positions. Registration order must not select an ambiguous type.

## Descriptor and state contract

[ContainerBinding.h](../ContainerBinding.h) defines the descriptor and catalog macro. Each entry captures the actual wrapped C++ type and wrapper policy through RTTI, its fixed metadata, its installation callback, and its factory contract. Uncatalogued helper specializations fail to link.

Definitions, names, and alias arrays remain immutable and outlive every Lua state using them. The macro and static alias arrays provide module lifetime; registry entries borrow their pointers.

The catalog macro also defines each helper's fixed `metaName` and three conversion metadata slots in its family source. Helpers declare these fields without header definitions. Do not initialize template static fields in headers by calling the descriptor accessor: with the supported toolchain, repeated instantiations leave substantial empty space in the DLL's startup initializer table. Keep ordinary container operations reading the fixed fields directly.

[ContainerBinding.cpp](../ContainerBinding.cpp) validates names, specializations, conversion metadata, existing metatables, and factory aliases before installation. It rejects conflicting registrations, including a specialization renamed in a later call. Identical repeated registration preserves the existing metatable. Each independent Lua state receives its own registration records and factory lookup.

Generic `registerClass` does not prove the wrapped C++ type. Container helpers must keep their `beginContainerBinding` check and must not install metatables through an unguarded direct call. Registration conflicts raise C++ exceptions; the startup and benchmark callers handle them.

Registration establishes type identity and availability. It does not establish engine object lifetime, safe mutation, or ownership transfer. See the [container API and ownership reference](../../../docs/ContainersReference.md).

## Tooling and verification

The inventory generator follows startup collectors across files and reads these same aliases and definitions. It records source provenance and factory contracts and rejects duplicate or unreachable entries, conflicting factory aliases, container installation in class binding sources, and unregistered literal container names. The class scaffold generator reports FastArray catalog requirements for review instead of installing them locally.

Run commands from the repository root:

```powershell
msbuild KenshiLua.vcxproj -p:Configuration=Release -p:Platform=x64
python -m unittest discover -s tests/luals -p "test_*.py"
python tools/luals/generate_binding_inventory.py --check
python tools/luals/generate_definitions.py --check
python tools/luals/generate_coverage_report.py --check
python tools/luals/generate_type_audit.py --check --require-correct
```

Use the [automated game runner](../../../tools/README.md#in-game-automated-testing) for affected runtime behavior. Generated source inventories and compilation do not prove engine lifetime safety. Record the executable hash and KenshiLib platform/version; address-dependent behavior requires both supported executables.
