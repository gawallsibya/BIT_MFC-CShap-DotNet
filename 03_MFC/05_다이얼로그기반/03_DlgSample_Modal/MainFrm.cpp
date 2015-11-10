// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DlgSample.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_wndView.Create(0,0, AFX_WS_DEFAULT_VIEW, 
		CRect(0,0,0,0), this, AFX_IDW_PANE_FIRST, 0);

	///////////////////////////////////////////////////////
//	m_wndToolBar.Create( this ); // 볼록 toolbar 만들기.
//	CToolBar m_wndToolBar;

	m_wndToolBar.CreateEx( this, 
		TBSTYLE_FLAT , // 툴바 style
		WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER );
			// 윈도우 style | control bar style

	m_wndToolBar.LoadToolBar( IDR_TOOLBAR1 );

	////////////////////////////////////////////////
	// Text 넣기.
	m_wndToolBar.SetButtonText(0, "검정색");
	m_wndToolBar.SetButtonText(1, "빨간색");
	m_wndToolBar.SetButtonText(2, "녹색");
	m_wndToolBar.SetButtonText(3, "파란색");

	m_wndToolBar.SetButtonText(5, "...");
	
	// Text를 넣은 경우는 반드시 버튼의 크기를 바꾸어야 한다.
	m_wndToolBar.SetSizes( CSize( 48, 40 ), // 버튼 크기
							CSize( 16,15) ); // 이미지 크기.



	///////////////////////////////////////////////////
	// Docking 가능 Toolbar로...

	EnableDocking( CBRS_ALIGN_ANY); // Frame을 Docking 가능하게
	m_wndToolBar.EnableDocking( CBRS_ALIGN_ANY ); // Toolbar
	DockControlBar( &m_wndToolBar ); // Frame에 Toolbar을 붙이기.

	return 0;
}












