#if !defined(AFX_COLORDLG_H__5AF922F8_0F59_4724_A9B1_03E395CFDFA4__INCLUDED_)
#define AFX_COLORDLG_H__5AF922F8_0F59_4724_A9B1_03E395CFDFA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorDlg dialog

class CColorDlg : public CDialog
{
// Construction
public:
	void SetColor();
	CColorDlg(CWnd* pParent = NULL);   // standard constructor
	int m_r, m_b, m_g;
// Dialog Data
	//{{AFX_DATA(CColorDlg)
	enum { IDD = IDD_DIALOG_COLOR };
	CScrollBar	m_Red;
	CScrollBar	m_Green;
	CScrollBar	m_Blue;
	CStatic	m_controltable;
	int		m_BlueVal;
	int		m_GreenVal;
	int		m_RedVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDLG_H__5AF922F8_0F59_4724_A9B1_03E395CFDFA4__INCLUDED_)
