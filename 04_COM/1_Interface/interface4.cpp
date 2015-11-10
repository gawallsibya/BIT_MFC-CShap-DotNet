 //------------------------------------------------------------------
// COM 인터페이스 구현 : 참조 카운팅 실습 
//------------------------------------------------------------------
#include <objbase.h>		// #define interface struct : 기본 public 선언..
#include <iostream.h>


// INTERFACE
// 추상 베이스 클래스...
interface IX	: IUnknown	// 인터페이스는 전통적으로 앞글자를 I 대문자 사용, 구조체일 뿐이다..
//class IX
{
public:
	// 순수 가상 함수 
	virtual void __stdcall Fx1() = 0;
	virtual void __stdcall Fx2() = 0;
};

//class IY
interface IY   : IUnknown 
{
public:
	virtual void __stdcall Fy1() = 0;
	virtual void __stdcall Fy2() = 0;
};




// COMPONENT
class CA : public IX, public IY
{
public:
	// IUnknown
	virtual HRESULT __stdcall QueryInterface(const IID & iid, void ** ppv);
	virtual ULONG __stdcall AddRef(); //{ return 0; }
	virtual ULONG __stdcall Release();// { return 0; }

	// IX
	virtual void __stdcall Fx1() { cout << "Fx1" << endl; }
	virtual void __stdcall Fx2() { cout << "Fx2" << endl; }

	// IY
	virtual void __stdcall Fy1() { cout << "Fy1" << endl; }
	virtual void __stdcall Fy2() { cout << "Fy2" << endl; }

	
	CA() : m_cRef(0) {}		// 생성자
	~CA() 
	{
		cout << "스스로 죽는다." << endl;
	}
private:
	long m_cRef;		// 생명 주기 저장 변수..
};


extern const IID IID_IX;
extern const IID IID_IY;

// 생명 주기 관련 함수 
ULONG __stdcall CA::AddRef()
{
	cout << "CA : AddRef  = " << m_cRef +1 << endl;
	return InterlockedIncrement(&m_cRef);
}
ULONG __stdcall CA::Release()
{
	cout << "CA : Release = " << m_cRef -1 << endl;
	if( InterlockedDecrement(&m_cRef) == 0 )
		delete this;
	return 0;
}

HRESULT __stdcall CA::QueryInterface(const IID & iid, void ** ppv)
{
	if(iid == IID_IUnknown)
	{
		*ppv = static_cast<IX*>(this);
	}
	else if( iid == IID_IX) 
	{
		*ppv = static_cast<IX*>(this);
	}
	else if( iid == IID_IY)
	{
		*ppv = static_cast<IY*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

// CreateInstacne
IUnknown *CreateInstance()
{
	IUnknown *pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
}

static const IID IID_IX = // {3FD8AC2C-1C15-4d61-8847-C74D2411F912}
{ 0x3fd8ac2c, 0x1c15, 0x4d61, { 0x88, 0x47, 0xc7, 0x4d, 0x24, 0x11, 0xf9, 0x12 } };

static const IID IID_IY = // {EB54B02D-DD55-42fc-BF34-148AE86574AF}
{ 0xeb54b02d, 0xdd55, 0x42fc, { 0xbf, 0x34, 0x14, 0x8a, 0xe8, 0x65, 0x74, 0xaf } };







// CLIENT
// COM 클라이언트 -> COM 컴포넌트가 어떻게 구성되었는지 알 수 없다.
// COM 클라이언트는 컴포넌트의 interface만 이용할 수 있다.
// 노출된 interface를 어떤 방법으로 얻을 수 있을까?? QueryInterface를 제공..

// 클라이언트가 인터페이스를 찾는 방법
// 1. interface의 이름 : 이름이 중복되면 충돌.. 고유한 ID로 대치
// 2. Queryinterface 함수를 통해 얻는다.
// 3. Queryinterface는 IUnknown 안에 있다.

// IUnknown ??
// 인터페이스의 조상... 모든 인터페이스는 반드시 Iunknown을 상속 받는다.
// IUnknown 을 상속받지 않으면 COM 컴포넌트가 아니다.
// IUnknown에는 3가지 함수가 있다.
// QueryInterface( 찾고자 하는 ID,  리턴받을 interface 주소)


// HRESULT 핸들이 아님.. 32bit의 매크로...

// CreateInstance???
// IUnknown은 CreateInstacne를 통해 얻는다...
// 객체를 생성시키는 역할
// IUnknown을 반환하는 역할.

// AddRef, Release
// 컴포넌트의 생성 주기와 관련된 일을 함... 클라이언트에서 컴포넌트 관련 작업 최소화 하기 위한 수단.


void main()
{
	HRESULT	hr;

	IUnknown* pIUnknown = CreateInstance();
	
//  CA *pA		= new CA;

	IX *pIX		= NULL;
	hr			= pIUnknown->QueryInterface( IID_IX, (void**)&pIX);
	if( SUCCEEDED(hr))
	{
		pIX->Fx1();
		pIX->Fx2();
	}

	IY *pIY		= NULL;
	hr			= pIUnknown->QueryInterface( IID_IY, (void**)&pIY);
	if( SUCCEEDED(hr))
	{
		pIY->Fy1();
		pIY->Fy2();
	}
	// 

	IUnknown *pIUnknown2  = NULL;
	hr			= pIY->QueryInterface(IID_IUnknown, (void**)&pIUnknown2);
	if( SUCCEEDED(hr))
	{
		if( pIUnknown == pIUnknown2)
		{
			cout << "동일" << endl;
		}
		pIUnknown2->Release();
	}
	pIUnknown->Release();
	pIX->Release();
	pIY->Release();
//	delete pIUnknown;
}