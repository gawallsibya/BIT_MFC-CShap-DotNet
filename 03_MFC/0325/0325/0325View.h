
// 0325View.h : CMy0325View Ŭ������ �������̽�
//

#pragma once


class CMy0325View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy0325View();
	DECLARE_DYNCREATE(CMy0325View)

// Ư���Դϴ�.
public:
	CMy0325Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMy0325View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0325View.cpp�� ����� ����
inline CMy0325Doc* CMy0325View::GetDocument() const
   { return reinterpret_cast<CMy0325Doc*>(m_pDocument); }
#endif

