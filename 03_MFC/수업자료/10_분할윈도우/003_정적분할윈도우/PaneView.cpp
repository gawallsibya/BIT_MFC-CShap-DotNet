// PaneView.cpp : implementation file
//

#include "stdafx.h"
#include "Sample.h"
#include "PaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaneView

IMPLEMENT_DYNCREATE(CPaneView, CView)

CPaneView::CPaneView()
{
}

CPaneView::~CPaneView()
{
}


BEGIN_MESSAGE_MAP(CPaneView, CView)
	//{{AFX_MSG_MAP(CPaneView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaneView drawing


/////////////////////////////////////////////////////////////////////////////
// CPaneView diagnostics

#ifdef _DEBUG
void CPaneView::AssertValid() const
{
	CView::AssertValid();
}

void CPaneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaneView message handlers

CSampleDoc* CPaneView::GetDocument()
{
	return (CSampleDoc*)m_pDocument;
}


void CPaneView::OnDraw(CDC* pDC)
{
	// View를 새롭게 만들경우 GetDocument()를 다시 만들어 주는게 
	// 좋다.
	CSampleDoc* pDoc = GetDocument();
	
	// Doc의 list내용을 2배 확대해서 그린다.
	POSITION pos = pDoc->m_list.GetHeadPosition();

	CPen pen(PS_SOLID, 25, RGB(255, 0,0));

	CPen* old = pDC->SelectObject( &pen ); // 수정.

	while ( pos )
	{
		Line* pLine = pDoc->m_list.GetNext(pos);

		pDC->MoveTo( pLine->ptFrom.x * 2, pLine->ptFrom.y*2);
		pDC->LineTo( pLine->ptTo.x * 2, pLine->ptTo.y *2);
	}
	pDC->SelectObject( old );

}