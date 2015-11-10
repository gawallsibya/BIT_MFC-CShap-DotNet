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
	// ���� ������ �ʱ�ȭ ��Ų��.
	CStringArray	driveNames;

	// ��ǻ�Ϳ� ���� �����Ǿ��� �ִ� ��� 
	// ��ũ ����̺��� �̸����� ���� ����� ���� �Լ� 
	GetDriveNames(&driveNames);

	// ��ũ ����̺���� Ʈ���信 �ʱ�ȭ
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

	// style �� �����Ѵ�.
	lpCreateStruct->style |= TVS_HASLINES | TVS_LINESATROOT
					| TVS_HASBUTTONS | TVS_EDITLABELS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	// drag & drop �� �� �� �ֵ��� ������ ���´�.-------------
	//LONG	exStyle = ::GetWindowLong(treeCtrl.m_hWnd, GWL_EXSTYLE);
	//exStyle |= WS_EX_ACCEPTFILES;
	//::SetWindowLong(treeCtrl.m_hWnd, GWL_EXSTYLE, exStyle);
	GetTreeCtrl().ModifyStyleEx(0, WS_EX_ACCEPTFILES);

	m_dropTarget.Register(this);
	m_cbFormat = (CLIPFORMAT)::RegisterClipboardFormat(FORMAT_FILECOPY);

	// ���� �̹����� �ʱ�ȭ ��Ų��.
	CBitmap		bitmap;
	bitmap.LoadBitmap(IDB_SHELL);

	// ILC_COLOR8 : ��ġ ���������� 8bit(256��)�� ���
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

	// ���� ��ǻ�Ϳ� �ִ� ��� ����̺��� �̸���
	// �� �� �ְ� ���ִ� API�Լ� 
	// ������ ũ�� ���� , ���ڿ��� ���� �ּҰ� 
	// ���� ���ڿ� : ex) a:\[NULL]c:\[NULL]d:\[NULL][NULL]
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
			// ��� ����̺� ����� �и��ؼ� ���� 
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

		// ����̺� ���¸� Ÿ�Ժ��� ���Ͻ�Ű�� API�Լ�
		nType = ::GetDriveType(strDriveName);

		switch(nType)
		{
		// ��ũ�� ����̺꿡�� ���ŵǾ��� �� �ִ� ����
		// �÷��ǵ�ũ ����̺� 
		case DRIVE_REMOVABLE   :
			// ����� ���� �Լ� ȣ��(����̺��, Image Idx)
			hItem = DisplayDrive(strDriveName, 4);
			// �ݵ�� ������ ������ �̸� �ϳ� �־� ���߸� �Ѵ�.
			// ���߿� Expanding �Ҷ��� �ݵ�� ������ �Ѵ�.
			InsertFolder('0', hItem);
			break;						
		// ��Ʈ ���丮�� �������� �ʴ� ������ ����̺�
		case DRIVE_NO_ROOT_DIR :
		// ��Ʈ�p ����̺�
		case DRIVE_REMOTE :
		// RAM ��ũ ����̺� 
		case DRIVE_RAMDISK :
		// ��ũ ����̺꿡�� ���ŵǾ� �� �� ���� ������ 
		// ����̺�, �� �Ϲ����� �ϵ��ũ ����̺� 
		case DRIVE_FIXED       :
			hItem = DisplayDrive(strDriveName, 5);
			InsertFolder('0', hItem);
			break;
		// CD-ROM ����̺� 
		case DRIVE_CDROM       :
			hItem = DisplayDrive(strDriveName, 6);
			InsertFolder('0', hItem);
			break;
		}
	}

}

// ȭ�鿡 �������� ��� 
HTREEITEM CLeftView::DisplayDrive(CString strDriveName, int nImage)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	TV_INSERTSTRUCT	tvStruct;

	tvStruct.hParent = NULL;			// ��Ʈ 
	tvStruct.hInsertAfter = TVI_SORT;	// ����
	tvStruct.item.iImage = nImage;		// �̹��� �ε��� 
	tvStruct.item.iSelectedImage = nImage;// ���ý� �̹��� �ε���
	tvStruct.item.cchTextMax = strDriveName.GetLength();
	tvStruct.item.pszText = (LPSTR)(LPCTSTR)strDriveName;//�̸�
	tvStruct.item.mask = TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;

	return	treeCtrl.InsertItem(&tvStruct);
}

// ��ũ ����̺��� �տ� '+' ǥ�ø� ��Ÿ���� ���ֱ� ������ 
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
// �ڵ� �߰� �κ� 
//-------------------------------------------------
// TVN_ITEMEXPANDING�� ����
// ����Ʈ�� �����ϸ� ȣ��Ǵ� ���� �޽��� 
// -   Ȯ�� / ��ҽ� ��� ȣ���
void CLeftView::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	// ��� ��ų ���� ������ ���� ��ų �ʿ䰡 ����
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

	// ���� �����ۿ� ���� ��θ� �˾Ƴ��� 
	// ����� ���� �Լ� 
	strFullName = GetFullPathName(hItem);

	// ���� ���� ����Ʈ�� ���ϴ� ����� ���� �Լ� 
	// ���丮 ��θ� �޾Ƽ� �� ������ ���丮���� 
	// �����Ͽ� CStringArray�� �����ϴ� �Լ��� 
	GetDocument()->GetChildFolders(&strFolderList, strFullName);

	// ��� ���ϵ� �����۵��� �����.
	DeleteChildItems(hItem);	

	for(int i = 0 ; i < strFolderList.GetSize() ; i++)
	{
		hChild = InsertFolder(strFolderList.GetAt(i), hItem);
		// ������ ������ �־� ���´�.
		InsertFolder('0', hChild);	
	}

	*pResult = 0;
}


// Item�� ������ ���ڷ� ���޹��� 
// �̸� �������� �װ��� �̸��� ���� �̸��� ���ļ� 
// �����θ� ����� �ִ�  �Լ��� 
// ����, ���� �������� ���� ��� NULL�� �����Ѵ�.
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
