// LeftView.cpp : implementation of the CLeftView class
//

#include "stdafx.h"
#include "MyExplorer.h"

#include "MyExplorerDoc.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView construction/destruction

CLeftView::CLeftView()
{
	// TODO: add construction code here

}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CMyExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


/////////////////////////////////////////////////////////////////////////////
// CLeftView printing

BOOL CLeftView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLeftView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLeftView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: You may populate your TreeView with items by directly accessing
	//  its tree control through a call to GetTreeCtrl().
	// 폴더 내용을 초기화 시킨다.
	CStringArray	driveNames;

	// 컴퓨터에 현재 설정되어져 있는 모든 
	// 디스크 드라이브의 이름들을 얻어내는 사용자 정의 함수 
	GetDriveNames(&driveNames);

	// 디스크 드라이브들을 트리뷰에 초기화
	InitFolders(&driveNames);
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

CMyExplorerDoc* CLeftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyExplorerDoc)));
	return (CMyExplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

int CLeftView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{

	// style 을 설정한다.
	lpCreateStruct->style |= TVS_HASLINES | TVS_LINESATROOT
					| TVS_HASBUTTONS | TVS_EDITLABELS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	// drag & drop 을 할 수 있도록 설정해 놓는다.-------------
	//LONG	exStyle = ::GetWindowLong(treeCtrl.m_hWnd, GWL_EXSTYLE);
	//exStyle |= WS_EX_ACCEPTFILES;
	//::SetWindowLong(treeCtrl.m_hWnd, GWL_EXSTYLE, exStyle);
	GetTreeCtrl().ModifyStyleEx(0, WS_EX_ACCEPTFILES);

	m_dropTarget.Register(this);
	m_cbFormat = (CLIPFORMAT)::RegisterClipboardFormat(FORMAT_FILECOPY);

	// 폴더 이미지를 초기화 시킨다.
	CBitmap		bitmap;
	bitmap.LoadBitmap(IDB_SHELL);

	// ILC_COLOR8 : 장치 독립적으로 8bit(256색)을 사용
	m_imageList.Create(16, 16, ILC_COLOR8, 1, 1);
	m_imageList.Add(&bitmap, RGB(255, 0, 255));

	treeCtrl.SetImageList(&m_imageList, TVSIL_NORMAL);		

	return 0;
}

void CLeftView::GetDriveNames(CStringArray *driveArray)
{
	int		nIndex = 0, nTemp = 0;
	BOOL	bBreak = TRUE;
	char	driveNames[100] = {0, };
	char	driveTemp[100]  = {0, };

	// 현재 컴퓨터에 있는 모든 드라이브의 이름을
	// 알 수 있게 해주는 API함수 
	// 버퍼의 크기 지정 , 문자열의 버퍼 주소값 
	// 리턴 문자열 : ex) a:\[NULL]c:\[NULL]d:\[NULL][NULL]
	::GetLogicalDriveStrings(sizeof(driveNames), driveNames);

	while(driveNames[nIndex] || bBreak)
	{
		if(driveNames[nIndex])
		{
			if ((driveNames[nIndex] != '\\') && (driveNames[nIndex] != '/'))
				driveTemp[nTemp++] = driveNames[nIndex];

			bBreak = TRUE;
		}
		else
		{
			driveTemp[nTemp] = '\0';
			// 모든 드라이브 목록을 분리해서 저장 
			driveArray->Add(driveTemp);
			bBreak = FALSE;
			nTemp = 0;
		}
		nIndex++;
	}
}

void CLeftView::InitFolders(CStringArray *driveNames)
{

	int			nType;
	HTREEITEM	hItem;
	CString		strDriveName;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	for(int i = 0 ; i < driveNames->GetSize() ; i++)
	{
		strDriveName = driveNames->GetAt(i);

		// 드라이브 형태를 타입별로 리턴시키는 API함수
		nType = ::GetDriveType(strDriveName);

		switch(nType)
		{
		// 디스크가 드라이브에서 제거되어질 수 있는 형태
		// 플로피디스크 드라이브 
		case DRIVE_REMOVABLE   :
			// 사용자 정의 함수 호출(드라이브명, Image Idx)
			hItem = DisplayDrive(strDriveName, 4);
			// 반드시 쓰레기 폴더를 미리 하나 넣어 놔야만 한다.
			// 나중에 Expanding 할때에 반드시 지워야 한다.
			InsertFolder('0', hItem);
			break;						
		// 루트 디렉토리가 존재하지 않는 형태의 드라이브
		case DRIVE_NO_ROOT_DIR :
		// 네트웤 드라이브
		case DRIVE_REMOTE :
		// RAM 디스크 드라이브 
		case DRIVE_RAMDISK :
		// 디스크 드라이브에서 제거되어 질 수 없는 형태의 
		// 드라이브, 즉 일반적인 하드디스크 드라이브 
		case DRIVE_FIXED       :
			hItem = DisplayDrive(strDriveName, 5);
			InsertFolder('0', hItem);
			break;
		// CD-ROM 드라이브 
		case DRIVE_CDROM       :
			hItem = DisplayDrive(strDriveName, 6);
			InsertFolder('0', hItem);
			break;
		}
	}

}

// 화면에 아이템을 출력 
HTREEITEM CLeftView::DisplayDrive(CString strDriveName, int nImage)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	TV_INSERTSTRUCT	tvStruct;

	tvStruct.hParent = NULL;			// 루트 
	tvStruct.hInsertAfter = TVI_SORT;	// 정렬
	tvStruct.item.iImage = nImage;		// 이미지 인덱스 
	tvStruct.item.iSelectedImage = nImage;// 선택시 이미지 인덱스
	tvStruct.item.cchTextMax = strDriveName.GetLength();
	tvStruct.item.pszText = (LPSTR)(LPCTSTR)strDriveName;//이름
	tvStruct.item.mask = TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;

	return	treeCtrl.InsertItem(&tvStruct);
}

