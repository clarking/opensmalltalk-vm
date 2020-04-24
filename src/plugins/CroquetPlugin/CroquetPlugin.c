/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270
   from
	CroquetPlugin VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270
 */
static char __buildInfo[] = "CroquetPlugin VMMaker.oscog-eem.2744 uuid: 0273a0b2-9293-4e5f-b9ff-546a7d6a8270 " __DATE__ ;



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

#include "CroquetPlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveAdj3(void);
EXPORT(sqInt) primitiveARC4Transform(void);
EXPORT(sqInt) primitiveDet3(void);
EXPORT(sqInt) primitiveGatherEntropy(void);
EXPORT(sqInt) primitiveInplaceHouseHolderInvert(void);
EXPORT(sqInt) primitiveInverseByAdjoint(void);
EXPORT(sqInt) primitiveMD5Transform(void);
EXPORT(sqInt) primitiveOptimizeVertexIndicesForCacheLocality(void);
EXPORT(sqInt) primitiveOrthoNormInverseMatrix(void);
EXPORT(sqInt) primitiveTransformDirection(void);
EXPORT(sqInt) primitiveTransformMatrixWithInto(void);
EXPORT(sqInt) primitiveTransformVector3(void);
EXPORT(sqInt) primitiveTransposeMatrix(void);
EXPORT(sqInt) primitiveTriBoxIntersects(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static void* stackMatrix(sqInt index);
static void* stackVector3(sqInt index);
static sqInt transformMatrixwithinto(float *src, float *arg, float *dst);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classPoint)(void);
static sqInt (*clone)(sqInt oop);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static sqInt (*primitiveFail)(void);
static sqInt (*push)(sqInt object);
static sqInt (*pushBool)(sqInt trueOrFalse);
static sqInt (*pushFloat)(double f);
static sqInt (*pushRemappableOop)(sqInt oop);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackObjectValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classPoint(void);
extern sqInt clone(sqInt oop);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt isWords(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern sqInt primitiveFail(void);
extern sqInt push(sqInt object);
extern sqInt pushBool(sqInt trueOrFalse);
extern sqInt pushFloat(double f);
extern sqInt pushRemappableOop(sqInt oop);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackObjectValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "CroquetPlugin VMMaker.oscog-eem.2744 " INT_EXT;



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


/*	Computes the adjoint of the Matrix4x4 receiver,
	placing the results the the Matrix4x4 argument,
	 */

	/* CroquetPlugin>>#primitiveAdj3 */
EXPORT(sqInt)
primitiveAdj3(void)
{
    sqInt argc;
    const int c11 = 0;
    const int c12 = 1;
    const int c13 = 2;
    const int c21 = 4;
    const int c22 = 5;
    const int c23 = 6;
    const int c31 = 8;
    const int c32 = 9;
    const int c33 = 10;
    float *dst;
    sqInt dstOop;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;


	/* <var: #c14 declareC: 'const int c14 = 3'> */
	/* <var: #c24 declareC: 'const int c24 = 7'> */
	/* <var: #c34 declareC: 'const int c34 = 11'> */
	/* then we need the following no-op to make Smalltalk shut up about vars not being initted. */
	argc = methodArgumentCount();
	if (!(argc == 1)) {
		return primitiveFail();
	}
	flag("stackArgv");
	srcOop = stackObjectValue(argc);
	src = firstIndexableField(srcOop);
	dstOop = stackObjectValue(argc - 1);

	/* read in the source matrix 3x3, which contains the encoded rotation and scale factors */
	dst = firstIndexableField(dstOop);
	m11 = src[c11];
	m12 = src[c12];
	m13 = src[c13];
	m21 = src[c21];
	m22 = src[c22];
	m23 = src[c23];
	m31 = src[c31];
	m32 = src[c32];

	/* do the actual work */
	/* compute our cofactors and transpose.  adj = transpose of cofactors */
	m33 = src[c33];
	dst[c11] = ((m22 * m33) - (m23 * m32));
	dst[c21] = (0.0 - ((m21 * m33) - (m23 * m31)));
	dst[c31] = ((m21 * m32) - (m22 * m31));
	dst[c12] = (0.0 - ((m12 * m33) - (m13 * m32)));
	dst[c22] = ((m11 * m33) - (m13 * m31));
	dst[c32] = (0.0 - ((m11 * m32) - (m12 * m31)));
	dst[c13] = ((m12 * m23) - (m13 * m22));
	dst[c23] = (0.0 - ((m11 * m23) - (m13 * m21)));
	dst[c33] = ((m11 * m22) - (m12 * m21));
	popthenPush(argc + 1, dstOop);
	return 0;
}


/*	Perform an ARC4 transform of input.
	Arguments:
	buffer		<ByteArray> transformed data
	startIndex <Integer>	start of transform
	stopIndex	<Integer>	end of transform
	m			<ByteArray>	key stream data
	x			<Integer>	key state value
	y			<Integer>	key state value
	Return value:
	x@y - updated key state value
	 */

	/* CroquetPlugin>>#primitiveARC4Transform */
EXPORT(sqInt)
primitiveARC4Transform(void)
{
    unsigned char a;
    unsigned char b;
    unsigned char *buffer;
    sqInt bufOop;
    sqInt bufSize;
    sqInt i;
    unsigned char *m;
    unsigned char mask;
    sqInt mOop;
    sqInt ptOop;
    sqInt startIndex;
    sqInt stopIndex;
    sqInt x;
    sqInt xOop;
    sqInt y;
    sqInt yOop;

	if (!((methodArgumentCount()) == 6)) {
		return primitiveFail();
	}
	y = stackIntegerValue(0);
	x = stackIntegerValue(1);
	mOop = stackObjectValue(2);
	stopIndex = stackIntegerValue(3);
	startIndex = stackIntegerValue(4);
	bufOop = stackObjectValue(5);
	if (failed()) {
		return null;
	}
	if (!((isBytes(mOop))
		 && (isBytes(bufOop)))) {
		return primitiveFail();
	}
	if (!((byteSizeOf(mOop)) == 256)) {
		return primitiveFail();
	}
	bufSize = byteSizeOf(bufOop);
	if (!((startIndex > 0)
		 && (startIndex <= bufSize))) {
		return primitiveFail();
	}
	if (!((stopIndex >= startIndex)
		 && (stopIndex <= bufSize))) {
		return primitiveFail();
	}
	m = firstIndexableField(mOop);
	buffer = firstIndexableField(bufOop);
	for (i = (startIndex - 1); i < stopIndex; i += 1) {
		x = (x + 1) & 0xFF;
		a = m[x];
		y = (y + a) & 0xFF;
		b = m[y];
		m[x] = b;
		m[y] = a;
		mask = m[(a + b) & 0xFF];
		buffer[i] = ((buffer[i]) ^ mask);
	}
	ptOop = instantiateClassindexableSize(classPoint(), 0);
	pushRemappableOop(ptOop);
	xOop = positive32BitIntegerFor(x);
	pushRemappableOop(xOop);
	yOop = positive32BitIntegerFor(y);
	xOop = popRemappableOop();
	ptOop = popRemappableOop();
	storePointerofObjectwithValue(0, ptOop, xOop);
	storePointerofObjectwithValue(1, ptOop, yOop);
	pop((methodArgumentCount()) + 1);
	return push(ptOop);
}


/*	Computes the determinant of the upper 3x3 of a Matrix4x4 */

	/* CroquetPlugin>>#primitiveDet3 */
EXPORT(sqInt)
primitiveDet3(void)
{
    sqInt argc;
    double det;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;

	argc = methodArgumentCount();
	if (!(argc == 0)) {
		return primitiveFail();
	}
	flag("stackArgv");
	srcOop = stackObjectValue(argc);
	src = firstIndexableField(srcOop);
	m11 = src[0];
	m12 = src[1];
	m13 = src[2];
	m21 = src[4];
	m22 = src[5];
	m23 = src[6];
	m31 = src[8];
	m32 = src[9];

	/* do the actual work */
	m33 = src[10];
	det = ((m11 * ((m22 * m33) - (m23 * m32))) + (m12 * ((m23 * m31) - (m21 * m33)))) + (m13 * ((m21 * m32) - (m22 * m31)));
	pop(argc + 1);
	return pushFloat(det);
}


/*	Primitive. Gather good random entropy from a system source. */

	/* CroquetPlugin>>#primitiveGatherEntropy */
EXPORT(sqInt)
primitiveGatherEntropy(void)
{
    sqInt bufOop;
    void *bufPtr;
    sqInt bufSize;
    sqInt okay;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	bufOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!(isBytes(bufOop))) {
		return primitiveFail();
	}
	bufSize = byteSizeOf(bufOop);
	bufPtr = firstIndexableField(bufOop);
	okay = ioGatherEntropy(bufPtr, bufSize);
	if (!okay) {
		return primitiveFail();
	}
	pop((methodArgumentCount()) + 1);
	return pushBool(1);
}


