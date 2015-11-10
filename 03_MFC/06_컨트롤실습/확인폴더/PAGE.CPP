// Page.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "Page.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CMyPage1, CPropertyPage)
IMPLEMENT_DYNCREATE(CMyPage2, CPropertyPage)
IMPLEMENT_DYNCREATE(CMyPage3, CPropertyPage)

/////////////////////////////////////////////////////////////////////////////
// CMyPage1 property page

CMyPage1::CMyPage1() : CPropertyPage(CMyPage1::IDD)
{
	//{{AFX_DATA_INIT(CMyPage1)
	//}}AFX_DATA_INIT
}

CMyPage1::~CMyPage1()
{
}

void CMyPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyPage1)
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Control(pDX, IDC_ANIMATE1, m_Animate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CMyPage1)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyPage2 property page

CMyPage2::CMyPage2() : CPropertyPage(CMyPage2::IDD)
{
	//{{AFX_DATA_INIT(CMyPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMyPage2::~CMyPage2()
{
}

void CMyPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyPage2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CMyPage2)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyPage3 property page

CMyPage3::CMyPage3() : CPropertyPage(CMyPage3::IDD)
{
	//{{AFX_DATA_INIT(CMyPage3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMyPage3::~CMyPage3()
{
}

void CMyPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyPage3)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CMyPage3)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_REPORT_TYPE, OnReportType)
	ON_BN_CLICKED(IDC_LIST_TYPE, OnListType)
	ON_BN_CLICKED(IDC_ICON_TYPE, OnIconType)
	ON_BN_CLICKED(IDC_SMALL_TYPE, OnSmallType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//=========================================================
// 첫 번째 프로퍼티 페이지에 대한 코드
BOOL CMyPage1::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_Spin.SetRange(0, 20);  // 스핀 버튼 컨트롤의 범위 설정
	m_Spin.SetPos(0);        // 스핀 버튼 컨트롤의 초기 위치
  
	m_Progress.SetRange(0, 100); // 프로그레스 컨트롤의 범위 설정
	m_Progress.SetPos(0);		 // 프로그레스 컨트롤의 초기 위치
	m_Animate.Open(IDR_AVI1); // 애니메이션 열기
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyPage1::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int value = m_Spin.GetPos(); // 스핀 버튼 컨트롤의 현재 위치
	m_Progress.SetPos(value*5);  // 프로그레스 컨트롤의 위치 설정
	CPropertyPage::OnVScroll(nSBCode, nPos, pScrollBar);
}

//=========================================================
// 두 번째 프로퍼티 페이지에 대한 코드
BOOL CMyPage2::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// 3개의 슬라이더 컨트롤에 대해 범위 설정 및 초기 위치 설정
	CSliderCtrl* pSlider1 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	CSliderCtrl* pSlider2 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER2);
	CSliderCtrl* pSlider3 = (CSliderCtrl*)GetDlgItem(IDC_SLIDER3);

	pSlider1->SetRange(0, 255);
	pSlider2->SetRange(0, 255);
	pSlider3->SetRange(0, 255);

	pSlider1->SetPos(128);
	pSlider2->SetPos(0);
	pSlider3->SetPos(128);
	
	// 슬라이더 컨트롤에 대응하는 정적 텍스트에 초기값 설정
	SetDlgItemInt(IDC_RED, 128);
	SetDlgItemInt(IDC_GREEN, 0);
	SetDlgItemInt(IDC_BLUE, 128);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyPage2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 3개의 슬라이더 컨트롤에 대한 반응
	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;

	switch(pSlider->GetDlgCtrlID())
	{
	case IDC_SLIDER1: // 첫 번째 슬라이더 컨트롤 조작시
		SetDlgItemInt(IDC_RED, pSlider->GetPos());
		break;
		
	case IDC_SLIDER2: // 두 번째 슬라이더 컨트롤 조작시
		SetDlgItemInt(IDC_GREEN, pSlider->GetPos());
		break;

	case IDC_SLIDER3: // 세 번째 슬라이더 컨트롤 조작시
		SetDlgItemInt(IDC_BLUE, pSlider->GetPos());
        break;
	}
	
	CurrentFillColor();	// 현재 색상 표시 
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMyPage2::CurrentFillColor()
{
	UINT nRed, nGreen, nBlue;
	nRed = GetDlgItemInt(IDC_RED);
	nGreen = GetDlgItemInt(IDC_GREEN);
	nBlue = GetDlgItemInt(IDC_BLUE);

	COLORREF color = RGB(nRed, nGreen, nBlue); // 현재 색상
	
	CRect rc;
	CStatic* pFrame = (CStatic*)GetDlgItem(IDC_COLOR_SHOW);
	pFrame->GetClientRect(rc);

	CClientDC dc(pFrame); 

	CBrush br(color);
	CBrush* pOld = dc.SelectObject(&br);
    dc.FillRect(rc, &br); // 현재 색상으로 사각형을 채운다.
	dc.SelectObject(pOld);
}

