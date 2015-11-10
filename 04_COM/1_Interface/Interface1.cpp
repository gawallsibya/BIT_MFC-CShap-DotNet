/*
[Interface]

 1. 인터페이스는 COM에서의 모든 것이다.
 2. 클라이언트에게 컴포넌트는 인터페이스의 집합이다.
    클라이언트는 오직 인터페이스 만을 통해서 COM 컴포넌트와 통신한다.
 3. 인터페이스는 시스템이 어떠한 변경에 의해서 영향을 받지 않도록 한다. 
 4. 인터페이스는 클라이언트가 같은 방법으로 다른 컴포넌트를 처리할 수 있도록 한다.
 5. 인터페이스는 캡슐화를 제공한다.
*/

//------------------------------------------------------------------
// COM 인터페이스 구현
//------------------------------------------------------------------
#include <iostream.h>

// INTERFACE
// 추상 베이스 클래스...
class IX
{
public:
	// 순수 가상 함수 
	virtual void Fx1() = 0;
	virtual void Fx2() = 0;
};

class IY
{
public:
	virtual void Fy1() = 0;
	virtual void Fy2() = 0;
};

// COMPONENT
class CA : public IX, public IY
{
public:
	virtual void Fx1() { cout << "Fx1" << endl; }
	virtual void Fx2() { cout << "Fx2" << endl; }
	virtual void Fy1() { cout << "Fy1" << endl; }
	virtual void Fy2() { cout << "Fy2" << endl; }
};

// CLIENT
void main()
{
	// 오브젝트 생성은 안됨...
//	IX   x;
	// 추상 기본 클래스의 오브젝트에 접근하는 방법...
	IX   *pX;
	CA   a;
	pX = &a;
	pX->Fx1();
}


	
