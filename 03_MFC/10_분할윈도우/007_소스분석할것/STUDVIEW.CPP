// StudentView.cpp : implementation file
//

#include "stdafx.h"
#include "Enroll.h"
#include "EnrlDoc.h"
#include "StudView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentView

IMPLEMENT_DYNCREATE(CStudentView, CListView)

CStudentView::CStudentView()
{
}

CStudentView::~CStudentView()
{
}


BEGIN_MESSAGE_MAP(CStudentView, CListView)
	//{{AFX_MSG_MAP(CStudentView)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(LVN_BEGINLABELEDIT, OnBeginlabeledit)
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndlabeledit)
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, OnColumnclick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentView drawing

void CStudentView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CStudentView diagnostics

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CListView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStudentView message handlers

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style &= ~(LVS_TYPEMASK);
	cs.style |= LVS_REPORT | LVS_EDITLABELS;

	return CListView::PreCreateWindow(cs);
}

int CStudentView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	GetDocument()->m_pStudentView = this;
	CEnrollApp* pApp = (CEnrollApp*)::AfxGetApp();
	CListCtrl& ctlList = GetListCtrl();

	// 이미지 리스트 생성
	m_ImageLarge.Create(32, 32, TRUE, 2, 1);
	m_ImageSmall.Create(16, 16, TRUE, 2, 1);
	m_ImageLarge.Add(pApp->LoadIcon(IDI_ICONLIST1));
	m_ImageLarge.Add(pApp->LoadIcon(IDI_ICONLIST2));
	m_ImageSmall.Add(pApp->LoadIcon(IDI_ICONLIST1));
	m_ImageSmall.Add(pApp->LoadIcon(IDI_ICONLIST2));

	// 리스트 콘트롤에 이미지 리스트 지정
	ctlList.SetImageList(&m_ImageLarge, LVSIL_NORMAL);
	ctlList.SetImageList(&m_ImageSmall, LVSIL_SMALL);

	return 0;
}

void CStudentView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	// 헤더 생성
	LV_COLUMN lvcolumn;
	CRect rect;
	GetClientRect(rect);
	TCHAR strTitle[3][10] = { "성명", "전화번호", "생년월일" };
	static BOOL bFirst = TRUE;
	
	if(!bFirst)
		return;
	bFirst = FALSE;

	CListCtrl& ctlList = GetListCtrl();
	
	lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	lvcolumn.fmt = LVCFMT_LEFT;
	lvcolumn.cx = rect.Width() / 3;
	for(int i=0; i < 3; i++) {
		lvcolumn.pszText = strTitle[i];
		lvcolumn.iSubItem = i;
		ctlList.InsertColumn(i, &lvcolumn);
	}
}

void CStudentView::OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	CListCtrl& ctlList = GetListCtrl();
	CEdit* pEdit = ctlList.GetEditControl();
	pEdit->LimitText(40);

	*pResult = 0;
}

void CStudentView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	CListCtrl& ctlList = GetListCtrl();
	if(pDispInfo->item.pszText != NULL) {
		CStudent* pStudent = (CStudent*)pDispInfo->item.lParam;
		pStudent->ChangeName(pDispInfo->item.pszText);
		pDispInfo->item.mask = LVIF_TEXT;
		ctlList.SetItem(&pDispInfo->item);
		GetDocument()->SetModifiedFlag();
	}
	*pResult = 0;
}

int CStudentView::CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CStudent* pStudent1 = (CStudent*)lParam1;
	CStudent* pStudent2 = (CStudent*)lParam2;

	return pStudent1->Compare(pStudent2, lParamSort);
}

void CStudentView::OnColumnclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CListCtrl& ctlList = GetListCtrl();
	ctlList.SortItems(CompareFunc, pNMListView->iSubItem);

	*pResult = 0;
}

CImageList* CStudentView::GetImageLarge()
{
	return &m_ImageLarge;
}

CImageList* CStudentView::GetImageSmall()
{
	return &m_ImageSmall;
}
