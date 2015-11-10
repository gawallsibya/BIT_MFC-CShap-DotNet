// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TES.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}
#define IDC_COMBOBOX 100
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);



   m_wndToolBar.SetButtonInfo( 12, IDC_COMBOBOX, TBBS_SEPARATOR, 100);
   CRect rect;
   m_wndToolBar.GetItemRect(12, &rect);
   rect.bottom = rect.top + 600;
   m_wndComboBox.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL |
	CBS_SORT | CBS_DROPDOWNLIST, rect, (CWnd*)&m_wndToolBar, IDC_COMBOBOX);

   m_wndComboBox.AddString("빨간색");
   m_wndComboBox.AddString("녹  색");
   m_wndComboBox.AddString("파란색");

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

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




// 핸들러 구현 
BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if( LOWORD(wParam)  == IDC_COMBOBOX ) // ID 조사.
	{
		if( HIWORD(wParam) == CBN_SELCHANGE)
		{
			char temp[20];
			int n = m_wndComboBox.GetCurSel();
			m_wndComboBox.GetLBText(n, temp);

			AfxMessageBox(temp);
		}
	}

	return CFrameWnd::OnCommand(wParam, lParam);
}
