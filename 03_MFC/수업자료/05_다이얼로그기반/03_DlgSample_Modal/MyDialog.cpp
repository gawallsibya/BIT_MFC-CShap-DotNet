// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DlgSample.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDialog dialog


CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDialog)
	m_cx = 0;
	m_cy = 0;
	m_color = -1;
	//}}AFX_DATA_INIT
}


void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDialog)
	DDX_Control(pDX, IDCANCEL, m_btn2);
	DDX_Control(pDX, IDOK, m_btn1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);
	DDX_Text(pDX, IDC_EDIT1, m_cx);
	DDV_MinMaxInt(pDX, m_cx, 10, 300);
	DDX_Text(pDX, IDC_EDIT2, m_cy);
	DDV_MinMaxInt(pDX, m_cy, 10, 300);
	DDX_Radio(pDX, IDC_RADIO1, m_color);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	//{{AFX_MSG_MAP(CMyDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDialog message handlers

BOOL CMyDialog::OnInitDialog() 
{
	CDialog::OnInitDialog(); // UpdateData(FALSE)
	
	// spin control을 초기화 한다.
	m_spin1.SetRange(10,300);
	m_spin2.SetRange(10,300);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

