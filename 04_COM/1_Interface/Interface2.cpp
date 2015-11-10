//------------------------------------------------------------------
// COM �������̽� ���� : interface keyword ��� 
//------------------------------------------------------------------
#include <objbase.h>		// #define interface struct : �⺻ public ����..
#include <iostream.h>

// INTERFACE
// �߻� ���̽� Ŭ����...
interface IX		// �������̽��� ���������� �ձ��ڸ� I �빮�� ���, ����ü�� ���̴�..
//class IX
{
public:
	// ���� ���� �Լ� 
	virtual void __stdcall Fx1() = 0;
	virtual void __stdcall Fx2() = 0;
};

//class IY
interface IY
{
public:
	virtual void __stdcall Fy1() = 0;
	virtual void __stdcall Fy2() = 0;
};

// COMPONENT
class CA : public IX, public IY
{
public:
	virtual void __stdcall Fx1() { cout << "Fx1" << endl; }
	virtual void __stdcall Fx2() { cout << "Fx2" << endl; }
	virtual void __stdcall Fy1() { cout << "Fy1" << endl; }
	virtual void __stdcall Fy2() { cout << "Fy2" << endl; }
};

// CLIENT
void main()
{
	CA *pA = new CA;		// ��ü ���� ?

	IX*		pIX = pA;		// �������̽� ���...
	pIX->Fx1();
	pIX->Fx2();

	IY*		pIY = pA;		// �������̽� ���...
	pIY->Fy1();
	pIY->Fy2();
}

/*
__stdcall : ���ϰ��� pascal(16bit) �� ��ȯ 
            ������ Cȣ�� ��ȯ : __cdecl 

            => ���� �ҰŰ� Ʋ�� 
			=> COM �������̽��� ���ؼ� �����ϴ� ��� �Լ��� pascal ��� ��� 

5���� ȣ�� �Ծ� 
__fastcall	 : Device Driver ���鶧 �ַ� ��� �ϴ� ��� 
this		 : C++ �� �ɹ� �Լ��� ȣ��ɶ� ����ϴ� ��� 
naked		 : Intel Cpu ������ ����ϴ� ���, �ٸ� CPU������ ȣȯ���� ���� ���� ��� ���� 
__stdcall	 : Argument Passing R-> L   ȣ���ڰ�  ���� �Ұ� C/C++ �Լ��� �⺻ ȣ�� �Ծ� 
__cdecl      :                  R -> L   ȣ��� �Լ��� ���� �Ұ�  ��κ��� System �Լ��� ��� 
					                      VB ���� ���� �Լ��� ��� 
									    ���� ũ�Ⱑ �پ�� system�� ��������...
*/



















	
// Ŭ���̾�Ʈ�� ������Ʈ�� 2���� �������̽��� ���ؼ� ����Ѵ�. 
// �������̽��� C++ ���� �߻� ���̽� Ŭ������ �����ȴ�. ........
// �ϳ��� COM ������Ʈ�� ���� ����� �����Ѵ�..................

// ������Ʈ   : 2���� �߻� ���̽� Ŭ������ ����Ͽ� �����Ǿ���.
// Ŭ���̾�Ʈ : ������Ʈ�� �ν��Ͻ��� �����. 
//              ������Ʈ�� ���ؼ� �����Ǵ� �������̽��� ���� �����͸� ��´�.   