/*	Primitive. Perform an inplace house holder matrix inversion */

	/* CroquetPlugin>>#primitiveInplaceHouseHolderInvert */
EXPORT(sqInt)
primitiveInplaceHouseHolderInvert(void)
{
    double beta;
    double d[4][4];
    sqInt i;
    sqInt j;
    sqInt k;
    double m[4][4];
    sqInt r;
    float *rcvr;
    double s;
    double sigma;
    double sum;
    double x[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };

	rcvr = stackMatrix(0);
	for (i = 0; i <= 3; i += 1) {
		for (j = 0; j <= 3; j += 1) {
			(m[i])[j] = (rcvr[(i * 4) + j]);
		}
	}
	for (j = 0; j <= 3; j += 1) {
		sigma = 0.0;
		for (i = j; i <= 3; i += 1) {
			sigma += ((m[i])[j]) * ((m[i])[j]);
		}
		if (sigma < 1.0e-10) {
			return primitiveFail();
		}
		if (((m[j])[j]) < 0.0) {
			s = sqrt(sigma);
		}
		else {
			s = 0.0 - (sqrt(sigma));
		}
		for (r = 0; r <= 3; r += 1) {
			(d[j])[r] = s;
		}
		beta = 1.0 / ((s * ((m[j])[j])) - sigma);
		(m[j])[j] = (((m[j])[j]) - s);
		for (k = (j + 1); k <= 3; k += 1) {
			sum = 0.0;
			for (i = j; i <= 3; i += 1) {
				sum += ((m[i])[j]) * ((m[i])[k]);
			}
			sum = sum * beta;
			for (i = j; i <= 3; i += 1) {
				(m[i])[k] = (((m[i])[k]) + (((m[i])[j]) * sum));
			}
		}
		for (r = 0; r <= 3; r += 1) {
			sum = 0.0;
			for (i = j; i <= 3; i += 1) {
				sum += ((x[i])[r]) * ((m[i])[j]);
			}
			sum = sum * beta;
			for (i = j; i <= 3; i += 1) {
				(x[i])[r] = (((x[i])[r]) + (sum * ((m[i])[j])));
			}
		}
	}
	for (r = 0; r <= 3; r += 1) {
		for (i = 3; i >= 0; i += -1) {
			for (j = (i + 1); j <= 3; j += 1) {
				(x[i])[r] = (((x[i])[r]) - (((x[j])[r]) * ((m[i])[j])));
			}
			(x[i])[r] = (((x[i])[r]) / ((d[i])[r]));
		}
	}
	for (i = 0; i <= 3; i += 1) {
		for (j = 0; j <= 3; j += 1) {
			rcvr[(i * 4) + j] = (((float) ((x[i])[j])));
		}
	}
	return null;
}


