-- LuaLS regression fixture: math and physics types, operators, and constructors.

local v1 = NxVec3(1, 2, 3)
local v2 = NxVec3(4, 5, 6)

local v_add = v1 + v2
local v_sub = v2 - v1
local v_unm = -v1
local v_mul = v1 * 2.0
local v_mul2 = 2.0 * v1

local dot = v1:dot(v2)
v1:set(v_unm.x, v_unm.y, v_unm.z)

local m1 = NxMat33()
local m_mul = m1 * v1
local m_mat = m1 * m1
local cell = m1(0, 0)
m1(0, 1, 3.5)

local h1 = hkVector4f(1.0, 2.0, 3.0, 4.0)
local val = h1(0)
h1(0, 99.0)

local comp = hkVector4fComparison(0)
local mask = comp:getMask()

local ok, new_v = pcall(NxVec3, 1, 2, 3)
