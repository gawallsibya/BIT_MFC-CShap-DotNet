// ui.h

void ui_InitControl(HWND hwnd);

void ui_BtnState(HWND hWnd, BOOL fCTable, BOOL fDTable, BOOL DataInsert, BOOL DataDel);

void ui_Refresh(int idx, char*name=NULL, char*num=NULL, char*phoneNumber=NULL, char*email=NULL);