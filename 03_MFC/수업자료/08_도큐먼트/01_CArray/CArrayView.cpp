// CArrayView.cpp : implementation of the CCArrayView class
//

#include "stdafx.h"
#include "CArray.h"

#include "CArrayDoc.h"
#include "CArrayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCArrayView

IMPLEMENT_DYNCREATE(CCArrayView, CView)

BEGIN_MESSAGE_MAP(CCArrayView, CView)
	//{{AFX_MSG_MAP(CCArrayView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCArrayView construction/destruction

CCArrayView::CCArrayView()
{
	// TODO: add construction code here

}

CCArrayView::~CCArrayView()
{
}

BOOL CCArrayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCArrayView drawing

void CCArrayView::OnDraw(CDC* pDC)
{
	CCArrayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	int i;

	// 4. 좌표 획득후 그리기 
	for(i=0; i<pDoc->arr.GetSize(); i++)
	{
		rect.left	= pDoc->arr.GetAt(i).x;
		rect.top	= pDoc->arr.GetAt(i).y;
		rect.right	= pDoc->arr.GetAt(i).x + 30;
		rect.bottom = pDoc->arr.GetAt(i).y + 30;

		pDC->Rectangle(&rect);
	}
}



/////////////////////////////////////////////////////////////////////////////
// CCArrayView printing

BOOL CCArrayView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCArrayView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCArrayView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCArrayView diagnostics

#ifdef _DEBUG
void CCArrayView::AssertValid() const
{
	CView::AssertValid();
}

void CCArrayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCArrayDoc* CCArrayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCArrayDoc)));
	return (CCArrayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCArrayView message handlers

void CCArrayView::OnLButtonDown(UINT nFlags, CPoint point) 
{

	// Doc 객체 포인터  얻기 
	CCArrayDoc *pDoc = GetDocument();
	
	// 사각형 영역 객체 생성 
	CRect rect(point.x, point.y, point.x + 30, point.y + 30);

	// 3. CArray에 좌표 추가 
	pDoc->arr.Add(point);

	// 다시 그리기 
	InvalidateRect(&rect);
	
	CView::OnLButtonDown(nFlags, point);
}
