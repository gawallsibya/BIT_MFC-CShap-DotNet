// ViewDivision.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "고정스플릿.h"
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


// ViewDivision 그리기입니다.

void ViewDivision::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// ViewDivision 진단입니다.

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


// ViewDivision 메시지 처리기입니다.
