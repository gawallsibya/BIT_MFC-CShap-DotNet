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
// 1. 기본 DC 확인 
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
// 위의 내용들은 윈도우의 크기 조절시 화면에서 사라짐 
void CWmPaintTestView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
// 화면에서 사라지지 않음 
//  WM_PAINT 메시지가 발생할 때마다 자동으로 호출되는 메시지 
	dc.MoveTo(10, 30);
	dc.LineTo(110, 30);
	dc.MoveTo(10, 40);
	dc.LineTo(110, 40);

/*
	CRect rect;
	GetClientRect(&rect);

	// 네모상자를 그리는 함수(선이 아닌 지정한 색상으로 채워준다.)
	// 시작되는 좌표(x, y), 폭과 높이(10, 10), 지정한 색상)
	dc.FillSolidRect(rect.left, rect.top, 10, 10, RGB(192, 192, 192));

	CPen pen;
	// 새로운 펜 생성 (흰색)
	pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

	dc.SelectObject(&pen);
	// 부채꼴 모양으로 그려줌
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

// 전형적인 코딩 스타일 
void CWmPaintTestView::DrawLine(CPaintDC *pDC)
{
	//1. 새로운 펜을 생성한다.// PS_DOT 확인 
	CPen* pNewPen = new CPen(PS_DASHDOTDOT, 1, RGB(255, 0, 0));
	//2. 본래 DC에 등록된 펜이 무엇인지 저장할 포인터
	CPen* pOldPen = NULL;

	//3. 새로만든 팬을 선택하되 본래의 펜이 무엇인지 기억한다.
	pOldPen = pDC->SelectObject(pNewPen);

	//4. 배경이 투명하도록 지정한 좌표에 선을 긋는다.
	pDC->SetBkMode(TRANSPARENT);
	pDC->MoveTo(100, 100);
	pDC->LineTo(300, 100);

	//5. 본래에 사용하던 펜으로 교체한다.
	pDC->SelectObject(pOldPen);

	//6. 다쓴 펜 객체를 삭제한다.
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
	// 폭과 높이가 정확하게 100
	// 펜의 두께가 바뀌어도 100 을 넘지 않는다.
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
	// 선이 정확하게 넣어준 값 범위에서 그려진다. 
	nStyle[2] = PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT;

	CPen* pNewPen = NULL;
	CPen* pOldPen = NULL;

	//생성할 펜에 대한 정보를 구조체에 넣는다.
	// 펜의 색상과 스타일 정의 가능 
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0, 0, 255);	//파란색

	for(int i = 0; i < 3; i++)
	{
		//LOGBRUSH 구조체를 이용하여 펜을 생성한다.
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

		//ㄱ자 모양으로 선을 그리되 이 두 선을 서로 패스로 묶어준다.
		// BeginPath EndPath의 역할 : 사이의 선이 연결선음을 암시 
		pDC->BeginPath();
		pDC->MoveTo(100 + i * 120, 200);
		pDC->LineTo(200 + i * 120, 200);
		pDC->LineTo(200 + i * 120, 200 + 50);
		pDC->EndPath();
		//두 연결된 선의 꺽어진 부분에 대해 Join 스타일을 적용하여 랜더링한다.
		// 여기서 그려주게 됨 
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
	//녹색의 Solid 브러시를 생성한다.
	CBrush* pNewBrush = new CBrush(RGB(0, 255, 0));
	CBrush* pOldBrush = NULL;

	pOldBrush = pDC->SelectObject(pNewBrush);
	//녹색으로 칠해진 네모가 그려진다.
	pDC->Rectangle(CRect(210, 200, 310, 300));

	pDC->SelectObject(pOldBrush);
	delete pNewBrush;

	ReleaseDC(pDC);
}

void CWmPaintTestView::OnMenuHatchBrush() 
{
	CDC* pDC = GetDC();
	//격자 무늬의 해치 브러시를 생성한다.
	CBrush* pNewBrush = new CBrush(HS_VERTICAL, RGB(255, 0, 0));
	CBrush* pOldBrush = NULL;

	pOldBrush = pDC->SelectObject(pNewBrush);
	pDC->SetBkMode(TRANSPARENT);
	//격자 무늬가 입혀진 네모가 그려진다.
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

	//비트맵 파일을 로딩한다.
	Bmp.LoadBitmap(IDB_Bitmap_Pattern);
	//비트맵을 가지고 패턴 브러시를 생성한다.
	pNewBrush->CreatePatternBrush(&Bmp);
	pOldBrush = pDC->SelectObject(pNewBrush);
	//비트맵 패턴이 입혀진 네모가 그려진다.
	pDC->Rectangle(CRect(210, 200, 310, 300));

	pDC->SelectObject(pOldBrush);
	delete pNewBrush;

	ReleaseDC(pDC);
}
