/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2673 uuid: ceb6ec91-3b0f-4fd3-93b7-19f6e445c4a5
   from
	SecurityPlugin VMMaker.oscog-eem.2673 uuid: ceb6ec91-3b0f-4fd3-93b7-19f6e445c4a5
 */
static char __buildInfo[] = "SecurityPlugin VMMaker.oscog-eem.2673 uuid: ceb6ec91-3b0f-4fd3-93b7-19f6e445c4a5 " __DATE__ ;



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

#include "SecurityPlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveCanWriteImage(void);
EXPORT(sqInt) primitiveDisableImageWrite(void);
EXPORT(sqInt) primitiveGetSecureUserDirectory(void);
EXPORT(sqInt) primitiveGetUntrustedUserDirectory(void);
EXPORT(sqInt) secCanConnectToPort(sqInt addr, sqInt port);
EXPORT(sqInt) secCanCreatePathOfSize(char *dirName, sqInt dirNameSize);
EXPORT(sqInt) secCanCreateSocketOfType(sqInt netType, sqInt socketType);
EXPORT(sqInt) secCanDeleteFileOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanDeletePathOfSize(char *dirName, sqInt dirNameSize);
EXPORT(sqInt) secCanGetFileTypeOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanListPathOfSize(char *pathName, sqInt pathNameSize);
EXPORT(sqInt) secCanOpenAsyncFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag);
EXPORT(sqInt) secCanOpenFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag);
EXPORT(sqInt) secCanRenameFileOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanRenameImage(void);
EXPORT(sqInt) secCanSetFileTypeOfSize(char *fileName, sqInt fileNameSize);
EXPORT(sqInt) secCanWriteImage(void);
EXPORT(sqInt) secCanListenOnPort(sqInt socket, sqInt port);
EXPORT(sqInt) secDisableFileAccess(void);
EXPORT(sqInt) secDisableSocketAccess(void);
EXPORT(sqInt) secHasEnvironmentAccess(void);
EXPORT(sqInt) secHasFileAccess(void);
EXPORT(sqInt) secHasSocketAccess(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*pushBool)(sqInt trueOrFalse);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt pushBool(sqInt trueOrFalse);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "SecurityPlugin VMMaker.oscog-eem.2673 " INT_EXT;



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

	/* SecurityPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return ioInitSecurity();
}

	/* SecurityPlugin>>#primitiveCanWriteImage */
EXPORT(sqInt)
primitiveCanWriteImage(void)
{
	pop(1);
	pushBool(ioCanWriteImage());
	return 0;
}

	/* SecurityPlugin>>#primitiveDisableImageWrite */
EXPORT(sqInt)
primitiveDisableImageWrite(void)
{
	ioDisableImageWrite();
	return 0;
}


/*	Primitive. Return the secure directory for the current user. */

	/* SecurityPlugin>>#primitiveGetSecureUserDirectory */
EXPORT(sqInt)
primitiveGetSecureUserDirectory(void)
{
    sqInt dirLen;
    char *dirName;
    sqInt dirOop;
    char *dirPtr;
    sqInt i;

	dirName = ioGetSecureUserDirectory();
	if ((dirName == null)
	 || (failed())) {
		return primitiveFail();
	}
	dirLen = strlen(dirName);
	dirOop = instantiateClassindexableSize(classString(), dirLen);
	if (failed()) {
		return null;
	}
	dirPtr = firstIndexableField(dirOop);
	for (i = 0; i < dirLen; i += 1) {
		dirPtr[i] = (dirName[i]);
	}
	popthenPush(1, dirOop);
	return 0;
}


/*	Primitive. Return the untrusted user directory name. */

	/* SecurityPlugin>>#primitiveGetUntrustedUserDirectory */
EXPORT(sqInt)
primitiveGetUntrustedUserDirectory(void)
{
    sqInt dirLen;
    char *dirName;
    sqInt dirOop;
    char *dirPtr;
    sqInt i;

	dirName = ioGetUntrustedUserDirectory();
	if ((dirName == null)
	 || (failed())) {
		return primitiveFail();
	}
	dirLen = strlen(dirName);
	dirOop = instantiateClassindexableSize(classString(), dirLen);
	if (failed()) {
		return null;
	}
	dirPtr = firstIndexableField(dirOop);
	for (i = 0; i < dirLen; i += 1) {
		dirPtr[i] = (dirName[i]);
	}
	popthenPush(1, dirOop);
	return 0;
}

	/* SecurityPlugin>>#secCanConnect:ToPort: */
EXPORT(sqInt)
secCanConnectToPort(sqInt addr, sqInt port)
{
	return ioCanConnectToPort(addr, port);
}

	/* SecurityPlugin>>#secCanCreatePath:OfSize: */
EXPORT(sqInt)
secCanCreatePathOfSize(char *dirName, sqInt dirNameSize)
{
	return ioCanCreatePathOfSize(dirName, dirNameSize);
}

	/* SecurityPlugin>>#secCanCreate:SocketOfType: */
EXPORT(sqInt)
secCanCreateSocketOfType(sqInt netType, sqInt socketType)
{
	return ioCanCreateSocketOfType(netType, socketType);
}

	/* SecurityPlugin>>#secCanDeleteFile:OfSize: */
EXPORT(sqInt)
secCanDeleteFileOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanDeleteFileOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanDeletePath:OfSize: */
EXPORT(sqInt)
secCanDeletePathOfSize(char *dirName, sqInt dirNameSize)
{
	return ioCanDeletePathOfSize(dirName, dirNameSize);
}

	/* SecurityPlugin>>#secCanGetFileType:OfSize: */
