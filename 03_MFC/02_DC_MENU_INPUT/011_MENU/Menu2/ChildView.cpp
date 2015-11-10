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
	// main menu 의 Pointer을 얻는다.
	CMenu* pMenu = AfxGetMainWnd()->GetMenu();  // 맞을까요 ?

	// Popup Menu 제거하기
	pMenu->DeleteMenu( 1, MF_BYPOSITION); 

	// Popup Menu를 지운경우 Menubar를 다시 그린다.
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
						ID_EDIT_COPY, // 새로운 ID
						"aaaaaa");
}










