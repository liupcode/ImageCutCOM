// MPAImageCutCOM.cpp : Implementation of DLL Exports.
//
// Note: COM+ 1.0 Information:
//      Please remember to run Microsoft Transaction Explorer to install the component(s).
//      Registration is not done by default. 

#include "stdafx.h"
#include "resource.h"
#include "MPAImageCutCOM.h"



class CMPAImageCutCOMModule : public CAtlDllModuleT< CMPAImageCutCOMModule >
{
public :
	DECLARE_LIBID(LIBID_MPAImageCutCOMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MPAIMAGECUTCOM, "{1E329682-EE99-49E4-ABAC-C0D64BCDEF1C}")
};

CMPAImageCutCOMModule _AtlModule;

Gdiplus::GdiplusStartupInput		gdiplusStartupInput;
ULONG_PTR							gdiplusToken;


// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	Gdiplus::GdiplusShutdown(gdiplusToken);

	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
