#include <afxwin.h>
#include <iostream.h>

// CFileFind�� �̿��� ȭ�� ����.
void main()
{
	SetCurrentDirectory("D:\\");

	CFileFind f;
	BOOL b = f.FindFile("*.*");

	while ( b )
	{
		b = f.FindNextFile();
		if ( f.IsDirectory() && ! f.IsHidden() )
			cout << f.GetFileName() << endl;
	}
}
// project -> settting -> using MFC static �� �ٲټ���.



