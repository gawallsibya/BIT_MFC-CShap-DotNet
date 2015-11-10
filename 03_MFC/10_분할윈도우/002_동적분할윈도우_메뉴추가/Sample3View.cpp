// Sample3View.cpp : implementation of the CSample3View class
//

#include "stdafx.h"
#include "Sample3.h"

#include "Sample3Doc.h"
#include "Sample3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSample3View

IMPLEMENT_DYNCREATE(CSample3View, CView)

BEGIN_MESSAGE_MAP(CSample3View, CView)
	//{{AFX_MSG_MAP(CSample3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSample3View construction/destruction

CSample3View::CSample3View()
{
	// TODO: add construction code here

}

CSample3View::~CSample3View()
{
}

BOOL CSample3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSample3View drawing

void CSample3View::OnDraw(CDC* pDC)
{
	CSample3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSample3View printing

BOOL CSample3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSample3View diagnostics

#ifdef _DEBUG
void CSample3View::AssertValid() const
{
	CView::AssertValid();
}

void CSample3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample3Doc* CSample3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample3Doc)));
	return (CSample3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSample3View message handlers