/*	Computes the inverse of the Matrix4x4 receiver, using the 'classical
	adjoint' method,
	placing the results the the Matrix4x4 argument,
	
 */

	/* CroquetPlugin>>#primitiveInverseByAdjoint */
EXPORT(sqInt)
primitiveInverseByAdjoint(void)
{
    sqInt argc;
    const int c11 = 0;
    const int c12 = 1;
    const int c13 = 2;
    const int c14 = 3;
    const int c21 = 4;
    const int c22 = 5;
    const int c23 = 6;
    const int c24 = 7;
    const int c31 = 8;
    const int c32 = 9;
    const int c33 = 10;
    const int c34 = 11;
    double det;
    float *dst;
    sqInt dstOop;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;
    double x;
    double y;
    double z;


	/* then we need the following no-op to make Smalltalk shut up about vars not being initted. */
	argc = methodArgumentCount();
	if (!(argc == 1)) {
		return primitiveFail();
	}
	flag("stackArgv");
	srcOop = stackObjectValue(argc);
	src = firstIndexableField(srcOop);
	dstOop = stackObjectValue(argc - 1);

	/* read in the source matrix 3x3, which contains the encoded rotation and scale factors */
	dst = firstIndexableField(dstOop);
	m11 = src[c11];
	m12 = src[c12];
	m13 = src[c13];
	m21 = src[c21];
	m22 = src[c22];
	m23 = src[c23];
	m31 = src[c31];
	m32 = src[c32];

	/* read in the source translation vector */
	m33 = src[c33];
	x = src[c14];
	y = src[c24];

	/* do the actual work */
	/* first, compute the determinant of the upper 3x3 of the source */
	z = src[c34];

	/* Compute the classical adjunct of the source, and divide by the source determinant
	   storing in the destination.  adjoint = transpose of cofactors, so we'll transpose as we store. */
	det = ((m11 * ((m22 * m33) - (m23 * m32))) + (m12 * ((m23 * m31) - (m21 * m33)))) + (m13 * ((m21 * m32) - (m22 * m31)));

	/* let's make div by det a multiply */
	det = 1 / det;
	dst[c11] = (((m22 * m33) - (m23 * m32)) * det);
	dst[c21] = ((0.0 - ((m21 * m33) - (m23 * m31))) * det);
	dst[c31] = (((m21 * m32) - (m22 * m31)) * det);
	dst[c12] = ((0.0 - ((m12 * m33) - (m13 * m32))) * det);
	dst[c22] = (((m11 * m33) - (m13 * m31)) * det);
	dst[c32] = ((0.0 - ((m11 * m32) - (m12 * m31))) * det);
	dst[c13] = (((m12 * m23) - (m13 * m22)) * det);
	dst[c23] = ((0.0 - ((m11 * m23) - (m13 * m21))) * det);
	dst[c33] = (((m11 * m22) - (m12 * m21)) * det);
	m11 = dst[c11];
	m12 = dst[c12];
	m13 = dst[c13];
	m21 = dst[c21];
	m22 = dst[c22];
	m23 = dst[c23];
	m31 = dst[c31];
	m32 = dst[c32];
	m33 = dst[c33];
	dst[c14] = (0.0 - (((x * m11) + (y * m12)) + (z * m13)));
	dst[c24] = (0.0 - (((x * m21) + (y * m22)) + (z * m23)));
	dst[c34] = (0.0 - (((x * m31) + (y * m32)) + (z * m33)));
	pop(argc + 1);
	return push(dstOop);
}


