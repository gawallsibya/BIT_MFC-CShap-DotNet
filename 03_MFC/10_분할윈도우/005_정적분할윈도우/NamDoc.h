// NamDoc.h : interface of the CNamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMDOC_H__0464396D_885A_4C09_B99E_2DE6CD53A2D3__INCLUDED_)
#define AFX_NAMDOC_H__0464396D_885A_4C09_B99E_2DE6CD53A2D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamDoc : public CDocument
{
protected: // create from serialization only
	CNamDoc();
	DECLARE_DYNCREATE(CNamDoc)

// Attributes
public:
	CString  m_str;
	COLORREF m_color;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMDOC_H__0464396D_885A_4C09_B99E_2DE6CD53A2D3__INCLUDED_)
