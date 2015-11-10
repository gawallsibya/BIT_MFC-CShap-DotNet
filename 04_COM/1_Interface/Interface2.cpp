//------------------------------------------------------------------
// COM 인터페이스 구현 : interface keyword 사용 
//------------------------------------------------------------------
#include <objbase.h>		// #define interface struct : 기본 public 선언..
#include <iostream.h>

// INTERFACE
// 추상 베이스 클래스...
interface IX		// 인터페이스는 전통적으로 앞글자를 I 대문자 사용, 구조체일 뿐이다..
//class IX
{
public:
	// 순수 가상 함수 
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
	CA *pA = new CA;		// 객체 생성 ?

	IX*		pIX = pA;		// 인터페이스 얻기...
	pIX->Fx1();
	pIX->Fx2();

	IY*		pIY = pA;		// 인터페이스 얻기...
	pIY->Fy1();
	pIY->Fy2();
}

/*
__stdcall : 리턴값을 pascal(16bit) 로 반환 
            원래는 C호출 반환 : __cdecl 

            => 스택 소거가 틀림 
			=> COM 인터페이스에 의해서 제공하는 모든 함수는 pascal 방식 사용 

5개의 호출 규약 
__fastcall	 : Device Driver 만들때 주로 사용 하는 방식 
this		 : C++ 의 맴버 함수가 호출될때 사용하는 방식 
naked		 : Intel Cpu 에서만 사용하는 방식, 다른 CPU에서는 호환성이 없어 거의 사용 안함 
__stdcall	 : Argument Passing R-> L   호출자가  스택 소거 C/C++ 함수의 기본 호출 규약 
__cdecl      :                  R -> L   호출된 함수가 스택 소거  대부분의 System 함수가 사용 
					                      VB 에서 내부 함수가 사용 
									    파일 크기가 줄어듬 system에 안정적임...
*/



















	
// 클라이언트와 컴포넌트는 2개의 인터페이스를 통해서 통신한다. 
// 인터페이스는 C++ 순수 추상 베이스 클래스로 구현된다. ........
// 하나의 COM 컴포넌트는 다중 상속을 지원한다..................

// 컴포넌트   : 2개의 추상 베이스 클래스를 사용하여 구현되었다.
// 클라이언트 : 컴포넌트의 인스턴스를 만든다. 
//              컴포넌트에 의해서 지원되는 인터페이스에 대한 포인터를 얻는다.   

