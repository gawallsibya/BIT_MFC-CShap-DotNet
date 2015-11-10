
// 0325View.h : CMy0325View 클래스의 인터페이스
//

#pragma once


class CMy0325View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy0325View();
	DECLARE_DYNCREATE(CMy0325View)

// 특성입니다.
public:
	CMy0325Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy0325View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0325View.cpp의 디버그 버전
inline CMy0325Doc* CMy0325View::GetDocument() const
   { return reinterpret_cast<CMy0325Doc*>(m_pDocument); }
#endif

