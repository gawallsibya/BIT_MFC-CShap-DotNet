// ChildView.cpp

#include "ChildView.h"
#include "resource.h"
BEGIN_MESSAGE_MAP(CChildView, CWnd)

ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_PAINT()

//ON_COMMAND(IDM_COLOR_RED, red)
// 메뉴의 범위 처리. 반드시 ID는 연속된 숫자로 define 되어야 한다.
// wizard 지원 안됌...
ON_COMMAND_RANGE( IDM_COLOR_RED, IDM_COLOR_BLACK, OnColor )

// POPUP 메뉴가 화면에 나타날때 처리하기(check 넣기)
ON_UPDATE_COMMAND_UI_RANGE( IDM_COLOR_RED, IDM_COLOR_BLACK, OnUpdate )
ON_COMMAND(ID_MENU_TEST, &CChildView::OnMenuTest)
ON_UPDATE_COMMAND_UI(ID_MENU_TEST, &CChildView::OnUpdateMenuTest)
END_MESSAGE_MAP()

//////////////////////////////////////////////////
CChildView::CChildView()
{
	m_color = RGB(0,0,0); // 검정으로 초기화.
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

// 무효화 영역이 나올때 호출되는 함수.
void CChildView::OnPaint()
{
	CPaintDC dc(this);

	CBrush brush(m_color);
	CBrush* pOld = dc.SelectObject( &brush ); // DC 의 brush 변경

	dc.Rectangle( 10,10, 100, 100);

	dc.SelectObject( pOld ); // DC 복구.
}









void CChildView::OnColor(UINT nID)
{ 
	switch( nID ) // 메뉴 ID
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
	// 화면을 다시 그리게 한다.-> WM_PAINT 발생 -> OnPaint()호출.
	InvalidateRect(0);
}




// 메뉴의 Update 명령에 대한 함수 모양
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateMenuTest(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(TRUE);
}
