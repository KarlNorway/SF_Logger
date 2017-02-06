#include "MyForm1.h"
#include "DataBase.h"
#include <string>
#include "sqlite3.h"
#include <Windows.h>

extern LogData * g_pLogData;

//void InitializeDataGridView()
//{
//	int  rc;
//	sqlite3 *db;
//	std::string name = g_pLogData->getName();
//	/* Open database */
//	rc = sqlite3_open(name.c_str(), &db);
//	//rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);//compile sql to byte code
//	if (rc) {
//		//fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		//return(0);
//	}
//	else {
//		//fprintf(stdout, "Opened database successfully\n");
//	}
//	sqlite3_stmt *res;
//	char * sql = "SELECT * from LOG";
//	int nByte = sizeof(sql) -1;
//	int dbRead = sqlite3_prepare_v2(db, sql, nByte, &res, 0 );
//	char *zErrMsg = 0;
//	if (dbRead != SQLITE_OK) {
//		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	else {
//		//fprintf(stdout, "Operation done successfully\n");
//	}
//	sqlite3_close(db);
//}


