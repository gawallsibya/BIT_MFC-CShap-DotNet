#include <objbase.h>
#include <assert.h>

#include "registry.h"


//-----------------------------------------------------------------------------------
// 함수 설명 : 스트링을 GUID로 변환
//             - 레지스트리는 CLSID 값을 문자값으로 가지고 있다. 
//             - 그러므로 GUID를 문자값으로 변환시켜야 한다. 
//-------------------------------------------------------------------------------------
void ClsidToChar(const CLSID& clsid, char* szCLSID, int length)
{
	LPOLESTR wszCLSID = NULL ;
	// GUID -> 문자값으로 변환
	HRESULT hr = StringFromCLSID(clsid, &wszCLSID) ;

	// Use String
	wcstombs(szCLSID, wszCLSID, length) ;

	// Free String
	CoTaskMemFree(wszCLSID) ;
}


//--------------------------------------------------------------------------------------
// 함수 설명 : 레지스트리 등록 
//             - 레지스트리에 등록되기 위한 기본적인 정보 필요 
//				1. InProcServer32			: DLL 경로에 관한 정보 
//				2. ProgID					: CLSID 대신 프로그램의 이름을 나타내는 별명
//				3. VersionIndependentProgID : 간단한 별명
//-----------------------------------------------------------------------------------------
BOOL SetRegistryInform(const char* szKey, const char* szSubkey, const char* szValue)
{
	HKEY hKey;
	char szBuf[1024] ;

	// 레지스터리의 키 와 서버 키의 값을 szBuf에 기록한다.
	strcpy(szBuf, szKey) ;

	if (szSubkey != NULL)
	{
		strcat(szBuf, "\\") ;
		strcat(szBuf, szSubkey ) ;
	}

	// szBuf에 기록된 키 값의 정보를 가지고 키를 생성한다.
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
// 함수 설명 : 레지스트리에서 삭제 
//             - 레지스트리 키값을 입력하면, 해당 키의 모든 서브 키값들을 재귀적으로 동작
//               하면서 삭제
//-------------------------------------------------------------------------------------------- 
DWORD DeleteRegistryKey(HKEY hStartKey , const char* pKeyName )
{
      DWORD   dwRtn, dwSubKeyLength;
      LPTSTR  pSubKey = NULL;
      TCHAR   szSubKey[256];
      HKEY    hKey;

      // NULL 값 혹은 pKeyName에 정보가 없다면 리턴한다.
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