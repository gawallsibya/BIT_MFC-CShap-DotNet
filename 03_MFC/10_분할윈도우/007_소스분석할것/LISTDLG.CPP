// ListPropertyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enroll.h"
#include "EnrlDoc.h"
#include "StudView.h"
#include "ListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListPropertyDlg dialog


CListPropertyDlg::CListPropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListPropertyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListPropertyDlg)
	m_bAutoArrange = FALSE;
	m_bEditLabel = FALSE;
	m_bNoColumnHeader = FALSE;
	m_bNoLabelWrap = FALSE;
	m_bNoSortHeader = FALSE;
	m_bSingleSel = FALSE;
	m_nSortMode = -1;
	m_nViewMode = -1;
	//}}AFX_DATA_INIT
	m_pParentListView = NULL;
}

void CListPropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListPropertyDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Check(pDX, IDC_AUTOARRANGE, m_bAutoArrange);
	DDX_Check(pDX, IDC_EDITLABEL, m_bEditLabel);
	DDX_Check(pDX, IDC_NOCOLUMNHEADER, m_bNoColumnHeader);
	DDX_Check(pDX, IDC_NOLABLEWRAP, m_bNoLabelWrap);
	DDX_Check(pDX, IDC_NOSORTHEADER, m_bNoSortHeader);
	DDX_Check(pDX, IDC_SINGLESEL, m_bSingleSel);
	DDX_CBIndex(pDX, IDC_SORTMODE, m_nSortMode);
	DDX_CBIndex(pDX, IDC_VIEWMODE, m_nViewMode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListPropertyDlg, CDialog)
	//{{AFX_MSG_MAP(CListPropertyDlg)
	ON_BN_CLICKED(IDC_AUTOARRANGE, OnAutoarrange)
	ON_BN_CLICKED(IDC_EDITLABEL, OnEditlabel)
	ON_BN_CLICKED(IDC_NOCOLUMNHEADER, OnNocolumnheader)
	ON_BN_CLICKED(IDC_NOLABLEWRAP, OnNolablewrap)
	ON_BN_CLICKED(IDC_NOSORTHEADER, OnNosortheader)
	ON_BN_CLICKED(IDC_SINGLESEL, OnSinglesel)
	ON_CBN_SELCHANGE(IDC_SORTMODE, OnSelchangeSortmode)
	ON_CBN_SELCHANGE(IDC_VIEWMODE, OnSelchangeViewmode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListPropertyDlg message handlers

BOOL CListPropertyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ASSERT(m_pParentListView != NULL);
	m_pList = &m_pParentListView->GetListCtrl();

	m_pImageLarge = m_pParentListView->GetImageLarge();
	m_pImageSmall = m_pParentListView->GetImageSmall();

	long lStyle = GetWindowLong(m_pList->m_hWnd, GWL_STYLE);
	FillListControl();
	SetWindowLong(m_ctlList.m_hWnd, GWL_STYLE, lStyle);
	SetControlsState(lStyle);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CListPropertyDlg::OnAutoarrange() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ChangeStyle(LVS_AUTOARRANGE, m_bAutoArrange);
}

void CListPropertyDlg::OnEditlabel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ChangeStyle(LVS_EDITLABELS, m_bEditLabel);
}

void CListPropertyDlg::OnNocolumnheader() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ChangeStyle(LVS_NOCOLUMNHEADER, m_bNoColumnHeader);
}

void CListPropertyDlg::OnNolablewrap() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ChangeStyle(LVS_NOLABELWRAP, m_bNoLabelWrap);
}

void CListPropertyDlg::OnNosortheader() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ChangeStyle(LVS_NOSORTHEADER, m_bNoSortHeader);
}

void CListPropertyDlg::OnSinglesel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ChangeStyle(LVS_SINGLESEL, m_bSingleSel);
}

void CListPropertyDlg::OnOK() 
{
	// TODO: Add extra validation here
	long lStyle;

	lStyle = GetWindowLong(m_ctlList.m_hWnd, GWL_STYLE);
	SetWindowLong(m_pList->m_hWnd, GWL_STYLE, lStyle);
	
	CDialog::OnOK();
}

void CListPropertyDlg::OnSelchangeSortmode() 
{
	// TODO: Add your control notification handler code here
	long lStyle;

	UpdateData(TRUE);

	lStyle = GetWindowLong(m_ctlList.m_hWnd, GWL_STYLE);
	lStyle &= ~(LVS_SORTASCENDING | LVS_SORTDESCENDING);	// 정렬하지 않음
	
	switch(m_nSortMode) {
	case 1:		// 오름차순
		lStyle |= LVS_SORTASCENDING;
		break;
	case 2:	// 내림차순
		lStyle |= LVS_SORTDESCENDING;
		break;
	}
	CRect rect;
	m_ctlList.GetWindowRect(&rect);
	ScreenToClient(&rect);
	m_ctlList.DestroyWindow();
	m_ctlList.Create(lStyle, rect, this, IDC_LIST1);
	FillListControl();
}

