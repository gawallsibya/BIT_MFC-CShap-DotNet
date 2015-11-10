// ImageEdit.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditDemo.h"
#include "ImageEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageEdit

CImageEdit::CImageEdit()
{
	m_hBrush = ::CreateSolidBrush(RGB(255, 255, 255));
}

CImageEdit::~CImageEdit()
{
	::DeleteObject(m_hBrush);
}


BEGIN_MESSAGE_MAP(CImageEdit, CEdit)
	//{{AFX_MSG_MAP(CImageEdit)
	ON_WM_ERASEBKGND()
	ON_CONTROL_REFLECT(EN_UPDATE, OnUpdate)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageEdit message handlers

BOOL CImageEdit::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	GetClientRect(&rect);
	CDC dcMemory;
	BITMAP bmpInfo;

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_Bitmap_Back);
	bitmap.GetBitmap(&bmpInfo);

	CBrush brush;
	brush.CreatePatternBrush(&bitmap);
	pDC->FillRect(&rect, &brush);

	return TRUE;
//	return CEdit::OnEraseBkgnd(pDC);
}

void CImageEdit::OnUpdate() 
{
	RedrawWindow();
}

HBRUSH CImageEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return m_hBrush;
}
