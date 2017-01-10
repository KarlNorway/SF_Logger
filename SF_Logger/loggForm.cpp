#include "loggForm.h"
#include <string>
#include <ctime>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
void mainNew() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SF_Logger::loggForm loggForm;
	Application::Run(%loggForm);
}

std::string getDTG() {
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date: %s", asctime(timeinfo));

	// print various components of tm structure.
	std::cout << "Year" << 1900 + timeinfo->tm_year << std::endl;
	std::cout << "Month: " << 1 + timeinfo->tm_mon << std::endl;
	std::cout << "Day: " << timeinfo->tm_mday << std::endl;
	std::cout << "Time: " << 1 + timeinfo->tm_hour << ":";
	std::cout << 1 + timeinfo->tm_min << ":";
	std::cout << 1 + timeinfo->tm_sec << std::endl;
	std::string strDTG = std::to_string(1900 + timeinfo->tm_year)+ "-" + std::to_string(1 + timeinfo->tm_mon)+ "-" + std::to_string(timeinfo->tm_mday) + " " + std::to_string(1 + timeinfo->tm_hour) + ":" + std::to_string(1 + timeinfo->tm_min) + ":" + std::to_string(1 + timeinfo->tm_sec);
	return strDTG;

}
