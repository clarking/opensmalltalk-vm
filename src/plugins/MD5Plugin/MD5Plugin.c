/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2673 uuid: ceb6ec91-3b0f-4fd3-93b7-19f6e445c4a5
   from
	MD5Plugin CryptographyPlugins-eem.14 uuid: 54292ff0-b538-43ba-9195-26766c158ba9
 */
static char __buildInfo[] = "MD5Plugin CryptographyPlugins-eem.14 uuid: 54292ff0-b538-43ba-9195-26766c158ba9 " __DATE__ ;



#include "config.h"
#include <math.h>
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

#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3
#if !defined(VMBIGENDIAN) /* Allow this to be overridden on the compiler command line */
# define VMBIGENDIAN 0
#endif


/*** Function Prototypes ***/
extern sqInt decodesizeInIntegers(char *array, unsigned int n);
EXPORT(const char*) getModuleName(void);
extern sqInt md5InitializeState(unsigned int *state);
extern sqInt md5ProcessBufferwithState(unsigned int *buffer, unsigned int *state);
EXPORT(sqInt) primitiveDecodeState(void);
EXPORT(sqInt) primitiveInitializeState(void);
EXPORT(sqInt) primitivePluginAvailable(void);
EXPORT(sqInt) primitiveProcessBufferWithState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static sqInt (*falseObject)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern sqInt falseObject(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt isBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stackValue(sqInt offset);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "MD5Plugin CryptographyPlugins-eem.14 " INT_EXT;
static sqInt swap;



/*	Change the endianness of the first n integers in array. Used only on big
	endian platforms.
 */

	/* MD5Plugin>>#decode:sizeInIntegers: */
sqInt
decodesizeInIntegers(char *array, unsigned int n)
{
	unsigned int i;
	unsigned int temp;

	for (i = 0; i < (4 * n); i += 4) {
		temp = array[i];
		array[i] = (array[i + 3]);
		array[i + 3] = temp;
		temp = array[i + 1];
		array[i + 1] = (array[i + 2]);
		array[i + 2] = temp;
	}
	return 0;
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

	/* MD5Plugin>>#md5InitializeState: */
sqInt
md5InitializeState(unsigned int *state)
{
	state[0] = 1732584193;
	state[1] = 4023233417U;
	state[2] = 2562383102U;
	state[3] = 271733878;
	return 0;
}


/*	This method is generated. See #compileMethods on the class side. */

	/* MD5Plugin>>#md5ProcessBuffer:withState: */
sqInt
md5ProcessBufferwithState(unsigned int *buffer, unsigned int *state)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;

	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[0])) + 3614090360U;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[1])) + 3905402710U;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[2])) + 606105819;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[3])) + 3250441966U;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[4])) + 4118548399U;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[5])) + 1200080426;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[6])) + 2821735955U;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[7])) + 4249261313U;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[8])) + 1770035416;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[9])) + 2336552879U;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[10])) + 4294925233U;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[11])) + 2304563134U;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[12])) + 1804603682;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[13])) + 4254626195U;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[14])) + 2792965006U;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[15])) + 1236535329;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[1])) + 4129170786U;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[6])) + 3225465664U;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[11])) + 643717713;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[0])) + 3921069994U;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[5])) + 3593408605U;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[10])) + 38016083;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[15])) + 3634488961U;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[4])) + 3889429448U;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[9])) + 568446438;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[14])) + 3275163606U;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[3])) + 4107603335U;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[8])) + 1163531501;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[13])) + 2850285829U;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[2])) + 4243563512U;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[7])) + 1735328473;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[12])) + 2368359562U;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b ^ c) ^ d) + (buffer[5])) + 4294588738U;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[8])) + 2272392833U;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[11])) + 1839030562;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[14])) + 4259657740U;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer[1])) + 2763975236U;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[4])) + 1272893353;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[7])) + 4139469664U;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[10])) + 3200236656U;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer[13])) + 681279174;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[0])) + 3936430074U;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[3])) + 3572445317U;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[6])) + 76029189;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer[9])) + 3654602809U;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[12])) + 3873151461U;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[15])) + 530742520;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[2])) + 3299628645U;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[0])) + 4096336452U;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[7])) + 1126891415;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[14])) + 2878612391U;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[5])) + 4237533241U;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[12])) + 1700485571;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[3])) + 2399980690U;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[10])) + 4293915773U;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[1])) + 2240044497U;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[8])) + 1873313359;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[15])) + 4264355552U;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[6])) + 2734768916U;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[13])) + 1309151649;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[4])) + 4149444226U;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[11])) + 3174756917U;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[2])) + 718787259;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[9])) + 3951481745U;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	state[0] = ((state[0]) + a);
	state[1] = ((state[1]) + b);
	state[2] = ((state[2]) + c);
	state[3] = ((state[3]) + d);
	return 0;
}


/*	This method is generated. See #compileMethods on the class side. */

	/* MD5Plugin>>#primitiveDecodeState: */
