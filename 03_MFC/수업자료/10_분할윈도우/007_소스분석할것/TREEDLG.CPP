// TreePropertyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enroll.h"
#include "EnrlDoc.h"
#include "CorsView.h"
#include "TreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreePropertyDlg dialog


CTreePropertyDlg::CTreePropertyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreePropertyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreePropertyDlg)
	m_bEditLabels = FALSE;
	m_bHasButtons = FALSE;
	m_bHasLines = FALSE;
	m_bLinesAtRoot = FALSE;
	m_bShowSelAlways = FALSE;
	m_bDisableDragDrop = FALSE;
	//}}AFX_DATA_INIT
	m_pParentTreeView = NULL;
}

void CTreePropertyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreePropertyDlg)
	DDX_Control(pDX, IDC_TREE1, m_ctlTree);
	DDX_Check(pDX, IDC_EDITLABELS, m_bEditLabels);
	DDX_Check(pDX, IDC_HASBUTTONS, m_bHasButtons);
	DDX_Check(pDX, IDC_HASLINES, m_bHasLines);
	DDX_Check(pDX, IDC_LINESATROOT, m_bLinesAtRoot);
	DDX_Check(pDX, IDC_SHOWSELALWAYS, m_bShowSelAlways);
	DDX_Check(pDX, IDC_DISABLEDRAGDROP, m_bDisableDragDrop);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTreePropertyDlg, CDialog)
	//{{AFX_MSG_MAP(CTreePropertyDlg)
	ON_BN_CLICKED(IDC_EDITLABELS, OnEditlabels)
	ON_BN_CLICKED(IDC_HASBUTTONS, OnHasbuttons)
	ON_BN_CLICKED(IDC_HASLINES, OnHaslines)
	ON_BN_CLICKED(IDC_LINESATROOT, OnLinesatroot)
	ON_BN_CLICKED(IDC_SHOWSELALWAYS, OnShowselalways)
	ON_BN_CLICKED(IDC_DISABLEDRAGDROP, OnDisabledragdrop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreePropertyDlg message handlers

BOOL CTreePropertyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ASSERT(m_pParentTreeView != NULL);
	m_pTree = &m_pParentTreeView->GetTreeCtrl();
	m_pImage = m_pParentTreeView->GetImage();
	m_ctlTree.SetImageList(m_pImage, TVSIL_NORMAL);

	long lStyle = GetWindowLong(m_pTree->m_hWnd, GWL_STYLE);
	FillTreeControl();
	SetWindowLong(m_ctlTree.m_hWnd, GWL_STYLE, lStyle);
	SetControlsState(lStyle);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTreePropertyDlg::OnEditlabels() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctlTree.SetNewStyle(TVS_EDITLABELS, m_bEditLabels);
}

void CTreePropertyDlg::OnHasbuttons() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctlTree.SetNewStyle(TVS_HASBUTTONS, m_bHasButtons);
}

void CTreePropertyDlg::OnHaslines() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctlTree.SetNewStyle(TVS_HASLINES, m_bHasLines);
}

void CTreePropertyDlg::OnLinesatroot() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctlTree.SetNewStyle(TVS_LINESATROOT, m_bLinesAtRoot);
}

void CTreePropertyDlg::OnShowselalways() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctlTree.SetNewStyle(TVS_SHOWSELALWAYS, m_bShowSelAlways);
}

void CTreePropertyDlg::OnDisabledragdrop() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctlTree.SetNewStyle(TVS_DISABLEDRAGDROP, m_bDisableDragDrop);
}

void CTreePropertyDlg::OnOK() 
{
	// TODO: Add extra validation here
	long lStyle;

	lStyle = GetWindowLong(m_ctlTree.m_hWnd, GWL_STYLE);
	SetWindowLong(m_pTree->m_hWnd, GWL_STYLE, lStyle);
	
	CDialog::OnOK();
}

void CTreePropertyDlg::SetParentTreeView(CCourseView* pView)
{
	m_pParentTreeView = pView;
}

void CTreePropertyDlg::FillTreeControl()
{
	/*
	루트 노드
		|
		|- 주 노드 1
		|	|
		|	|- 부 노드 11
		|	|- 부 노드 12
		|	|- 부 노드 13
		|
		|- 주 노드 2
			|
			|- 부 노드 21
			|- 부 노드 22
			|- 부 노드 23
			|- 부 노드 24
	*/
	TCHAR strSubNode1[3][11] = 
		{ "부 노드 11", "부 노드 12", "부 노드 13" };
	TCHAR strSubNode2[4][11] = 
		{ "부 노드 21", "부 노드 22", "부 노드 23", "부 노드 24" };

	HTREEITEM hRoot, hSub1, hSub2, hPrev;
	int i;

	// 루트 노드 추가
	hRoot = m_ctlTree.AddItem((HTREEITEM)NULL, "루트 노드", 
							  (HTREEITEM)TVI_ROOT, 0, 2);
	// 주 노드 추가
	hSub1 = m_ctlTree.AddItem(hRoot, "주 노드 1",
							  (HTREEITEM)TVI_FIRST, 1, 2);
	hSub2 = m_ctlTree.AddItem(hRoot, "주 노드 2", hSub1, 1, 2);

	// 부 노드 1 추가
	hPrev = (HTREEITEM)TVI_FIRST;
	for(i = 0; i < 3; ++i)
		hPrev = m_ctlTree.AddItem(hSub1, strSubNode1[i], hPrev, 1, 2);

	// 부 노드 2 추가
	hPrev = (HTREEITEM)TVI_FIRST;
	for(i = 0; i < 4; ++i)
		hPrev = m_ctlTree.AddItem(hSub2, strSubNode2[i], hPrev, 1, 2);

	m_ctlTree.Expand(hRoot, TVE_EXPAND);
	m_ctlTree.Expand(hSub1, TVE_EXPAND);
	m_ctlTree.Expand(hSub2, TVE_EXPAND);
}

void CTreePropertyDlg::SetControlsState(long lStyle)
{
	int nChecked;
	CButton* pButton = (CButton*)GetDlgItem(IDC_EDITLABELS);
	nChecked = 0;
	if(lStyle & TVS_EDITLABELS)
		nChecked = 1;
	pButton->SetCheck(nChecked);
	
	pButton = (CButton*)GetDlgItem(IDC_HASBUTTONS);
	nChecked = 0;
	if(lStyle & TVS_HASBUTTONS)
		nChecked = 1;
	pButton->SetCheck(nChecked);

	pButton = (CButton*)GetDlgItem(IDC_HASLINES);
	nChecked = 0;
	if(lStyle & TVS_HASLINES)
		nChecked = 1;
	pButton->SetCheck(nChecked);

	pButton = (CButton*)GetDlgItem(IDC_LINESATROOT);
	nChecked = 0;
	if(lStyle & TVS_LINESATROOT)
		nChecked = 1;
	pButton->SetCheck(nChecked);

	pButton = (CButton*)GetDlgItem(IDC_DISABLEDRAGDROP);
	nChecked = 0;
	if(lStyle & TVS_DISABLEDRAGDROP)
		nChecked = 1;
	pButton->SetCheck(nChecked);

	pButton = (CButton*)GetDlgItem(IDC_SHOWSELALWAYS);
	nChecked = 0;
	if(lStyle & TVS_SHOWSELALWAYS)
		nChecked = 1;
	pButton->SetCheck(nChecked);
}
