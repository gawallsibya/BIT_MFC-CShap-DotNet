#include <afxwin.h>
#include <iostream.h>

// CFileFind을 이용한 화일 열거.
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
// project -> settting -> using MFC static 로 바꾸세요.



