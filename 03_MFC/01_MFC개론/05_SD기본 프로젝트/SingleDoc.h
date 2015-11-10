// SingleDoc.h : interface of the CSingleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEDOC_H__2F814E29_892E_4A8A_8913_730C6F264DC9__INCLUDED_)
#define AFX_SINGLEDOC_H__2F814E29_892E_4A8A_8913_730C6F264DC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSingleDoc : public CDocument
{
protected: // create from serialization only
	CSingleDoc();
	DECLARE_DYNCREATE(CSingleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSingleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSingleDoc)
	afx_msg void OnTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEDOC_H__2F814E29_892E_4A8A_8913_730C6F264DC9__INCLUDED_)
