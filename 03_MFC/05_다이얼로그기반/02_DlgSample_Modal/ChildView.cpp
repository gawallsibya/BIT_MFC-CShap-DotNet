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
	m_strText = "Dialog Sample";
	m_size = 720;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_COMMAND(IDM_SETTING_DIALOG, OnSettingDialog)
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
	
	CFont font;
	font.CreatePointFont( m_size, "�ü�ü"); // !!!!

	CFont* old = (CFont*)dc.SelectObject( &font );

	CRect r; GetClientRect( &r );
	dc.DrawText( m_strText, -1, r,
				DT_SINGLELINE | DT_CENTER | DT_VCENTER );

	dc.SelectObject( old );
}






#include "MyDialog.h"

void CChildView::OnSettingDialog() 
{
	// Dialog �� ��Ÿ���� ���� ������ ���.
	// �ַ� About Dialog ��Ÿ����...
//	CDialog dlg( IDD_DIALOG1 );
//	dlg.DoModal();

	// Dialog �� ��Ÿ���� �Ϲ����� ���.
	CMyDialog dlg;

	// dlg �� �ʱ�ȭ �Ѵ�.
	dlg.text = m_strText;
	
	if ( dlg.DoModal() == IDOK )
	{
		// Dialog�� ����� ���� ���´�.
		m_strText = dlg.text;

		InvalidateRect( 0 );
	}
}










