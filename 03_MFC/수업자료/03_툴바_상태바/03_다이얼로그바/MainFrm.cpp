// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "aaa.h"

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
	ON_COMMAND_EX(CG_ID_VIEW_MYDIALOGBAR, OnBarCheck)
	ON_UPDATE_COMMAND_UI(CG_ID_VIEW_MYDIALOGBAR, OnUpdateControlBarMenu)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_DIALOGBAR, OnViewDialogbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DIALOGBAR, OnUpdateViewDialogbar)
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO,OnComboChange)//<--추가

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

	// TODO: Add a menu item that will toggle the visibility of the
	// dialog bar named "My Dialog Bar":
	//   1. In ResourceView, open the menu resource that is used by
	//      the CMainFrame class
	//   2. Select the View submenu
	//   3. Double-click on the blank item at the bottom of the submenu
	//   4. Assign the new item an ID: CG_ID_VIEW_MYDIALOGBAR
	//   5. Assign the item a Caption: My Dialog Bar

	// TODO: Change the value of CG_ID_VIEW_MYDIALOGBAR to an appropriate value:
	//   1. Open the file resource.h
	// CG: The following block was inserted by the 'Dialog Bar' component
	{
		// Initialize dialog bar m_wndMyDialogBar
		if (!m_wndMyDialogBar.Create(this, CG_IDD_MYDIALOGBAR,
			CBRS_TOP | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_HIDE_INPLACE,
			CG_ID_VIEW_MYDIALOGBAR))
		{
			TRACE0("Failed to create dialog bar m_wndMyDialogBar\n");
			return -1;		// fail to create
		}

		m_wndMyDialogBar.EnableDocking(CBRS_ALIGN_ANY);
		EnableDocking(CBRS_ALIGN_ANY);
		DockControlBar(&m_wndMyDialogBar);
	}
	CComboBox *pWnd;
     pWnd=(CComboBox*)m_wndMyDialogBar.GetDlgItem(IDC_COMBO);
	pWnd->SetCurSel(0);
	
	
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

// 다이얼로그바 제어 -------------------------------------------------------
void CMainFrame::OnViewDialogbar() 
{
if(m_wndMyDialogBar.IsWindowVisible())
		ShowControlBar(&m_wndMyDialogBar,FALSE,FALSE);
	else
		ShowControlBar(&m_wndMyDialogBar,TRUE,FALSE);	
	
}

void CMainFrame::OnUpdateViewDialogbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_wndMyDialogBar.IsWindowVisible())
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);	

	
}
void CMainFrame::OnComboChange()
{
	CComboBox *pWnd;
     pWnd=(CComboBox*)m_wndMyDialogBar.GetDlgItem(IDC_COMBO);
	int num=pWnd->GetCurSel();
	CString message;
	pWnd->GetLBText(num,message);
	AfxMessageBox(message);

}
