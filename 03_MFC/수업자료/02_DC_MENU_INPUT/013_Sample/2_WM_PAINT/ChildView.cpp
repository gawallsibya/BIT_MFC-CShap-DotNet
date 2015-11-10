// ChildView.cpp

#include "ChildView.h"

BEGIN_MESSAGE_MAP(CChildView, CWnd)

ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()

ON_WM_PAINT() // WM_PAINT 메세지 처리하기.

END_MESSAGE_MAP()

//////////////////////////////////////////////////
CChildView::CChildView()
{
	// Array 초기화.
	m_buf.RemoveAll();
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
// Message Handler
void CChildView::OnLButtonDown( UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	// DC의 GDI Object 변경하기.
	CPen pen( PS_SOLID, 5, RGB(255,0,0));

	// DC에 선택.
	CPen* old = dc.SelectObject( &pen );

	dc.Rectangle( point.x,      point.y, 
		          point.x + 50, point.y + 50);

	// dc가 없어지기 전에 반드시 DC에 넣은 Pen을 선택해지 한다.
	// 이전의 Pen을 넣으면 된다.
	dc.SelectObject( old );

	// 모든 점을 다시 그리기 위해 buffer에 저장한다.
	m_buf.Add( point );

}
void CChildView::OnRButtonDown( UINT nFlags, CPoint point)
{
	// 무효화 영역 만들어 내기.
	CRect r( 100,100,200,200 );

	InvalidateRect( 0, TRUE ); // 0 은 윈도우 화면 전체..
}


void CChildView::OnPaint()
{
	// 항상 보여야 하는 출력물을 출력한다.
	CPaintDC dc(this); // 내부적으로 BeginPaint()호출.

	CRect r;
	GetClientRect(&r); // client 영역의 크기를 구한다.
	// 사각형 영역의 가운데 출력하기.
	dc.DrawText( "hello", -1, &r, 
			DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	// m_buf있는 모든 좌표를 다시 그린다.
	for (int i = 0; i < m_buf.GetSize(); i++)
		dc.Rectangle( m_buf[i].x,      m_buf[i].y,
					  m_buf[i].x + 50, m_buf[i].y + 50);
}














