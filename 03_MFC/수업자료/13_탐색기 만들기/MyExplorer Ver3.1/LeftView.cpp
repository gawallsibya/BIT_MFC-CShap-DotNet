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
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_WM_RBUTTONDOWN()
	ON_WM_CAPTURECHANGED()
	ON_COMMAND(ID_FILE_RENAME, OnFileRename)
	ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, OnBeginlabeledit)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_COMMAND(ID_FILE_DELETE, OnFileDelete)
	ON_COMMAND(ID_FOLDER_NEW, OnFolderNew)
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
	m_bRButtonDown	= FALSE;

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

//---------------------------------------------
// �߰� 
//----------------------------------------------
void CLeftView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM	hItem = pNMTreeView->itemNew.hItem;

	// ���õ� ���������� GetFullPathName�� ȣ���Ͽ� 
	// ��θ� ���´�.
	// �׸��� Doc�� SelectTreeViewFolder�Լ��� ȣ����
	GetDocument()->SelectTreeViewFolder(GetFullPathName(hItem));

	*pResult = 0;
}

void CLeftView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bRButtonDown = TRUE;
	m_ptRButton = point;

	
	CTreeView::OnRButtonDown(nFlags, point);
}

void CLeftView::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	if (m_bRButtonDown == TRUE)
	{
		UINT		uFlags;
		HTREEITEM	hTreeItem;
		CString		strFolder;
		CTreeCtrl&	treeCtrl = GetTreeCtrl();

		m_bRButtonDown = FALSE;
		hTreeItem = treeCtrl.HitTest(m_ptRButton, &uFlags);

		if (hTreeItem == NULL)
		{
			CTreeView::OnCaptureChanged(pWnd);
			return;
		}

		strFolder = treeCtrl.GetItemText(hTreeItem);

		if (strFolder.IsEmpty())
		{
			CTreeView::OnCaptureChanged(pWnd);
			return;
		}

		m_hContextItem = hTreeItem;
		ClientToScreen(&m_ptRButton);

		ViewContextMenu(2, m_ptRButton);
	}

	m_bRButtonDown = FALSE;	
	CTreeView::OnCaptureChanged(pWnd);
}

void CLeftView::ViewContextMenu(int nSubIndex, CPoint point)
{
	CMenu		menu;
	CMenu*		pSubMenu;

	menu.LoadMenu(IDR_CONTEXTMENU);

	pSubMenu = menu.GetSubMenu(nSubIndex);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CLeftView::OnFileRename() 
{
	// ���콺 ���� ��ư���� ������ ������ �ڵ��� �̿��Ͽ�
	// �ش� �������� �����Ѵ�.
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	HTREEITEM	hTreeItem = m_hContextItem;

	treeCtrl.EditLabel(hTreeItem);		
}

void CLeftView::OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM	hTreeItem = pTVDispInfo->item.hItem;

	// ��ũ ����̺��̸�
	if (IsDiskDrive(hTreeItem))
	{
		*pResult = 1;	// �̸� �ٲٱ⸦ �ߴ��Ѵ�.
		return;
	}
	*pResult = 0;
}

#include "MainFrm.h"
void CLeftView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;

	CString		strOldFolder, strNewFolder;
	HTREEITEM	hTreeItem;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	CEdit*		pEdit = treeCtrl.GetEditControl();

	hTreeItem = pTVDispInfo->item.hItem;
	strOldFolder = treeCtrl.GetItemText(hTreeItem);
	pEdit->GetWindowText(strNewFolder);	// ����� ���� �̸��� �����´�.

	// ���� �̸��� �ٲ��� �ʾ�����
	if (strNewFolder == strOldFolder)
	{
		*pResult = 0;
		return;
	}

	// ���� �̸��� ������
	if (strNewFolder.IsEmpty())
	{
		MessageBox("���� �̸��� �Է��ؾ� �մϴ�.", "�̸� �ٲٱ�", MB_ICONSTOP);
		treeCtrl.EditLabel(hTreeItem);
		*pResult = 0;
		return;
	}

	CFileStatus		fs;
	CString			strOldPath, strNewPath;
	
	strOldPath = GetFullPathName(hTreeItem);

	if (strOldPath.Right(1) == '\\')
		strOldPath = strOldPath.Left(strOldPath.GetLength() - 1);

	strNewPath = strOldPath.Left(strOldPath.GetLength() - strOldFolder.GetLength());
	strNewPath += strNewFolder;

	// ���� �̸��� ������ �����ϸ�
	if (CFile::GetStatus(strNewPath, fs))
	{
		CString		str = strOldFolder + "�� �̸��� �ٲܼ� �����ϴ�.\n"
			+ "������ �̸��� ���� ������ �̹� �ֽ��ϴ�.\n"
			+ "�ٸ� ���� �̸��� �����Ͻʽÿ�.";
		MessageBox(str, "���� �̸� �ٲٱ� ����", MB_ICONSTOP);
		treeCtrl.EditLabel(hTreeItem);
		*pResult = 0;
		return;
	}

	// ������ �ٲ� ������ Rename ��Ų��.
	rename(strOldPath, strNewPath);	// ������ ������ �ٲ۴�.
	treeCtrl.SetItemText(hTreeItem, strNewFolder);

	*pResult = 0;
}

