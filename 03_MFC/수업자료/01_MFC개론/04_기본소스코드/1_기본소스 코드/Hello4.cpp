// CFrameWnd::Create()�� ������ �Ķ���͸� �ٲٸ� �����Ǵ� 
// �������� ��絵 �ٲܼ� �ִ�.

#include <afxwin.h>

class CHelloApp : public CWinApp 
{
public:
	virtual BOOL InitInstance()
	{
		CFrameWnd* pFrame = new CFrameWnd;
		

		pFrame->Create( 0, "Hello, MFC", 
						WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
						CRect(100,100,200,200), 0, 0,
						WS_EX_TOPMOST); // Ȯ�� ������ style

		pFrame->ShowWindow( SW_SHOW );
		pFrame->UpdateWindow( );
		
		m_pMainWnd = pFrame;

		return TRUE;
	}
};

CHelloApp theApp;