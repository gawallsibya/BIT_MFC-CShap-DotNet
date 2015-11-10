// �Ϲ������� CFrameWnd�� ���� ������� �ʰ� �ű⼭ 
// ��µ� class ����� ����Ѵ�.

// ���� PreCreateWindow()�� ������ �ϸ� �����Ǵ� �������� Ŭ����,
// �� style ���� �����Ҽ� �ִ�.
// AfxGetApp()�� �ϴ����� ?
// ���� �޸𸮿��� ����ڰ� ���� ��ü�� � ������?, 
// ���� ��� ������ ?


#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs )
	{
		if ( !CFrameWnd::PreCreateWindow( cs ) )
			return FALSE;

		cs.style = cs.style & ~WS_MAXIMIZEBOX;

		cs.lpszClass = AfxRegisterWndClass( 0, AfxGetApp()->LoadStandardCursor(IDC_ARROW),
							(HBRUSH)GetStockObject(LTGRAY_BRUSH), 
							AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

		return TRUE;
	}
};

class CHelloApp : public CWinApp 
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;

		pFrame->Create(0, "Hello, MFC");
		pFrame->ShowWindow( SW_SHOW );
		pFrame->UpdateWindow( );
		
		m_pMainWnd = pFrame;

		return TRUE;
	}
};

CHelloApp theApp;