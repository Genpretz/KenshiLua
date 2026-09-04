#pragma once

// ============================================================================
// SDK Compatibility & Type Shims
//
// Provides struct/class definitions for types that are incomplete or only forward-
// declared in KenshiLib SDK headers, but are required as complete types for:
// - Standard container instantiation (e.g. std::deque<CraftingItem>)
// - Function parameter/return types
// ============================================================================


// Used in Building/CraftingBuilding/FarmBuilding/TownBase
class Layout {};
class AreaBiomeGroup {};
class PosRotPair {};
class StaticBoxEntity {};
class CraftingItem {};

