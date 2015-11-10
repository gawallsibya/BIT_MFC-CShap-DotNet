// DirDoc.h : interface of the CDirDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIRDOC_H__D29BFA6F_77A5_4D56_B810_6E92F7DB3B8F__INCLUDED_)
#define AFX_DIRDOC_H__D29BFA6F_77A5_4D56_B810_6E92F7DB3B8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDirDoc : public CDocument
{
protected: // create from serialization only
	CDirDoc();
	DECLARE_DYNCREATE(CDirDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDirDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDirDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDirDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIRDOC_H__D29BFA6F_77A5_4D56_B810_6E92F7DB3B8F__INCLUDED_)