/*	Perform an MD5 transform of input */

	/* CroquetPlugin>>#primitiveMD5Transform */
EXPORT(sqInt)
primitiveMD5Transform(void)
{
    unsigned int *buffer;
    sqInt bufOop;
    unsigned int *hash;
    sqInt hashOop;

	if (!((methodArgumentCount()) == 2)) {
		return primitiveFail();
	}
	hashOop = stackObjectValue(0);
	if (!((isWords(hashOop))
		 && ((slotSizeOf(hashOop)) == 4))) {
		return primitiveFail();
	}
	hash = firstIndexableField(hashOop);
	bufOop = stackObjectValue(1);
	if (!((isWords(bufOop))
		 && ((slotSizeOf(bufOop)) == 16))) {
		return primitiveFail();
	}
	buffer = firstIndexableField(bufOop);
	MD5Transform(hash, buffer);
	pop((methodArgumentCount()) + 1);
	return push(bufOop);
}


/*	Given a list of integer indices for rendering a triangle-mesh in
	indexed-triangles mode, reorganize the indices in-place to provide better
	vertex cache locality.
	We use Tom Forsyth's algorithm:
	http://home.comcast.net/~tom_forsyth/papers/fast_vert_cache_opt.html
	... and the MIT-licensed implementation by Michael Georgoulpoulos at:
	http://code.google.com/p/vcacne/ */

	/* CroquetPlugin>>#primitiveOptimizeVertexIndicesForCacheLocality */
