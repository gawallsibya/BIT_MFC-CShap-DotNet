// TESTDoc.h : interface of the CTESTDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTDOC_H__8BC8B278_9A3C_452F_8399_2FB19D3D3034__INCLUDED_)
#define AFX_TESTDOC_H__8BC8B278_9A3C_452F_8399_2FB19D3D3034__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTESTDoc : public CDocument
{
protected: // create from serialization only
	CTESTDoc();
	DECLARE_DYNCREATE(CTESTDoc)

public:
	CPoint data[50];
	int count;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTESTDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTESTDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTESTDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDOC_H__8BC8B278_9A3C_452F_8399_2FB19D3D3034__INCLUDED_)
