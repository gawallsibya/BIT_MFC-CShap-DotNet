#include <objbase.h>
#include <iostream>
using namespace std;

#include "registry.h"


static HMODULE g_hModule = NULL;

const int CLSID_STRING_SIZE = 39;
const char szFriendlyName[] = "InsideCom Example";
const char szVerIndProgID[] = "InsideCom.Component";
const char szProgID[] = "InsideCom.Component.1";


interface ISetVal : IUnknown
{
	virtual void __stdcall SetValue(int , int) = 0;
};

interface ICalcu : IUnknown
{	
	virtual int __stdcall Sum() = 0;
	virtual int __stdcall Sub() = 0;
};

class CInsideCom : public ISetVal, ICalcu
{
	int x,y;

	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	virtual void __stdcall SetValue(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	virtual int __stdcall Sum() {
		return x+y;
	}
	virtual int __stdcall Sub() {
		return x-y;
	}
public:
	CInsideCom() : m_cRef(0) {}
	~CInsideCom() {
		cout << "CInsideCom is destroyed by itself." << endl;
	}
private:
	long m_cRef;
};

extern const CLSID CLSID_COMPONENT;
extern const IID IID_ISetVal;
extern const IID IID_ICalcu;

HRESULT __stdcall CInsideCom::QueryInterface(REFIID iid, void** ppv)
{
	if(iid == IID_IUnknown || iid == IID_ISetVal) {
		*ppv = static_cast<ISetVal*>(this);
	}
	else if(iid == IID_ICalcu) {
		*ppv = static_cast<ICalcu*>(this);
	}
	else {
		cout << "QueryInterface : interface not supported" << endl;
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	static_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG __stdcall CInsideCom::AddRef() 
{
	cout << "m_cRef = " << m_cRef+1 << endl;
	return InterlockedIncrement(&m_cRef);
}

ULONG __stdcall CInsideCom::Release()
{	
	cout << "m_cRef = " << m_cRef-1 << endl;
	if(InterlockedDecrement(&m_cRef) == 0 )	{
		delete this;
		return 0;
	}
	return m_cRef;
}

static const CLSID CLSID_InsideCom = // {19CE762B-C2BE-49d1-9514-139395EB6A63}
{ 0x19ce762b, 0xc2be, 0x49d1, { 0x95, 0x14, 0x13, 0x93, 0x95, 0xeb, 0x6a, 0x63 } };

// {7D1DA4D3-2DD8-4317-937D-157BF19DE48C}
static const IID IID_ISetVal = 
{ 0x7d1da4d3, 0x2dd8, 0x4317, { 0x93, 0x7d, 0x15, 0x7b, 0xf1, 0x9d, 0xe4, 0x8c } };

// {1BA9514E-9303-4c4d-948A-D1EAA0932A82}
static const IID IID_ICalcu = 
{ 0x1ba9514e, 0x9303, 0x4c4d, { 0x94, 0x8a, 0xd1, 0xea, 0xa0, 0x93, 0x2a, 0x82 } };

BOOL APIENTRY DllMain(HINSTANCE hModule,DWORD dwReason,LPVOID lpReserved)
{
	switch(dwReason) {
		case DLL_PROCESS_ATTACH:
			g_hModule = hModule;
			break;
	}
	return TRUE;
}

STDAPI DllGetClassObject(REFCLSID clsid, REFIID iid,LPVOID *ppv)
{
	*ppv = static_cast<ISetVal*>(new CInsideCom);
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

STDAPI DllRegisterServer()
{
	char szCLSID[CLSID_STRING_SIZE];
	char szModule[512];
	char szKey[64];

	DWORD dwResult = ::GetModuleFileName(g_hModule,
										 szModule,
										 sizeof(szModule)/sizeof(char));
	if(dwResult == 0) {
		return E_FAIL;
	}
	ClsidToChar(CLSID_InsideCom, szCLSID,sizeof(szCLSID));
	strcpy(szKey,"CLSID\\");
	strcat(szKey,szCLSID);
	SetRegistryInform(szKey,NULL,szFriendlyName);
	SetRegistryInform(szKey,"InprocServer32",szModule); //Location..Threading Model
	SetRegistryInform(szKey,"ProgID",szProgID); // Program ID
	SetRegistryInform(szKey,"VersionIndependentProgID",szVerIndProgID);

	//HKEY_CLASSES_ROOT\InsideCom Example
	SetRegistryInform(szVerIndProgID,NULL,szFriendlyName);
	SetRegistryInform(szVerIndProgID,"CLSID",szCLSID);
	SetRegistryInform(szVerIndProgID,"CurVer",szProgID);

	//HKEY_CLASSES_ROOT\InsideCom.Component.1
	SetRegistryInform(szProgID, NULL, szFriendlyName);
	SetRegistryInform(szProgID, "CLSID", szCLSID);

	return S_OK;
}

STDAPI DllUnregisterServer()
{
	//Build the key CLSID\\{...}
	char szCLSID[CLSID_STRING_SIZE];
	char szKey[64];
	ClsidToChar(CLSID_InsideCom,szCLSID,sizeof(szCLSID));
	strcpy(szKey,"CLSID\\");
	strcat(szKey, szCLSID);

	//CLSID Key - CLSID\{...} 삭제.
	LONG lResult = DeleteRegistryKey(HKEY_CLASSES_ROOT,szKey);
	//version-independent ProgID Key 삭제.
	lResult = DeleteRegistryKey(HKEY_CLASSES_ROOT,szVerIndProgID);
	//ProgID Key 삭제
	lResult = DeleteRegistryKey(HKEY_CLASSES_ROOT,szProgID);

	return S_OK;
}

