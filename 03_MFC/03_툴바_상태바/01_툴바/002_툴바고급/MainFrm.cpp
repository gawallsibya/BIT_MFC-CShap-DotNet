// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Sample.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
	
	// ToolBar에서 화살표 버튼을 누를때 처리하기.
	ON_NOTIFY( TBN_DROPDOWN, AFX_IDW_TOOLBAR, OnDrop)

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

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	
	// ToolBar의 고급기법 -> ToolBar가 내부적으로 가지고 있는
	// CToolBarCtrl의 멤버 함수 사용.
	CToolBarCtrl& tbc = m_wndToolBar.GetToolBarCtrl();

	// 단계 1. ToolBarCtrl style 변경.
	tbc.SetExtendedStyle( TBSTYLE_EX_DRAWDDARROWS );

	// 단계 2. 원하는 버튼에 화살표 넣기. ID->index
	int index = m_wndToolBar.CommandToIndex( ID_EDIT_CUT );

	UINT style = m_wndToolBar.GetButtonStyle( index );
	
	style = style | TBSTYLE_DROPDOWN;
	
	m_wndToolBar.SetButtonStyle( index , style );

	///////////////////////////////////////////////////


	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
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

// ToolBar에서 TBN_DROPDOWN이 올때.
// 메시지 핸들러 수동 등록
void CMainFrame::OnDrop(NMTOOLBAR *p, LRESULT *ret)
{
	// 현재 버튼의 정확한 크기(위치)를 얻어 온다.
	CRect r;
	m_wndToolBar.SendMessage( TB_GETRECT, p->iItem, // 버튼 ID
							(LPARAM)&r);
	m_wndToolBar.ClientToScreen( &r);

	// Context 메뉴를 버튼 아래 나타낸다.
	CMenu menu;
	menu.LoadMenu( IDR_MAINFRAME );

	CMenu* pSub = menu.GetSubMenu( 1);

	pSub->TrackPopupMenu( TPM_LEFTBUTTON, r.left, r.bottom,
					this);
}






