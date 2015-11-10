// WmPaintTestView.h : interface of the CWmPaintTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMPAINTTESTVIEW_H__D5BD285B_D18C_4396_8C60_BA2EB82850B9__INCLUDED_)
#define AFX_WMPAINTTESTVIEW_H__D5BD285B_D18C_4396_8C60_BA2EB82850B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWmPaintTestView : public CView
{
protected: // create from serialization only
	CWmPaintTestView();
	DECLARE_DYNCREATE(CWmPaintTestView)

// Attributes
public:
	CWmPaintTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmPaintTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawLine(CPaintDC* pDC);
	virtual ~CWmPaintTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWmPaintTestView)
	afx_msg void OnMenuDrawLine1();
	afx_msg void OnMenuDrawLine2();
	afx_msg void OnPaint();
	afx_msg void OnMenuPSNormal();
	afx_msg void OnMenuPSINSIDE();
	afx_msg void OnMenuGMEndcap();
	afx_msg void OnMenuGMJoin();
	afx_msg void OnMenuSolidBrush();
	afx_msg void OnMenuHatchBrush();
	afx_msg void OnMenuPatternBrush();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WmPaintTestView.cpp
inline CWmPaintTestDoc* CWmPaintTestView::GetDocument()
   { return (CWmPaintTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPAINTTESTVIEW_H__D5BD285B_D18C_4396_8C60_BA2EB82850B9__INCLUDED_)

/*
 [DC를 제공하는 클래스] : 그랙픽 관련된 모든 일을 수행하는 핵심적인 클래스
 
 1) 화면에 출력하기 위해서는 DC가 필요하고 DC는 시스템자우너이기 때문에 얻어오고 
    반납하는 과정 필요 
 2) 각각 해당되는 DC 클래스 제공
	
	- class CDC  // 모든 그리는 함수와 DC의 속성을 바꾸는 함수 제공 
	  {
		 // 그리는 모든 함수 
		 void Rectangle(int, int, int, int);
	  };
	  CDC *pDC = GetDC();  // 작업 수행 
	  ReleaseDC(pDC);      // 작업 종료 

      ==> 번거로운 작업을 해결하기 위해 CClientDC를 제공 
	      CDC 클래스의 상속을 받음
		  위의 기능을 다 갖고 왔고 
		  추가 부분은 생성자 소멸자 부분 

      // 클라이언트 영역 외 출력 가능 
    - class CWindowDC : public CDC
	  {
		// 생성자에서 GetWindowDC()
		// 소멸자에서 ReleaseDC()
	  };

      // 클라이언트 영역내 출력 가능 
    - class _CClientDC : public CDC
	  {
		public:
			HWND m_hWnd;
			HDC  m_hDC;
		_CClientDC( CWnd* pWnd )
		{
			m_hWnd = pWnd->m_hWnd;
			m_hDC = ::GetDC(m_hWnd);
		}
		~_CClientDC( ) { ::ReleaseDC( m_hWnd, m_hDC);}
		// 그리기 함수들...
		void Rectangle( int x, int y, int x2, int y2 )
		{
			// API호출..
			::Rectangle( m_hDC, x, y, x2, y2);
		}
	  };

  3) OnDraw() 함수에 전달된 CDC 객체 포인터는 Application Framework가 소멸시켜
     주기 때문에 자신이 직접 소멸시키면 안된다.
	 void CView::OnPaint()
	 {
		CPintDC dc(this);
		OnPrepareDC(&dc);
		OnDraw(&dc);
	 }
	 ==> CPaint 생성자는 BeginPaint() 함수를 호출하고
	     소멸자는 EndPaint() 함수를 호출한다.
		 스택상에 DC를 생성한 경우 EndPaint는 자동 호출된다.

----------------------------------------------------------------------------------------
             사용처							생성자       소멸자          기타 
----------------------------------------------------------------------------------------
CPaintDC    OnDraw,OnPaint에서만		   BeginPaint	 EndPaint      무효화-->유효화 

CWindowDC   OnDraw,OnPaint 제외 모든 곳    GetWindowDC	 ReleaseDC
	
CClientDC   nDraw,OnPaint  제외 모든 곳    GetDC		ReleaseDC
-----------------------------------------------------------------------------------------
*/