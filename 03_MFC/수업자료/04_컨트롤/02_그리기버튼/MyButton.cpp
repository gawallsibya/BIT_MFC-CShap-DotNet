// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "그리기버튼.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

void CMyButton::DrawItem(LPDRAWITEMSTRUCT lp) 
{
	// 원하는 그림을 그린다.
	CDC* pDC = CDC::FromHandle( lp->hDC );
	CRect r( lp->rcItem );

	CBrush brush( RGB(255,255,255));
	pDC->Rectangle( r );

	if ( m_bOver == TRUE )
		pDC->Draw3dRect( r, RGB(255,255,255), RGB(0,0,0));
}
void CMyButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 마우스가 버튼을 벗어 나는것을 감지 하기 위해 마우스 캡쳐
	if ( GetCapture() != this )
	{
		m_bOver = TRUE;
		SetCapture();
		InvalidateRect( 0 );// 무효화 발생 -> 화면을 다시 그린다.
	}
	else // 마우스가 캡쳐 중.
	{
		CRect r; GetClientRect( &r);
		
		if ( r.PtInRect( point ) == FALSE) // 벗어난경우.
		{
			ReleaseCapture();
			m_bOver = FALSE;
			InvalidateRect(0);
		}
	}
}

void CMyButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);

	CRect r; GetClientRect( &r);
	dc.Draw3dRect( r, RGB(0,0,0), RGB(255,255,255));
}

void CMyButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	InvalidateRect(0);
}







