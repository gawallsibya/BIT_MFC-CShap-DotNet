// ProgressStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "ProgressStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar

CProgressStatusBar::CProgressStatusBar()
{
}

CProgressStatusBar::~CProgressStatusBar()
{
}


BEGIN_MESSAGE_MAP(CProgressStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CProgressStatusBar)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar message handlers

void CProgressStatusBar::CreateProgress(UINT nPane, //pane 위치
										int nWidth) // pane width
{
	m_nPane = nPane;
	// 먼저 원하는 Pane의 크기를 변경한다
	UINT id, style;
	int width;
	GetPaneInfo(nPane, id, style, width);
	SetPaneInfo(nPane, id, style, nWidth); // 넓이만 변경
	// 이제 해당 pane의 정확한 크기를 얻는다.
	CRect r;
	GetItemRect( nPane, &r);
	// 이제 해당 Pane에 자식윈도우로 Progress만든다.
	m_wndProgress.Create( WS_CHILD | WS_VISIBLE ,
			r, this, 99); // ID
	// 초기화.
	m_wndProgress.SetRange( 0, 100);
	m_wndProgress.SetPos( 0);
}
void CProgressStatusBar::SetProgressPos(int nPos)
{
	m_wndProgress.SetPos( nPos);
}
void CProgressStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);
	
	// 상태바의 구획 크기가 변하면 Progress도 다시 위치해야...
	if ( ::IsWindow( m_wndProgress.m_hWnd) ) // Progress만든경우
	{
		CRect r;
		GetItemRect( m_nPane, &r);
		m_wndProgress.MoveWindow(r);
	}	
}