//=========================================================
// 세 번째 프로퍼티 페이지에 대한 코드
BOOL CMyPage3::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	FillTree();	
	FillList();
	return TRUE;  
}

void CMyPage3::FillTree()
{
	m_imageList.Create(IDB_LIST, 16, 1, (COLORREF)-1);
	m_Tree.SetImageList(&m_imageList, TVSIL_NORMAL);

	HTREEITEM hSub = m_Tree.InsertItem("시네마 천국", 0, 1);
	m_Tree.InsertItem("아마게돈", 2, 1, hSub);
	m_Tree.InsertItem("퇴마록", 2, 1, hSub);
	
	hSub = m_Tree.InsertItem("키트리 극장", 0, 1);
	hSub = m_Tree.InsertItem("동방불패", 2, 1, hSub);
	m_Tree.InsertItem("동방불패2", 3, 1, hSub);
}

void CMyPage3::FillList()
{
	m_List.InsertColumn(0, "주연 배우"); 

	m_imageTree.Create(IDB_LIST, 16, 1, (COLORREF)-1);
	m_List.SetImageList(&m_imageTree, LVSIL_SMALL);

	m_imageLarge.Create(IDB_LARGE, 32, 1, (COLORREF)-1);
	m_List.SetImageList(&m_imageLarge, LVSIL_NORMAL);
	
	m_List.InsertItem(0, "한 석규", 0);
	m_List.InsertItem(1, "브루스 윌리스", 1);
	m_List.InsertItem(2, "게리 올드만", 2);
	m_List.InsertItem(3, "드까프리 성호", 3);
	m_List.InsertItem(4, "김 병세", 0);

	// 헤더 컨트롤의 크기를 조절한다.
	CHeaderCtrl* pH = (CHeaderCtrl*)m_List.GetDlgItem(0);
	int nCount = pH->GetItemCount(); 

	for(int i =0; i < nCount; i++)
		m_List.SetColumnWidth(i, LVSCW_AUTOSIZE);
}

void CMyPage3::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	
	HTREEITEM hSel = pNMTreeView->itemNew.hItem;
	if(hSel != NULL)
	{
		CString strText = m_Tree.GetItemText(hSel);
		SetDlgItemText(IDC_SELECT_TREE, strText);
	}

	*pResult = 0;
}

void CMyPage3::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	int nSel = pNMListView->iItem;
	if(nSel != -1)
	{
		CString strText = m_List.GetItemText(nSel, 0);
		SetDlgItemText(IDC_SELECT_LIST, strText);
	}

	*pResult = 0;
}

//=========================================================
// 위저드 다이얼로그의 버튼 처리
BOOL CMyPage1::OnSetActive() 
{
	// [다음]버튼을 활성화
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT); 	
	return CPropertyPage::OnSetActive();
}

BOOL CMyPage2::OnSetActive() 
{
	// [뒤로], [다음]버튼을 활성화	
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT); 
	return CPropertyPage::OnSetActive();
}

BOOL CMyPage3::OnSetActive() 
{
	// [뒤로], [완료]버튼을 활성화	
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH); 
	return CPropertyPage::OnSetActive();
}

//=========================================================
// 리스트 컨트롤의 항목 표시 형식에 대한 코드

// 레포트 형식
void CMyPage3::OnReportType() 
{    
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);	
}
// 리스트 형식
void CMyPage3::OnListType() 
{
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_LIST);	
}
// 큰 아이콘 형식
void CMyPage3::OnIconType() 
{
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}
// 작은 아이콘 형식
void CMyPage3::OnSmallType() 
{
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);	
}

LRESULT CMyPage1::OnWizardNext() 
{
	int nCount = GetDlgItemInt(IDC_EDIT1);
	
	if(	nCount != 7 )
	{
		AfxMessageBox("Key count는 7입니다.", MB_ICONINFORMATION);
		return -1; // 페이지 이동 방지
	}

	return CPropertyPage::OnWizardNext();
}
