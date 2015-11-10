//InsideComClient.cpp
#include <iostream.h>
#include <objbase.h>
#include "../InsideCom/interface.h"
#include "../InsideCom/interface_i.c"

void main(void)
{
	HRESULT hr;
	int x1, y1;

	CoInitialize(NULL);
	cout << "Please enter an integer x1 and y1" << endl;
	cin >> x1 >> y1;
	//CoCreateInstance를 사용하여 DLL을 로드한다.
//	IUnknown* pIUnknown=NULL;
	ICalcu*	pICalcu= NULL;
	hr = CoCreateInstance(CLSID_InsideCom,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_ICalcu,
		(LPVOID*)&pICalcu);
//		IID_IUnknown,
//		(LPVOID*) &pIUnknown);

	if(FAILED(hr)) {
		cout << "CoCreateInstance() failed with error" << endl;
		return;
	}

	//ICalcu* pICalcu = NULL;
//	IUnknown* pIUnknown = NULL;
//	hr = pIUnknown->QueryInterface(IID_ICalcu,(void**)&pICalcu);
//	hr = pICalcu->QueryInterface(IID_IUnknown, (void**)&pIUnknown);
	if(SUCCEEDED(hr)) {
		cout << "x1 + y1 = " << pICalcu->Sum(x1, y1) << endl;
		cout << "x1 - y1 = " << pICalcu->Sub(x1, y1) << endl;
		pICalcu->Release();
	}
//	pIUnknown->Release();
	CoUninitialize();
}
