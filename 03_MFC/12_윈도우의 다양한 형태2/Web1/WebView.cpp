// WebView.cpp : implementation of the CWebView class
//

#include "stdafx.h"
#include "Web.h"

#include "WebDoc.h"
#include "WebView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebView

IMPLEMENT_DYNCREATE(CWebView, CHtmlView)

BEGIN_MESSAGE_MAP(CWebView, CHtmlView)
	//{{AFX_MSG_MAP(CWebView)
	ON_COMMAND(ID_GO_BACK, OnGoBack)
	ON_COMMAND(ID_GO_FORWARD, OnGoForward)
	ON_COMMAND(ID_GO_HOME, OnGoHome)
	ON_COMMAND(ID_GO_REFRESH, OnGoRefresh)
	ON_COMMAND(ID_GO_STOP, OnGoStop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebView construction/destruction

CWebView::CWebView()
{
	// TODO: add construction code here

}

CWebView::~CWebView()
{
}

BOOL CWebView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWebView drawing

void CWebView::OnDraw(CDC* pDC)
{
	CWebDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CWebView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	GoHome();
}

/////////////////////////////////////////////////////////////////////////////
// CWebView printing


/////////////////////////////////////////////////////////////////////////////
// CWebView diagnostics

#ifdef _DEBUG
void CWebView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CWebDoc* CWebView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebDoc)));
	return (CWebDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebView message handlers

void CWebView::OnTitleChange(LPCTSTR lpszText) 
{
	AfxGetMainWnd()->SetWindowText( lpszText );


	CHtmlView::OnTitleChange(lpszText);
}

void CWebView::OnGoBack() 
{
	GoBack();	
}
void CWebView::OnGoForward() 
{
	GoForward();
}
void CWebView::OnGoHome() 
{
	GoHome();
}
void CWebView::OnGoRefresh() 
{
	Refresh();
}
void CWebView::OnGoStop() 
{
	Stop();
}

#include "MainFrm.h"

void CWebView::OnProgressChange(long nProgress, long nProgressMax) 
{
	if ( nProgress == -1 || 
		nProgress == 0 || 
		nProgressMax ==0 ) // 완료된 경우.
		return ;

	// 상태바에 접근하려면 Frame을 알아야.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	int pos = (nProgress / nProgressMax) * 100;

	// m_wndStatusBar를 public으로 옮기 세요.
	pFrame->m_wndStatusBar.SetProgressPos( pos );	
	
	TRACE2("%d, %d\n", nProgress, nProgressMax); 

	CHtmlView::OnProgressChange(nProgress, nProgressMax);
}







