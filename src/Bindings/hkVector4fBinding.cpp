#include "pch.h"
#include "kenshi\havok.h"
#include "hkVector4fBinding.h"
#include "hkVector4fComparisonBinding.h"
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

int hkVector4fBinding::equals3(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to equals3 must be hkVector4f");

    float epsilon = (float)luaL_optnumber(L, 3, 0.0001f);
    unsigned int res = instance->equals3(*v, epsilon);
    lua_pushboolean(L, res != 0 ? 1 : 0);
    return 1;
}

int hkVector4fBinding::setAbs(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* v = getInstance(L, 2);
    if (!v) return luaL_error(L, "Argument 2 to setAbs must be hkVector4f");

    instance->setAbs(*v);
    return 0;
}

int hkVector4fBinding::setMin(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    hkVector4f* b = getInstance(L, 3);
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 to setMin must be hkVector4f");

    instance->setMin(*a, *b);
    return 0;
}

int hkVector4fBinding::setMax(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    hkVector4f* b = getInstance(L, 3);
    if (!a || !b) return luaL_error(L, "Arguments 2 and 3 to setMax must be hkVector4f");

    instance->setMax(*a, *b);
    return 0;
}

int hkVector4fBinding::setClamped(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    hkVector4f* minVal = getInstance(L, 3);
    hkVector4f* maxVal = getInstance(L, 4);
    if (!a || !minVal || !maxVal) return luaL_error(L, "Arguments 2, 3, and 4 to setClamped must be hkVector4f");

    instance->setClamped(*a, *minVal, *maxVal);
    return 0;
}

int hkVector4fBinding::setClampedZeroOne(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 to setClampedZeroOne must be hkVector4f");

    instance->setClampedZeroOne(*a);
    return 0;
}

int hkVector4fBinding::setReciprocal(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 to setReciprocal must be hkVector4f");

    instance->setReciprocal(*a);
    return 0;
}

int hkVector4fBinding::setSqrt(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 to setSqrt must be hkVector4f");

    instance->setSqrt(*a);
    return 0;
}

int hkVector4fBinding::setSqrtInverse(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 to setSqrtInverse must be hkVector4f");

    instance->setSqrtInverse(*a);
    return 0;
}

int hkVector4fBinding::setSelect(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison* comp = checkObject<hkVector4fComparison>(L, 2, hkVector4fComparisonBinding::getMetatableName());
    hkVector4f* trueVal = getInstance(L, 3);
    hkVector4f* falseVal = getInstance(L, 4);
    if (!comp || !trueVal || !falseVal) return luaL_error(L, "Arguments must be (hkVector4fComparison, hkVector4f, hkVector4f)");

    instance->setSelect(*comp, *trueVal, *falseVal);
    return 0;
}

int hkVector4fBinding::zeroIfFalse(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison* comp = checkObject<hkVector4fComparison>(L, 2, hkVector4fComparisonBinding::getMetatableName());
    if (!comp) return luaL_error(L, "Argument 2 must be hkVector4fComparison");

    instance->zeroIfFalse(*comp);
    return 0;
}

int hkVector4fBinding::zeroIfTrue(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison* comp = checkObject<hkVector4fComparison>(L, 2, hkVector4fComparisonBinding::getMetatableName());
    if (!comp) return luaL_error(L, "Argument 2 must be hkVector4fComparison");

    instance->zeroIfTrue(*comp);
    return 0;
}

