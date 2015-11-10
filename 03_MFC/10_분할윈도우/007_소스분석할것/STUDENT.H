// CStudent Å¬·¡½º
#ifndef STUDENT
#define STUDENT

class CStudent : public CObject
{
public:
	int Compare(CStudent* pStudent, int subItem);
	CStudent(CString name, CString telno, CString birth, BOOL sex);
	void AddItem(CListView* pView);
	void ChangeName(CString name);
	void DeleteAll(CListView* pView);
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CStudent)
protected:
	CStudent();
	CString m_Name;
	CString m_Telno;
	CString m_Birth;
	BOOL m_Sex;
};

#endif