EXPORT(sqInt)
secCanGetFileTypeOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanGetFileTypeOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanListPath:OfSize: */
EXPORT(sqInt)
secCanListPathOfSize(char *pathName, sqInt pathNameSize)
{
	return ioCanListPathOfSize(pathName, pathNameSize);
}

	/* SecurityPlugin>>#secCanOpenAsyncFile:OfSize:Writable: */
EXPORT(sqInt)
secCanOpenAsyncFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag)
{
	return ioCanOpenAsyncFileOfSizeWritable(fileName, fileNameSize, writeFlag);
}

	/* SecurityPlugin>>#secCanOpenFile:OfSize:Writable: */
EXPORT(sqInt)
secCanOpenFileOfSizeWritable(char *fileName, sqInt fileNameSize, sqInt writeFlag)
{
	return ioCanOpenFileOfSizeWritable(fileName, fileNameSize, writeFlag);
}

	/* SecurityPlugin>>#secCanRenameFile:OfSize: */
EXPORT(sqInt)
secCanRenameFileOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanRenameFileOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanRenameImage */
EXPORT(sqInt)
secCanRenameImage(void)
{
	return ioCanRenameImage();
}

	/* SecurityPlugin>>#secCanSetFileType:OfSize: */
EXPORT(sqInt)
secCanSetFileTypeOfSize(char *fileName, sqInt fileNameSize)
{
	return ioCanSetFileTypeOfSize(fileName, fileNameSize);
}

	/* SecurityPlugin>>#secCanWriteImage */
EXPORT(sqInt)
secCanWriteImage(void)
{
	return ioCanWriteImage();
}

	/* SecurityPlugin>>#secCan:ListenOnPort: */
EXPORT(sqInt)
secCanListenOnPort(sqInt socket, sqInt port)
{
	return ioCanListenOnPort(socket, port);
}

	/* SecurityPlugin>>#secDisableFileAccess */
EXPORT(sqInt)
secDisableFileAccess(void)
{
	return ioDisableFileAccess();
}

	/* SecurityPlugin>>#secDisableSocketAccess */
EXPORT(sqInt)
secDisableSocketAccess(void)
{
	return ioDisableSocketAccess();
}

	/* SecurityPlugin>>#secHasEnvironmentAccess */
EXPORT(sqInt)
secHasEnvironmentAccess(void)
{
	return ioHasEnvironmentAccess();
}

	/* SecurityPlugin>>#secHasFileAccess */
EXPORT(sqInt)
secHasFileAccess(void)
{
	return ioHasFileAccess();
}

	/* SecurityPlugin>>#secHasSocketAccess */
EXPORT(sqInt)
secHasSocketAccess(void)
{
	return ioHasSocketAccess();
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
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		pushBool = interpreterProxy->pushBool;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "SecurityPlugin";
void* SecurityPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveCanWriteImage\000\377", (void*)primitiveCanWriteImage},
	{(void*)_m, "primitiveDisableImageWrite\000\377", (void*)primitiveDisableImageWrite},
	{(void*)_m, "primitiveGetSecureUserDirectory\000\377", (void*)primitiveGetSecureUserDirectory},
	{(void*)_m, "primitiveGetUntrustedUserDirectory\000\377", (void*)primitiveGetUntrustedUserDirectory},
	{(void*)_m, "secCanConnectToPort", (void*)secCanConnectToPort},
	{(void*)_m, "secCanCreatePathOfSize", (void*)secCanCreatePathOfSize},
	{(void*)_m, "secCanCreateSocketOfType", (void*)secCanCreateSocketOfType},
	{(void*)_m, "secCanDeleteFileOfSize", (void*)secCanDeleteFileOfSize},
	{(void*)_m, "secCanDeletePathOfSize", (void*)secCanDeletePathOfSize},
	{(void*)_m, "secCanGetFileTypeOfSize", (void*)secCanGetFileTypeOfSize},
	{(void*)_m, "secCanListPathOfSize", (void*)secCanListPathOfSize},
	{(void*)_m, "secCanOpenAsyncFileOfSizeWritable", (void*)secCanOpenAsyncFileOfSizeWritable},
	{(void*)_m, "secCanOpenFileOfSizeWritable", (void*)secCanOpenFileOfSizeWritable},
	{(void*)_m, "secCanRenameFileOfSize", (void*)secCanRenameFileOfSize},
	{(void*)_m, "secCanRenameImage\000\377", (void*)secCanRenameImage},
	{(void*)_m, "secCanSetFileTypeOfSize", (void*)secCanSetFileTypeOfSize},
	{(void*)_m, "secCanWriteImage\000\377", (void*)secCanWriteImage},
	{(void*)_m, "secCanListenOnPort", (void*)secCanListenOnPort},
	{(void*)_m, "secDisableFileAccess\000\377", (void*)secDisableFileAccess},
	{(void*)_m, "secDisableSocketAccess\000\377", (void*)secDisableSocketAccess},
	{(void*)_m, "secHasEnvironmentAccess\000\377", (void*)secHasEnvironmentAccess},
	{(void*)_m, "secHasFileAccess\000\377", (void*)secHasFileAccess},
	{(void*)_m, "secHasSocketAccess\000\377", (void*)secHasSocketAccess},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */


#endif /* ifdef SQ_BUILTIN_PLUGIN */
