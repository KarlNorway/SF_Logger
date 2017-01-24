#include "loggForm.h"
#include "MyForm.h"
#include <string>
#include <ctime>
//#include <iostream>
#include <fstream>
#include <Windows.h>
#include <atlstr.h>
#include "DataBase.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace SF_Logger;


System::Void SF_Logger::loggForm::txtMessage_TextChanged(System::Object ^ sender_txtMessChange, System::EventArgs ^ e)
{
	using namespace System;
	using namespace System::Runtime::InteropServices;
	SF_Logger::loggForm LF;
	std::string fromMessage = (const char*)(Marshal::StringToHGlobalAnsi(LF.txtMessage->Text)).ToPointer();
	return System::Void();
}

System::Void loggForm::btnSave_Click(System::Object^  sender_save, System::EventArgs^  e) {
	using namespace System;
	using namespace System::Runtime::InteropServices;
	//SF_Logger::loggForm LF;
	std::string fromStr = (const char*)(Marshal::StringToHGlobalAnsi(loggForm::txtFrom->Text)).ToPointer();
	std::string toStr = (const char*)(Marshal::StringToHGlobalAnsi(loggForm::txtTo->Text)).ToPointer();
	std::string fromMessage = (const char*)(Marshal::StringToHGlobalAnsi(loggForm::txtMessage->Text)).ToPointer();
	loggForm::txtFrom->Clear();
	loggForm::txtTo->Clear();
	loggForm::txtMessage->Clear();
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::string date = std::to_string(1900 + timeinfo->tm_year) + "-" + std::to_string(1 + timeinfo->tm_mon) + "-" + std::to_string(timeinfo->tm_mday);
	std::string strDTG = date + " " + std::to_string(1 + timeinfo->tm_hour) + ":" + std::to_string(1 + timeinfo->tm_min) + ":" + std::to_string(1 + timeinfo->tm_sec);
	std::string fileName = "Logg-" + date;
	LogData logg(fileName);
	logg.addEntry(strDTG, fromStr, toStr, fromMessage);
	MessageBox::Show("The operation has been completed ", "Notification", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}