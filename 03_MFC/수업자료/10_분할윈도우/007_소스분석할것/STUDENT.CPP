#include "stdafx.h"
#include "Student.h"


IMPLEMENT_SERIAL(CStudent, CObject, 1)

CStudent::CStudent()
{
}

CStudent::CStudent(CString name, CString telno, CString birth, BOOL sex)
	: m_Name(name), m_Telno(telno), m_Birth(birth), m_Sex(sex)
{
}

void CStudent::AddItem(CListView* pView)
{
	LV_ITEM lvItem;
	int iIcon;
	CListCtrl& ctlList = pView->GetListCtrl();
	int nCount = ctlList.GetItemCount();

	if(m_Sex)
		iIcon = 1;
	else
		iIcon = 0;
	
	lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | 
				  LVIF_STATE | LVIF_DI_SETITEM;
	lvItem.state = 0;
	lvItem.stateMask = 0;

	lvItem.iSubItem = 0;
	lvItem.pszText = m_Name.GetBuffer(m_Name.GetLength());
	lvItem.cchTextMax = m_Name.GetLength();
	lvItem.iItem = nCount;
	lvItem.iImage = iIcon;
	lvItem.lParam = (LPARAM)this;
	ctlList.InsertItem(&lvItem);

	lvItem.mask = LVIF_TEXT;
	lvItem.iSubItem = 1;
	lvItem.pszText = m_Telno.GetBuffer(m_Telno.GetLength());
	ctlList.SetItem(&lvItem);

	lvItem.iSubItem = 2;
	lvItem.pszText = m_Birth.GetBuffer(m_Birth.GetLength());
	ctlList.SetItem(&lvItem);

}

void CStudent::ChangeName(CString name)
{
	m_Name = name;
}

void CStudent::DeleteAll(CListView* pView)
{
	CListCtrl& ctlList = pView->GetListCtrl();
	ctlList.DeleteAllItems();
}

void CStudent::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
		ar << m_Name << m_Telno << m_Birth << m_Sex;
	else
		ar >> m_Name >> m_Telno >> m_Birth >> m_Sex;
}

int CStudent::Compare(CStudent* pStudent, int subItem)
{
	switch(subItem) {
	case 0 :	// 이름
		return m_Name.Compare(pStudent->m_Name);
	case 1 :	// 전화번호
		return m_Telno.Compare(pStudent->m_Telno);
	case 2:		// 생년월일
		return m_Birth.Compare(pStudent->m_Birth);
	}
	return 0;
}