int hkVector4fBinding::less(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4f");

    hkVector4fComparison res = instance->less(*a);
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::lessEqual(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4f");

    hkVector4fComparison res = instance->lessEqual(*a);
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::greater(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4f");

    hkVector4fComparison res = instance->greater(*a);
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::greaterEqual(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4f");

    hkVector4fComparison res = instance->greaterEqual(*a);
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::equal(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4f");

    hkVector4fComparison res = instance->equal(*a);
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::notEqual(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4f* a = getInstance(L, 2);
    if (!a) return luaL_error(L, "Argument 2 must be hkVector4f");

    hkVector4fComparison res = instance->notEqual(*a);
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::lessZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison res = instance->lessZero();
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::lessEqualZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison res = instance->lessEqualZero();
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::greaterZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison res = instance->greaterZero();
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::greaterEqualZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison res = instance->greaterEqualZero();
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::equalZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison res = instance->equalZero();
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::notEqualZero(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    hkVector4fComparison res = instance->notEqualZero();
    return pushValue<hkVector4fComparison>(L, res, hkVector4fComparisonBinding::getMetatableName());
}

int hkVector4fBinding::isOk3(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    lua_pushboolean(L, instance->isOk3() ? 1 : 0);
    return 1;
}

int hkVector4fBinding::isOk4(lua_State* L)
{
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hkVector4f is nil");

    lua_pushboolean(L, instance->isOk4() ? 1 : 0);
    return 1;
}

int hkVector4fBinding::create(lua_State* L)
{
    int idx = lua_isuserdata(L, 1) ? 2 : 1;
    float a = (float)luaL_optnumber(L, idx, 0.0);
    float b = (float)luaL_optnumber(L, idx + 1, 0.0);
    float c = (float)luaL_optnumber(L, idx + 2, 0.0);
    float d = (float)luaL_optnumber(L, idx + 3, 0.0);
    hkVector4f v(a, b, c, d);
    return pushValue<hkVector4f>(L, v, hkVector4fBinding::getMetatableName());
}

/*
Skipped methods needing manual binding:
  line 153: void*operator new(...) - static method
  line 155: void operator delete(...) - static method
  line 171: void operator=(...) - operator
  line 205: void setInterpolate(...) - unsupported arg type
  line 223: void setFlipSign(...) - overloaded method
  line 224: void setFlipSign(...) - overloaded method
  line 225: void setFlipSign(...) - overloaded method
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
  line 271: const float& operator(...) - operator
  line 272: float& operator(...) - operator
  line 273: const hkSimdFloat32 getComponent(...) - unsupported return type
  line 274: const hkSimdFloat32 getW(...) - unsupported return type
  line 277: void setComponent(...) - unsupported arg type
  line 282: const hkVector4f& getConstant(...) - unsupported return type
  line 293: hkSimdFloat32 dot3(...) - unsupported return type
  line 318: void setNeg3(...) - unsupported arg type
  line 328: hkSimdFloat32 normalizeWithLength3(...) - unsupported return type
  line 335: hkSimdFloat32 length3(...) - unsupported return type
  line 337: hkSimdFloat32 lengthSquared3(...) - unsupported return type
  line 365: hkSimdFloat32 distanceTo3(...) - unsupported return type
  line 366: hkSimdFloat32 distanceToSquared3(...) - unsupported return type
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
    hkVector4f* instance = getInstance(L, 1);
    if (!instance) {
        lua_pushstring(L, "hkVector4f(nil)");
        return 1;
    }
    float components[4];
    _mm_storeu_ps(components, instance->m_quad);
    char buf[128];
    sprintf_s(buf, "hkVector4f(%.3f, %.3f, %.3f, %.3f)", components[0], components[1], components[2], components[3]);
    lua_pushstring(L, buf);
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
        { "equals3", hkVector4fBinding::equals3 },
        { "setAbs", hkVector4fBinding::setAbs },
        { "setMin", hkVector4fBinding::setMin },
        { "setMax", hkVector4fBinding::setMax },
        { "setClamped", hkVector4fBinding::setClamped },
        { "setClampedZeroOne", hkVector4fBinding::setClampedZeroOne },
        { "setReciprocal", hkVector4fBinding::setReciprocal },
        { "setSqrt", hkVector4fBinding::setSqrt },
        { "setSqrtInverse", hkVector4fBinding::setSqrtInverse },
        { "setSelect", hkVector4fBinding::setSelect },
        { "zeroIfFalse", hkVector4fBinding::zeroIfFalse },
        { "zeroIfTrue", hkVector4fBinding::zeroIfTrue },
        { "less", hkVector4fBinding::less },
        { "lessEqual", hkVector4fBinding::lessEqual },
        { "greater", hkVector4fBinding::greater },
        { "greaterEqual", hkVector4fBinding::greaterEqual },
        { "equal", hkVector4fBinding::equal },
        { "notEqual", hkVector4fBinding::notEqual },
        { "lessZero", hkVector4fBinding::lessZero },
        { "lessEqualZero", hkVector4fBinding::lessEqualZero },
        { "greaterZero", hkVector4fBinding::greaterZero },
        { "greaterEqualZero", hkVector4fBinding::greaterEqualZero },
        { "equalZero", hkVector4fBinding::equalZero },
        { "notEqualZero", hkVector4fBinding::notEqualZero },
        { "isOk3", hkVector4fBinding::isOk3 },
        { "isOk4", hkVector4fBinding::isOk4 },
        { "create", hkVector4fBinding::create },
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
    pushGlobalTable(L, "hkVector4f");
    registerStaticMethod(L, "getZero", hkVector4fBinding::getZero);
    registerStaticMethod(L, "create", hkVector4fBinding::create);
    lua_setglobal(L, "hkVector4f");
}

} // namespace KenshiLua