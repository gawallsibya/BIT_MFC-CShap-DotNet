// control.h

BOOL control_Init(HWND hwnd);

void control_CreateTable(HWND hwnd);
void control_DeleteTable(HWND hWnd);
void control_InsertData(HWND hWnd);
void control_DeleteData(HWND hwnd);

void control_GetData(int idx, char *name, char *num, char*phoneNumber, char*email );

