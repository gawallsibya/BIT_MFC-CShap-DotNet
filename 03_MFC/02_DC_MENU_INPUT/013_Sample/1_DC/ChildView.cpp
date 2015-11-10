// ChildView.cpp

#include "ChildView.h"

BEGIN_MESSAGE_MAP(CChildView, CWnd)

ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()

END_MESSAGE_MAP()

//////////////////////////////////////////////////
CChildView::CChildView()
{
}
CChildView::~CChildView()
{
}
/////////////////////////////////////////////////
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if ( ! CWnd::PreCreateWindow( cs ) )
		return FALSE;

	return TRUE;
}
//////////////////////////////////////////////////
//#########################################################################

// ���鿩���� �׸��� �Լ��� ������ Ŭ������ ����ִٸ� ������尡 ũ��.

// ������ �θ�Ŭ������ CDC�� �Լ��� �ְ� CClientDC�� CWindowDC�� ������ش�.

/*
class CDC // ��� �׸��� �Լ��� DC�� �Ӽ��� �ٲٴ� �Լ� ����.
{
	public:

        HDC m_hDC;
        HWND m_hWnd;

        void Rectangle( int x, int y, int xx, int yy )
        {
               ::Rectangle( m_hDC, x, y, xx, yy );
        }
        // �׿��� ���鿩���� �׸��� �Լ���..
}

// CWindowDC�� ���� ���
class CWindowDC : public CDC
{
     CWindowDC( CWnd* pWnd )
     {   
		m_hWnd = pWnd->m_hWnd;
		m_hDC = GetWindowDC( m_hWnd ); // ĸ�ǹٿ� �׸��� �ַ� ���.
     }

     ~CWindowDC()
	 {
         ReleaseDC( m_hWnd, m_hDC );
     }
};


// CClientDC�� �������
class _CClientDC : public CDC
{
public:
	_CClientDC( CWnd* pWnd )
	{
		m_hWnd = pWnd->m_hWnd;
		m_hDC = ::GetDC(m_hWnd);
	}
	~_CClientDC( ) 
	{ 
		::ReleaseDC( m_hWnd, m_hDC);
	}
};


*/

// Message Handler
void CChildView::OnLButtonDown( UINT nFlags, CPoint point)
{
	// ���� �ð��� caption�� �����ϱ�.
	static BOOL b = FALSE;
	b = !b;

	CWnd* pFrame = AfxGetMainWnd();

	if ( b )
		pFrame->ModifyStyle( WS_CAPTION, 0); // ������ style, ���� style
	else
		pFrame->ModifyStyle( 0, WS_CAPTION); //???  �ɱ� ?

	// style �ٲ۰�� �ݵ�� �ٽ� �����츦 �׸��� �ؾ� �Ѵ�.
	pFrame->SetWindowPos( 0,0,0,0,0, // zorder, x, y, w, h
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_DRAWFRAME);

	
	// caption bar�� �׸���.
	//CWindowDC dc( this); // view �� caption �� ����.

//	CWindowDC dc( AfxGetMainWnd() );
//	dc.TextOut( 0,0, "hello"); // caption bar�� �׷����� ?


/*	// Win32 Code�� ����� �׸��׸���.
	HDC hdc = ::GetDC( this->m_hWnd );
	::Rectangle( hdc, point.x, point.y,  point.x + 50, point.y + 50);
	::ReleaseDC( this->m_hWnd, hdc);
	*/
}

void CChildView::OnRButtonDown( UINT nFlags, CPoint point)
{
	// DC class �� ����Ҷ��� code
	CClientDC dc(this);
	dc.Rectangle( point.x, point.y, point.x+50, point.y+50);
}




