// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MultiLook.h"

#include "MainFrm.h"
#include "MultiLookDoc.h"
#include "MultiLookView.h"
#include "FontView.h"
#include "PaintView.h"

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
	ON_COMMAND(ID_FONT_VIEW, OnFontView)
	ON_UPDATE_COMMAND_UI(ID_FONT_VIEW, OnUpdateFontView)
	ON_COMMAND(ID_FORM_VIEW, OnFormView)
	ON_UPDATE_COMMAND_UI(ID_FORM_VIEW, OnUpdateFormView)
	ON_COMMAND(ID_PAINT_VIEW, OnPaintView)
	ON_UPDATE_COMMAND_UI(ID_PAINT_VIEW, OnUpdatePaintView)
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


void CMainFrame::SwitchView(ViewType nType)
{
	CView* pOldView = GetActiveView();
	CView* pNewView = (CView*)GetDlgItem(nType);

	if(pNewView == NULL)
	{
		switch(nType)
		{
		case FORMVIEW:
			pNewView = (CView*)new CMultiLookView;
			break;
		case FONTVIEW:
			pNewView = (CView*)new CFontView;
			break;
		case PAINTVIEW:
			pNewView = (CView*)new CPaintView;
			break;
		}

		CCreateContext context;
		context.m_pCurrentDoc = pOldView->GetDocument();
		pNewView->Create(NULL, NULL, WS_BORDER, 
			CFrameWnd::rectDefault, this, nType, &context);
		pNewView->OnInitialUpdate();
	}

	SetActiveView(pNewView);
	pNewView->ShowWindow(SW_SHOW);
	pOldView->ShowWindow(SW_HIDE);
	if(pOldView->GetRuntimeClass() == RUNTIME_CLASS(CMultiLookView))
		pOldView->SetDlgCtrlID(FORMVIEW);
	if(pOldView->GetRuntimeClass() == RUNTIME_CLASS(CFontView))
		pOldView->SetDlgCtrlID(FONTVIEW);
	if(pOldView->GetRuntimeClass() == RUNTIME_CLASS(CPaintView))
		pOldView->SetDlgCtrlID(PAINTVIEW);

	pNewView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
	
}

void CMainFrame::OnFormView() 
{
	SwitchView(FORMVIEW);	
}

void CMainFrame::OnUpdateFormView(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(
		GetActiveView()->IsKindOf(RUNTIME_CLASS(CMultiLookView)));
}

void CMainFrame::OnFontView() 
{
	SwitchView(FONTVIEW);	
}

void CMainFrame::OnUpdateFontView(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(
		GetActiveView()->IsKindOf(RUNTIME_CLASS(CFontView)));
}

void CMainFrame::OnPaintView() 
{
	SwitchView(PAINTVIEW);	
}

void CMainFrame::OnUpdatePaintView(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(
		GetActiveView()->IsKindOf(RUNTIME_CLASS(CPaintView)));
}
