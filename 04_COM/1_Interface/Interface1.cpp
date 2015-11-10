/*
[Interface]

 1. �������̽��� COM������ ��� ���̴�.
 2. Ŭ���̾�Ʈ���� ������Ʈ�� �������̽��� �����̴�.
    Ŭ���̾�Ʈ�� ���� �������̽� ���� ���ؼ� COM ������Ʈ�� ����Ѵ�.
 3. �������̽��� �ý����� ��� ���濡 ���ؼ� ������ ���� �ʵ��� �Ѵ�. 
 4. �������̽��� Ŭ���̾�Ʈ�� ���� ������� �ٸ� ������Ʈ�� ó���� �� �ֵ��� �Ѵ�.
 5. �������̽��� ĸ��ȭ�� �����Ѵ�.
*/

//------------------------------------------------------------------
// COM �������̽� ����
//------------------------------------------------------------------
#include <iostream.h>

// INTERFACE
// �߻� ���̽� Ŭ����...
class IX
{
public:
	// ���� ���� �Լ� 
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
	// ������Ʈ ������ �ȵ�...
//	IX   x;
	// �߻� �⺻ Ŭ������ ������Ʈ�� �����ϴ� ���...
	IX   *pX;
	CA   a;
	pX = &a;
	pX->Fx1();
}


	
