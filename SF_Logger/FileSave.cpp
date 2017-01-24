#include "FileSave.h"
#include <string>
#include <fstream>
#include <Windows.h>
#include <atlstr.h>

void FileSave::save(const std::string & content) {

	LPCWSTR cLocati = L"C:\\SF_Logger\\";
	static const char * textstring = content.c_str();
	static const char * filename = fileName.c_str();

	if ((GetFileAttributes(cLocati)) == INVALID_FILE_ATTRIBUTES)
	{
		//std::cout << "Directory doesn't exist\n";
		CreateDirectory(cLocati, 0);
		//std::cout << "Directory Created\n";
	}

	std::string path = CW2A(cLocati);
	std::ofstream ofile(path + filename, std::ios_base::app);
	ofile << textstring << std::endl;
	ofile.close();
	textstring = "";
}