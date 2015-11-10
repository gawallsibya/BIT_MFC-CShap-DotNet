// CCoruse Å¬·¡½º
#ifndef COURSE
#define COURSE

#include "Student.h"

class CCourse : public CObject
{
public:
	CCourse(CString name);
	HTREEITEM AddItem(CTreeView* pView, HTREEITEM hParent);
	void ChangeName(CString name);
	void DeleteAll(CTreeView* pView);
	void Serialize(CArchive& ar);
	void ShowStudents(CListView* pView);
	void ClearStudents(CListView* pView);
	BOOL AddStudent(CStudent* pStudent, CListView* pView);
	CStudent* GetFirstStudent();
	CStudent* GetNextStudent(CStudent*& pStudent);
	void DeleteAllStudents();
	DECLARE_SERIAL(CCourse)
protected:
	CCourse();
	CString m_Name;
	CObList m_Students;
};

#endif