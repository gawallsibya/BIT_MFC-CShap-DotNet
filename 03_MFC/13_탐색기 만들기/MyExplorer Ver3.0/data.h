////////////////////////////////////////////////////////////
//	data.h

#ifndef	_DATA_H_
#define	_DATA_H_

// Drag & Drop �� ���� ���ڿ� ����
static	const	TCHAR	*FORMAT_FILECOPY = "FormatFileCopy";

// ���� �Ǵ� ������ �Ӽ��� �����ϴ� ����ü
typedef	struct	_LIST_VIEW
{
	CString		strName;			// �̸�
	CString		strPath;			// ���
	//BOOL		bIsDirectory;		// ���丮
	DWORD		dwFileSize;			// ���� ũ��
	CString		strKind;			// ���� ����
	CTime		tCreateTime;		// ���� ��¥
	CTime		tLastAccessTime;	// ����� ��¥
	CTime		tLastWriteTime;		// �ٲ� ��¥
	BOOL		bIsHidden;			// hidden ����
	BOOL		bIsReadOnly;		// �б� ���� ����
	BOOL		bIsArchived;		// ��� ����
	BOOL		bIsSystem;			// �ý��� ����
}LIST_VIEW;

#endif	// _DATA_H_
