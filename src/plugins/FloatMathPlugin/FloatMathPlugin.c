/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270
   from
	FloatMathPlugin VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270
 */
static char __buildInfo[] = "FloatMathPlugin VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270 " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif

#include "FloatMathPlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
static sqInt floatExponentBits(void);
EXPORT(const char*) getModuleName(void);
static sqInt isFinite(double aDouble);
EXPORT(sqInt) primitiveArcCos(void);
EXPORT(sqInt) primitiveArcCosH(void);
EXPORT(sqInt) primitiveArcSin(void);
EXPORT(sqInt) primitiveArcSinH(void);
EXPORT(sqInt) primitiveArcTan(void);
EXPORT(sqInt) primitiveArcTan2(void);
EXPORT(sqInt) primitiveArcTanH(void);
EXPORT(sqInt) primitiveCos(void);
EXPORT(sqInt) primitiveCosH(void);
EXPORT(sqInt) primitiveExp(void);
EXPORT(sqInt) primitiveFMod(void);
EXPORT(sqInt) primitiveFractionalPart(void);
EXPORT(sqInt) primitiveHypot(void);
EXPORT(sqInt) primitiveLog10(void);
EXPORT(sqInt) primitiveLogN(void);
EXPORT(sqInt) primitiveRaisedToPower(void);
EXPORT(sqInt) primitiveSin(void);
EXPORT(sqInt) primitiveSinH(void);
EXPORT(sqInt) primitiveSqrt(void);
EXPORT(sqInt) primitiveTan(void);
EXPORT(sqInt) primitiveTanH(void);
EXPORT(sqInt) primitiveTimesTwoPower(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnFloat)(double aFloat);
static sqInt (*pop)(sqInt nItems);
static sqInt (*primitiveFail)(void);
static sqInt (*pushFloat)(double f);
static double (*stackFloatValue)(sqInt offset);
static sqInt (*stackIntegerValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnFloat(double aFloat);
extern sqInt pop(sqInt nItems);
extern sqInt primitiveFail(void);
extern sqInt pushFloat(double f);
extern double stackFloatValue(sqInt offset);
extern sqInt stackIntegerValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "FloatMathPlugin VMMaker.oscog-eem.2744 " INT_EXT;



/*	Answer the number of bits in the double-precision exponent. This is an
	11-bit field. */

	/* FloatMathPlugin>>#floatExponentBits */
static sqInt
floatExponentBits(void)
{
	return 11;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* FloatMathPlugin>>#isFinite: */
static sqInt
isFinite(double aDouble)
{
	return (aDouble - aDouble) == 0.0;
}


/*	Computes acos(receiver) */

	/* FloatMathPlugin>>#primitiveArcCos */
EXPORT(sqInt)
primitiveArcCos(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_acos(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes acosh(receiver) */

	/* FloatMathPlugin>>#primitiveArcCosH */
EXPORT(sqInt)
primitiveArcCosH(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_acosh(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes asin(receiver) */

	/* FloatMathPlugin>>#primitiveArcSin */
EXPORT(sqInt)
primitiveArcSin(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_asin(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes asinh(receiver) */

	/* FloatMathPlugin>>#primitiveArcSinH */
EXPORT(sqInt)
primitiveArcSinH(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_asinh(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes atan(receiver) */

	/* FloatMathPlugin>>#primitiveArcTan */
EXPORT(sqInt)
primitiveArcTan(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_atan(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes atan2(receiver, arg) */

	/* FloatMathPlugin>>#primitiveArcTan2 */
EXPORT(sqInt)
primitiveArcTan2(void)
{
    double arg;
    double rcvr;
    double result;

	arg = stackFloatValue(0);
	rcvr = stackFloatValue(1);
	if (failed()) {
		return null;
	}
	result = __ieee754_atan2(rcvr, arg);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes atanh(receiver) */

	/* FloatMathPlugin>>#primitiveArcTanH */
EXPORT(sqInt)
primitiveArcTanH(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_atanh(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes cos(receiver) */

	/* FloatMathPlugin>>#primitiveCos */
EXPORT(sqInt)
primitiveCos(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_cos(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes cosh(receiver) */

	/* FloatMathPlugin>>#primitiveCosH */
EXPORT(sqInt)
primitiveCosH(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_cosh(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes E raised to the receiver power. */

	/* FloatMathPlugin>>#primitiveExp */
EXPORT(sqInt)
primitiveExp(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_exp(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes receiver \\ arg */

	/* FloatMathPlugin>>#primitiveFMod */
EXPORT(sqInt)
primitiveFMod(void)
{
    double arg;
    double rcvr;
    double result;

	arg = stackFloatValue(0);
	rcvr = stackFloatValue(1);
	if (failed()) {
		return null;
	}
	result = __ieee754_fmod(rcvr, arg);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes receiver \\ 1.0 */

	/* FloatMathPlugin>>#primitiveFractionalPart */
EXPORT(sqInt)
primitiveFractionalPart(void)
{
    double rcvr;
    double result;
    double trunc;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_modf(rcvr, &trunc);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	hypot(x,y) returns sqrt(x^2+y^2) with error less than 1 ulps */

	/* FloatMathPlugin>>#primitiveHypot */
EXPORT(sqInt)
primitiveHypot(void)
{
    double arg;
    double rcvr;
    double result;

	arg = stackFloatValue(0);
	rcvr = stackFloatValue(1);
	if (failed()) {
		return null;
	}
	result = __ieee754_hypot(rcvr, arg);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes log10(receiver) */

	/* FloatMathPlugin>>#primitiveLog10 */
EXPORT(sqInt)
primitiveLog10(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return primitiveFail();
	}
	result = __ieee754_log10(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes log(receiver) */

	/* FloatMathPlugin>>#primitiveLogN */
EXPORT(sqInt)
primitiveLogN(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return primitiveFail();
	}
	result = __ieee754_log(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes receiver**arg */

	/* FloatMathPlugin>>#primitiveRaisedToPower */
EXPORT(sqInt)
primitiveRaisedToPower(void)
{
    double arg;
    double rcvr;
    double result;

	arg = stackFloatValue(0);
	rcvr = stackFloatValue(1);
	if (failed()) {
		return null;
	}
	result = __ieee754_pow(rcvr, arg);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes sin(receiver) */

	/* FloatMathPlugin>>#primitiveSin */
EXPORT(sqInt)
primitiveSin(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_sin(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes sinh(receiver) */

	/* FloatMathPlugin>>#primitiveSinH */
EXPORT(sqInt)
primitiveSinH(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_sinh(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes sqrt(receiver) */

	/* FloatMathPlugin>>#primitiveSqrt */
EXPORT(sqInt)
primitiveSqrt(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return primitiveFail();
	}
	result = __ieee754_sqrt(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes tan(receiver) */

	/* FloatMathPlugin>>#primitiveTan */
EXPORT(sqInt)
primitiveTan(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_tan(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Computes tanh(receiver) */

	/* FloatMathPlugin>>#primitiveTanH */
EXPORT(sqInt)
primitiveTanH(void)
{
    double rcvr;
    double result;

	rcvr = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	result = __ieee754_tanh(rcvr);
	if (isnan(result)) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	pushFloat(result);
	return 0;
}


/*	Multiply the receiver by the power of the argument. */

	/* FloatMathPlugin>>#primitiveTimesTwoPower */
EXPORT(sqInt)
primitiveTimesTwoPower(void)
{
    sqInt arg;
    double rcvr;
    double result;
    sqInt twiceMaxExponent;

	arg = stackIntegerValue(0);
	rcvr = stackFloatValue(1);
	if (failed()) {
		return null;
	}
	if (BytesPerOop > 4) {

		/* clip arg to at most int range; ldexp's last arg is of type int */
		twiceMaxExponent = 4096;
		if (arg < (-twiceMaxExponent)) {
			arg = -twiceMaxExponent;
		}
		else {
			if (arg > twiceMaxExponent) {
				arg = twiceMaxExponent;
			}
		}
	}
	result = __ieee754_ldexp(rcvr, (int)arg);
	if (!(isnan(result))) {
		methodReturnFloat(result);
	}
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		methodReturnFloat = interpreterProxy->methodReturnFloat;
		pop = interpreterProxy->pop;
		primitiveFail = interpreterProxy->primitiveFail;
		pushFloat = interpreterProxy->pushFloat;
		stackFloatValue = interpreterProxy->stackFloatValue;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "FloatMathPlugin";
void* FloatMathPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveArcCos\000\000", (void*)primitiveArcCos},
	{(void*)_m, "primitiveArcCosH\000\000", (void*)primitiveArcCosH},
	{(void*)_m, "primitiveArcSin\000\000", (void*)primitiveArcSin},
	{(void*)_m, "primitiveArcSinH\000\000", (void*)primitiveArcSinH},
	{(void*)_m, "primitiveArcTan\000\000", (void*)primitiveArcTan},
	{(void*)_m, "primitiveArcTan2\000\000", (void*)primitiveArcTan2},
	{(void*)_m, "primitiveArcTanH\000\000", (void*)primitiveArcTanH},
	{(void*)_m, "primitiveCos\000\000", (void*)primitiveCos},
	{(void*)_m, "primitiveCosH\000\000", (void*)primitiveCosH},
	{(void*)_m, "primitiveExp\000\000", (void*)primitiveExp},
	{(void*)_m, "primitiveFMod\000\000", (void*)primitiveFMod},
	{(void*)_m, "primitiveFractionalPart\000\000", (void*)primitiveFractionalPart},
	{(void*)_m, "primitiveHypot\000\000", (void*)primitiveHypot},
	{(void*)_m, "primitiveLog10\000\000", (void*)primitiveLog10},
	{(void*)_m, "primitiveLogN\000\000", (void*)primitiveLogN},
	{(void*)_m, "primitiveRaisedToPower\000\000", (void*)primitiveRaisedToPower},
	{(void*)_m, "primitiveSin\000\000", (void*)primitiveSin},
	{(void*)_m, "primitiveSinH\000\000", (void*)primitiveSinH},
	{(void*)_m, "primitiveSqrt\000\000", (void*)primitiveSqrt},
	{(void*)_m, "primitiveTan\000\000", (void*)primitiveTan},
	{(void*)_m, "primitiveTanH\000\000", (void*)primitiveTanH},
	{(void*)_m, "primitiveTimesTwoPower\000\000", (void*)primitiveTimesTwoPower},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveArcCosAccessorDepth = 0;
signed char primitiveArcCosHAccessorDepth = 0;
signed char primitiveArcSinAccessorDepth = 0;
signed char primitiveArcSinHAccessorDepth = 0;
signed char primitiveArcTanAccessorDepth = 0;
signed char primitiveArcTan2AccessorDepth = 0;
signed char primitiveArcTanHAccessorDepth = 0;
signed char primitiveCosAccessorDepth = 0;
signed char primitiveCosHAccessorDepth = 0;
signed char primitiveExpAccessorDepth = 0;
signed char primitiveFModAccessorDepth = 0;
signed char primitiveFractionalPartAccessorDepth = 0;
signed char primitiveHypotAccessorDepth = 0;
signed char primitiveLog10AccessorDepth = 0;
signed char primitiveLogNAccessorDepth = 0;
signed char primitiveRaisedToPowerAccessorDepth = 0;
signed char primitiveSinAccessorDepth = 0;
signed char primitiveSinHAccessorDepth = 0;
signed char primitiveSqrtAccessorDepth = 0;
signed char primitiveTanAccessorDepth = 0;
signed char primitiveTanHAccessorDepth = 0;
signed char primitiveTimesTwoPowerAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
