#if !defined(AFX_PIXELDLG_H__E4F05BB6_0857_11D2_B6E8_B785B166E236__INCLUDED_)
#define AFX_PIXELDLG_H__E4F05BB6_0857_11D2_B6E8_B785B166E236__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PixelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPixelDlg dialog

class CPixelDlg : public CDialog
{
// Construction
public:
	void SendCurrentColor(COLORREF color);
	void CurrentPixelColor(COLORREF color);
	CPixelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPixelDlg)
	enum { IDD = IDD_MODELESS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPixelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPixelDlg)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnOK();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIXELDLG_H__E4F05BB6_0857_11D2_B6E8_B785B166E236__INCLUDED_)
