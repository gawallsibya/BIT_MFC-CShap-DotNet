// NamView.cpp : implementation of the CNamView class
//

#include "stdafx.h"
#include "Nam.h"

#include "NamDoc.h"
#include "NamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNamView

IMPLEMENT_DYNCREATE(CNamView, CView)

BEGIN_MESSAGE_MAP(CNamView, CView)
	//{{AFX_MSG_MAP(CNamView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamView construction/destruction

CNamView::CNamView()
{
	// TODO: add construction code here

}

CNamView::~CNamView()
{
}

BOOL CNamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNamView drawing

void CNamView::OnDraw(CDC* pDC)
{
	CNamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// 글자 색 변경.
	pDC->SetTextColor( pDoc->m_color );

	CRect r; GetClientRect(&r);
	pDC->DrawText( pDoc->m_str, r,
		DT_SINGLELINE | DT_VCENTER | DT_CENTER);

}

/////////////////////////////////////////////////////////////////////////////
// CNamView printing

BOOL CNamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNamView diagnostics

#ifdef _DEBUG
void CNamView::AssertValid() const
{
	CView::AssertValid();
}

void CNamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamDoc* CNamView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamDoc)));
	return (CNamDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNamView message handlers
