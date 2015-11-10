// ChildView.cpp : implementation of the CChildView class
//
#include "stdafx.h"
#include "DlgSample.h"
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
	m_color = 0;
	m_size.cx = 100;
	m_size.cy = 100;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_COMMAND(IDM_COLOR_RED, OnColorRed)
	ON_COMMAND(IDM_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(IDM_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(IDM_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(IDM_SIZE_BIG, OnSizeBig)
	ON_COMMAND(IDM_SIZE_NORMAL, OnSizeNormal)
	ON_COMMAND(IDM_SIZE_SMALL, OnSizeSmall)
	ON_COMMAND(IDM_COLOR_SETTING, OnColorSetting)
	ON_COMMAND(IDM_COLOR_OTHER, OnColorOther)
	ON_UPDATE_COMMAND_UI(IDM_COLOR_BLACK, OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(IDM_COLOR_BLUE, OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(IDM_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(IDM_COLOR_RED, OnUpdateColorRed)
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
	
	COLORREF color;
	switch( m_color )
	{
	case 0:	color = RGB(0,0,0); break;
	case 1:	color = RGB(255,0,0); break;
	case 2:	color = RGB(0,255,0); break;
	case 3:	color = RGB(0,0,255); break;
	case 4: color = m_useColor; break;
	}
	CBrush brush(color);
	CBrush* old = dc.SelectObject(&brush);

	CRect r( 10, 10,   10 + m_size.cx, 10 + m_size.cy);

	dc.Rectangle( r );
	dc.SelectObject(old);
		
}
void CChildView::OnColorRed() 
{
	m_color = 1;
	InvalidateRect( 0);
}
void CChildView::OnColorBlue() 
{
	m_color = 3;
	InvalidateRect( 0);
}
void CChildView::OnColorGreen() 
{
	m_color = 2;
	InvalidateRect( 0);
}
void CChildView::OnColorBlack() 
{
	m_color = 0;
	InvalidateRect( 0);
}

void CChildView::OnSizeBig() 
{
	m_size.cx = 200;
	m_size.cy = 200;
	InvalidateRect(0);	
}
void CChildView::OnSizeNormal() 
{
	m_size.cx = 100;
	m_size.cy = 100;
	InvalidateRect(0);
}
void CChildView::OnSizeSmall() 
{
	m_size.cx = 50;
	m_size.cy = 50;
	InvalidateRect(0);	
}
#include "MyDialog.h"

void CChildView::OnColorSetting() 
{
	// Dialog Box를 나타낸다.	
	CMyDialog dlg;

	// 먼저 view 멤버의 값을 dlg의 멤버로 
	dlg.m_cx = m_size.cx;
	dlg.m_cy = m_size.cy;
	dlg.m_color = m_color;

	if ( dlg.DoModal() == IDOK )
	{
		m_size.cx = dlg.m_cx;
		m_size.cy = dlg.m_cy;
		m_color = dlg.m_color;

		InvalidateRect(0); // 무효화 발생 -> 다시 그린다.
	}
}

// 실행해 보세요.
void CChildView::OnColorOther() 
{
	// 색상 Dialog 나타내기.
	CColorDialog dlg;
	if ( dlg.DoModal() == IDOK )
	{
		m_useColor = dlg.GetColor();
		m_color = 4;
		InvalidateRect( 0);
	}
}

void CChildView::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_color == 0);	
}
void CChildView::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_color == 3);	
}
void CChildView::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_color == 2);	
}
void CChildView::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck( m_color == 1);	
}










