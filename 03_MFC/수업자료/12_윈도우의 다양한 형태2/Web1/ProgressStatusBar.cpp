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

void CProgressStatusBar::CreateProgress(UINT nPane, //pane ��ġ
										int nWidth) // pane width
{
	m_nPane = nPane;
	// ���� ���ϴ� Pane�� ũ�⸦ �����Ѵ�
	UINT id, style;
	int width;
	GetPaneInfo(nPane, id, style, width);
	SetPaneInfo(nPane, id, style, nWidth); // ���̸� ����
	// ���� �ش� pane�� ��Ȯ�� ũ�⸦ ��´�.
	CRect r;
	GetItemRect( nPane, &r);
	// ���� �ش� Pane�� �ڽ�������� Progress�����.
	m_wndProgress.Create( WS_CHILD | WS_VISIBLE ,
			r, this, 99); // ID
	// �ʱ�ȭ.
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
	
	// ���¹��� ��ȹ ũ�Ⱑ ���ϸ� Progress�� �ٽ� ��ġ�ؾ�...
	if ( ::IsWindow( m_wndProgress.m_hWnd) ) // Progress������
	{
		CRect r;
		GetItemRect( m_nPane, &r);
		m_wndProgress.MoveWindow(r);
	}	
}