EXPORT(sqInt)
primitiveDecodeState(void)
{
	unsigned int i;
	char *state;
	unsigned int temp;

	if (!(isBytes(stackValue(0)))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	state = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	if (VMBIGENDIAN) {
		/* begin decode:sizeInIntegers: */
		for (i = 0; i < (4 * 4); i += 4) {
			temp = state[i];
			state[i] = (state[i + 3]);
			state[i + 3] = temp;
			temp = state[i + 1];
			state[i + 1] = (state[i + 2]);
			state[i + 2] = temp;
		}
	}
	if (!(failed())) {
		pop(1);
	}
	return null;
}

	/* MD5Plugin>>#primitiveInitializeState: */
EXPORT(sqInt)
primitiveInitializeState(void)
{
	char *state;

	if (!(isBytes(stackValue(0)))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	state = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	/* begin md5InitializeState: */
	(((unsigned int*) state))[0] = 1732584193;
	(((unsigned int*) state))[1] = 4023233417U;
	(((unsigned int*) state))[2] = 2562383102U;
	(((unsigned int*) state))[3] = 271733878;
	if (!(failed())) {
		pop(1);
	}
	return null;
}

	/* MD5Plugin>>#primitivePluginAvailable */
EXPORT(sqInt)
primitivePluginAvailable(void)
{
	sqInt _return_value;

	_return_value = ((1) ? trueObject() : falseObject());
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}

	/* MD5Plugin>>#primitiveProcessBuffer:withState: */
EXPORT(sqInt)
primitiveProcessBufferWithState(void)
{
	unsigned int a;
	unsigned int b;
	char *buffer;
	unsigned int *buffer1;
	unsigned int c;
	unsigned int d;
	char *state;
	unsigned int *state1;

	if (!((isBytes(stackValue(1)))
		 && (isBytes(stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	buffer = ((char *) (firstIndexableField(stackValue(1))));
	state = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	/* begin md5ProcessBuffer:withState: */
	buffer1 = ((unsigned int *) buffer);
	state1 = ((unsigned int *) state);
	a = state1[0];
	b = state1[1];
	c = state1[2];
	d = state1[3];
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer1[0])) + 3614090360U;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer1[1])) + 3905402710U;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer1[2])) + 606105819;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer1[3])) + 3250441966U;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer1[4])) + 4118548399U;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer1[5])) + 1200080426;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer1[6])) + 2821735955U;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer1[7])) + 4249261313U;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer1[8])) + 1770035416;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer1[9])) + 2336552879U;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer1[10])) + 4294925233U;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer1[11])) + 2304563134U;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer1[12])) + 1804603682;
	a = ((((usqInt)(a) << 7)) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer1[13])) + 4254626195U;
	d = ((((usqInt)(d) << 12)) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer1[14])) + 2792965006U;
	c = ((((usqInt)(c) << 17)) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer1[15])) + 1236535329;
	b = ((((usqInt)(b) << 22)) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer1[1])) + 4129170786U;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer1[6])) + 3225465664U;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer1[11])) + 643717713;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer1[0])) + 3921069994U;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer1[5])) + 3593408605U;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer1[10])) + 38016083;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer1[15])) + 3634488961U;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer1[4])) + 3889429448U;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer1[9])) + 568446438;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer1[14])) + 3275163606U;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer1[3])) + 4107603335U;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer1[8])) + 1163531501;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer1[13])) + 2850285829U;
	a = ((((usqInt)(a) << 5)) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer1[2])) + 4243563512U;
	d = ((((usqInt)(d) << 9)) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer1[7])) + 1735328473;
	c = ((((usqInt)(c) << 14)) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer1[12])) + 2368359562U;
	b = ((((usqInt)(b) << 20)) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b ^ c) ^ d) + (buffer1[5])) + 4294588738U;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer1[8])) + 2272392833U;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer1[11])) + 1839030562;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer1[14])) + 4259657740U;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer1[1])) + 2763975236U;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer1[4])) + 1272893353;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer1[7])) + 4139469664U;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer1[10])) + 3200236656U;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer1[13])) + 681279174;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer1[0])) + 3936430074U;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer1[3])) + 3572445317U;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer1[6])) + 76029189;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer1[9])) + 3654602809U;
	a = ((((usqInt)(a) << 4)) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer1[12])) + 3873151461U;
	d = ((((usqInt)(d) << 11)) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer1[15])) + 530742520;
	c = ((((usqInt)(c) << 16)) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer1[2])) + 3299628645U;
	b = ((((usqInt)(b) << 23)) | (((usqInt) b) >> (32 - 23))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer1[0])) + 4096336452U;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer1[7])) + 1126891415;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer1[14])) + 2878612391U;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer1[5])) + 4237533241U;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer1[12])) + 1700485571;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer1[3])) + 2399980690U;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer1[10])) + 4293915773U;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer1[1])) + 2240044497U;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer1[8])) + 1873313359;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer1[15])) + 4264355552U;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer1[6])) + 2734768916U;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer1[13])) + 1309151649;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer1[4])) + 4149444226U;
	a = ((((usqInt)(a) << 6)) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer1[11])) + 3174756917U;
	d = ((((usqInt)(d) << 10)) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer1[2])) + 718787259;
	c = ((((usqInt)(c) << 15)) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer1[9])) + 3951481745U;
	b = ((((usqInt)(b) << 21)) | (((usqInt) b) >> (32 - 21))) + c;
	state1[0] = ((state1[0]) + a);
	state1[1] = ((state1[1]) + b);
	state1[2] = ((state1[2]) + c);
	state1[3] = ((state1[3]) + d);
	if (!(failed())) {
		pop(2);
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
		falseObject = interpreterProxy->falseObject;
		firstIndexableField = interpreterProxy->firstIndexableField;
		isBytes = interpreterProxy->isBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		stackValue = interpreterProxy->stackValue;
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

static char _m[] = "MD5Plugin";
void* MD5Plugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDecodeState\000\377", (void*)primitiveDecodeState},
	{(void*)_m, "primitiveInitializeState\000\377", (void*)primitiveInitializeState},
	{(void*)_m, "primitivePluginAvailable\000\377", (void*)primitivePluginAvailable},
	{(void*)_m, "primitiveProcessBufferWithState\000\377", (void*)primitiveProcessBufferWithState},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */


#endif /* ifdef SQ_BUILTIN_PLUGIN */