// 디스크 드라이브의 앞에 '+' 표시를 나타내게 해주기 위함임 
HTREEITEM CLeftView::InsertFolder(CString strFolderName, HTREEITEM hParentItem)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	TV_INSERTSTRUCT	tvStruct;

	tvStruct.hParent = hParentItem;
	tvStruct.hInsertAfter = TVI_SORT;
	tvStruct.item.iImage = 2;
	tvStruct.item.iSelectedImage = 3;
	tvStruct.item.cchTextMax = strFolderName.GetLength();
	tvStruct.item.pszText = (LPSTR)(LPCTSTR)strFolderName;
	tvStruct.item.mask = TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;

	return	treeCtrl.InsertItem(&tvStruct);
}


//-------------------------------------------------
// 코드 추가 부분 
//-------------------------------------------------
// TVN_ITEMEXPANDING을 맵핑
// 리스트를 선택하면 호출되는 통지 메시지 
// -   확장 / 축소시 모두 호출됨
void CLeftView::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	// 축소 시킬 경우는 로직을 실행 시킬 필요가 없슴
	if (pNMTreeView->action != TVE_EXPAND)
	{
		*pResult = 0;
		return;
	}
	
	HTREEITEM		hItem = pNMTreeView->itemNew.hItem;
	HTREEITEM		hChild;
	CString			strFullName;
	CStringArray	strFolderList;
	CTreeCtrl&		treeCtrl = GetTreeCtrl();

	// 폴더 아이템에 대한 경로를 알아내는 
	// 사용자 정의 함수 
	strFullName = GetFullPathName(hItem);

	// 하위 폴더 리스트를 구하는 사용자 정의 함수 
	// 디렉토리 경로를 받아서 그 하위의 디렉토리만을 
	// 추출하여 CStringArray에 저장하는 함수임 
	GetDocument()->GetChildFolders(&strFolderList, strFullName);

	// 모든 차일드 아이템들을 지운다.
	DeleteChildItems(hItem);	

	for(int i = 0 ; i < strFolderList.GetSize() ; i++)
	{
		hChild = InsertFolder(strFolderList.GetAt(i), hItem);
		// 임의의 폴더를 넣어 놓는다.
		InsertFolder('0', hChild);	
	}

	*pResult = 0;
}


// Item의 정보를 인자로 전달받음 
// 이를 바탕으로 그것의 이름과 상위 이름을 합쳐서 
// 절대경로를 만들어 주는  함수임 
// 만약, 상위 아이템이 없을 경우 NULL을 리턴한다.
CString CLeftView::GetFullPathName(HTREEITEM hItem)
{
	CString		strParentName;
	CString		strFullName;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	strFullName = treeCtrl.GetItemText(hItem) + '\\';

	while((hItem = treeCtrl.GetParentItem(hItem)) != NULL)
	{
		strParentName = treeCtrl.GetItemText(hItem);
		strFullName = strParentName + '\\' + strFullName;
	}

	return	strFullName;
}


void CLeftView::DeleteChildItems(HTREEITEM hItem)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	if (treeCtrl.ItemHasChildren(hItem) == FALSE)
		return;

	HTREEITEM	hNextItem;

	hItem = treeCtrl.GetChildItem(hItem);

	while((hNextItem = treeCtrl.GetNextSiblingItem(hItem)) != NULL)
	{
		treeCtrl.DeleteItem(hItem);
		hItem = hNextItem;
	}
	treeCtrl.DeleteItem(hItem);
}
