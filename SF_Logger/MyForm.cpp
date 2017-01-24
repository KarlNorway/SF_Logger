#include "MyForm.h"
#include "loggForm.h"
#include "DataBase.h"
#include <ctime>
#include <string>

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace System;
using namespace System::Windows::Forms;
using namespace SF_Logger;

[STAThread]//leave this as is
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	/*time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::string date = std::to_string(1900 + timeinfo->tm_year) + "-" + std::to_string(1 + timeinfo->tm_mon) + "-" + std::to_string(timeinfo->tm_mday);
	std::string strDTG = date + " " + std::to_string(1 + timeinfo->tm_hour) + ":" + std::to_string(1 + timeinfo->tm_min) + ":" + std::to_string(1 + timeinfo->tm_sec);
	std::string fileName = "Logg-" + date;
	LogData logg(fileName);*/
	SF_Logger::MyForm formMain;
	Application::Run(%formMain);
}
System::Void MyForm::btnNew_Click(System::Object^  sender, System::EventArgs^  e) {
	loggForm ^ formNew = gcnew loggForm;
	formNew->Show();
}