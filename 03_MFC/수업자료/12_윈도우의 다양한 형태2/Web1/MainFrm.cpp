// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Web.h"

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
	
	// Rebar에서의 Enter키는 Dialog와 같이 IDOK버튼을 누른것과
	// 동일하게 처리
	ON_BN_CLICKED( IDOK, OnNavigate )

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
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, 
		WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS ) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	// ToolBar에 ImageList연결하기.
	CToolBarCtrl& t = m_wndToolBar.GetToolBarCtrl();

	CImageList img;
	
	img.Create( IDB_BITMAP1, 16, 1, RGB(255,255,255));
	t.SetImageList( &img ); // 흑백
	img.Detach();

	img.Create( IDB_BITMAP2, 16, 1, RGB(255,255,255));
	t.SetHotImageList( &img); // color
	img.Detach();

	///////////////////////////////////////////////////




//////////////////////////////////////////////////////////
	// ComboBox 만들기.
	m_wndAddress.Create( WS_CHILD | WS_VISIBLE | WS_BORDER | 
					CBS_DROPDOWN,
				CRect(0,0,100,100), this, 1);

	// ReBar 만들기.
	m_wndRebar.Create( this );

	// Rebar에 ToolBar와 Combo를 붙인다.
	m_wndRebar.AddBar( & m_wndToolBar);
	m_wndRebar.AddBar( &m_wndAddress, "주소 : ");
//////////////////////////////////////////////////////////

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	// 상태바에 Progress을 넣는다.
	m_wndStatusBar.CreateProgress( 1, 100 );
	m_wndStatusBar.SetProgressPos( 50 );

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
#include "WebDoc.h"
#include "WebView.h"

void CMainFrame::OnNavigate()
{
	// View의 Pointer를 얻는다.
	CWebView* pView = (CWebView*)GetActiveView();

	// Combo의 주소 얻기.
	CString strURL;
	m_wndAddress.GetWindowText( strURL );

	pView->Navigate2( strURL, 0,0 );
}








