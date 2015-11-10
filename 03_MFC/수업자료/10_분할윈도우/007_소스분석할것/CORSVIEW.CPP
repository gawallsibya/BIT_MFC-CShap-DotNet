// CourseView.cpp : implementation of the CCourseView class
//

#include "stdafx.h"
#include "Enroll.h"
#include "EnrlDoc.h"
#include "CorsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseView

IMPLEMENT_DYNCREATE(CCourseView, CTreeView)

BEGIN_MESSAGE_MAP(CCourseView, CTreeView)
	//{{AFX_MSG_MAP(CCourseView)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, OnBeginlabeledit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseView construction/destruction

CCourseView::CCourseView()
{
	// TODO: add construction code here

}

CCourseView::~CCourseView()
{
}

BOOL CCourseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	// 트리뷰 속성 지정
	cs.style |= TVS_HASLINES | TVS_HASBUTTONS | 
				TVS_EDITLABELS | TVS_LINESATROOT |
				TVS_SHOWSELALWAYS;
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCourseView drawing

void CCourseView::OnDraw(CDC* pDC)
{
	CEnrollDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void CCourseView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to GetTreeCtrl().
	CTreeCtrl& ctlTree = GetTreeCtrl();
	HTREEITEM hItem = ctlTree.GetRootItem();
	if(hItem)
		ctlTree.SelectItem(hItem);
}

/////////////////////////////////////////////////////////////////////////////
// CCourseView diagnostics

#ifdef _DEBUG
void CCourseView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CCourseView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CEnrollDoc* CCourseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnrollDoc)));
	return (CEnrollDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCourseView message handlers

int CCourseView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	GetDocument()->m_pCourseView = this;
	CEnrollApp* pApp = (CEnrollApp*)::AfxGetApp();
	CTreeCtrl& ctlTree = GetTreeCtrl();
	
	// 이미지 리스트 생성
	m_ImageList.Create(16, 16, TRUE, 3, 1);
	m_ImageList.Add(pApp->LoadIcon(IDI_ICONTREE1));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICONTREE2));
	m_ImageList.Add(pApp->LoadIcon(IDI_ICONTREE3));
	// 트리 콘트롤에 이미지 리스트 지정
	ctlTree.SetImageList(&m_ImageList, TVSIL_NORMAL);

	return 0;
}

void CCourseView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	CEnrollDoc* pDoc = GetDocument();
	CTreeCtrl& ctlTree = GetTreeCtrl();
	CCourse* pCourse = (CCourse*)pNMTreeView->itemNew.lParam;
	if(ctlTree.GetRootItem() == ctlTree.GetSelectedItem())
		pCourse->ClearStudents((CListView*)pDoc->m_pStudentView);
	else
		pCourse->ShowStudents((CListView*)pDoc->m_pStudentView);
	pDoc->m_pCurCourse = pCourse;
	*pResult = 0;
}

void CCourseView::OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	CTreeCtrl& ctlTree = GetTreeCtrl();
	CEdit* pEdit = ctlTree.GetEditControl();
	pEdit->LimitText(40);
		
	*pResult = 0;
}

void CCourseView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	CTreeCtrl& ctlTree = GetTreeCtrl();
	if(pTVDispInfo->item.pszText != NULL) {
		CCourse* pCourse = (CCourse*)pTVDispInfo->item.lParam;
		pCourse->ChangeName(pTVDispInfo->item.pszText);
		pTVDispInfo->item.mask = TVIF_TEXT;
		ctlTree.SetItem(&pTVDispInfo->item);
		GetDocument()->SetModifiedFlag();
	}
	*pResult = 0;
}

CImageList* CCourseView::GetImage()
{
	return &m_ImageList;
}
