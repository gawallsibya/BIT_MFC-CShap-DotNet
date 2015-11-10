// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "�׸����ư.h"
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
	// ���ϴ� �׸��� �׸���.
	CDC* pDC = CDC::FromHandle( lp->hDC );
	CRect r( lp->rcItem );

	CBrush brush( RGB(255,255,255));
	pDC->Rectangle( r );

	if ( m_bOver == TRUE )
		pDC->Draw3dRect( r, RGB(255,255,255), RGB(0,0,0));
}
void CMyButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���콺�� ��ư�� ���� ���°��� ���� �ϱ� ���� ���콺 ĸ��
	if ( GetCapture() != this )
	{
		m_bOver = TRUE;
		SetCapture();
		InvalidateRect( 0 );// ��ȿȭ �߻� -> ȭ���� �ٽ� �׸���.
	}
	else // ���콺�� ĸ�� ��.
	{
		CRect r; GetClientRect( &r);
		
		if ( r.PtInRect( point ) == FALSE) // ������.
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







