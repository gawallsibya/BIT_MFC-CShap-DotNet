// TicTacDoc.h : interface of the CTicTacDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TICTACDOC_H__CD14B353_5A28_42C1_9E1D_5A0E0F601452__INCLUDED_)
#define AFX_TICTACDOC_H__CD14B353_5A28_42C1_9E1D_5A0E0F601452__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTicTacDoc : public CDocument
{
protected: // create from serialization only
	CTicTacDoc();
	DECLARE_DYNCREATE(CTicTacDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicTacDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTicTacDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTicTacDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICTACDOC_H__CD14B353_5A28_42C1_9E1D_5A0E0F601452__INCLUDED_)
