// TestSQLite.cpp : Defines the entry point for the console application.
//

#include "UsingSQLite.h"

list<USGN_INFO> CUsingSQLite::QueryDllUnsigned(CHAR* szDatabase)
{
	USGN_INFO temp;
	list<USGN_INFO> dll_list;
	dll_list.clear();
	list<USGN_INFO>::iterator first_element;
	try
	{
		// Open a database file
		SQLite::Database    db(szDatabase);

		// Compile a SQL query, containing one parameter (index 1)
		//SQLite::Statement   query(db, "SELECT * FROM DLL_UNSIGNED");
		SQLite::Statement   query(db, "SELECT * FROM DLL_UNSIGNED");
		// Bind the integer value 6 to the first parameter of the SQL query
		//query.bind(1, 6);

		// Loop to execute the query step by step, to get rows of result
		while (query.executeStep())
		{
			// Demonstrate how to get some typed column value
			int               id = query.getColumn(0);
			DWORD             dwPID = query.getColumn(1);
			const char*       szPath = query.getColumn(2);
			const char*       szSigner = query.getColumn(3);
			temp.dwPID = dwPID;
			temp.szPath = szPath;
			temp.szSigner = szSigner;
			dll_list.push_back(temp);

		}
	}
	catch (std::exception& e)
	{
		//std::cout << "exception: " << e.what() << std::endl;
		OutputDebugStringA(e.what());
	}

	return dll_list;
}

list<COM_INFO> QueryCOM(CHAR* szDatabase);
list<IJT_INFO> QueryInject(CHAR* szDatabase);
list<HOLLOW_INFO> QueryHollow(CHAR* szDatabase);
list<ATR_INFO> QueryAutoruns(CHAR* szDatabase);