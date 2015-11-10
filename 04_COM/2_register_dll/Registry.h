#ifndef __Registry_H__
#define __Registry_H__
//
//	Registry.h
//
void ClsidToChar(const CLSID& clsid, char* szCLSID, int length);
BOOL SetRegistryInform(const char* szKey, const char* szSubkey, const char* szValue);
DWORD DeleteRegistryKey(HKEY hStartKey , const char* pKeyName );
#endif