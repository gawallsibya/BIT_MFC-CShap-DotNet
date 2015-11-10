#include <iostream.h>
#include <objbase.h>
#include "interface_i.c"
#include "interface.h"
#include "registry.h"


static HMODULE	g_hModule = NULL;
static long g_cComponents = 0;
static long g_cServerLocks = 0;

const int CLSID_STRING_SIZE = 39;

const char szFriendlyName[] = "InsideCom Example";
const char szVerIndProgID[] = "InsideCom.Contorl";
const char szProgID[] = "InsideCom.Control.1";
class CInsideCom : public ICalcu
{
public:
	virtual HRESULT	__stdcall QueryInterface(REFIID iid, LPVOID* ppv);
	virtual ULONG	__stdcall AddRef();
	virtual ULONG	__stdcall Release();
	virtual int		__stdcall Sum(int x, int y)
	{	
		return x+y;
	}
	virtual int		__stdcall Sub(int x, int y)
	{	
		return x-y;
	}
	virtual int		__stdcall Mul(int x, int y)
	{	
		return x*y;
	}
	
	virtual double  __stdcall Div(int x, int y)
	{	
		return x/y;
	}
public:
	CInsideCom() : m_cRef(1)
	{
		InterlockedIncrement(&g_cComponents);
	}
	~CInsideCom()
	{
		InterlockedDecrement(&g_cComponents);
		cout << "CInsideCom is Destroyed by itself." << endl;
	}
private:
	long m_cRef;
};
HRESULT	__stdcall CInsideCom::QueryInterface(REFIID iid, LPVOID* ppv)
{
	if(iid == IID_IUnknown || iid == IID_ICalcu) {
		cout << "QueryInterface : Return pointer to IUnknown." << endl;
		*ppv = static_cast<ICalcu*>(this);
	}
	else {
		cout << "QueryInterface : Interface not supported." << endl;
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	static_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG	__stdcall CInsideCom::AddRef()
{
	cout << "CInsideCom: Addref = " << m_cRef+1 << endl;
	return InterlockedIncrement(&m_cRef);
}

ULONG	__stdcall CInsideCom::Release()
{
	cout << "CInsideCom: Release = " << m_cRef-1 << endl;
	if(InterlockedDecrement(&m_cRef) == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

class CFactory : public IClassFactory
{
public:
	virtual HRESULT	__stdcall QueryInterface(REFIID iid, LPVOID* ppv);
	virtual ULONG	__stdcall AddRef();
	virtual ULONG	__stdcall Release();
	virtual HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,
											 REFIID iid,
											 LPVOID* ppv);
	virtual HRESULT __stdcall LockServer(BOOL bLock);
	CFactory() : m_cRef(1) {}
	~CFactory() 
	{
		cout << "Class Factory is destroyed itself." << endl;
	}
private:
	long m_cRef;
};

HRESULT	__stdcall CFactory::QueryInterface(REFIID iid, LPVOID* ppv)
{
	if((iid == IID_IUnknown) || (iid == IID_IClassFactory)) {
		*ppv = static_cast<IClassFactory*>(this);
	}
	else {
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG	__stdcall CFactory::AddRef()
{
	cout << "CFactory: Addref = " << m_cRef+1 << endl;
	return InterlockedIncrement(&m_cRef);
}

ULONG	__stdcall CFactory::Release()
{
	cout << "CFactory: Release = " << m_cRef-1 << endl;
	if(InterlockedDecrement(&m_cRef) == 0) {
		delete this;
		return 0;
	}
	return m_cRef;
}

HRESULT __stdcall CFactory::CreateInstance(IUnknown* pUnknownOuter,
										 REFIID iid,
										 LPVOID* ppv)
{
	if(pUnknownOuter != NULL) {
		return CLASS_E_NOAGGREGATION;
	}
	CInsideCom* pObCom = new CInsideCom;
	if(pObCom == NULL) {
		return E_OUTOFMEMORY;
	}
	HRESULT hr = pObCom->QueryInterface(iid,ppv);
	pObCom->Release();
	return hr;
}

HRESULT __stdcall CFactory::LockServer(BOOL bLock)
{
	if(bLock) {
		InterlockedIncrement(&g_cServerLocks);
	}
	else {
		InterlockedDecrement(&g_cServerLocks);
	}
	return S_OK;
}

BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason) {
		case DLL_PROCESS_ATTACH:
			g_hModule = hModule;
			break;
	}
	return TRUE;
}
STDAPI DllCanUnloadNow()
{
	if((g_cComponents ==0) && (g_cServerLocks == 0)) {
		return S_OK;
	}
	else {
		return S_FALSE;
	}
}

//클래스 팩토리 객체를 생성하고, IClassFactory interface 요청에 대한 QueryInterface를 수행한다.
STDAPI	DllGetClassObject(REFCLSID clsid,REFIID iid,LPVOID* ppv)
{
	CFactory* pFactory = new CFactory;
	if(pFactory == NULL) {
		return E_OUTOFMEMORY;
	}
	HRESULT hr = pFactory->QueryInterface(iid, ppv);
	pFactory->Release();
	return hr;
}

STDAPI	DllRegisterServer()
{	char szCLSID[CLSID_STRING_SIZE];
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
{//Build the key CLSID\\{...}
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

