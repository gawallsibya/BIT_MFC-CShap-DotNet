// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Menu4.h"

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
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
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

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 그리는 메뉴 1단계 . 메뉴 Item 의 style변경
	CMenu* p = GetMenu();
	CMenu* pSubMenu = p->GetSubMenu(1); // edit popup 메뉴

	pSubMenu->ModifyMenu( ID_EDIT_UNDO, //기존 ID
					MF_BYCOMMAND | MF_OWNERDRAW,
					ID_EDIT_UNDO,  // 새로운 ID
					"aaa"); // 새로운 string

	//////////////////////////////////////////////////////////



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


void CMainFrame::OnMeasureItem(int nIDCtl, 
							   LPMEASUREITEMSTRUCT lp) 
{
	// 그리는 메뉴 항목의 크기를 알려준다.

	if ( lp->itemID == ID_EDIT_UNDO )
	{
		lp->itemWidth = 300;
		lp->itemHeight = 300;
	}
	CFrameWnd::OnMeasureItem(nIDCtl, lp);
}
void CMainFrame::OnDrawItem(int nIDCtl, 
							LPDRAWITEMSTRUCT lp) 
{
	// 원하는 메뉴 항목에 그림을 그린다.
	HDC hdc = lp->hDC; // 메뉴 DC 핸들.
	CDC* pDC = CDC::FromHandle( hdc ); // API의 핸들->MFC객체를 얻는다.

	CRect r = lp->rcItem;
	
	if ( lp->itemID == ID_EDIT_UNDO )
	{
		// 메뉴 선택 여부를 조사해서 선택 사각형을 그린다.
		int state = lp->itemState;

		COLORREF color;
		if ( state & ODS_SELECTED ) // 선택비트 조사.
		{
			color = GetSysColor( COLOR_HIGHLIGHT );
		}
		else
		{
			color = GetSysColor(COLOR_MENU);
		}
		CBrush brush(color); // 붓만들기.
		pDC->FillRect( r, &brush);  // 선택 사각형



		// 원하는 그림을 그린다.
		HICON hIcon = AfxGetApp()->LoadStandardIcon( IDI_QUESTION );
		
		pDC->DrawIcon( r.left, r.top, hIcon );

	}	
//	CFrameWnd::OnDrawItem(nIDCtl, lp);
}










