//student.cpp

#include "std.h"

Student stu[DATA_MAX] = 
	{ 
		{"À¯½ÂÀç", 2008243060, "010-7172-2091", "optatum06@naver.com"},
		{"±è´ë±Ù", 2005732009, "010-2363-2767", "eorms1986@nate.com"},
		{"ÀÌÈñ¿ø", 2005123456, "011-1234-5678", "dlgmldnjs@nate.com"},
		{"ÁÖÀºÈ£", 2003123456, "016-5678-1234", "wndmsgh@nate.com"}
	};

Student get_stu[DATA_MAX];
int count;

Student* student_GetData(int idx)
{
	return &stu[idx];
}