void CListPropertyDlg::OnSelchangeViewmode() 
{
	// TODO: Add your control notification handler code here
	long lStyle, lStyleOld;

	UpdateData(TRUE);
	switch(m_nViewMode) {
	case 0: // 작은 아이콘
		lStyle = LVS_SMALLICON;
		break;
	case 1:	// 큰 아이콘
		lStyle = LVS_ICON;
		break;
	case 2:	// 리스트
		lStyle = LVS_LIST;
		break;
	default:	// 보고서
		lStyle = LVS_REPORT;
		break;
	}

	lStyleOld = GetWindowLong(m_ctlList.m_hWnd, GWL_STYLE);
	lStyleOld &= ~(LVS_TYPEMASK); // 모든 형태 모드 삭제
	lStyleOld |= lStyle;
	SetWindowLong(m_ctlList.m_hWnd, GWL_STYLE, lStyleOld);
}

void CListPropertyDlg::SetParentListView(CStudentView* pView)
{
	m_pParentListView = pView;
}

void CListPropertyDlg::FillListControl()
{
	LV_ITEM	lvitem;
	LV_COLUMN lvcolumn;

	TCHAR strTitle[2][10] = { "주항목", "부항목" };
	TCHAR MainContents[10][10] = {
		"주항목1",
		"주항목2",
		"주항목3",
		"주항목4",
		"주항목5",
		"주항목6",
		"주항목7",
		"주항목8",
		"주항목9",
		"주항목0",};
	TCHAR SubContents[10][10] = {
		"부항목1",
		"부항목2",
		"부항목3",
		"부항목4",
		"부항목5",
		"부항목6",
		"부항목7",
		"부항목8",
		"부항목9",
		"부항목0",};

	// 리스트뷰 콘트롤 컬럼 생성
	CRect rect;
	m_ctlList.GetWindowRect(&rect);
	for (int i = 0; i < 2; i++) {
		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvcolumn.fmt = LVCFMT_LEFT;
		lvcolumn.pszText = strTitle[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = rect.Width() / 2;
		m_ctlList.InsertColumn(i, &lvcolumn);
	}
	
	// 리스트뷰 콘트롤에 이미지 리스트 콘트롤 지정
	m_ctlList.SetImageList(m_pImageLarge, LVSIL_NORMAL);
	m_ctlList.SetImageList(m_pImageSmall, LVSIL_SMALL);

	// 예제 항목 추가
	int iIcon;

	lvitem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
	lvitem.state = 0;      
	lvitem.stateMask = 0;  
	
	for (i = 0; i < 10; i++) {
		for (int iSubItem = 0; iSubItem < 2; iSubItem++) {
			if (iSubItem == 0)
				iIcon = rand() % 2;
			lvitem.mask =  iSubItem == 0 ? 
				(LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE) : 
				 LVIF_TEXT;
			lvitem.iItem = i;
			lvitem.iSubItem = iSubItem;
			lvitem.pszText = 
				iSubItem == 0 ? MainContents[i] : SubContents[i];
			lvitem.iImage = iIcon;
			if (iSubItem == 0)
				m_ctlList.InsertItem(&lvitem);
			else
				m_ctlList.SetItem(&lvitem);
		}
	}
}

void CListPropertyDlg::ChangeStyle(long lStyle, BOOL bSetBit)
{
	long lStyleOld;

	ASSERT(lStyle != 0);
	lStyleOld = GetWindowLong(m_ctlList.m_hWnd, GWL_STYLE);
	lStyleOld &= ~lStyle;
	if (bSetBit)
		lStyleOld |= lStyle;

	SetWindowLong(m_ctlList.m_hWnd, GWL_STYLE, lStyleOld);
	UpdateData(FALSE);
}

void CListPropertyDlg::SetControlsState(long lStyle)
{
	BOOL bReport, bLargeIconic, bSmallIconic;
	BOOL bAscending, bDescending;

	bReport = lStyle & LVS_REPORT;
	bLargeIconic = lStyle & LVS_ICON;
	bSmallIconic = lStyle & LVS_SMALLICON;
	bAscending = lStyle & LVS_SORTASCENDING;
	bDescending = lStyle & LVS_SORTDESCENDING;

	CComboBox* pCombo;
	CButton* pButton;
	
	pCombo = (CComboBox*)GetDlgItem(IDC_VIEWMODE);
	if(bSmallIconic)
		pCombo->SetCurSel(0);
	else
	if(bLargeIconic)
		pCombo->SetCurSel(1);
	else
	if(bReport)
		pCombo->SetCurSel(3);
	else
		pCombo->SetCurSel(2);

	pCombo = (CComboBox*)GetDlgItem(IDC_SORTMODE);
	if(bAscending)
		pCombo->SetCurSel(1);
	else
	if(bDescending)
		pCombo->SetCurSel(2);
	else
		pCombo->SetCurSel(0);

	pButton = (CButton*)GetDlgItem(IDC_EDITLABEL);
	if(lStyle & LVS_EDITLABELS)
		pButton->SetCheck(1);
	else
		pButton->SetCheck(0);

}
