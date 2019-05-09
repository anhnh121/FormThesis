#pragma once
#include <Windows.h>
#include <iostream>
#include "sqlite3.h"
#include <atlstr.h>
#include "list"
#include "vector"
#include "tchar.h"
#include "SQLiteCpp\SQLiteCpp.h"

using namespace std;

#define DATABASE_PATH "C:\\Users\\Altair\\Desktop\\Test\\Out\\bkscanner.db"

typedef struct _UNSIGNED_INFOMATION_
{
	DWORD dwPID;
	CStringW szPath;
	CStringW szSigner;
}USGN_INFO, *P_USGN_INFO;

typedef struct _COM_INFOMATION_
{
	CStringW szLocation;
	CStringW szItemName;
	CStringW szImagePath;
}COM_INFO, *P_COM_INFO;

typedef struct _INJECT_INFOMATION_
{
	DWORD dwPID;
	CStringW szPath;
	DWORD dwThreadID;
	PBYTE dwStartAddr;
}IJT_INFO, *P_IJT_INFO;

typedef struct _PROCESS_HOLLOWING_
{
	DWORD dwPID;
	CStringW szPath;
}HOLLOW_INFO, *P_HOLLOW_INFO;

typedef struct _AUTORUNS_INFOMATION_
{
	CStringW szLocation;
	CStringW szItemName;
	CStringW szExtend;
	CStringW szDescription;
	CStringW szCompany;
	CStringW szSigner;
	CStringW szImagePath;
	CStringW szWMI;
}ATR_INFO, *P_ATR_INFO;

class CUsingSQLite
{
public:
	//list<USGN_INFO> retList;
	list<USGN_INFO> QueryDllUnsigned(CHAR* szDatabase);
	list<COM_INFO> QueryCOM(CHAR* szDatabase);
	list<IJT_INFO> QueryInject(CHAR* szDatabase);
	list<HOLLOW_INFO> QueryHollow(CHAR* szDatabase);
	list<ATR_INFO> QueryAutoruns(CHAR* szDatabase);
	//void InsertInjection(CHAR* szDatabase, list<IJT_INFO> mylist);
};