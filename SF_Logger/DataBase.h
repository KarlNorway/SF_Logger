#ifndef _DATABASE_H
#define _DATABASE_H
#include <string>


class LogData {
public:
	LogData(const std::string &name);
	bool addEntry(const std::string &DTG, const std::string &from, const std::string &to , const std::string &message);
	bool readTable();
	//std::string getName() const;
private:
	std::string dbName;
	int iD;
};

#endif