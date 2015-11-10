// MySplitterWnd.cpp : implementation file
//

#include "stdafx.h"
#include "고정스플릿.h"
#include "MySplitterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySplitterWnd

IMPLEMENT_DYNCREATE(CMySplitterWnd, CSplitterWnd)

CMySplitterWnd::CMySplitterWnd()
{
}

CMySplitterWnd::~CMySplitterWnd()
{
}



BEGIN_MESSAGE_MAP(CMySplitterWnd, CSplitterWnd)
	//{{AFX_MSG_MAP(CMySplitterWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySplitterWnd message handlers

void CMySplitterWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 아무 일도 하지 않는다.
}

void CMySplitterWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 아무 일도 하지 않는다.
}