EXPORT(sqInt)
primitiveOptimizeVertexIndicesForCacheLocality(void)
{
    sqInt byteSize;
    void *indices;
    sqInt indicesOop;
    sqInt result;
    sqInt triCount;


	/* Get the oop of the IntegerArray containing the indices. */
	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	indicesOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!(isWords(indicesOop))) {
		return primitiveFail();
	}
	byteSize = byteSizeOf(indicesOop);
	triCount = byteSize / 12;
	if (!((triCount * 12) == byteSize)) {
		return primitiveFail();
	}
	indices = firstIndexableField(indicesOop);
	if (failed()) {
		return null;
	}
	result = optimizeVertexIndices((int*)indices, triCount);
	if (!(result == 0)) {

		/* success */
		return primitiveFail();
	}
	return pop(1);
}

	/* CroquetPlugin>>#primitiveOrthoNormInverseMatrix */
EXPORT(sqInt)
primitiveOrthoNormInverseMatrix(void)
{
    float *dst;
    sqInt dstOop;
    double rx;
    double ry;
    double rz;
    float *src;
    sqInt srcOop;
    double x;
    double y;
    double z;

	if (!((methodArgumentCount()) == 0)) {
		return primitiveFail();
	}
	srcOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!((isWords(srcOop))
		 && ((slotSizeOf(srcOop)) == 16))) {
		return primitiveFail();
	}

	/* reload srcOop in case of GC */
	dstOop = clone(srcOop);
	srcOop = stackObjectValue(0);
	src = firstIndexableField(srcOop);

	/* Transpose upper 3x3 matrix */
	/* dst at: 0 put: (src at: 0). */
	dst = firstIndexableField(dstOop);
	dst[1] = (src[4]);
	dst[2] = (src[8]);
	dst[4] = (src[1]);
	dst[6] = (src[9]);
	dst[8] = (src[2]);
	dst[9] = (src[6]);
	x = src[3];
	y = src[7];
	z = src[11];
	rx = ((x * (dst[0])) + (y * (dst[1]))) + (z * (dst[2]));
	ry = ((x * (dst[4])) + (y * (dst[5]))) + (z * (dst[6]));
	rz = ((x * (dst[8])) + (y * (dst[9]))) + (z * (dst[10]));
	dst[3] = (((float) (0.0 - rx)));
	dst[7] = (((float) (0.0 - ry)));
	dst[11] = (((float) (0.0 - rz)));
	popthenPush(1, dstOop);
	return 0;
}

	/* CroquetPlugin>>#primitiveTransformDirection */
EXPORT(sqInt)
primitiveTransformDirection(void)
{
    float *matrix;
    double rx;
    double ry;
    double rz;
    sqInt v3Oop;
    float *vertex;
    double x;
    double y;
    double z;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	v3Oop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!((isWords(v3Oop))
		 && ((slotSizeOf(v3Oop)) == 3))) {
		return primitiveFail();
	}
	vertex = firstIndexableField(v3Oop);
	matrix = stackMatrix(1);
	if (matrix == null) {
		return primitiveFail();
	}
	x = vertex[0];
	y = vertex[1];
	z = vertex[2];
	rx = ((x * (matrix[0])) + (y * (matrix[1]))) + (z * (matrix[2]));
	ry = ((x * (matrix[4])) + (y * (matrix[5]))) + (z * (matrix[6]));
	rz = ((x * (matrix[8])) + (y * (matrix[9]))) + (z * (matrix[10]));
	v3Oop = clone(v3Oop);
	vertex = firstIndexableField(v3Oop);
	vertex[0] = (((float) rx));
	vertex[1] = (((float) ry));
	vertex[2] = (((float) rz));
	pop(2);
	return push(v3Oop);
}


