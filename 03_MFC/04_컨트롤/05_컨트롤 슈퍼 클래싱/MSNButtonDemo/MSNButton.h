#if !defined(AFX_MSNBUTTON_H__70173A5C_3A0D_4AB1_A553_A84A18FC6990__INCLUDED_)
#define AFX_MSNBUTTON_H__70173A5C_3A0D_4AB1_A553_A84A18FC6990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MSNButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMSNButton window

class CMSNButton : public CButton
{
// Construction
public:
	CMSNButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSNButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL	m_bTracking;	//���콺 Ʈ��ŷ ��
	BOOL	m_bHover;		//�����Ͱ� ��ư ���� ����
	BOOL	m_bClicked;		//��ư�� Ŭ���Ǿ���
	virtual ~CMSNButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMSNButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	afx_msg void OnMouseHover(WPARAM wparam, LPARAM lparam) ;

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSNBUTTON_H__70173A5C_3A0D_4AB1_A553_A84A18FC6990__INCLUDED_)
