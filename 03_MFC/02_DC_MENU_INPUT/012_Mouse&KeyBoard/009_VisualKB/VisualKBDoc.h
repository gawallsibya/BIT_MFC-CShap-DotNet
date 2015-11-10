// VisualKBDoc.h : interface of the CVisualKBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VISUALKBDOC_H__10644946_C47C_4B42_BE91_0540D0169F55__INCLUDED_)
#define AFX_VISUALKBDOC_H__10644946_C47C_4B42_BE91_0540D0169F55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVisualKBDoc : public CDocument
{
protected: // create from serialization only
	CVisualKBDoc();
	DECLARE_DYNCREATE(CVisualKBDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualKBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVisualKBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVisualKBDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISUALKBDOC_H__10644946_C47C_4B42_BE91_0540D0169F55__INCLUDED_)
