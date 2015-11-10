// InsTapeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VideoShop2.h"
#include "InsTapeDlg.h"
#include "TapeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInsTapeDlg dialog


CInsTapeDlg::CInsTapeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInsTapeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInsTapeDlg)
	m_strActor = _T("");
	m_lTapeCD = 0;
	m_strDirector = _T("");
	m_tInday = _T("");
	m_lMoney = 0;
	m_strTitle = _T("");
	//}}AFX_DATA_INIT
}


void CInsTapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInsTapeDlg)
	DDX_Text(pDX, IDC_ACTOR_EDIT, m_strActor);
	DDX_Text(pDX, IDC_CODE_EDIT, m_lTapeCD);
	DDX_Text(pDX, IDC_DIRECTOR_EDIT, m_strDirector);
	DDX_Text(pDX, IDC_INDAY_EDIT, m_tInday);
	DDX_Text(pDX, IDC_MONEY_EDIT, m_lMoney);
	DDX_Text(pDX, IDC_TITLE_EDIT, m_strTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInsTapeDlg, CDialog)
	//{{AFX_MSG_MAP(CInsTapeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInsTapeDlg message handlers

BOOL CInsTapeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_lTapeCD = ((CTapeDlg*)GetParent())->m_lTapeCD + 1;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CInsTapeDlg::OnOK() 
{
	// TODO: Add extra validation here
//	UpdateData(TRUE);
//	if((m_strTitle == "")||(m_lMoney <= 0))
//	{
//		MessageBox("영화제목과 금액을 올바로 입력하셔야 합니다.");
//		return;
//	}
//	OnOK();
	CDialog::OnOK();
}
