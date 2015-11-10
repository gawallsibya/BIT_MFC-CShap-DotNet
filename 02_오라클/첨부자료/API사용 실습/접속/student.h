//stdent.h

struct Student
{
	string sName;
	int sNum;
	string sPhone;
	string email;
};

#define DATA_MAX	4
extern Student stu[DATA_MAX];

Student* student_GetData(int idx);

// db에서 가져온 데이터 저장
extern Student get_stu[DATA_MAX];
extern int count;