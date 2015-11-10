#if !defined(AFX_PROGRESSSTATUSBAR_H__67A4A742_BC17_4DA5_9EA0_4C3D0D9CF8D4__INCLUDED_)
#define AFX_PROGRESSSTATUSBAR_H__67A4A742_BC17_4DA5_9EA0_4C3D0D9CF8D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgressStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar window

class CProgressStatusBar : public CStatusBar
{
private:
	CProgressCtrl m_wndProgress;

	UINT m_nPane; // Progress 가 놓인 pane의 위치 기록.
public:
	CProgressCtrl& GetProgressCtrl()
	{
		return m_wndProgress; // progress의 참조를 리턴.
	}

// Construction
public:
	CProgressStatusBar();


// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetProgressPos(int nPos);
	void CreateProgress(UINT nPane, int nWidth);
	virtual ~CProgressStatusBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CProgressStatusBar)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSSTATUSBAR_H__67A4A742_BC17_4DA5_9EA0_4C3D0D9CF8D4__INCLUDED_)