/*	Transform two matrices into the third */

	/* CroquetPlugin>>#primitiveTransformMatrixWithInto */
EXPORT(sqInt)
primitiveTransformMatrixWithInto(void)
{
    double c1;
    double c2;
    double c3;
    double c4;
    sqInt i;
    float *m1;
    float *m11;
    float *m2;
    float *m21;
    float *m3;
    float *m31;

	m3 = stackMatrix(0);
	m2 = stackMatrix(1);
	m1 = stackMatrix(2);
	if (((m1 == null) || (m2 == null)) || (m3 == null)) {
		return primitiveFail();
	}
	if (m2 == m3) {
		return primitiveFail();
	}
	/* begin transformMatrix:with:into: */
	m11 = ((float *) m1);
	m21 = ((float *) m2);
	m31 = ((float *) m3);
	for (i = 0; i <= 3; i += 1) {

		/* Compute next row */
		c1 = ((((((double) (m11[0]) )) * (((double) (m21[0]) ))) + ((((double) (m11[1]) )) * (((double) (m21[4]) )))) + ((((double) (m11[2]) )) * (((double) (m21[8]) )))) + ((((double) (m11[3]) )) * (((double) (m21[12]) )));
		c2 = ((((((double) (m11[0]) )) * (((double) (m21[1]) ))) + ((((double) (m11[1]) )) * (((double) (m21[5]) )))) + ((((double) (m11[2]) )) * (((double) (m21[9]) )))) + ((((double) (m11[3]) )) * (((double) (m21[13]) )));
		c3 = ((((((double) (m11[0]) )) * (((double) (m21[2]) ))) + ((((double) (m11[1]) )) * (((double) (m21[6]) )))) + ((((double) (m11[2]) )) * (((double) (m21[10]) )))) + ((((double) (m11[3]) )) * (((double) (m21[14]) )));

		/* Store result */
		c4 = ((((((double) (m11[0]) )) * (((double) (m21[3]) ))) + ((((double) (m11[1]) )) * (((double) (m21[7]) )))) + ((((double) (m11[2]) )) * (((double) (m21[11]) )))) + ((((double) (m11[3]) )) * (((double) (m21[15]) )));
		m31[0] = c1;
		m31[1] = c2;
		m31[2] = c3;
		m31[3] = c4;
		m11 += 4;
		m31 += 4;
	}
	return pop(3);
}

	/* CroquetPlugin>>#primitiveTransformVector3 */
EXPORT(sqInt)
primitiveTransformVector3(void)
{
    float *matrix;
    double rw;
    double rx;
    double ry;
    double rz;
    sqInt v3Oop;
    float *vertex;
    double x;
    double y;
    double z;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	v3Oop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!((isWords(v3Oop))
		 && ((slotSizeOf(v3Oop)) == 3))) {
		return primitiveFail();
	}
	vertex = firstIndexableField(v3Oop);
	matrix = stackMatrix(1);
	if (matrix == null) {
		return primitiveFail();
	}
	x = vertex[0];
	y = vertex[1];
	z = vertex[2];
	rx = (((x * (matrix[0])) + (y * (matrix[1]))) + (z * (matrix[2]))) + (matrix[3]);
	ry = (((x * (matrix[4])) + (y * (matrix[5]))) + (z * (matrix[6]))) + (matrix[7]);
	rz = (((x * (matrix[8])) + (y * (matrix[9]))) + (z * (matrix[10]))) + (matrix[11]);
	rw = (((x * (matrix[12])) + (y * (matrix[13]))) + (z * (matrix[14]))) + (matrix[15]);
	v3Oop = clone(v3Oop);
	vertex = firstIndexableField(v3Oop);
	if (rw == 1.0) {
		vertex[0] = (((float) rx));
		vertex[1] = (((float) ry));
		vertex[2] = (((float) rz));
	}
	else {
		if (rw == 0.0) {
			rw = 0.0;
		}
		else {
			rw = 1.0 / rw;
		}
		vertex[0] = (((float) (rx * rw)));
		vertex[1] = (((float) (ry * rw)));
		vertex[2] = (((float) (rz * rw)));
	}
	pop(2);
	return push(v3Oop);
}

	/* CroquetPlugin>>#primitiveTransposeMatrix */
