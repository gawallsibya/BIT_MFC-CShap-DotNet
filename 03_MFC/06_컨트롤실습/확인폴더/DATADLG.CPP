// DataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Movie.h"
#include "DataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog


CDataDlg::CDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataDlg)
	m_strEdit3 = _T("");
	m_strStatic3 = _T("");
	m_strCount = _T("");
	//}}AFX_DATA_INIT
}


void CDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataDlg)
	DDX_Control(pDX, IDC_STATIC_IMAGE, m_ImageCtrl);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_STATIC2, m_ctlStatic2);
	DDX_Control(pDX, IDC_EDIT2, m_ctlEdit2);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
	DDX_Text(pDX, IDC_STATIC3, m_strStatic3);
	DDX_Text(pDX, IDC_STATIC_COUNT, m_strCount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataDlg, CDialog)
	//{{AFX_MSG_MAP(CDataDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_COMBO_ADD, OnComboAdd)
	ON_BN_CLICKED(IDC_LIST_ADD, OnListAdd)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataDlg message handlers

void CDataDlg::OnButton1() 
{
	// 가장 손쉬운 방법
	CString  str;
	GetDlgItemText(IDC_EDIT1, str); // IDC_EDIT1에 입력한 문자열을 얻음
	SetDlgItemText(IDC_STATIC1, str); // IDC_STATIC1에 문자열 출력 		
}

void CDataDlg::OnButton2() 
{
	// 컨트롤을 이용하는 방법
	CString  str;
	m_ctlEdit2.GetWindowText(str); // CEdit형 멤버 변수
	m_ctlStatic2.SetWindowText(str); // CEdit형 멤버 변수
}

void CDataDlg::OnButton3() 
{
	// 데이터 값을 이용하는 방법
	UpdateData(TRUE);
	m_strStatic3 = m_strEdit3; // CString형 멤버 변수 
	UpdateData(FALSE);
}

void CDataDlg::OnButton4() 
{
	// 객체 포인터를 이용하는 방법
	CString  str;
	CEdit* pE4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	pE4->GetWindowText(str);

	CStatic* pS4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	pS4->SetWindowText(str);	
}

void CDataDlg::OnComboAdd() 
{
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	m_Combo.AddString(str);

	GetDlgItemText(IDC_EDIT2, str);
	m_Combo.AddString(str);

	GetDlgItemText(IDC_EDIT3, str);
	m_Combo.AddString(str);
	
	GetDlgItemText(IDC_EDIT4, str);
	m_Combo.AddString(str);	
	m_Combo.SetCurSel(0);
}

void CDataDlg::OnListAdd() 
{
	CString str;
	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST1);
	GetDlgItemText(IDC_EDIT1, str);
	pList->AddString(str);

	GetDlgItemText(IDC_EDIT2, str);
	pList->AddString(str);

	GetDlgItemText(IDC_EDIT3, str);
	pList->AddString(str);
	
	GetDlgItemText(IDC_EDIT4, str);
	pList->AddString(str);
	pList->SetCurSel(2);
}

void CDataDlg::OnSelchangeCombo1() 
{
	int nIndex;
	nIndex = m_Combo.GetCurSel();
	
	CString  str;
	m_Combo.GetLBText(nIndex, str);
	SetDlgItemText(IDC_STATIC_COMBO, str);	
}

void CDataDlg::OnDblclkList1() 
{
	int nIndex;
	CListBox* pList = (CListBox*)GetDlgItem(IDC_LIST1);
	nIndex = pList->GetCurSel();
	
	CString  str;
	pList->GetText(nIndex, str);
	SetDlgItemText(IDC_STATIC_LIST, str);
}

BOOL CDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CButton*  pOption = (CButton*)GetDlgItem(IDC_RADIO1);
	pOption->SetCheck(1);

    CScrollBar* pScroll = (CScrollBar*)GetDlgItem(IDC_SCROLLBAR1);
	pScroll->SetScrollRange(0, 100);
	pScroll->SetScrollPos(0);
	
	m_imgBatman.LoadBitmap(IDB_BATMAN);
	m_imgBatgirl.LoadBitmap(IDB_BATGIRL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDataDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	UINT nTemp;
	nTemp = pScrollBar->GetScrollPos();

	switch(nSBCode)
	{
	case SB_LINELEFT: // 좌측 화살표 버튼 클릭시
		if(nTemp > 0)
			nTemp -= 5;
		else
			nTemp = 0;
		pScrollBar->SetScrollPos(nTemp);
		break;

	case SB_PAGELEFT: // Thumb과 좌측 화살표 버튼 사이 클릭시
		if(nTemp >= 0)
			nTemp -= 20;
		else
			nTemp = 0;
		pScrollBar->SetScrollPos(nTemp);
		break;

    case SB_LINERIGHT: // 우측 화살표 버튼 클릭시
		if(nTemp < 100)
			nTemp += 5;
		else
			nTemp = 100;
		pScrollBar->SetScrollPos(nTemp);
        break;

	case SB_PAGERIGHT: // Thumb과 우측 화살표 버튼사이 클릭시
		if(nTemp <= 90)
			nTemp += 20;
		else
			nTemp = 0;
		pScrollBar->SetScrollPos(nTemp);
		break;

	case SB_THUMBTRACK: // Thumb을 드래그&드롭할 때  
		nTemp = nPos;
		pScrollBar->SetScrollPos(nTemp);
        break;
	}

	CString  str;
	str.Format("%d%%", nTemp);
	m_strCount = str;
	UpdateData(FALSE);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDataDlg::OnRadio1() 
{
	m_ImageCtrl.SetBitmap(m_imgBatman);
}

void CDataDlg::OnRadio2() 
{
	m_ImageCtrl.SetBitmap(m_imgBatgirl);
}
