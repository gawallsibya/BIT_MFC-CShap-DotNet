
// 0325View.cpp : CMy0325View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CMy0325View ����/�Ҹ�

CMy0325View::CMy0325View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy0325View::~CMy0325View()
{
}

BOOL CMy0325View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy0325View �׸���

void CMy0325View::OnDraw(CDC* pDC)
{
	CMy0325Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	for(int i=0; i< pDoc->m_rect.GetSize(); i++)
	{
		CPoint pt = pDoc->m_rect[i];
		pDC->Rectangle(pt.x, pt.y, pt.x+50, pt.y+50);
	}	
}


// CMy0325View ����

#ifdef _DEBUG
void CMy0325View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0325View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0325Doc* CMy0325View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0325Doc)));
	return (CMy0325Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0325View �޽��� ó����


void CMy0325View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC  dc(this);
	dc.Rectangle(point.x, point.y, point.x+50, point.y+50);

	CMy0325Doc *pDoc = GetDocument();
	pDoc->m_rect.Add(point);

	CView::OnLButtonDown(nFlags, point);
}

void CMy0325View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMy0325App *pApp = (CMy0325App*)AfxGetApp();
	pApp->App_foo(10,20);

	CView::OnRButtonDown(nFlags, point);
}
