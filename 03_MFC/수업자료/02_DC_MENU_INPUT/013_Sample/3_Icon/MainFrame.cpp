// MainFrame.cpp
#include "MainFrame.h"
#include "resource.h" // ���ҽ����� ���� ID �� ����ϱ� ���� �ʿ�

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

ON_WM_CREATE()
ON_WM_SETFOCUS()

ON_WM_SETCURSOR() // ���콺�� �����϶�
					// Ŀ���� �����ϱ� ���� ���´�.

END_MESSAGE_MAP()

/////////////////////////////////////////////
CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}
///////////////////////////////////////////////
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if ( ! CFrameWnd::PreCreateWindow( cs ) )
		return FALSE;

	// icon �� �����ϱ�����. ���ο� class �� ����� ����Ѵ�.
	cs.lpszClass = AfxRegisterWndClass( 0, // class style
					0, // cursor -> View���� ����.
			(HBRUSH)(COLOR_WINDOW+1), // ���� -> View���� ����
					AfxGetApp()->LoadIcon( IDI_MYICON ));

	return TRUE;
}
//////////////////////////////////////
int CMainFrame::OnCreate( LPCREATESTRUCT lpc)
{
	if ( CFrameWnd::OnCreate(lpc ) == -1 ) 
		return -1;

	// View �����.
	m_wndView.CreateEx( 0, 0, 0, AFX_WS_DEFAULT_VIEW, 
		CRect(0,0,0,0), this, AFX_IDW_PANE_FIRST);

	return 0;
}
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// Frame �� Focus�� ������ View���� �����Ѵ�.
	m_wndView.SetFocus();
}

// Ŀ���� �����ϱ� ���� ������ �޼���.
BOOL CMainFrame::OnSetCursor(CWnd *pWnd, // Ŀ�� �Ʒ� �ִ� ������
							 UINT nHit, // hit Test code
							 UINT msg)
{
	if ( nHit == HTCAPTION ) // hit test code -> ���� Ŀ���� ��ġ
	{
		//SetCursor( AfxGetApp()->LoadCursor(IDC_CURSOR1) );

		// Animation Cursor ����ϱ�. API �Լ�.
		HCURSOR h = LoadCursorFromFile("C:\\winnt\\cursors\\banana.ani");
		SetCursor( h );
		return TRUE; // Ŀ���� �ٲ۰��.
	}
	// Ŀ���� �ٲ��� ���� ���� �ݵ�� �θ𿡰� ������.
	// �׷��� �θ� default ������ �ٲپ� �ش�.
	return CFrameWnd::OnSetCursor(pWnd, nHit, msg );
}










