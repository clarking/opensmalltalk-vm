/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270
   from
	LocalePlugin VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270
 */
static char __buildInfo[] = "LocalePlugin VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270 " __DATE__ ;



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

#include "LocalePlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveCountry(void);
EXPORT(sqInt) primitiveCurrencyNotation(void);
EXPORT(sqInt) primitiveCurrencySymbol(void);
EXPORT(sqInt) primitiveDaylightSavings(void);
EXPORT(sqInt) primitiveDecimalSymbol(void);
EXPORT(sqInt) primitiveDigitGroupingSymbol(void);
EXPORT(sqInt) primitiveLanguage(void);
EXPORT(sqInt) primitiveLongDateFormat(void);
EXPORT(sqInt) primitiveMeasurementMetric(void);
EXPORT(sqInt) primitiveShortDateFormat(void);
EXPORT(sqInt) primitiveTimeFormat(void);
EXPORT(sqInt) primitiveTimezoneOffset(void);
EXPORT(sqInt) primitiveVMOffsetToUTC(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static sqInt (*falseObject)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
#if !defined(integerObjectOf)
static sqInt (*integerObjectOf)(sqInt value);
#endif
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt classString(void);
extern sqInt failed(void);
extern sqInt falseObject(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
#if !defined(integerObjectOf)
extern sqInt integerObjectOf(sqInt value);
#endif
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "LocalePlugin VMMaker.oscog-eem.2744 " INT_EXT;



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

	/* LocalePlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return sqLocInitialize();
}


/*	return a 3 char string describing the country in use. ISO 3166 is the
	relevant source here; see http://www.unicode.org/onlinedat/countries.html
	for details. Using the 3 character Alpha-3 codes
 */

	/* LocalePlugin>>#primitiveCountry */
EXPORT(sqInt)
primitiveCountry(void)
{
	sqInt oop;

	oop = instantiateClassindexableSize(classString(), 3);
	sqLocGetCountryInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a boolean specifying whether the currency symbol is pre or post
	fix. true -> pre
 */

	/* LocalePlugin>>#primitiveCurrencyNotation */
EXPORT(sqInt)
primitiveCurrencyNotation(void)
{
	sqInt _return_value;

	_return_value = (((sqLocCurrencyNotation())) ? trueObject() : falseObject());
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}


/*	return a string describing the currency symbol used 
	Still need to find details on standard symbols - ISO 4217 is supposed to
	be it but cannot find on web
 */

	/* LocalePlugin>>#primitiveCurrencySymbol */
EXPORT(sqInt)
primitiveCurrencySymbol(void)
{
	sqInt length;
	sqInt oop;

	length = sqLocCurrencySymbolSize();
	oop = instantiateClassindexableSize(classString(), length);
	sqLocGetCurrencySymbolInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a boolean specifying the DST setting. true -> active */

	/* LocalePlugin>>#primitiveDaylightSavings */
EXPORT(sqInt)
primitiveDaylightSavings(void)
{
	sqInt _return_value;

	_return_value = (((sqLocDaylightSavings())) ? trueObject() : falseObject());
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}


/*	return a 1 char string describing the decimal symbol used - usually a . or
	a ,
 */

	/* LocalePlugin>>#primitiveDecimalSymbol */
EXPORT(sqInt)
primitiveDecimalSymbol(void)
{
	sqInt oop;

	oop = instantiateClassindexableSize(classString(), 1);
	sqLocGetDecimalSymbolInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a 1 char string describing the digitGrouping symbol used - usually
	a . or a , between triples of digits
 */

	/* LocalePlugin>>#primitiveDigitGroupingSymbol */
EXPORT(sqInt)
primitiveDigitGroupingSymbol(void)
{
	sqInt oop;

	oop = instantiateClassindexableSize(classString(), 1);
	sqLocGetDigitGroupingSymbolInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a 3 char string describing the language in use. ISO 639 is the
	relevant source here; see http://www.w3.org/WAI/ER/IG/ert/iso639.html for
	details 
 */

	/* LocalePlugin>>#primitiveLanguage */
EXPORT(sqInt)
primitiveLanguage(void)
{
	sqInt oop;

	oop = instantiateClassindexableSize(classString(), 3);
	sqLocGetLanguageInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a string describing the long date formatting.
	Format is made up of
	d day, m month, y year,
	double symbol is null padded, single not padded (m=6, mm=06)
	dddd weekday
	mmmm month nam
	
 */

	/* LocalePlugin>>#primitiveLongDateFormat */
EXPORT(sqInt)
primitiveLongDateFormat(void)
{
	sqInt length;
	sqInt oop;

	length = sqLocLongDateFormatSize();
	oop = instantiateClassindexableSize(classString(), length);
	sqLocGetLongDateFormatInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a boolean specifying whether the currency symbol is pre or post
	fix. true -> pre
 */

	/* LocalePlugin>>#primitiveMeasurementMetric */
EXPORT(sqInt)
primitiveMeasurementMetric(void)
{
	sqInt _return_value;

	_return_value = (((sqLocMeasurementMetric())) ? trueObject() : falseObject());
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}


/*	return a string describing the long date formatting.
	Format is made up of
	d day, m month, y year,
	double symbol is null padded, single not padded (m=6, mm=06)
	dddd weekday
	mmmm month nam
	
 */

	/* LocalePlugin>>#primitiveShortDateFormat */
EXPORT(sqInt)
primitiveShortDateFormat(void)
{
	sqInt length;
	sqInt oop;

	length = sqLocShortDateFormatSize();
	oop = instantiateClassindexableSize(classString(), length);
	sqLocGetShortDateFormatInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return a string describing the time formatting.
	Format is made up of
	h hour (h 12, H 24), m minute, s seconds, x (am/pm String)
	double symbol is null padded, single not padded (h=6, hh=06)
 */

	/* LocalePlugin>>#primitiveTimeFormat */
EXPORT(sqInt)
primitiveTimeFormat(void)
{
	sqInt length;
	sqInt oop;

	length = sqLocTimeFormatSize();
	oop = instantiateClassindexableSize(classString(), length);
	sqLocGetTimeFormatInto(firstIndexableField(oop));
	if (!(failed())) {
		popthenPush(1, oop);
	}
	return null;
}


/*	return the number of minutes this VM's time value is offset from UTC */

	/* LocalePlugin>>#primitiveTimezoneOffset */
EXPORT(sqInt)
primitiveTimezoneOffset(void)
{
	popthenPush(1, integerObjectOf((sqLocGetTimezoneOffset())));
	return null;
}


/*	return the number of minutes this VM's time value is offset from UTC */

	/* LocalePlugin>>#primitiveVMOffsetToUTC */
EXPORT(sqInt)
primitiveVMOffsetToUTC(void)
{
	popthenPush(1, integerObjectOf((sqLocGetVMOffsetToUTC())));
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
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		falseObject = interpreterProxy->falseObject;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
#if !defined(integerObjectOf)
		integerObjectOf = interpreterProxy->integerObjectOf;
#endif
		popthenPush = interpreterProxy->popthenPush;
		trueObject = interpreterProxy->trueObject;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "LocalePlugin";
void* LocalePlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveCountry\000\377", (void*)primitiveCountry},
	{(void*)_m, "primitiveCurrencyNotation\000\377", (void*)primitiveCurrencyNotation},
	{(void*)_m, "primitiveCurrencySymbol\000\377", (void*)primitiveCurrencySymbol},
	{(void*)_m, "primitiveDaylightSavings\000\377", (void*)primitiveDaylightSavings},
	{(void*)_m, "primitiveDecimalSymbol\000\377", (void*)primitiveDecimalSymbol},
	{(void*)_m, "primitiveDigitGroupingSymbol\000\377", (void*)primitiveDigitGroupingSymbol},
	{(void*)_m, "primitiveLanguage\000\377", (void*)primitiveLanguage},
	{(void*)_m, "primitiveLongDateFormat\000\377", (void*)primitiveLongDateFormat},
	{(void*)_m, "primitiveMeasurementMetric\000\377", (void*)primitiveMeasurementMetric},
	{(void*)_m, "primitiveShortDateFormat\000\377", (void*)primitiveShortDateFormat},
	{(void*)_m, "primitiveTimeFormat\000\377", (void*)primitiveTimeFormat},
	{(void*)_m, "primitiveTimezoneOffset\000\377", (void*)primitiveTimezoneOffset},
	{(void*)_m, "primitiveVMOffsetToUTC\000\377", (void*)primitiveVMOffsetToUTC},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */


#endif /* ifdef SQ_BUILTIN_PLUGIN */
