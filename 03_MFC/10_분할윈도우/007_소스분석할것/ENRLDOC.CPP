// EnrollDoc.cpp : implementation of the CEnrollDoc class
//

#include "stdafx.h"
#include "Enroll.h"
#include "EnrlDoc.h"
#include "CorsView.h"
#include "StudView.h"
#include "dlg.h"
#include "ListDlg.h"
#include "TreeDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnrollDoc

IMPLEMENT_DYNCREATE(CEnrollDoc, CDocument)

BEGIN_MESSAGE_MAP(CEnrollDoc, CDocument)
	//{{AFX_MSG_MAP(CEnrollDoc)
	ON_COMMAND(ID_COURSE_INSERT, OnCourseInsert)
	ON_COMMAND(ID_STUDENT_INSERT, OnStudentInsert)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_INSERT, OnUpdateStudentInsert)
	ON_COMMAND(ID_TREE_PROPERTY, OnTreeProperty)
	ON_COMMAND(ID_LIST_PROPERTY, OnListProperty)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnrollDoc construction/destruction

CEnrollDoc::CEnrollDoc()
{
	// TODO: add one-time construction code here
	// 뷰 포인터 초기화
	m_pCourseView = NULL;
	m_pStudentView = NULL;
	m_pRootCourse = NULL;
}

CEnrollDoc::~CEnrollDoc()
{
	if(m_pRootCourse) {
		delete m_pRootCourse;
	}
	DeleteAllCourse();
}

BOOL CEnrollDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_pRootCourse = new CCourse("전체 수강 현황");
	m_pRootCourse->DeleteAll((CTreeView*)m_pCourseView);
	m_hRootTree = m_pRootCourse->AddItem((CTreeView*)m_pCourseView, NULL);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CEnrollDoc serialization

void CEnrollDoc::Serialize(CArchive& ar)
{
	m_Course.Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
//		CCourse* pCourse = GetFirstCourse();
//		while(pCourse) {
//			pCourse->AddItem((CTreeView*)m_pCourseView, m_hRootTree);
//			GetNextCourse(pCourse);
//		}
//		m_pCurCourse = m_pRootCourse;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEnrollDoc diagnostics

#ifdef _DEBUG
void CEnrollDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEnrollDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnrollDoc commands
BOOL CEnrollDoc::AddCourse(CCourse* pCourse)
{
	m_Course.AddTail(pCourse);
	pCourse->AddItem((CTreeView*)m_pCourseView, m_hRootTree);
	m_pCurCourse = pCourse;
	return TRUE;
}

CCourse* CEnrollDoc::GetFirstCourse()
{
	POSITION pos = m_Course.GetHeadPosition();
	if(pos)
		return (CCourse*)m_Course.GetNext(pos);
	else
		return (CCourse*)NULL;
}

CCourse* CEnrollDoc::GetNextCourse(CCourse*& pCourse)
{
	POSITION pos = m_Course.Find(pCourse);
	if(pos) {
		m_Course.GetNext(pos);
		if(pos) {
			pCourse = (CCourse*)m_Course.GetNext(pos);
			return pCourse;
		}
	}
	pCourse = (CCourse*)NULL;
	return pCourse;
}

void CEnrollDoc::DeleteAllCourse()
{
	POSITION pos = m_Course.GetHeadPosition();
	CCourse* pCourse;
	while(pos) {
		pCourse = (CCourse*)m_Course.GetNext(pos);
		pCourse->DeleteAllStudents();
		delete pCourse;
	}
	m_Course.RemoveAll();
}

void CEnrollDoc::OnCourseInsert() 
{
	// TODO: Add your command handler code here
	CCourseDlg dlg;
	if(dlg.DoModal() == IDOK) {
		CCourse* pCourse = new CCourse(dlg.m_Name);
		AddCourse(pCourse);
		pCourse->ClearStudents((CListView*)m_pStudentView);
		SetModifiedFlag();
	}
}

void CEnrollDoc::OnStudentInsert() 
{
	// TODO: Add your command handler code here
	CStudentDlg dlg;
	dlg.m_Sex = 0;
	if(dlg.DoModal() == IDOK) {
		CStudent* pStudent = new CStudent(dlg.m_Name, dlg.m_Telno,
										  dlg.m_Birth, dlg.m_Sex);
		m_pCurCourse->AddStudent(pStudent, (CListView*)m_pStudentView);
		SetModifiedFlag();
	}
}

void CEnrollDoc::OnUpdateStudentInsert(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_pCurCourse != m_pRootCourse);
}

void CEnrollDoc::OnListProperty() 
{
	// TODO: Add your command handler code here
	CListPropertyDlg dlg;
	dlg.SetParentListView(m_pStudentView);
	dlg.DoModal();
}

void CEnrollDoc::OnTreeProperty() 
{
	// TODO: Add your command handler code here
	CTreePropertyDlg dlg;
	dlg.SetParentTreeView(m_pCourseView);
	dlg.DoModal();
}
