// App�� ExitInstance() ������ �ϱ� 

// �ݵ�� �θ��� ExitInstance()�� ȣ���ؾ� �� ??


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