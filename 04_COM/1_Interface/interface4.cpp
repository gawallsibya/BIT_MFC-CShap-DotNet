 //------------------------------------------------------------------
// COM �������̽� ���� : ���� ī���� �ǽ� 
//------------------------------------------------------------------
#include <objbase.h>		// #define interface struct : �⺻ public ����..
#include <iostream.h>


// INTERFACE
// �߻� ���̽� Ŭ����...
interface IX	: IUnknown	// �������̽��� ���������� �ձ��ڸ� I �빮�� ���, ����ü�� ���̴�..
//class IX
{
public:
	// ���� ���� �Լ� 
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

	
	CA() : m_cRef(0) {}		// ������
	~CA() 
	{
		cout << "������ �״´�." << endl;
	}
private:
	long m_cRef;		// ���� �ֱ� ���� ����..
};


extern const IID IID_IX;
extern const IID IID_IY;

// ���� �ֱ� ���� �Լ� 
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
// COM Ŭ���̾�Ʈ -> COM ������Ʈ�� ��� �����Ǿ����� �� �� ����.
// COM Ŭ���̾�Ʈ�� ������Ʈ�� interface�� �̿��� �� �ִ�.
// ����� interface�� � ������� ���� �� ������?? QueryInterface�� ����..

// Ŭ���̾�Ʈ�� �������̽��� ã�� ���
// 1. interface�� �̸� : �̸��� �ߺ��Ǹ� �浹.. ������ ID�� ��ġ
// 2. Queryinterface �Լ��� ���� ��´�.
// 3. Queryinterface�� IUnknown �ȿ� �ִ�.

// IUnknown ??
// �������̽��� ����... ��� �������̽��� �ݵ�� Iunknown�� ��� �޴´�.
// IUnknown �� ��ӹ��� ������ COM ������Ʈ�� �ƴϴ�.
// IUnknown���� 3���� �Լ��� �ִ�.
// QueryInterface( ã���� �ϴ� ID,  ���Ϲ��� interface �ּ�)


// HRESULT �ڵ��� �ƴ�.. 32bit�� ��ũ��...

// CreateInstance???
// IUnknown�� CreateInstacne�� ���� ��´�...
// ��ü�� ������Ű�� ����
// IUnknown�� ��ȯ�ϴ� ����.

// AddRef, Release
// ������Ʈ�� ���� �ֱ�� ���õ� ���� ��... Ŭ���̾�Ʈ���� ������Ʈ ���� �۾� �ּ�ȭ �ϱ� ���� ����.


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
			cout << "����" << endl;
		}
		pIUnknown2->Release();
	}
	pIUnknown->Release();
	pIX->Release();
	pIY->Release();
//	delete pIUnknown;
}