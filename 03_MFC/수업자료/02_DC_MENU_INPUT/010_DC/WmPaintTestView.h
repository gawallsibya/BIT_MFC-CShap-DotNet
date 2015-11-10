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
 [DC�� �����ϴ� Ŭ����] : �׷��� ���õ� ��� ���� �����ϴ� �ٽ����� Ŭ����
 
 1) ȭ�鿡 ����ϱ� ���ؼ��� DC�� �ʿ��ϰ� DC�� �ý����ڿ���̱� ������ ������ 
    �ݳ��ϴ� ���� �ʿ� 
 2) ���� �ش�Ǵ� DC Ŭ���� ����
	
	- class CDC  // ��� �׸��� �Լ��� DC�� �Ӽ��� �ٲٴ� �Լ� ���� 
	  {
		 // �׸��� ��� �Լ� 
		 void Rectangle(int, int, int, int);
	  };
	  CDC *pDC = GetDC();  // �۾� ���� 
	  ReleaseDC(pDC);      // �۾� ���� 

      ==> ���ŷο� �۾��� �ذ��ϱ� ���� CClientDC�� ���� 
	      CDC Ŭ������ ����� ����
		  ���� ����� �� ���� �԰� 
		  �߰� �κ��� ������ �Ҹ��� �κ� 

      // Ŭ���̾�Ʈ ���� �� ��� ���� 
    - class CWindowDC : public CDC
	  {
		// �����ڿ��� GetWindowDC()
		// �Ҹ��ڿ��� ReleaseDC()
	  };

      // Ŭ���̾�Ʈ ������ ��� ���� 
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
		// �׸��� �Լ���...
		void Rectangle( int x, int y, int x2, int y2 )
		{
			// APIȣ��..
			::Rectangle( m_hDC, x, y, x2, y2);
		}
	  };

  3) OnDraw() �Լ��� ���޵� CDC ��ü �����ʹ� Application Framework�� �Ҹ����
     �ֱ� ������ �ڽ��� ���� �Ҹ��Ű�� �ȵȴ�.
	 void CView::OnPaint()
	 {
		CPintDC dc(this);
		OnPrepareDC(&dc);
		OnDraw(&dc);
	 }
	 ==> CPaint �����ڴ� BeginPaint() �Լ��� ȣ���ϰ�
	     �Ҹ��ڴ� EndPaint() �Լ��� ȣ���Ѵ�.
		 ���û� DC�� ������ ��� EndPaint�� �ڵ� ȣ��ȴ�.

----------------------------------------------------------------------------------------
             ���ó							������       �Ҹ���          ��Ÿ 
----------------------------------------------------------------------------------------
CPaintDC    OnDraw,OnPaint������		   BeginPaint	 EndPaint      ��ȿȭ-->��ȿȭ 

CWindowDC   OnDraw,OnPaint ���� ��� ��    GetWindowDC	 ReleaseDC
	
CClientDC   nDraw,OnPaint  ���� ��� ��    GetDC		ReleaseDC
-----------------------------------------------------------------------------------------
*/