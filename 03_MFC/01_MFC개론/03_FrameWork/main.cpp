#include <iostream>
using namespace std;

class Application;

Application *_app;

void SetApp(Application *p)
{
	_app = p;
}

Application *GetApp()
{
	return _app;
}

class Application{
public:
	Application() { SetApp(this); }
	virtual bool InitInstance() = 0;
	virtual void ExitInstance() {}
	virtual void Run() {}
};

void main()
{
	Application *pApp = GetApp();

	if( !pApp->InitInstance() )
	{
		cout << "�������α׷� �ʱ�ȭ ����!���α׷� ����" << endl;
		return;
	}

	//main loop
	pApp->Run();

	pApp->ExitInstance();
}

//----------- ������� library ���� 
#include <fstream>

class MyApp : public Application
{
public:
	ofstream f;

	virtual bool InitInstance()
	{
		f.open("c://test.txt");

		if( ! f.is_open())
		{
			return false;
		}
		return true;
	}

	virtual void Run() 
	{
		f << "hello" << endl;
	}

	virtual void ExitInstance() { f.close(); }
};

MyApp theApp;