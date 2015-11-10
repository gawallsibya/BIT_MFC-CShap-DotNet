//------------------------------------------------------------
// [ COM 규약을 전혀 고려하지 않은 일반적인 프로그램 ]
//------------------------------------------------------------
#include <iostream.h>

class Cpoo
{
	int x;
	int y;

public:
	Cpoo(int x1, int y1)
	{
		x = x1;
		y = y1;
	};
	int sum(){return x+y;};
	int sub(){return x-y;};
};

void main()
{
	int x1, y1;
	cout << "enter an integer x1 : " ;
	cin >> x1;

	cout << "enter an integer y1 : " ;
	cin >> y1;

	Cpoo	poo(x1, y1);
	cout << "x1 + y1 = " << poo.sum() << endl;
	cout << "x1 - y1 = " << poo.sub() << endl;
}