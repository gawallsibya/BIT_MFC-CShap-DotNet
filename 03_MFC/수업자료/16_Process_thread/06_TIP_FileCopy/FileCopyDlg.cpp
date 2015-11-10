// FileCopyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileCopy.h"
#include "FileCopyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileCopyDlg dialog

CFileCopyDlg::CFileCopyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileCopyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileCopyDlg)
	m_strDest = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileCopyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileCopyDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrlListBox);
	DDX_Text(pDX, IDC_EDIT1, m_strDest);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileCopyDlg, CDialog)
	//{{AFX_MSG_MAP(CFileCopyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FROM, OnFrom)
	ON_BN_CLICKED(IDC_TO, OnTo)
	ON_BN_CLICKED(IDC_START_COPY, OnStartCopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileCopyDlg message handlers

BOOL CFileCopyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFileCopyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFileCopyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileCopyDlg::OnFrom() 
{
	m_ctrlListBox.ResetContent();
	char szFilter[] = "All Files(*.*)|*.*||";

	CFileDialog dlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, szFilter);
	if(IDOK == dlg.DoModal())
		for(POSITION pos=dlg.GetStartPosition(); pos!=NULL ; )
			m_ctrlListBox.AddString(dlg.GetNextPathName(pos));
}

void CFileCopyDlg::OnTo() 
{
	ITEMIDLIST		*pidlBrowse;
	char			pszPathname[MAX_PATH];

	BROWSEINFO BrInfo;
	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.pidlRoot = NULL;

	memset( &BrInfo, 0, sizeof(BrInfo) );
	BrInfo.pszDisplayName = pszPathname;
	BrInfo.lpszTitle = "복사할 디렉터리를 선택하세요";
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	// 대화상자를 띄우기
	pidlBrowse = ::SHBrowseForFolder(&BrInfo);	

	if( pidlBrowse != NULL)
	{
		// 패스를 얻어옴
		SHGetPathFromIDList(pidlBrowse, pszPathname);	
		m_strDest = pszPathname;
		UpdateData(FALSE);
	}
}

void CFileCopyDlg::OnStartCopy() 
{
	UpdateData();

	SHFILEOPSTRUCT *pFO = new SHFILEOPSTRUCT;
	pFO->hwnd = NULL;
	pFO->wFunc = FO_COPY;
	pFO->fFlags = FOF_NOCONFIRMMKDIR;
	pFO->fAnyOperationsAborted = TRUE;
	pFO->lpszProgressTitle = _T("파일 복사중");

	CMemFile file;
	CArchive ar(&file, CArchive::store);

	CString str;
	int nCount = m_ctrlListBox.GetCount();
	char null = 0;
	for(int i=0 ; i<nCount ; i++)
	{
		m_ctrlListBox.GetText(i, str);
		ar.WriteString(str);
		ar.Write(&null, 1);
	}
	ar.Write(&null, 1);
	ar.Close();

	pFO->pFrom = (char *)file.Detach();

	// 복사될 디렉토리명 (Destination)
	pFO->pTo = new char [m_strDest.GetLength()+1];
	strcpy((LPSTR)pFO->pTo, (LPSTR)(LPCTSTR)m_strDest);
	((LPSTR)pFO->pTo)[m_strDest.GetLength()]=0;

	AfxBeginThread(ThreadFunc, pFO);
}


UINT ThreadFunc(LPVOID pParam)
{
	SHFILEOPSTRUCT *pFO = (SHFILEOPSTRUCT *)pParam;

	::SHFileOperation(pFO);

	delete [] (char *)pFO->pFrom;
	delete [] (char *)pFO->pTo;
	delete pFO;

	return 0;
}
