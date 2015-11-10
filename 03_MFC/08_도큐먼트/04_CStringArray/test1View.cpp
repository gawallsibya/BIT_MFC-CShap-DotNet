// test1View.cpp : implementation of the CTest1View class
//

#include "stdafx.h"
#include "test1.h"

#include "test1Doc.h"
#include "test1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1View

IMPLEMENT_DYNCREATE(CTest1View, CView)

BEGIN_MESSAGE_MAP(CTest1View, CView)
	//{{AFX_MSG_MAP(CTest1View)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1View construction/destruction

CTest1View::CTest1View()
{
	// TODO: add construction code here

}

CTest1View::~CTest1View()
{
}

BOOL CTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View drawing

void CTest1View::OnDraw(CDC* pDC)
{
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View printing

BOOL CTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest1View diagnostics

#ifdef _DEBUG
void CTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1Doc* CTest1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1Doc)));
	return (CTest1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1View message handlers

void CTest1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CStringArray array;
	array.SetSize(10);
	// 1. 
	for(int i=0; i<10; i++)
	{
		// ���������� ����ֱ�
		array.SetAt(i,i+65);
	}
	// 2. �迭�� �߰��� ����... size���� Ȯ��
	array.InsertAt(1, 75); 

	// 3. ���� ������. ���� ����
	array.SetAt(2, "test");
	

	// 4. �迭 ���� �־��ش�.... �迭 ������ ����...
	array.Add("test");

	// 5.
	int test = array.GetSize(); // �迭�� ������ ������....
	CString str;
	str.Format("%d", test);
	MessageBox(str);

	// 6. �� �������� 
	for(i=0; i<10; i++)
	{
		// �� ��������
		CString str = array.GetAt(i);
		MessageBox(str);
	}	

	// �Ǵٸ�  array �迭 �����...
	CStringArray aaa;
	aaa.SetSize(2);
	// 7. �ڽ��� �迭 �ڿ� �ٿ���... 
	aaa.Append(array);	
	for(i =0; i<14; i++)
	{
		CString str = aaa.GetAt(i);
		MessageBox(str);
	}
	
	aaa.RemoveAll();	// ��ü ���� 
	aaa.RemoveAt(2);	// ��ġ�� �ִ� �迭 ����

	CView::OnLButtonDown(nFlags, point);
}


class CPoint3D{
	public:
		CPoint3D() {x=y=z=0;}
 		CPoint3D(int xPos, int yPos, int zPos){x=xPos; y=yPos; z=zPos;}
		int x, y, z;
};

void CTest1View::OnRButtonDown(UINT nFlags, CPoint point) 
{

	// TODO: Add your message handler code here and/or call default
	/*
	// 1.
	CArray<CPoint, CPoint&> array;

	for(int i=0; i<10; i++)
	{
		array.SetAtGrow(i, CPoint(i*10, 0));
		
	}
	for(i=0; i<array.GetSize(); i++)
	{
		CPoint point = array[i];
		CString str;
		str.Format("%d,%d", point.x, point.y);
		MessageBox(str);
	}
	*/

	// 2.
	CArray<CPoint3D, CPoint3D&> array;
// �迭�� ä��� �ʿ信 ���� ������Ų��.
	for(int i=0; i<10; i++)
	{
		array.SetAtGrow(i, CPoint3D(i*10, 0,0));
	}

// �迭�� �׸��� �����Ѵ�.
int nCount = array.GetSize();
	for(i=0; i<nCount; i++){
		CPoint3D point = array[i];
		CString str;
		str.Format("%d, %d, %d", array[i].x, array[i].y, array[i].z);
		MessageBox(str);
}

	CView::OnRButtonDown(nFlags, point);
}
