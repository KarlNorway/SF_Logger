#include "MyForm1.h"
#include "DataBase.h"
#include <string>
#include "sqlite3.h"
#include <Windows.h>

extern LogData * g_pLogData;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		//SF_Logger::MyForm1::dataGridView1->ro;

	}
	//printf("\n");
	return 0;
}

bool SF_Logger::MyForm1::readDataBase() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	const char* data = "Callback function called";
	std::string dbName = g_pLogData -> getName();

	/* Open database */
	rc = sqlite3_open(dbName.c_str(), &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "SELECT * from LOG";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		System::Windows::Forms::MessageBox::Show("The operation has been completed ", "Notification", System::Windows::Forms::MessageBoxButtons::OKCancel, System::Windows::Forms::MessageBoxIcon::Asterisk);
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		//fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
	return true;
}

