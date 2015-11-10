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

// 수백여개의 그리는 함수가 각각의 클래스에 들어있다면 오버헤드가 크다.

// 때문에 부모클래스인 CDC에 함수가 있고 CClientDC와 CWindowDC에 상속해준다.

/*
class CDC // 모든 그리는 함수와 DC의 속성을 바꾸는 함수 제공.
{
	public:

        HDC m_hDC;
        HWND m_hWnd;

        void Rectangle( int x, int y, int xx, int yy )
        {
               ::Rectangle( m_hDC, x, y, xx, yy );
        }
        // 그외의 수백여개의 그리는 함수들..
}

// CWindowDC의 실제 모양
class CWindowDC : public CDC
{
     CWindowDC( CWnd* pWnd )
     {   
		m_hWnd = pWnd->m_hWnd;
		m_hDC = GetWindowDC( m_hWnd ); // 캡션바에 그릴때 주로 사용.
     }

     ~CWindowDC()
	 {
         ReleaseDC( m_hWnd, m_hDC );
     }
};


// CClientDC의 실제모양
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
	// 실행 시간에 caption바 제거하기.
	static BOOL b = FALSE;
	b = !b;

	CWnd* pFrame = AfxGetMainWnd();

	if ( b )
		pFrame->ModifyStyle( WS_CAPTION, 0); // 제거할 style, 넣을 style
	else
		pFrame->ModifyStyle( 0, WS_CAPTION); //???  될까 ?

	// style 바꾼경우 반드시 다시 윈도우를 그리게 해야 한다.
	pFrame->SetWindowPos( 0,0,0,0,0, // zorder, x, y, w, h
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_DRAWFRAME);

	
	// caption bar에 그리기.
	//CWindowDC dc( this); // view 는 caption 이 없다.

//	CWindowDC dc( AfxGetMainWnd() );
//	dc.TextOut( 0,0, "hello"); // caption bar에 그려질까 ?


/*	// Win32 Code를 사용한 그림그리기.
	HDC hdc = ::GetDC( this->m_hWnd );
	::Rectangle( hdc, point.x, point.y,  point.x + 50, point.y + 50);
	::ReleaseDC( this->m_hWnd, hdc);
	*/
}

void CChildView::OnRButtonDown( UINT nFlags, CPoint point)
{
	// DC class 를 사용할때의 code
	CClientDC dc(this);
	dc.Rectangle( point.x, point.y, point.x+50, point.y+50);
}




