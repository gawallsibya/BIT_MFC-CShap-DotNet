// AfxRegisterWndClass() �� ����ؼ� ������ class �����ϱ�...
// MFC�� ���������� ������Ŭ������ ���������, 
// ����ڰ� �ٽ� ����ؼ� ����Ҽ��� �ִ�.

#include <afxwin.h>

class CHelloApp : public CWinApp 
{
public:
	virtual BOOL InitInstance()
	{
		CFrameWnd* pFrame = new CFrameWnd;
		
		CString str = AfxRegisterWndClass( 0, LoadStandardCursor(IDC_IBEAM),
							(HBRUSH)GetStockObject(BLACK_BRUSH), 
							LoadStandardIcon(IDI_WINLOGO));

		pFrame->Create( str,  // ������ Ŭ����..
						"Hello, MFC", 
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