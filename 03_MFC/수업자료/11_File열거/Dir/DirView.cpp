// DirView.cpp : implementation of the CDirView class
//

#include "stdafx.h"
#include "Dir.h"

#include "DirDoc.h"
#include "DirView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDirView

IMPLEMENT_DYNCREATE(CDirView, CTreeView)

BEGIN_MESSAGE_MAP(CDirView, CTreeView)
	//{{AFX_MSG_MAP(CDirView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDirView construction/destruction

CDirView::CDirView()
{
	// TODO: add construction code here

}

CDirView::~CDirView()
{
}

BOOL CDirView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDirView drawing

void CDirView::OnDraw(CDC* pDC)
{
	CDirDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}
// View 가 Document 에 처음 붙일때 호출. 주로 view의 초기화 Code
// 는 여기서 만든다.
void CDirView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	
	/////////////////////////////////////
	// TreeView가 가지고 있는 TreeControl을 얻어 온다.
	CTreeCtrl& t = GetTreeCtrl();

	// Tree 1단계. Image List연결하기
	CImageList img;
	img.Create( IDB_BITMAP1,	// resource id 
							16, // width
							  1, // grow size
					RGB(255,255,255) ); // 투명하게 처리할 색.

	t.SetImageList( &img, TVSIL_NORMAL );

	img.Detach(); // handle 보호.
	///////////////////////////////////////////////
	// Step 2. Tree에 항목 넣기.
	/*
	TVINSERTSTRUCT tv;
	tv.hParent =  0;
	tv.hInsertAfter = TVI_SORT;
	tv.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	tv.item.pszText = "AAA";
	tv.item.iImage = 0;
	tv.item.iSelectedImage = 1;

	HTREEITEM hItem = t.InsertItem(&tv);
*/
	// Tree Style 지정하기.
	ModifyStyle( 0, TVS_HASLINES | TVS_HASBUTTONS | 
					TVS_LINESATROOT);


	HTREEITEM hItem = t.InsertItem( "AAA", 0, // imagelist no
										1 );  // selected image
	t.InsertItem( "AAA", 0, 1, hItem );
	t.InsertItem( "AAA", 0, 1, hItem );

	HTREEITEM hItem2 = t.InsertItem( "AAA", 0, 1, hItem );
	t.InsertItem( "AAA", 0, 1, hItem2 );
	t.InsertItem( "AAA", 0, 1, hItem2 );



}

/////////////////////////////////////////////////////////////////////////////
// CDirView printing

BOOL CDirView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDirView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDirView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDirView diagnostics

#ifdef _DEBUG
void CDirView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CDirView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CDirDoc* CDirView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDirDoc)));
	return (CDirDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDirView message handlers
