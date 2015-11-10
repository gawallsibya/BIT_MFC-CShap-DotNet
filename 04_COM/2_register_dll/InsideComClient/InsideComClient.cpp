//InsideComClient.cpp
#include <objbase.h>
#include <iostream>
using namespace std;

#include "interface.h"
#include "interface_i.c"

void main(void)
{
	HRESULT hr;
	int x1, y1;

	CoInitialize(NULL);
	cout << "Please enter an integer x1 and y1" << endl;
	cin >> x1 >> y1;
	IUnknown* pIUnknown=NULL;

	hr = CoGetClassObject(
		CLSID_InsideCom,
		CLSCTX_INPROC_SERVER,
		NULL,
		IID_IUnknown,
		(LPVOID*) &pIUnknown);

	if(FAILED(hr)) {
		cout << "CoGetClassObject() failed with error" << endl;
		return;
	}
	ISetVal* pISetVal=NULL;
	hr = pIUnknown->QueryInterface(IID_ISetVal,(void**)&pISetVal);
	if(SUCCEEDED(hr)) {
		pISetVal->SetValue(x1,y1);
		pISetVal->Release();
	}

	ICalcu* pICalcu = NULL;
	hr = pIUnknown->QueryInterface(IID_ICalcu,(void**)&pICalcu);
	if(SUCCEEDED(hr)) {
		cout << "x1 + y1 = " << pICalcu->Sum() << endl;
		cout << "x1 - y1 = " << pICalcu->Sub() << endl;
		pICalcu->Release();
	}
	pIUnknown->Release();
	CoUninitialize();
}

// IUnknown 포인터 가져오기

// 기존 DLL을 이용 : CreateInstance() 함수 내에서 얻어옴.
// ==> 단순히 CoGetClassObject만 호출하면됨....