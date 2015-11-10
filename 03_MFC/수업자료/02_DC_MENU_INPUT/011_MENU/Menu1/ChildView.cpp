// ChildView.cpp

#include "ChildView.h"
#include "resource.h"
BEGIN_MESSAGE_MAP(CChildView, CWnd)

ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_PAINT()

//ON_COMMAND(IDM_COLOR_RED, red)
// �޴��� ���� ó��. �ݵ�� ID�� ���ӵ� ���ڷ� define �Ǿ�� �Ѵ�.
// wizard ���� �ȉ�...
ON_COMMAND_RANGE( IDM_COLOR_RED, IDM_COLOR_BLACK, OnColor )

// POPUP �޴��� ȭ�鿡 ��Ÿ���� ó���ϱ�(check �ֱ�)
ON_UPDATE_COMMAND_UI_RANGE( IDM_COLOR_RED, IDM_COLOR_BLACK, OnUpdate )
ON_COMMAND(ID_MENU_TEST, &CChildView::OnMenuTest)
ON_UPDATE_COMMAND_UI(ID_MENU_TEST, &CChildView::OnUpdateMenuTest)
END_MESSAGE_MAP()

//////////////////////////////////////////////////
CChildView::CChildView()
{
	m_color = RGB(0,0,0); // �������� �ʱ�ȭ.
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
	MessageBox("LButton");
}
void CChildView::OnRButtonDown( UINT nFlags, CPoint point)
{
	MessageBox("RButton");
}

// ��ȿȭ ������ ���ö� ȣ��Ǵ� �Լ�.
void CChildView::OnPaint()
{
	CPaintDC dc(this);

	CBrush brush(m_color);
	CBrush* pOld = dc.SelectObject( &brush ); // DC �� brush ����

	dc.Rectangle( 10,10, 100, 100);

	dc.SelectObject( pOld ); // DC ����.
}









void CChildView::OnColor(UINT nID)
{ 
	switch( nID ) // �޴� ID
	{
	case IDM_COLOR_RED:
		m_color = RGB(255,0,0);
		break;
	case IDM_COLOR_GREEN:
		m_color = RGB(0,255,0);
		break;
	case IDM_COLOR_BLUE:
		m_color = RGB(0,0,255);
		break;
	case IDM_COLOR_BLACK:
		m_color = RGB(0,0,0);
		break;
	}
	// ȭ���� �ٽ� �׸��� �Ѵ�.-> WM_PAINT �߻� -> OnPaint()ȣ��.
	InvalidateRect(0);
}




// �޴��� Update ��ɿ� ���� �Լ� ���
void CChildView::OnUpdate(CCmdUI *pCmdUI)
{
	switch( pCmdUI->m_nID )
	{
	case IDM_COLOR_RED:
		pCmdUI->SetCheck( m_color == RGB(255,0,0)); // ?
		break;

	case IDM_COLOR_GREEN:
		pCmdUI->SetCheck( m_color == RGB(0,255,0)); // ?
		break;

	case IDM_COLOR_BLUE:
		pCmdUI->SetCheck( m_color == RGB(0,0,255)); // ?
		break;

	case IDM_COLOR_BLACK:
		pCmdUI->SetCheck( m_color == RGB(0,0,0)); // ?
		break;
	}
}


void CChildView::OnMenuTest()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CChildView::OnUpdateMenuTest(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(TRUE);
}
