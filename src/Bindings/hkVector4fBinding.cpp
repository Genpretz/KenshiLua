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

int hkVector4fBinding::getZero(lua_State* L)
{
    const hkVector4f& result = hkVector4f::getZero();
    return pushObject(L, const_cast<hkVector4f*>(&result), hkVector4fBinding::getMetatableName());
}

int hkVector4fBinding::set(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    float a = (float)luaL_checknumber(L, 2);
    float b = (float)luaL_checknumber(L, 3);
    float c = (float)luaL_checknumber(L, 4);
    float d = (float)luaL_checknumber(L, 5);
    instance->set(a, b, c, d);
    return 0;
}

int hkVector4fBinding::setAll(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    float a = (float)luaL_checknumber(L, 2);
    instance->setAll(a);
    return 0;
}

int hkVector4fBinding::add(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    instance->add(*a);
    return 0;
}

int hkVector4fBinding::sub(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    instance->sub(*a);
    return 0;
}

int hkVector4fBinding::mul(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    instance->mul(*a);
    return 0;
}

int hkVector4fBinding::div(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    instance->div(*a);
    return 0;
}

int hkVector4fBinding::setAdd(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v0 = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* v1 = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->setAdd(*v0, *v1);
    return 0;
}

int hkVector4fBinding::setSub(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v0 = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* v1 = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->setSub(*v0, *v1);
    return 0;
}

int hkVector4fBinding::setMul(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v0 = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* v1 = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->setMul(*v0, *v1);
    return 0;
}

int hkVector4fBinding::setDiv(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v0 = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* v1 = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->setDiv(*v0, *v1);
    return 0;
}

int hkVector4fBinding::addMul(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* x = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* y = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->addMul(*x, *y);
    return 0;
}

int hkVector4fBinding::setAddMul(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* x = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    hkVector4f* y = checkObject<hkVector4f>(L, 4, hkVector4fBinding::getMetatableName());
    instance->setAddMul(*a, *x, *y);
    return 0;
}

int hkVector4fBinding::subMul(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* x = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* y = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->subMul(*x, *y);
    return 0;
}

int hkVector4fBinding::setSubMul(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* x = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    hkVector4f* y = checkObject<hkVector4f>(L, 4, hkVector4fBinding::getMetatableName());
    instance->setSubMul(*a, *x, *y);
    return 0;
}

int hkVector4fBinding::setCross(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v0 = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* v1 = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->setCross(*v0, *v1);
    return 0;
}

int hkVector4fBinding::setXYZ_W(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* xyz = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    hkVector4f* w = checkObject<hkVector4f>(L, 3, hkVector4fBinding::getMetatableName());
    instance->setXYZ_W(*xyz, *w);
    return 0;
}

int hkVector4fBinding::setW(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* w = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    instance->setW(*w);
    return 0;
}

int hkVector4fBinding::setXYZ(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    if (lua_isnumber(L, 2))
    {
        float v = (float)luaL_checknumber(L, 2);
        instance->setXYZ(v);
        return 0;
    }
    else
    {
        hkVector4f* xyz = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
        instance->setXYZ(*xyz);
        return 0;
    }
}

int hkVector4fBinding::setXYZ_0(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* xyz = checkObject<hkVector4f>(L, 2, hkVector4fBinding::getMetatableName());
    instance->setXYZ_0(*xyz);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 153: void*operator new(...) - static method
  line 155: void operator delete(...) - static method
  line 171: void operator=(...) - operator
  line 173: void set(...) - unsupported arg type
  line 175: void setAll(...) - unsupported arg type
  line 180: void mul(...) - unsupported arg type
  line 183: void setAdd(...) - unsupported arg type
  line 185: void setSub(...) - unsupported arg type
  line 187: void setMul(...) - unsupported arg type
  line 188: void setMul(...) - unsupported arg type
  line 191: void setReciprocal(...) - unsupported arg type
  line 192: void setSqrt(...) - unsupported arg type
  line 193: void setSqrtInverse(...) - unsupported arg type
  line 194: void addMul(...) - unsupported arg type
  line 195: void addMul(...) - unsupported arg type
  line 197: void setAddMul(...) - unsupported arg type
  line 199: void subMul(...) - unsupported arg type
  line 200: void subMul(...) - unsupported arg type
  line 202: void setSubMul(...) - unsupported arg type
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
  line 257: void setXYZ_W(...) - unsupported arg type
  line 259: void setW(...) - unsupported arg type
  line 262: void setXYZ(...) - overloaded method
  line 263: void setXYZ(...) - overloaded method
  line 264: void setXYZ_0(...) - unsupported arg type
  line 271: const float& operator(...) - operator
  line 272: float& operator(...) - operator
  line 273: const hkSimdFloat32 getComponent(...) - unsupported return type
  line 274: const hkSimdFloat32 getW(...) - unsupported return type
  line 277: void setComponent(...) - unsupported arg type
  line 281: const hkVector4f& getZero(...) - static method
  line 282: const hkVector4f& getConstant(...) - unsupported return type
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
        { "getZero", hkVector4fBinding::getZero },
        { "set", hkVector4fBinding::set },
        { "setAll", hkVector4fBinding::setAll },
        { "add", hkVector4fBinding::add },
        { "sub", hkVector4fBinding::sub },
        { "mul", hkVector4fBinding::mul },
        { "div", hkVector4fBinding::div },
        { "setAdd", hkVector4fBinding::setAdd },
        { "setSub", hkVector4fBinding::setSub },
        { "setMul", hkVector4fBinding::setMul },
        { "setDiv", hkVector4fBinding::setDiv },
        { "addMul", hkVector4fBinding::addMul },
        { "setAddMul", hkVector4fBinding::setAddMul },
        { "subMul", hkVector4fBinding::subMul },
        { "setSubMul", hkVector4fBinding::setSubMul },
        { "setCross", hkVector4fBinding::setCross },
        { "setXYZ_W", hkVector4fBinding::setXYZ_W },
        { "setW", hkVector4fBinding::setW },
        { "setXYZ", hkVector4fBinding::setXYZ },
        { "setXYZ_0", hkVector4fBinding::setXYZ_0 },
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

    // Register global class table for static methods
    lua_newtable(L);
    registerStaticMethod(L, "getZero", hkVector4fBinding::getZero);
    lua_setglobal(L, "hkVector4f");
}

} // namespace KenshiLua