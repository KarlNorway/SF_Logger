#include "MyForm.h"
#include "loggForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SF_Logger::MyForm formMain;
	Application::Run(%formMain);
}

