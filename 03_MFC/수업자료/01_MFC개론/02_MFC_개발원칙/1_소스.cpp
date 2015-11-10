
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

//////////// 어디가 호출?? //////////// 
// MFC의 기본구조의 이해 = 가상함수에 대한 이해 필요