
//1  C++
#include <iostream.h>

class Dot{
public:
	virtual void Draw() {cout << "Dot..." <<endl; }
    void ScreenPrint();
};

void Dot::ScreenPrint()
{
    Draw();
}


class Line : public Dot{
public: 
	void Draw() {cout << "Line" << endl; }
};

void main()
{
	Line line;
	line.ScreenPrint();
	line.Draw();
}

//////////// ��� ȣ��?? //////////// 
// MFC�� �⺻������ ���� = �����Լ��� ���� ���� �ʿ