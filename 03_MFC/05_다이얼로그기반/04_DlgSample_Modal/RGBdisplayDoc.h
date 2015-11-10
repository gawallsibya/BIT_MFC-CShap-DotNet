// RGBdisplayDoc.h : interface of the CRGBdisplayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGBDISPLAYDOC_H__863FD23C_C451_41A1_BD24_AFD17EC70813__INCLUDED_)
#define AFX_RGBDISPLAYDOC_H__863FD23C_C451_41A1_BD24_AFD17EC70813__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRGBdisplayDoc : public CDocument
{
protected: // create from serialization only
	CRGBdisplayDoc();
	DECLARE_DYNCREATE(CRGBdisplayDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGBdisplayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRGBdisplayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRGBdisplayDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGBDISPLAYDOC_H__863FD23C_C451_41A1_BD24_AFD17EC70813__INCLUDED_)