BOOL CLeftView::IsDiskDrive(HTREEITEM hTreeItem)
{
	CTreeCtrl&	treeCtrl = GetTreeCtrl();

	hTreeItem = treeCtrl.GetParentItem(hTreeItem);

	if (hTreeItem == NULL)
		return	TRUE;
	else
		return	FALSE;
}

void CLeftView::OnFileDelete() 
{
	// TODO: Add your command handler code here
	CString		strFullPathName;
	HTREEITEM	hTreeItem;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	
	hTreeItem = m_hContextItem;
	strFullPathName = GetFullPathName(hTreeItem);
	if (strFullPathName.Right(1) == '\\')
		strFullPathName = strFullPathName.Left(strFullPathName.GetLength() - 1);

	DeleteDirectory(strFullPathName, hTreeItem);
	if (::RemoveDirectory(strFullPathName) == FALSE)
	{
		MessageBox("������ ������ ���� �����ϴ�.", "���� ����", MB_ICONSTOP);
	}	
}

BOOL CLeftView::DeleteDirectory(CString strFolderName, HTREEITEM hTreeItem)
{
	CFileFind		ff;
	CString			strDirectory = strFolderName;
	CStringArray	strFileArray;

	if (strFolderName.Right(1) != '\\')
	{
		strFolderName += '\\';
	}

	strFolderName += "*.*";

	if (ff.FindFile(strFolderName) == TRUE)
	{
		CString		strFileName;
		BOOL		bFlag = TRUE;

		while(bFlag == TRUE)
		{
			bFlag = ff.FindNextFile();
			strFileName = ff.GetFilePath();

			if (ff.IsDots())
			{
				continue;
			}

			if (ff.IsDirectory())
			{
				DeleteDirectory(strFileName, NULL);
				if (::RemoveDirectory(strFileName) == FALSE)
				{
					MessageBox("������ ������ ���� �����ϴ�.", "���� ����", MB_ICONSTOP);
					return	FALSE;
				}
			}
			else
			{
				if (::DeleteFile(strFileName) == FALSE)
				{
					if (GetDocument()->DeleteReadOnlyFile(strFileName) == FALSE)
					{
						MessageBox("������ ������ ���� �����ϴ�.", "���� ����", MB_ICONSTOP);
						return	FALSE;
					}
				}
			}
		}
	}
	ff.Close();

	if (hTreeItem != NULL)
	{
		CTreeCtrl&	treeCtrl = GetTreeCtrl();
		treeCtrl.DeleteItem(hTreeItem);
	}

	return	TRUE;
}

void CLeftView::OnFolderNew() 
{
	// TODO: Add your command handler code here
	CString		strFolderName, strFullName;
	HTREEITEM	hTreeItem, hChildItem;
	CTreeCtrl&	treeCtrl = GetTreeCtrl();
	
	hTreeItem = m_hContextItem;
	strFolderName += GetNewFolderName(hTreeItem);
	strFullName = GetFullPathName(hTreeItem) + strFolderName;

	if (::CreateDirectory(strFullName, NULL) == FALSE)
	{
		MessageBox("���� ����⿡ �����Ͽ����ϴ�.", "���� �����", MB_ICONSTOP);
		return;
	}

	hChildItem = InsertFolder(strFolderName, hTreeItem);

	treeCtrl.Expand(hTreeItem, TVE_EXPAND);
	treeCtrl.EditLabel(hChildItem);	
}

CString CLeftView::GetNewFolderName(HTREEITEM hTreeItem)
{
	CFileStatus		fs;
	int				nIndex = 0;
	BOOL			bFlag = TRUE;
	CString			strPathName, strTemp;
	CString			strFolderName = "�� ����";
	
	strPathName = GetFullPathName(hTreeItem);

	while(bFlag)
	{
		strTemp = strPathName + strFolderName;

		// ���� �̸��� ������ �����ϸ�
		if (CFile::GetStatus(strTemp, fs))
		{
			strFolderName = "�� ����";
			strTemp.Format("-%d", ++nIndex);
			strTemp = strFolderName + strTemp;
			strFolderName = strTemp;
		}
		else
		{
			bFlag = FALSE;
		}
	}

	return	strFolderName;
}
