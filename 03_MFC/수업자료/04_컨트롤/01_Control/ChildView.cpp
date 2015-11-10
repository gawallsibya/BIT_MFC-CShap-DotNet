// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Control.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// control ID
#define IDC_EDIT	1
#define IDC_BUTTON	2
#define IDC_LIST	3
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
	ON_WM_CREATE()
	//}}AFX_MSG_MAP

	// �ڽ� �����찡 ������ ���� ó���ϱ�.
	//ON_BN_CLICKED ( IDC_BUTTON, OnButton ) // ��ư�ϰ�� ����.

	ON_CONTROL ( BN_CLICKED, IDC_BUTTON, OnButton) // �Ϲ����� ǥ��.

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


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd ::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Control �� �����Ѵ�.
	m_edit.Create( 
		WS_CHILD | WS_VISIBLE | WS_BORDER | 
		ES_MULTILINE | WS_HSCROLL | WS_VSCROLL, 
					CRect(10,10, 100,100), this, IDC_EDIT);

	m_btn1.Create( "Push", 
			WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
			CRect(110,10,200,100), this, IDC_BUTTON);

	m_list.Create( WS_CHILD | WS_VISIBLE | WS_BORDER ,
			CRect(210,10,300,100), this, IDC_LIST);

	m_edit.SetMargins( 10, 10);

	return 0;
}

void CChildView::OnButton()
{
	// edit���� ������ ��´�.
	CString msg;
	m_edit.GetWindowText( msg );

	// list�� �ִ´�.
	m_list.AddString( msg);
	// SendMessage( m_list.m_hWnd, LB_ADDSTRING, 0, (LPARAM)&msg);

	// edit�� �����.
	m_edit.SetWindowText("");
}	










