// LeftView.cpp : implementation file
//

#include "stdafx.h"
#include "Image.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

CLeftView::CLeftView()
{
}

CLeftView::~CLeftView()
{
}


BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_COMMAND(IDM_CHANGE_FOLDER, OnChangeFolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

void CLeftView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TreeControl 의 참조를 얻는다.
	CTreeCtrl& t = GetTreeCtrl();

	CImageList img;
	img.Create( IDB_BITMAP1, 16, 1, RGB(255,255,255) );
	t.SetImageList( &img, TVSIL_NORMAL );

	img.Detach(); // 핸들 보호.

	// Tree 를 채운다.
	char buf[256];
	GetWindowsDirectory(buf, 256); // windows가 설치된 디렉토리

	Refresh( buf );
}

void CLeftView::Refresh(CString path)
{
	SetCurrentDirectory( path );
	CFileFind f;
	BOOL b = f.FindFile("*.bmp");
	
	CTreeCtrl& t = GetTreeCtrl(); // !!
	t.DeleteAllItems();

	while ( b )
	{
		b = f.FindNextFile();

		t.InsertItem( f.GetFileName(), 0, 0);
	}
}
#include "ImageView.h"

void CLeftView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	CTreeCtrl& t = GetTreeCtrl();

	HTREEITEM hItem = t.GetSelectedItem();

	CString item = t.GetItemText( hItem);

	char path[256];
	GetCurrentDirectory(256, path );
	strcat( path, "\\");
	strcat( path, item );

	// bitmap을 다시 Load하게 한다
	// 1. splitter의 Pointer를 얻는다.
	CSplitterWnd* p = (CSplitterWnd*)GetParent();

	// 2. Splitter에게 오른쪽 창의 주소를 물어 본다.
	CImageView* pRight = (CImageView*)(p->GetPane( 0,1)); // 

	pRight->Refresh( path );  // ??

	*pResult = 0;
}

void CLeftView::OnChangeFolder() 
{
	BROWSEINFO bi = {0};

	bi.hwndOwner = this->m_hWnd;
	bi.lpszTitle = "그림이 있는 폴더를 선택해 주세요";
	LPITEMIDLIST pidl = SHBrowseForFolder( &bi );

	char buf[256];
	SHGetPathFromIDList( pidl, buf );

	Refresh( buf );
}
