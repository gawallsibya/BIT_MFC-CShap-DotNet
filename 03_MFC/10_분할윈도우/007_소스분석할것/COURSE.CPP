#include "stdafx.h"
#include "Course.h"

IMPLEMENT_SERIAL(CCourse, CObject, 1)

CCourse::CCourse()
{
}

CCourse::CCourse(CString name)
	: m_Name(name)
{
}

HTREEITEM CCourse::AddItem(CTreeView* pView, HTREEITEM hParent)
{
	HTREEITEM hItem;
	TV_ITEM tvitem;
	TV_INSERTSTRUCT tvstruct;

	CTreeCtrl& ctlTree = pView->GetTreeCtrl();

	tvitem.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM;
	tvitem.pszText = m_Name.GetBuffer(m_Name.GetLength());
	tvitem.iImage = hParent == NULL ? 0 : 1;
	tvitem.iSelectedImage = 2;
	tvitem.lParam = (LPARAM)this;

	tvstruct.item = tvitem;
	tvstruct.hInsertAfter = TVI_LAST;
	tvstruct.hParent = hParent;

	hItem = ctlTree.InsertItem(&tvstruct);
	ctlTree.Expand(hParent, TVE_EXPAND);
	ctlTree.SelectItem(hItem);
	return hItem;
}

void CCourse::ChangeName(CString name)
{
	m_Name = name;
}

void CCourse::DeleteAll(CTreeView* pView)
{
	CTreeCtrl& ctlTree = pView->GetTreeCtrl();
	ctlTree.DeleteAllItems();
}

void CCourse::ShowStudents(CListView* pView)
{
	CListCtrl& ctlList = pView->GetListCtrl();
	ctlList.DeleteAllItems();
	
	CStudent* pStudent = GetFirstStudent();
	while(pStudent) {
		pStudent->AddItem(pView);
		GetNextStudent(pStudent);
	}
}

void CCourse::ClearStudents(CListView* pView)
{
	CListCtrl& ctlList = pView->GetListCtrl();
	ctlList.DeleteAllItems();
}

BOOL CCourse::AddStudent(CStudent* pStudent, CListView* pView)
{
	m_Students.AddTail(pStudent);
	pStudent->AddItem(pView);
	return TRUE;
}

CStudent* CCourse::GetFirstStudent()
{
	POSITION pos = m_Students.GetHeadPosition();
	if(pos)
		return (CStudent*)m_Students.GetNext(pos);
	else
		return (CStudent*)NULL;
}

CStudent* CCourse::GetNextStudent(CStudent*& pStudent)
{
	POSITION pos = m_Students.Find(pStudent);
	if(pos) {
		m_Students.GetNext(pos);
		if(pos) {
			pStudent = (CStudent*)m_Students.GetNext(pos);
			return pStudent;
		}
	}
	pStudent = (CStudent*)NULL;
	return pStudent;
}

void CCourse::DeleteAllStudents()
{
	POSITION pos = m_Students.GetHeadPosition();
	while(pos)
		delete (CStudent*)m_Students.GetNext(pos);
	m_Students.RemoveAll();
}

void CCourse::Serialize(CArchive& ar)
{
	m_Students.Serialize(ar);
	if(ar.IsStoring())
		ar << m_Name;
	else
		ar >> m_Name;
}
