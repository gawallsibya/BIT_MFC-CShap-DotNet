// ImageView.cpp : implementation of the CImageView class
//

#include "stdafx.h"
#include "Image.h"

#include "ImageDoc.h"
#include "ImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageView

IMPLEMENT_DYNCREATE(CImageView, CView)

BEGIN_MESSAGE_MAP(CImageView, CView)
	//{{AFX_MSG_MAP(CImageView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageView construction/destruction

CImageView::CImageView()
{
	// TODO: add construction code here

}

CImageView::~CImageView()
{
}

BOOL CImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageView drawing

void CImageView::OnDraw(CDC* pDC)
{
	CImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	// ��Ʈ�� ����ϱ�.
	CBitmap bitmap;
	bitmap.Attach( m_hBitmap ); // �ڵ��� MFC ��ü�� ���δ�.

	// Handle->MFC ��ü�� �ٲٱ� 
	//CBitmap* pbitmap = CBitmap::FromHandle( m_hBitmap);

	// 1.ȭ�� DC�� ȣȯ�Ǵ� �޸� DC �����.
	CDC memDC;
	memDC.CreateCompatibleDC( pDC );

	// 2. �޸� DC�� ��Ʈ�� �ֱ�.
	memDC.SelectObject( &bitmap);

	// 3. �޸� DC->ȭ�� DC�� �ű��.
	CRect r; GetClientRect( &r );

	int x = ( r.Width() - m_bm.bmWidth) /2;
	int y = ( r.Height() - m_bm.bmHeight) /2;

	pDC->BitBlt(x, y, m_bm.bmWidth, m_bm.bmHeight,
					&memDC, 0,0, SRCCOPY);
	
	bitmap.Detach(); // �ڵ��� ���� ����.
}

/////////////////////////////////////////////////////////////////////////////
// CImageView printing

BOOL CImageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageView diagnostics

#ifdef _DEBUG
void CImageView::AssertValid() const
{
	CView::AssertValid();
}

void CImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageDoc* CImageView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageDoc)));
	return (CImageDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageView message handlers

void CImageView::Refresh(CString path)
{
	// Bitmap ȭ���� Load�Ѵ�.
	m_hBitmap = (HBITMAP)LoadImage( 0, path, IMAGE_BITMAP, 
								0,0, // ũ��(Icon, Cursor�����)
								LR_LOADFROMFILE);

	// bitmap�� ��������� ��� �д�.
	GetObject( m_hBitmap, sizeof(m_bm), &m_bm); 

	// ȭ���� ��ȿȭ �ؼ� bitmap�� ȭ�鿡 ����ϰ� �Ѵ�.
	InvalidateRect(0);
}

int CImageView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// �ʱ⿡ Bitmap�� Load�Ѵ�.
	
	Refresh( "C:\\Winnt\\ȸ��.bmp");

	return 0;
}
