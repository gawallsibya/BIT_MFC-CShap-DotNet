// PASSCALDlg.h : header file
//

#if !defined(AFX_PASSCALDLG_H__388921EF_48E1_4BB8_9886_A5CA23AA396F__INCLUDED_)
#define AFX_PASSCALDLG_H__388921EF_48E1_4BB8_9886_A5CA23AA396F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPASSCALDlg dialog

class CPASSCALDlg : public CDialog
{
// Construction
public:
	CPASSCALDlg(CWnd* pParent = NULL);	// standard constructor
	HINSTANCE m_hInstDll; // DLL의 인스턴스 핸들

// Dialog Data
	//{{AFX_DATA(CPASSCALDlg)
	enum { IDD = IDD_PASSCAL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPASSCALDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPASSCALDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRuntimeLink();
	afx_msg void OnImportLib();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSCALDLG_H__388921EF_48E1_4BB8_9886_A5CA23AA396F__INCLUDED_)
