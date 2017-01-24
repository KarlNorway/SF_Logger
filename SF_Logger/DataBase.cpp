#include "DataBase.h"
#include <string>
#include "sqlite3.h"
#include <sstream>
#include <iostream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

LogData::LogData(const std::string &name)
{	
	name + ".db";
	dbName = name;
	iD = 1;
	sqlite3 *db;
	char *zErrMsg = 0;
	int  rc;
	char *sql;

	/* Open database */
	rc = sqlite3_open(name.c_str(), &db);
	//rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);//compile sql to byte code
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		//return(0);
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "CREATE TABLE LOGG("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"DTG          TEXT    NOT NULL," \
		"FRA          TEXT    NOT NULL," \
		"TIL            TEXT     NOT NULL," \
		"MELDING        CHAR(250));";
		//"SALARY         REAL );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	//return 0;
}

bool LogData::addEntry(const std::string &DTG, const std::string &from, const std::string &to, const std::string &message) {
	
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	
	/* Open database */
	rc = sqlite3_open(dbName.c_str(), &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	std::cout << DTG << std::endl;
	std::cout << from << std::endl;
	std::cout << to << std::endl;
	std::cout << message << std::endl;
	/* Create SQL statement */
	
	std::string entry = "INSERT INTO LOGG(ID, DTG, FRA, TIL, MELDING)" ;
	entry += "VALUES (";

	std::stringstream ssid;
	ssid << iD;
	std::string id;
	ssid >> id;
	entry += id + ",'" +DTG + "','" +from + "','" + to + "','" + message + "');";
	std::cout << id << std::endl;
	std::cout << entry << std::endl;
	sql = new char[entry.size() + 1];
	std::copy(entry.begin(), entry.end(), sql);
	sql[entry.size()] = '\0'; // don't forget the terminating 0

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}
	
	sqlite3_close(db);
	std::cout << iD << std::endl;
	return true;
}

//std::string LogData::getName()const {
//	return dbName;
//}