EXPORT(sqInt)
primitiveTransposeMatrix(void)
{
    float *dst;
    sqInt dstOop;
    float *src;
    sqInt srcOop;

	if (!((methodArgumentCount()) == 0)) {
		return primitiveFail();
	}
	srcOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!((isWords(srcOop))
		 && ((slotSizeOf(srcOop)) == 16))) {
		return primitiveFail();
	}

	/* reload srcOop in case of GC */
	dstOop = clone(srcOop);
	srcOop = stackObjectValue(0);
	src = firstIndexableField(srcOop);

	/* dst at: 0 put: (src at: 0). */
	dst = firstIndexableField(dstOop);
	dst[1] = (src[4]);
	dst[2] = (src[8]);
	dst[3] = (src[12]);
	dst[4] = (src[1]);
	dst[6] = (src[9]);
	dst[7] = (src[13]);
	dst[8] = (src[2]);
	dst[9] = (src[6]);
	dst[11] = (src[14]);
	dst[12] = (src[3]);
	dst[13] = (src[7]);
	dst[14] = (src[11]);
	pop(1);
	return push(dstOop);
}


/*	Primitive. Answer whether an AABB intersects with a given triangle */

	/* CroquetPlugin>>#primitiveTriBoxIntersects */
EXPORT(sqInt)
primitiveTriBoxIntersects(void)
{
    float *maxCorner;
    float *minCorner;
    sqInt result;
    float *v0;
    float *v1;
    float *v2;

	if (!((methodArgumentCount()) == 5)) {
		return primitiveFail();
	}
	v2 = stackVector3(0);
	v1 = stackVector3(1);
	v0 = stackVector3(2);
	maxCorner = stackVector3(3);
	minCorner = stackVector3(4);
	result = triBoxOverlap(minCorner, maxCorner, v0, v1, v2);
	if (result < 0) {
		return primitiveFail();
	}
	pop(6);
	return pushBool(result);
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
		byteSizeOf = interpreterProxy->byteSizeOf;
		classPoint = interpreterProxy->classPoint;
		clone = interpreterProxy->clone;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		isWords = interpreterProxy->isWords;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		primitiveFail = interpreterProxy->primitiveFail;
		push = interpreterProxy->push;
		pushBool = interpreterProxy->pushBool;
		pushFloat = interpreterProxy->pushFloat;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackObjectValue = interpreterProxy->stackObjectValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Load a 4x4 transformation matrix from the interpreter stack.
	Return a pointer to the matrix data if successful, nil otherwise. */

	/* CroquetPlugin>>#stackMatrix: */
static void*
stackMatrix(sqInt index)
{
    sqInt oop;

	oop = stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if ((isWords(oop))
	 && ((slotSizeOf(oop)) == 16)) {
		return firstIndexableField(oop);
	}
	return null;
}


/*	Load a Vector3 from the interpreter stack.
	Return a pointer to the float data if successful, nil otherwise. */

	/* CroquetPlugin>>#stackVector3: */
static void*
stackVector3(sqInt index)
{
    sqInt oop;

	oop = stackObjectValue(index);
	if (oop == null) {
		return null;
	}
	if ((isWords(oop))
	 && ((slotSizeOf(oop)) == 3)) {
		return firstIndexableField(oop);
	}
	return null;
}


/*	Transform src with arg into dst.
	It is allowed that src == dst but not arg == dst */

	/* CroquetPlugin>>#transformMatrix:with:into: */
static sqInt
transformMatrixwithinto(float *src, float *arg, float *dst)
{
    double c1;
    double c2;
    double c3;
    double c4;
    sqInt i;
    float *m1;
    float *m2;
    float *m3;

	m1 = ((float *) src);
	m2 = ((float *) arg);
	m3 = ((float *) dst);
	for (i = 0; i <= 3; i += 1) {

		/* Compute next row */
		c1 = ((((((double) (m1[0]) )) * (((double) (m2[0]) ))) + ((((double) (m1[1]) )) * (((double) (m2[4]) )))) + ((((double) (m1[2]) )) * (((double) (m2[8]) )))) + ((((double) (m1[3]) )) * (((double) (m2[12]) )));
		c2 = ((((((double) (m1[0]) )) * (((double) (m2[1]) ))) + ((((double) (m1[1]) )) * (((double) (m2[5]) )))) + ((((double) (m1[2]) )) * (((double) (m2[9]) )))) + ((((double) (m1[3]) )) * (((double) (m2[13]) )));
		c3 = ((((((double) (m1[0]) )) * (((double) (m2[2]) ))) + ((((double) (m1[1]) )) * (((double) (m2[6]) )))) + ((((double) (m1[2]) )) * (((double) (m2[10]) )))) + ((((double) (m1[3]) )) * (((double) (m2[14]) )));

		/* Store result */
		c4 = ((((((double) (m1[0]) )) * (((double) (m2[3]) ))) + ((((double) (m1[1]) )) * (((double) (m2[7]) )))) + ((((double) (m1[2]) )) * (((double) (m2[11]) )))) + ((((double) (m1[3]) )) * (((double) (m2[15]) )));
		m3[0] = c1;
		m3[1] = c2;
		m3[2] = c3;
		m3[3] = c4;
		m1 += 4;
		m3 += 4;
	}
	return null;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "CroquetPlugin";
void* CroquetPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveAdj3\000\001", (void*)primitiveAdj3},
	{(void*)_m, "primitiveARC4Transform\000\001", (void*)primitiveARC4Transform},
	{(void*)_m, "primitiveDet3\000\001", (void*)primitiveDet3},
	{(void*)_m, "primitiveGatherEntropy\000\001", (void*)primitiveGatherEntropy},
	{(void*)_m, "primitiveInplaceHouseHolderInvert\000\000", (void*)primitiveInplaceHouseHolderInvert},
	{(void*)_m, "primitiveInverseByAdjoint\000\001", (void*)primitiveInverseByAdjoint},
	{(void*)_m, "primitiveMD5Transform\000\001", (void*)primitiveMD5Transform},
	{(void*)_m, "primitiveOptimizeVertexIndicesForCacheLocality\000\001", (void*)primitiveOptimizeVertexIndicesForCacheLocality},
	{(void*)_m, "primitiveOrthoNormInverseMatrix\000\001", (void*)primitiveOrthoNormInverseMatrix},
	{(void*)_m, "primitiveTransformDirection\000\001", (void*)primitiveTransformDirection},
	{(void*)_m, "primitiveTransformMatrixWithInto\000\000", (void*)primitiveTransformMatrixWithInto},
	{(void*)_m, "primitiveTransformVector3\000\001", (void*)primitiveTransformVector3},
	{(void*)_m, "primitiveTransposeMatrix\000\001", (void*)primitiveTransposeMatrix},
	{(void*)_m, "primitiveTriBoxIntersects\000\000", (void*)primitiveTriBoxIntersects},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveAdj3AccessorDepth = 1;
signed char primitiveARC4TransformAccessorDepth = 1;
signed char primitiveDet3AccessorDepth = 1;
signed char primitiveGatherEntropyAccessorDepth = 1;
signed char primitiveInplaceHouseHolderInvertAccessorDepth = 0;
signed char primitiveInverseByAdjointAccessorDepth = 1;
signed char primitiveMD5TransformAccessorDepth = 1;
signed char primitiveOptimizeVertexIndicesForCacheLocalityAccessorDepth = 1;
signed char primitiveOrthoNormInverseMatrixAccessorDepth = 1;
signed char primitiveTransformDirectionAccessorDepth = 1;
signed char primitiveTransformMatrixWithIntoAccessorDepth = 0;
signed char primitiveTransformVector3AccessorDepth = 1;
signed char primitiveTransposeMatrixAccessorDepth = 1;
signed char primitiveTriBoxIntersectsAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
