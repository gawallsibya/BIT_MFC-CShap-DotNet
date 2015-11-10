// EnrollDoc.h : interface of the CEnrollDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include "Student.h"
#include "Course.h"

class CCourseView;
class CStudentView;

class CEnrollDoc : public CDocument
{
protected: // create from serialization only
	CEnrollDoc();
	DECLARE_DYNCREATE(CEnrollDoc)

// Attributes
public:
	// ∫‰ ∆˜¿Œ≈Õ
	CCourseView* m_pCourseView;
	CStudentView* m_pStudentView;
	CCourse* m_pCurCourse;
	BOOL AddCourse(CCourse* pCourse);
	CCourse* GetFirstCourse();
	CCourse* GetNextCourse(CCourse*& pCourse);
	void DeleteAllCourse();
protected:
	HTREEITEM m_hRootTree;
	CCourse* m_pRootCourse;
	CObList m_Course;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnrollDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEnrollDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEnrollDoc)
	afx_msg void OnCourseInsert();
	afx_msg void OnStudentInsert();
	afx_msg void OnUpdateStudentInsert(CCmdUI* pCmdUI);
	afx_msg void OnTreeProperty();
	afx_msg void OnListProperty();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
