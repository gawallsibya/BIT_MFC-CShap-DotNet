// TESView.cpp : implementation of the CTESView class
//

#include "stdafx.h"
#include "TES.h"

#include "TESDoc.h"
#include "TESView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTESView

IMPLEMENT_DYNCREATE(CTESView, CView)

BEGIN_MESSAGE_MAP(CTESView, CView)
	//{{AFX_MSG_MAP(CTESView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTESView construction/destruction

CTESView::CTESView()
{
	// TODO: add construction code here

}

CTESView::~CTESView()
{
}

BOOL CTESView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTESView drawing

void CTESView::OnDraw(CDC* pDC)
{
	CTESDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTESView printing

BOOL CTESView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTESView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTESView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTESView diagnostics

#ifdef _DEBUG
void CTESView::AssertValid() const
{
	CView::AssertValid();
}

void CTESView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTESDoc* CTESView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTESDoc)));
	return (CTESDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTESView message handlers
