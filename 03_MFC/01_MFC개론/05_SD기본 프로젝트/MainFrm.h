// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__F78BB1C7_A426_4A19_B93B_10B7D9351CB8__INCLUDED_)
#define AFX_MAINFRM_H__F78BB1C7_A426_4A19_B93B_10B7D9351CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/*
    - MainFrame 클래스는 타이틀 바, 메뉴바 , 툴바 및 상태 바를 포함하는 윈도우를 나타낸다.

 (1) CFrameWnd로부터 상속을 받는다. Alt+F12 (클래스계층확인)
     CCmdTarget <= CWnd <= CFrameWnd
     윈도우 메시지(CCmdTarget)을 받아야 하며, 윈도우(CWnd)를 가진다.
*/

class CMainFrame : public CFrameWnd			// (1)
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)			// (2)
/*
(2)  동적으로 자신을 생성하기 위해 필요한 매크로
     F12 : 매크로의 정의를 AFX.h에서 찾을 수 있다.
     #define DECLARE_DYNCREATE(class_name) \
	  DECLARE_DYNAMIC(class_name) \
	  static CObject* PASCAL CreateObject();

    - DECLARE_DYNAMIC 매크로 포함
      자신을 동적으로 생성하는 정적 맴버함수의 선언이 있다.


	#define _DECLARE_DYNAMIC(class_name) \
	protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \	// CRuntimeClass의 주소를 얻는 함수 
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
#ifdef _DEBUG										// 디버그시 사용하는 진단함수 
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
(3)(4) 각각 가상함수와 매시지 맵의 함수가 선언되는 곳 

       가상함수 & 메시지 핸들러 

       윈도우의 구조상 필요한 함수			윈도우 메시지에 대응하는 함수
	   ----------------------------------------------------------
    1. 가상함수								메시지 핸들러
    2. 접근 권한은 public					접근 권한은 protected
    3. 윈도우 메시지의 순서					WM_으로 시작하는 윈도우 메시지에 
	   혹은 MFC의 내부 						대응하는 이벤트 핸들러
*/


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__F78BB1C7_A426_4A19_B93B_10B7D9351CB8__INCLUDED_)
