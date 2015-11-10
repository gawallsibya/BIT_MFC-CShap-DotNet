// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Image.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
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
//#include "ImageDoc.h" // view class 는 내부적으로 Doc헤더를 요구한다.
					  // 그래서 view헤더를 include할때는 doc도 같이 
					  // include 하는경우가 많다.
#include "LeftView.h"
#include "ImageView.h"

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// 1. 정적 splitter 만들기.
	m_wndSplitter.CreateStatic( this, 1,2 );

	// 2. View 만들기.
	m_wndSplitter.CreateView( 0, 0, RUNTIME_CLASS( CLeftView ),
						CSize(100,100), pContext);

	m_wndSplitter.CreateView( 0, 1, RUNTIME_CLASS( CImageView ),
						CSize(100,100), pContext);

	return TRUE;
}









BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// 원래의 기능은 ActiveView에게만 보낸다.
	// 이제 view가 2개이상이면 모든 View에게 보낼 필요가 있다.
	// Document는 모든 View를 알고 있다.
	CDocument* pDoc = GetActiveDocument();
	POSITION pos = pDoc->GetFirstViewPosition();//CList 와 동일

	while ( pos )
	{
		CView* pView = pDoc->GetNextView( pos );
		if ( pView->OnCmdMsg( nID, nCode, pExtra, pHandlerInfo ) )
			return TRUE;
	}
	////////////////////////////////////////////////////////	

	// 모든 View에 보낸 후에는 다시 부모에게 보내야 App까지 계속
	// 전달 될수 있다.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}







