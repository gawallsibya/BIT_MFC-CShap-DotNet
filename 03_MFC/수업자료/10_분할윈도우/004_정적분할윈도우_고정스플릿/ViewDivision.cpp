// ViewDivision.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "�������ø�.h"
#include "ViewDivision.h"


// ViewDivision

IMPLEMENT_DYNCREATE(ViewDivision, CView)

ViewDivision::ViewDivision()
{

}

ViewDivision::~ViewDivision()
{
}

BEGIN_MESSAGE_MAP(ViewDivision, CView)
END_MESSAGE_MAP()


// ViewDivision �׸����Դϴ�.

void ViewDivision::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// ViewDivision �����Դϴ�.

#ifdef _DEBUG
void ViewDivision::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void ViewDivision::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// ViewDivision �޽��� ó�����Դϴ�.
