// ChildView.cpp

#include "ChildView.h"

BEGIN_MESSAGE_MAP(CChildView, CWnd)

ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()

ON_WM_PAINT() // WM_PAINT �޼��� ó���ϱ�.

END_MESSAGE_MAP()

//////////////////////////////////////////////////
CChildView::CChildView()
{
	// Array �ʱ�ȭ.
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

	// DC�� GDI Object �����ϱ�.
	CPen pen( PS_SOLID, 5, RGB(255,0,0));

	// DC�� ����.
	CPen* old = dc.SelectObject( &pen );

	dc.Rectangle( point.x,      point.y, 
		          point.x + 50, point.y + 50);

	// dc�� �������� ���� �ݵ�� DC�� ���� Pen�� �������� �Ѵ�.
	// ������ Pen�� ������ �ȴ�.
	dc.SelectObject( old );

	// ��� ���� �ٽ� �׸��� ���� buffer�� �����Ѵ�.
	m_buf.Add( point );

}
void CChildView::OnRButtonDown( UINT nFlags, CPoint point)
{
	// ��ȿȭ ���� ����� ����.
	CRect r( 100,100,200,200 );

	InvalidateRect( 0, TRUE ); // 0 �� ������ ȭ�� ��ü..
}


void CChildView::OnPaint()
{
	// �׻� ������ �ϴ� ��¹��� ����Ѵ�.
	CPaintDC dc(this); // ���������� BeginPaint()ȣ��.

	CRect r;
	GetClientRect(&r); // client ������ ũ�⸦ ���Ѵ�.
	// �簢�� ������ ��� ����ϱ�.
	dc.DrawText( "hello", -1, &r, 
			DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	// m_buf�ִ� ��� ��ǥ�� �ٽ� �׸���.
	for (int i = 0; i < m_buf.GetSize(); i++)
		dc.Rectangle( m_buf[i].x,      m_buf[i].y,
					  m_buf[i].x + 50, m_buf[i].y + 50);
}














