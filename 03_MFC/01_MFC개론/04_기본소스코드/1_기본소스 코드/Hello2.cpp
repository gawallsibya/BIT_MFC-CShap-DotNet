// App의 ExitInstance() 재정의 하기 

// 반드시 부모의 ExitInstance()를 호출해야 함 ??


#include <afxwin.h>

class CHelloApp : public CWinApp 
{
public:
	virtual BOOL InitInstance()
	{
		AfxMessageBox("Hello, MFC");
		return FALSE;
	}
	virtual int ExitInstance()
	{
		AfxMessageBox("ExitInstance");
		return CWinApp::ExitInstance();
	}
};

CHelloApp theApp;