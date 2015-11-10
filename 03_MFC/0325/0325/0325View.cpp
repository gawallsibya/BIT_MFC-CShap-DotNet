
// 0325View.cpp : CMy0325View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "0325.h"
#endif

#include "0325Doc.h"
#include "0325View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0325View

IMPLEMENT_DYNCREATE(CMy0325View, CView)

BEGIN_MESSAGE_MAP(CMy0325View, CView)

	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0325View 생성/소멸

CMy0325View::CMy0325View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy0325View::~CMy0325View()
{
}

BOOL CMy0325View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy0325View 그리기

void CMy0325View::OnDraw(CDC* pDC)
{
	CMy0325Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for(int i=0; i< pDoc->m_rect.GetSize(); i++)
	{
		CPoint pt = pDoc->m_rect[i];
		pDC->Rectangle(pt.x, pt.y, pt.x+50, pt.y+50);
	}	
}


// CMy0325View 진단

#ifdef _DEBUG
void CMy0325View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0325View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0325Doc* CMy0325View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0325Doc)));
	return (CMy0325Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0325View 메시지 처리기


void CMy0325View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC  dc(this);
	dc.Rectangle(point.x, point.y, point.x+50, point.y+50);

	CMy0325Doc *pDoc = GetDocument();
	pDoc->m_rect.Add(point);

	CView::OnLButtonDown(nFlags, point);
}

void CMy0325View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMy0325App *pApp = (CMy0325App*)AfxGetApp();
	pApp->App_foo(10,20);

	CView::OnRButtonDown(nFlags, point);
}
