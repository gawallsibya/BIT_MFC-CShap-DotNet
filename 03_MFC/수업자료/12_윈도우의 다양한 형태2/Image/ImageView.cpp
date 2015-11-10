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
	
	// 비트맵 출력하기.
	CBitmap bitmap;
	bitmap.Attach( m_hBitmap ); // 핸들을 MFC 객체에 붙인다.

	// Handle->MFC 객체로 바꾸기 
	//CBitmap* pbitmap = CBitmap::FromHandle( m_hBitmap);

	// 1.화면 DC와 호환되는 메모리 DC 만들기.
	CDC memDC;
	memDC.CreateCompatibleDC( pDC );

	// 2. 메모리 DC에 비트맵 넣기.
	memDC.SelectObject( &bitmap);

	// 3. 메모리 DC->화면 DC로 옮기기.
	CRect r; GetClientRect( &r );

	int x = ( r.Width() - m_bm.bmWidth) /2;
	int y = ( r.Height() - m_bm.bmHeight) /2;

	pDC->BitBlt(x, y, m_bm.bmWidth, m_bm.bmHeight,
					&memDC, 0,0, SRCCOPY);
	
	bitmap.Detach(); // 핸들을 떼어 낸다.
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
	// Bitmap 화일을 Load한다.
	m_hBitmap = (HBITMAP)LoadImage( 0, path, IMAGE_BITMAP, 
								0,0, // 크기(Icon, Cursor만사용)
								LR_LOADFROMFILE);

	// bitmap의 헤더정보를 얻어 둔다.
	GetObject( m_hBitmap, sizeof(m_bm), &m_bm); 

	// 화면을 무효화 해서 bitmap을 화면에 출력하게 한다.
	InvalidateRect(0);
}

int CImageView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// 초기에 Bitmap을 Load한다.
	
	Refresh( "C:\\Winnt\\회벽.bmp");

	return 0;
}
