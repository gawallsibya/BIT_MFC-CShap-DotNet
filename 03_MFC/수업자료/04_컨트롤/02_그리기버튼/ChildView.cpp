// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "그리기버튼.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_MEASUREITEM()
//	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}

#define IDC_BUTTON 1

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_btn.Create( "Push", 
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_OWNERDRAW,
		CRect(10,10,100,100), this, IDC_BUTTON );
	
	return 0;
}












void CChildView::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// 메뉴나 listbox 에서는 많이 사용. 하지만 button을 별로
	// 처리하지 않는다.
}
// 버튼에 그림을 그린다.
void CChildView::OnDrawItem(int nIDCtl, 
							LPDRAWITEMSTRUCT lp) 
{
	HDC hdc = lp->hDC;
	
	CDC* pDC = CDC::FromHandle( hdc ); /// !!!!

	pDC->Ellipse( &(lp->rcItem) );

}













