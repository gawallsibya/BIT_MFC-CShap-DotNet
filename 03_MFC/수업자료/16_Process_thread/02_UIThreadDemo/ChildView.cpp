// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "UIThreadDemo.h"
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
	
	//�÷��� ���� ���� �ؽ�Ʈ�� ����Ѵ�.
	CString tmp = _T("");
	if(m_bMain)		tmp.Format("%s", "���� ������ ������");
	else			tmp.Format("%s", "����� �������̽� ������ ������");
	dc.TextOut(10, 10, tmp);
	//���� ������ ID ���� ����Ѵ�.
	tmp.Format("Current Thread ID : %d", ::GetCurrentThreadId());
	dc.TextOut(10, 30, tmp);
}


void CChildView::SetMainWnd(BOOL bFlag)
{
	m_bMain = bFlag;
}
