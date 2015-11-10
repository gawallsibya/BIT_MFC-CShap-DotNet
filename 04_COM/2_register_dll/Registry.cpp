#include <objbase.h>
#include <assert.h>

#include "registry.h"


//-----------------------------------------------------------------------------------
// �Լ� ���� : ��Ʈ���� GUID�� ��ȯ
//             - ������Ʈ���� CLSID ���� ���ڰ����� ������ �ִ�. 
//             - �׷��Ƿ� GUID�� ���ڰ����� ��ȯ���Ѿ� �Ѵ�. 
//-------------------------------------------------------------------------------------
void ClsidToChar(const CLSID& clsid, char* szCLSID, int length)
{
	LPOLESTR wszCLSID = NULL ;
	// GUID -> ���ڰ����� ��ȯ
	HRESULT hr = StringFromCLSID(clsid, &wszCLSID) ;

	// Use String
	wcstombs(szCLSID, wszCLSID, length) ;

	// Free String
	CoTaskMemFree(wszCLSID) ;
}


//--------------------------------------------------------------------------------------
// �Լ� ���� : ������Ʈ�� ��� 
//             - ������Ʈ���� ��ϵǱ� ���� �⺻���� ���� �ʿ� 
//				1. InProcServer32			: DLL ��ο� ���� ���� 
//				2. ProgID					: CLSID ��� ���α׷��� �̸��� ��Ÿ���� ����
//				3. VersionIndependentProgID : ������ ����
//-----------------------------------------------------------------------------------------
BOOL SetRegistryInform(const char* szKey, const char* szSubkey, const char* szValue)
{
	HKEY hKey;
	char szBuf[1024] ;

	// �������͸��� Ű �� ���� Ű�� ���� szBuf�� ����Ѵ�.
	strcpy(szBuf, szKey) ;

	if (szSubkey != NULL)
	{
		strcat(szBuf, "\\") ;
		strcat(szBuf, szSubkey ) ;
	}

	// szBuf�� ��ϵ� Ű ���� ������ ������ Ű�� �����Ѵ�.
	long lResult = RegCreateKeyEx(HKEY_CLASSES_ROOT, 
								szBuf, 
								0, 
								NULL, 
								REG_OPTION_NON_VOLATILE,
	                            KEY_ALL_ACCESS, NULL, 
	                            &hKey, 
								NULL) ;

	if (lResult != ERROR_SUCCESS)
	{
		return FALSE ;
	}
	
	RegSetValueEx(hKey, 
				NULL, 
				0, 
				REG_SZ,
				(BYTE *)szValue,
				strlen(szValue)+1) ;

	RegCloseKey(hKey) ;

	return TRUE ;
}


//--------------------------------------------------------------------------------------------
// �Լ� ���� : ������Ʈ������ ���� 
//             - ������Ʈ�� Ű���� �Է��ϸ�, �ش� Ű�� ��� ���� Ű������ ��������� ����
//               �ϸ鼭 ����
//-------------------------------------------------------------------------------------------- 
DWORD DeleteRegistryKey(HKEY hStartKey , const char* pKeyName )
{
      DWORD   dwRtn, dwSubKeyLength;
      LPTSTR  pSubKey = NULL;
      TCHAR   szSubKey[256];
      HKEY    hKey;

      // NULL �� Ȥ�� pKeyName�� ������ ���ٸ� �����Ѵ�.
      if ( pKeyName &&  lstrlen(pKeyName))
      {
			if( (dwRtn=RegOpenKeyEx(hStartKey,pKeyName,
				0, KEY_ENUMERATE_SUB_KEYS | DELETE, &hKey )) == ERROR_SUCCESS)
			{
				while (dwRtn == ERROR_SUCCESS )
				{
					dwSubKeyLength = 256;
					dwRtn=RegEnumKeyEx(
                              hKey,
                              0,       // always index zero
                              szSubKey,
                              &dwSubKeyLength,
                              NULL,
                              NULL,
                              NULL,
                              NULL
                            );

					if(dwRtn == ERROR_NO_MORE_ITEMS)
					{
						dwRtn = RegDeleteKey(hStartKey, pKeyName);
						break;
					}
					else if(dwRtn == ERROR_SUCCESS)
					dwRtn=DeleteRegistryKey(hKey, szSubKey);
				}
				
				RegCloseKey(hKey);
			}
		}
		else
			dwRtn = ERROR_BADKEY;

		return dwRtn;
}