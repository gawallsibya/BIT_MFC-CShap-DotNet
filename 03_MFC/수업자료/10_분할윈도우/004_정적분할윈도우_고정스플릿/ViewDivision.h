#pragma once


// ViewDivision ���Դϴ�.

class ViewDivision : public CView
{
	DECLARE_DYNCREATE(ViewDivision)

protected:
	ViewDivision();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~ViewDivision();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


