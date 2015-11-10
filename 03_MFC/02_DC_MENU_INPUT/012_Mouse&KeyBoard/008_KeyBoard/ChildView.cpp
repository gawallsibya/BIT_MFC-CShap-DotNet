// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "KeyBoard.h"
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
	pCaret.x = 0;
	pCaret.y = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
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

void CChildView::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd ::OnSetFocus(pOldWnd);
	
	// ĳ���� ���� �Ѵ�.(12page)
	CreateSolidCaret(10, 20);

	SetCaretPos( pCaret );
	
	ShowCaret();
}
void CChildView::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd ::OnKillFocus(pNewWnd);
	
	// Caret ����.
	HideCaret();
	DestroyCaret();
}




int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// system FONT( �������� Font�� �ʺ�� ���̸� ��´�.)
	CClientDC dc(this);
	
	// ���� DC�� OS�� �������� ��Ʈ�� �ִ´�.
	CFont* old = (CFont*)dc.SelectStockObject( SYSTEM_FIXED_FONT );

	TEXTMETRIC tm;
	dc.GetTextMetrics( &tm );

	cxChar = tm.tmAveCharWidth;
	cyChar = tm.tmHeight;

	dc.SelectObject( old );
	
	return 0;
}








void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	switch( nChar ) // virtual key code
	{
	case VK_UP:
		pCaret.y = max( pCaret.y - cyChar, 0);
		break;
	
	case VK_DOWN:
		pCaret.y = pCaret.y + cyChar;
		break;
	case VK_LEFT:
		pCaret.x = max( pCaret.x - cxChar, 0);
		break;
	case VK_RIGHT:
		pCaret.x = pCaret.x + cxChar;
		break;
	}
	SetCaretPos( pCaret );
}

void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if ( nChar == VK_RETURN ) //return Ű
	{
		pCaret.y += cyChar;
		pCaret.x = 0;
		SetCaretPos( pCaret );
		return ;
	}
	CClientDC dc(this);
	CFont* old = (CFont*)dc.SelectStockObject( SYSTEM_FIXED_FONT );

	// ������� caret ���߱�.
	HideCaret();

	char msg[] = { nChar }; // 1���� ���ڸ� ���ڿ��� �ٲٱ�.
	dc.TextOut( pCaret.x, pCaret.y, msg, 1);

	pCaret.x += cxChar;
	SetCaretPos( pCaret );

	ShowCaret(); // ����� �ٽ� Caret�� ���� �ش�.

	dc.SelectObject( old); // dc ����.
}






void CChildView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// Caret�� ��ġ�� �̵��Ѵ�....
	pCaret.x = ( point.x / cxChar ) * cxChar;
	pCaret.y = ( point.y / cyChar ) * cyChar;

	SetCaretPos( pCaret );
}
// �ԷµǴ� ��� ���ڴ� buffer�� ������ WM_PAINT���� �ٽ� ��µǾ��
// �մϴ�..- �ָ��� �غ�����..!!
















