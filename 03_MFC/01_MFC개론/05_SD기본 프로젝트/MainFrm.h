// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__F78BB1C7_A426_4A19_B93B_10B7D9351CB8__INCLUDED_)
#define AFX_MAINFRM_H__F78BB1C7_A426_4A19_B93B_10B7D9351CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/*
    - MainFrame Ŭ������ Ÿ��Ʋ ��, �޴��� , ���� �� ���� �ٸ� �����ϴ� �����츦 ��Ÿ����.

 (1) CFrameWnd�κ��� ����� �޴´�. Alt+F12 (Ŭ��������Ȯ��)
     CCmdTarget <= CWnd <= CFrameWnd
     ������ �޽���(CCmdTarget)�� �޾ƾ� �ϸ�, ������(CWnd)�� ������.
*/

class CMainFrame : public CFrameWnd			// (1)
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)			// (2)
/*
(2)  �������� �ڽ��� �����ϱ� ���� �ʿ��� ��ũ��
     F12 : ��ũ���� ���Ǹ� AFX.h���� ã�� �� �ִ�.
     #define DECLARE_DYNCREATE(class_name) \
	  DECLARE_DYNAMIC(class_name) \
	  static CObject* PASCAL CreateObject();

    - DECLARE_DYNAMIC ��ũ�� ����
      �ڽ��� �������� �����ϴ� ���� �ɹ��Լ��� ������ �ִ�.


	#define _DECLARE_DYNAMIC(class_name) \
	protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \	// CRuntimeClass�� �ּҸ� ��� �Լ� 
	public: \
	static AFX_DATA CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \
*/



// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);			// (3)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG										// ����׽� ����ϴ� �����Լ� 
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);		// (4)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/*
(3)(4) ���� �����Լ��� �Ž��� ���� �Լ��� ����Ǵ� �� 

       �����Լ� & �޽��� �ڵ鷯 

       �������� ������ �ʿ��� �Լ�			������ �޽����� �����ϴ� �Լ�
	   ----------------------------------------------------------
    1. �����Լ�								�޽��� �ڵ鷯
    2. ���� ������ public					���� ������ protected
    3. ������ �޽����� ����					WM_���� �����ϴ� ������ �޽����� 
	   Ȥ�� MFC�� ���� 						�����ϴ� �̺�Ʈ �ڵ鷯
*/


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__F78BB1C7_A426_4A19_B93B_10B7D9351CB8__INCLUDED_)
