#include "pch.h"
#include "kenshi\havok.h"
#include "hkVector4fBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static hkVector4f* getInstance(lua_State* L, int idx)
{
    return checkObject<hkVector4f>(L, idx, hkVector4fBinding::getMetatableName());
}

// --- Getters for hkVector4f ---
// --- Setters for hkVector4f ---
int hkVector4fBinding::setZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    instance->setZero();
    return 0;
}

int hkVector4fBinding::zeroComponent(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    const int i = (int)luaL_checkinteger(L, 2);
    instance->zeroComponent(i);
    return 0;
}

int hkVector4fBinding::setInt24W(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    int value = (int)luaL_checkinteger(L, 2);
    instance->setInt24W(value);
    return 0;
}

int hkVector4fBinding::getInt24W(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    int result = instance->getInt24W();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fBinding::getInt16W(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    int result = instance->getInt16W();
    lua_pushinteger(L, result);
    return 1;
}

int hkVector4fBinding::setZero4(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    instance->setZero4();
    return 0;
}

int hkVector4fBinding::normalize3(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    instance->normalize3();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 153: void*operator new(...) - static method
  line 155: void operator delete(...) - static method
  line 164: hkVector4f* _CONSTRUCTOR(...) - overloaded method
  line 167: hkVector4f* _CONSTRUCTOR(...) - overloaded method
  line 169: hkVector4f* _CONSTRUCTOR(...) - overloaded method
  line 171: void operator=(...) - operator
  line 172: void set(...) - overloaded method
  line 173: void set(...) - overloaded method
  line 174: void setAll(...) - overloaded method
  line 175: void setAll(...) - overloaded method
  line 178: void add(...) - unsupported arg type
  line 179: void sub(...) - unsupported arg type
  line 180: void mul(...) - overloaded method
  line 181: void mul(...) - overloaded method
  line 182: void div(...) - unsupported arg type
  line 183: void setAdd(...) - overloaded method
  line 184: void setAdd(...) - overloaded method
  line 185: void setSub(...) - overloaded method
  line 186: void setSub(...) - overloaded method
  line 187: void setMul(...) - overloaded method
  line 188: void setMul(...) - overloaded method
  line 189: void setMul(...) - overloaded method
  line 190: void setDiv(...) - unsupported arg type
  line 191: void setReciprocal(...) - unsupported arg type
  line 192: void setSqrt(...) - unsupported arg type
  line 193: void setSqrtInverse(...) - unsupported arg type
  line 194: void addMul(...) - overloaded method
  line 195: void addMul(...) - overloaded method
  line 196: void addMul(...) - overloaded method
  line 197: void setAddMul(...) - overloaded method
  line 198: void setAddMul(...) - overloaded method
  line 199: void subMul(...) - overloaded method
  line 200: void subMul(...) - overloaded method
  line 201: void subMul(...) - overloaded method
  line 202: void setSubMul(...) - overloaded method
  line 203: void setSubMul(...) - overloaded method
  line 204: void setCross(...) - unsupported arg type
  line 205: void setInterpolate(...) - unsupported arg type
  line 206: const hkVector4fComparison less(...) - unsupported return type
  line 207: const hkVector4fComparison lessEqual(...) - unsupported return type
  line 208: const hkVector4fComparison greater(...) - unsupported return type
  line 209: const hkVector4fComparison greaterEqual(...) - unsupported return type
  line 210: const hkVector4fComparison equal(...) - unsupported return type
  line 211: const hkVector4fComparison notEqual(...) - unsupported return type
  line 212: const hkVector4fComparison lessZero(...) - unsupported return type
  line 213: const hkVector4fComparison lessEqualZero(...) - unsupported return type
  line 214: const hkVector4fComparison greaterZero(...) - unsupported return type
  line 215: const hkVector4fComparison greaterEqualZero(...) - unsupported return type
  line 216: const hkVector4fComparison equalZero(...) - unsupported return type
  line 217: const hkVector4fComparison notEqualZero(...) - unsupported return type
  line 220: void setSelect(...) - unsupported arg type
  line 221: void zeroIfFalse(...) - unsupported arg type
  line 222: void zeroIfTrue(...) - unsupported arg type
  line 223: void setFlipSign(...) - overloaded method
  line 224: void setFlipSign(...) - overloaded method
  line 225: void setFlipSign(...) - overloaded method
  line 226: void setAbs(...) - unsupported arg type
  line 227: void setMin(...) - unsupported arg type
  line 228: void setMax(...) - unsupported arg type
  line 230: void setClamped(...) - unsupported arg type
  line 231: void setClampedZeroOne(...) - unsupported arg type
  line 232: void setClampedToMaxLength(...) - unsupported arg type
  line 233: void setRotatedDir(...) - overloaded method
  line 234: void setRotatedDir(...) - overloaded method
  line 235: void setRotatedInverseDir(...) - overloaded method
  line 236: void setRotatedInverseDir(...) - overloaded method
  line 237: void setTransformedPos(...) - overloaded method
  line 238: void setTransformedPos(...) - overloaded method
  line 239: void setTransformedPos(...) - overloaded method
  line 240: void setTransformedInversePos(...) - overloaded method
  line 241: void setTransformedInversePos(...) - overloaded method
  line 242: void setTransformedInversePos(...) - overloaded method
  line 243: void _setRotatedDir(...) - overloaded method
  line 244: void _setRotatedDir(...) - overloaded method
  line 245: void _setRotatedInverseDir(...) - overloaded method
  line 246: void _setRotatedInverseDir(...) - overloaded method
  line 247: void _setTransformedPos(...) - overloaded method
  line 248: void _setTransformedPos(...) - overloaded method
  line 249: void _setTransformedPos(...) - overloaded method
  line 250: void _setTransformedInversePos(...) - overloaded method
  line 251: void _setTransformedInversePos(...) - overloaded method
  line 252: void _setTransformedInversePos(...) - overloaded method
  line 253: void setPlaneConstant(...) - unsupported arg type
  line 254: const hkSimdFloat32 dot4xyz1(...) - unsupported return type
  line 255: const hkSimdFloat32 distanceTo(...) - unsupported return type
  line 256: const hkSimdFloat32 distanceToSquared(...) - unsupported return type
  line 257: void setXYZ_W(...) - overloaded method
  line 258: void setXYZ_W(...) - overloaded method
  line 259: void setW(...) - overloaded method
  line 260: void setW(...) - overloaded method
  line 262: void setXYZ(...) - overloaded method
  line 263: void setXYZ(...) - overloaded method
  line 264: void setXYZ_0(...) - unsupported arg type
  line 271: const float& operator(...) - operator
  line 272: float& operator(...) - operator
  line 273: const hkSimdFloat32 getComponent(...) - unsupported return type
  line 274: const hkSimdFloat32 getW(...) - unsupported return type
  line 277: void setComponent(...) - unsupported arg type
  line 281: const hkVector4f& getZero(...) - static method
  line 282: const hkVector4f& getConstant(...) - static method
  line 293: hkSimdFloat32 dot3(...) - unsupported return type
  line 318: void setNeg3(...) - unsupported arg type
  line 328: hkSimdFloat32 normalizeWithLength3(...) - unsupported return type
  line 335: hkSimdFloat32 length3(...) - unsupported return type
  line 337: hkSimdFloat32 lengthSquared3(...) - unsupported return type
  line 354: unsigned int equals3(...) - unsupported arg type
  line 365: hkSimdFloat32 distanceTo3(...) - unsupported return type
  line 366: hkSimdFloat32 distanceToSquared3(...) - unsupported return type
  line 373: hkBool isOk3(...) - unsupported return type
  line 374: hkBool isOk4(...) - unsupported return type
*/

/*
Skipped properties needing manual binding:
  line 284: m_quad (union __m128) - unsupported type
*/

int hkVector4fBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int hkVector4fBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hkVector4f object");
    return 1;
}

void hkVector4fBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       hkVector4fBinding::gc },
        { "__tostring", hkVector4fBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setZero", hkVector4fBinding::setZero },
        { "zeroComponent", hkVector4fBinding::zeroComponent },
        { "setInt24W", hkVector4fBinding::setInt24W },
        { "getInt24W", hkVector4fBinding::getInt24W },
        { "getInt16W", hkVector4fBinding::getInt16W },
        { "setZero4", hkVector4fBinding::setZero4 },
        { "normalize3", hkVector4fBinding::normalize3 },
        { 0, 0 }
    };

    registerClass(
        L, 
        hkVector4fBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, hkVector4fBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua