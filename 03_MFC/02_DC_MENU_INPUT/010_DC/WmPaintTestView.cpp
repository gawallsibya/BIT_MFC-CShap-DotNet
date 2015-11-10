// WmPaintTestView.cpp : implementation of the CWmPaintTestView class
//

#include "stdafx.h"
#include "WmPaintTest.h"

#include "WmPaintTestDoc.h"
#include "WmPaintTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestView

IMPLEMENT_DYNCREATE(CWmPaintTestView, CView)

BEGIN_MESSAGE_MAP(CWmPaintTestView, CView)
	//{{AFX_MSG_MAP(CWmPaintTestView)
	ON_COMMAND(ID_Menu_DrawLine1, OnMenuDrawLine1)
	ON_COMMAND(ID_Menu_DrawLine2, OnMenuDrawLine2)
	ON_WM_PAINT()
	ON_COMMAND(ID_Menu_PS_Normal, OnMenuPSNormal)
	ON_COMMAND(ID_Menu_PS_INSIDE, OnMenuPSINSIDE)
	ON_COMMAND(ID_Menu_GM_Endcap, OnMenuGMEndcap)
	ON_COMMAND(ID_Menu_GM_Join, OnMenuGMJoin)
	ON_COMMAND(ID_Menu_SolidBrush, OnMenuSolidBrush)
	ON_COMMAND(ID_Menu_HatchBrush, OnMenuHatchBrush)
	ON_COMMAND(ID_Menu_PatternBrush, OnMenuPatternBrush)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestView construction/destruction

CWmPaintTestView::CWmPaintTestView()
{
	// TODO: add construction code here

}

CWmPaintTestView::~CWmPaintTestView()
{
}

BOOL CWmPaintTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestView drawing

void CWmPaintTestView::OnDraw(CDC* pDC)
{
	CWmPaintTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

}

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestView printing

BOOL CWmPaintTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWmPaintTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWmPaintTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestView diagnostics

#ifdef _DEBUG
void CWmPaintTestView::AssertValid() const
{
	CView::AssertValid();
}

void CWmPaintTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWmPaintTestDoc* CWmPaintTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWmPaintTestDoc)));
	return (CWmPaintTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWmPaintTestView message handlers
// 1. �⺻ DC Ȯ�� 
void CWmPaintTestView::OnMenuDrawLine1() 
{
	// TODO: Add your command handler code here
	CDC* pDC = GetDC();

	pDC->MoveTo(10, 10);
	pDC->LineTo(110, 10);

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuDrawLine2() 
{
	// TODO: Add your command handler code here
	CDC* pDC = GetDC();

	pDC->MoveTo(10, 20);
	pDC->LineTo(110, 20);

	ReleaseDC(pDC);
}
// ���� ������� �������� ũ�� ������ ȭ�鿡�� ����� 
void CWmPaintTestView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
// ȭ�鿡�� ������� ���� 
//  WM_PAINT �޽����� �߻��� ������ �ڵ����� ȣ��Ǵ� �޽��� 
	dc.MoveTo(10, 30);
	dc.LineTo(110, 30);
	dc.MoveTo(10, 40);
	dc.LineTo(110, 40);

/*
	CRect rect;
	GetClientRect(&rect);

	// �׸���ڸ� �׸��� �Լ�(���� �ƴ� ������ �������� ä���ش�.)
	// ���۵Ǵ� ��ǥ(x, y), ���� ����(10, 10), ������ ����)
	dc.FillSolidRect(rect.left, rect.top, 10, 10, RGB(192, 192, 192));

	CPen pen;
	// ���ο� �� ���� (���)
	pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

	dc.SelectObject(&pen);
	// ��ä�� ������� �׷���
	dc.Pie(CRect(0, 0, 40, 40),
		CPoint(20, 0),
		CPoint(0, 20));

	dc.FillSolidRect(0, 0, 4, rect.bottom, RGB(192, 192, 192));	
	dc.FillSolidRect(0, 0, rect.right, 4, RGB(192, 192, 192));

// 2. Cen
	DrawLine(&dc);
*/
	// Do not call CView::OnPaint() for painting messages
}

// �������� �ڵ� ��Ÿ�� 
void CWmPaintTestView::DrawLine(CPaintDC *pDC)
{
	//1. ���ο� ���� �����Ѵ�.// PS_DOT Ȯ�� 
	CPen* pNewPen = new CPen(PS_DASHDOTDOT, 1, RGB(255, 0, 0));
	//2. ���� DC�� ��ϵ� ���� �������� ������ ������
	CPen* pOldPen = NULL;

	//3. ���θ��� ���� �����ϵ� ������ ���� �������� ����Ѵ�.
	pOldPen = pDC->SelectObject(pNewPen);

	//4. ����� �����ϵ��� ������ ��ǥ�� ���� �ߴ´�.
	pDC->SetBkMode(TRANSPARENT);
	pDC->MoveTo(100, 100);
	pDC->LineTo(300, 100);

	//5. ������ ����ϴ� ������ ��ü�Ѵ�.
	pDC->SelectObject(pOldPen);

	//6. �پ� �� ��ü�� �����Ѵ�.
	delete pNewPen;
}

void CWmPaintTestView::OnMenuPSNormal() 
{
	CDC* pDC = GetDC();
	CPen* pNewPen = new CPen(PS_SOLID, 10, RGB(255, 0, 0));
	CPen* pOldPen = NULL;

	pOldPen = pDC->SelectObject(pNewPen);

	pDC->SetBkMode(TRANSPARENT);
	pDC->Rectangle(CRect(100, 200, 200, 300));

	pDC->SelectObject(pOldPen);
	delete pNewPen;

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuPSINSIDE() 
{
	CDC* pDC = GetDC();
	// ���� ���̰� ��Ȯ�ϰ� 100
	// ���� �β��� �ٲ� 100 �� ���� �ʴ´�.
	CPen* pNewPen = new CPen(PS_SOLID | PS_INSIDEFRAME,
									10, RGB(255, 0, 0));
	CPen* pOldPen = NULL;

	pOldPen = pDC->SelectObject(pNewPen);

	pDC->SetBkMode(TRANSPARENT);
	pDC->Rectangle(CRect(210, 200, 310, 300));

	pDC->SelectObject(pOldPen);
	delete pNewPen;

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuGMEndcap() 
{
	CDC* pDC = GetDC();
	int nStyle[3];
	nStyle[0] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND;
	nStyle[1] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_SQUARE;
	// ���� ��Ȯ�ϰ� �־��� �� �������� �׷�����. 
	nStyle[2] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT;

	CPen* pNewPen = NULL;
	CPen* pOldPen = NULL;

	//������ �濡 ���� ������ ����ü�� �ִ´�.
	// ���� ����� ��Ÿ�� ���� ���� 
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 0, 255);	//�Ķ���

	for(int i = 0; i < 3; i++)
	{
		//LOGBRUSH ����ü�� �̿��Ͽ� ���� �����Ѵ�.
		pNewPen = new CPen(nStyle[i], 16, &lb);
		pOldPen = pDC->SelectObject(pNewPen);

		pDC->MoveTo(100, 200 + i * 20);
		pDC->LineTo(200, 200 + i * 20);

		pDC->SelectObject(pOldPen);
		delete pNewPen;
	}

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuGMJoin() 
{
	CDC* pDC = GetDC();
	int nStyle[3];
	nStyle[0] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_BEVEL;
	nStyle[1] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND;
	nStyle[2] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_MITER;

	CPen* pNewPen = NULL;
	CPen* pOldPen = NULL;

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 0, 255);

	for(int i = 0; i < 3; i++)
	{
		pNewPen = new CPen(nStyle[i], 16, &lb);
		pOldPen = pDC->SelectObject(pNewPen);

		//���� ������� ���� �׸��� �� �� ���� ���� �н��� �����ش�.
		// BeginPath EndPath�� ���� : ������ ���� ���ἱ���� �Ͻ� 
		pDC->BeginPath();
		pDC->MoveTo(100 + i * 120, 200);
		pDC->LineTo(200 + i * 120, 200);
		pDC->LineTo(200 + i * 120, 200 + 50);
		pDC->EndPath();
		//�� ����� ���� ������ �κп� ���� Join ��Ÿ���� �����Ͽ� �������Ѵ�.
		// ���⼭ �׷��ְ� �� 
		pDC->StrokePath();

		pDC->SelectObject(pOldPen);
		delete pNewPen;
	}

	ReleaseDC(pDC);
}

// Brush 
void CWmPaintTestView::OnMenuSolidBrush() 
{
	CDC* pDC = GetDC();
	//����� Solid �귯�ø� �����Ѵ�.
	CBrush* pNewBrush = new CBrush(RGB(0, 255, 0));
	CBrush* pOldBrush = NULL;

	pOldBrush = pDC->SelectObject(pNewBrush);
	//������� ĥ���� �׸� �׷�����.
	pDC->Rectangle(CRect(210, 200, 310, 300));

	pDC->SelectObject(pOldBrush);
	delete pNewBrush;

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuHatchBrush() 
{
	CDC* pDC = GetDC();
	//���� ������ ��ġ �귯�ø� �����Ѵ�.
	CBrush* pNewBrush = new CBrush(HS_VERTICAL, RGB(255, 0, 0));
	CBrush* pOldBrush = NULL;

	pOldBrush = pDC->SelectObject(pNewBrush);
	pDC->SetBkMode(TRANSPARENT);
	//���� ���̰� ������ �׸� �׷�����.
	pDC->Rectangle(CRect(210, 200, 310, 240));

	pDC->SelectObject(pOldBrush);
	delete pNewBrush;

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuPatternBrush() 
{
	CDC* pDC = GetDC();
	CBitmap	Bmp;
	CBrush* pNewBrush = new CBrush;
	CBrush* pOldBrush = NULL;

	//��Ʈ�� ������ �ε��Ѵ�.
	Bmp.LoadBitmap(IDB_Bitmap_Pattern);
	//��Ʈ���� ������ ���� �귯�ø� �����Ѵ�.
	pNewBrush->CreatePatternBrush(&Bmp);
	pOldBrush = pDC->SelectObject(pNewBrush);
	//��Ʈ�� ������ ������ �׸� �׷�����.
	pDC->Rectangle(CRect(210, 200, 310, 300));

	pDC->SelectObject(pOldBrush);
	delete pNewBrush;

	ReleaseDC(pDC);
}
