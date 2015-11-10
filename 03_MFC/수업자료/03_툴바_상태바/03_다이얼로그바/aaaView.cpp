// aaaView.cpp : implementation of the CAaaView class
//

#include "stdafx.h"
#include "aaa.h"

#include "aaaDoc.h"
#include "aaaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAaaView

IMPLEMENT_DYNCREATE(CAaaView, CView)

BEGIN_MESSAGE_MAP(CAaaView, CView)
	//{{AFX_MSG_MAP(CAaaView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAaaView construction/destruction

CAaaView::CAaaView()
{
	// TODO: add construction code here

}

CAaaView::~CAaaView()
{
}

BOOL CAaaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAaaView drawing

void CAaaView::OnDraw(CDC* pDC)
{
	CAaaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAaaView printing

BOOL CAaaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAaaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAaaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAaaView diagnostics

#ifdef _DEBUG
void CAaaView::AssertValid() const
{
	CView::AssertValid();
}

void CAaaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAaaDoc* CAaaView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAaaDoc)));
	return (CAaaDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAaaView message handlers
