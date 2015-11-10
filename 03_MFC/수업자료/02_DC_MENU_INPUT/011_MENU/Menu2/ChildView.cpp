// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Menu2.h"
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
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_COMMAND(AFX_ID_PREVIEW_CLOSE, &CChildView::OnAfxIdPreviewClose)
	ON_COMMAND(ID_STATE_LOGIN, &CChildView::OnStateLogin)
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
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}
void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// main menu �� Pointer�� ��´�.
	CMenu* pMenu = AfxGetMainWnd()->GetMenu();  // ������� ?

	// Popup Menu �����ϱ�
	pMenu->DeleteMenu( 1, MF_BYPOSITION); 

	// Popup Menu�� ������ Menubar�� �ٽ� �׸���.
	AfxGetMainWnd()->DrawMenuBar();
}
// 14 page.. code..
void CChildView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CMenu* pMenu = AfxGetMainWnd()->GetMenu();

	CMenu* pSubMenu = pMenu->GetSubMenu( 1 );

//	pSubMenu->RemoveMenu( 1, MF_BYPOSITION);

//	pSubMenu->AppendMenu( MF_STRING, 
//							5000, "AAA"); // id, caption

	pSubMenu->ModifyMenu( ID_EDIT_COPY, MF_BYCOMMAND,
						ID_EDIT_COPY, // ���ο� ID
						"aaaaaa");

}

void CChildView::OnAfxIdPreviewClose()
{

}

BOOL g_state = FALSE;
void CChildView::OnStateLogin()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMenu* pMenu = AfxGetMainWnd()->GetMenu();
	CMenu* pSubMenu = pMenu->GetSubMenu( 4 );

	if( g_state )
	{
	pSubMenu->ModifyMenu( ID_STATE_LOGIN, MF_BYCOMMAND,
						ID_STATE_LOGIN, // ���ο� ID
						"�α���");
	g_state = FALSE;
	}
	else
	{
	pSubMenu->ModifyMenu( ID_STATE_LOGIN, MF_BYCOMMAND,
						ID_STATE_LOGIN, // ���ο� ID
						"�α׾ƿ�");
	g_state = TRUE;

	}
}
