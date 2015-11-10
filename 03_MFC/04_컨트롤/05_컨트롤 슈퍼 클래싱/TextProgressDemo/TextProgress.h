#if !defined(AFX_TEXTPROGRESS_H__3AD9AF42_7386_443A_A9FE_FE44E9678EEA__INCLUDED_)
#define AFX_TEXTPROGRESS_H__3AD9AF42_7386_443A_A9FE_FE44E9678EEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextProgress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextProgress window

class CTextProgress : public CProgressCtrl
{
// Construction
public:
	CTextProgress();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextProgress)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetValue(int nNewData);
	void InitProgress();
	int m_nData;
	virtual ~CTextProgress();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTextProgress)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPROGRESS_H__3AD9AF42_7386_443A_A9FE_FE44E9678EEA__INCLUDED_)
