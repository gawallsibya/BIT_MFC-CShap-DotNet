#if !defined(AFX_NUMEDIT_H__2FF3C7D0_0BB6_472F_B72A_03E86ED869EB__INCLUDED_)
#define AFX_NUMEDIT_H__2FF3C7D0_0BB6_472F_B72A_03E86ED869EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumEdit window

// class를 DLL외부에 노출해야 다른 프로그램에서 사용가능하다.

class AFX_EXT_CLASS CNumEdit : public CEdit
{
// Construction
public:
	CNumEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNumEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMEDIT_H__2FF3C7D0_0BB6_472F_B72A_03E86ED869EB__INCLUDED_)
