// ColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RGBdisplay.h"
#include "ColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorDlg dialog


CColorDlg::CColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorDlg)
	m_BlueVal = 0;
	m_GreenVal = 0;
	m_RedVal = 0;
	//}}AFX_DATA_INIT
}


void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorDlg)
	DDX_Control(pDX, IDC_SC_RED, m_Red);
	DDX_Control(pDX, IDC_SC_GREEN, m_Green);
	DDX_Control(pDX, IDC_SC_BLUE, m_Blue);
	DDX_Control(pDX, IDC_COLOR, m_controltable);
	DDX_Text(pDX, IDC_EDIT_BLUE_VAL, m_BlueVal);
	DDX_Text(pDX, IDC_EDIT_GREEN_VAL, m_GreenVal);
	DDX_Text(pDX, IDC_EDIT_RED_VAL, m_RedVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialog)
	//{{AFX_MSG_MAP(CColorDlg)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorDlg message handlers

void CColorDlg::SetColor()
{
	CClientDC dc(this);
	CRect rect;
	m_controltable.GetWindowRect(rect);
	ScreenToClient(&rect);
	CPen pen(PS_SOLID, 1, RGB(m_r, m_g, m_b));
	CPen *oldpen = dc.SelectObject(&pen);

	for(int i=0; i<=rect.Height(); i++)
	{
		dc.MoveTo(rect.left, rect.top+i);
		dc.LineTo(rect.right, rect.top+i);
	}

	dc.SelectObject(oldpen);

}

BOOL CColorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
m_Red.SetScrollRange(0,255);
	m_Green.SetScrollRange(0,255);
	m_Blue.SetScrollRange(0,255);

	m_Red.SetScrollPos(m_RedVal);
	m_Green.SetScrollPos(m_GreenVal);
	m_Blue.SetScrollPos(m_BlueVal);

	SetColor();
	UpdateData(FALSE);
	Invalidate();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CColorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
int n = pScrollBar->GetScrollPos();
	switch(nSBCode)
	{
	case SB_LINELEFT:
		n--;
		if(n<0) n=0;
		break;

	case SB_LINERIGHT:
		n++;
		if(n>255) n=255;
		break;

	case SB_THUMBPOSITION:
		n=nPos;
		break;

	case SB_PAGEUP:
		n-=10;
		if(n<0) n=0;
		break;

	case SB_PAGEDOWN:
		n+=10;
		if(n>255) n=255;
		break;
	}

	pScrollBar->SetScrollPos(n);
	m_r = m_Red.GetScrollPos();
	m_g = m_Green.GetScrollPos();
	m_b = m_Blue.GetScrollPos();

	m_RedVal = m_r;
	m_GreenVal = m_g;
	m_BlueVal = m_b;
	UpdateData(FALSE);
	SetColor();
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


