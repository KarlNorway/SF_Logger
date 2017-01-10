#pragma once
#include <string>
#include <msclr\marshal.h> 
//#include <ctime>
#include <time.h>
#include <locale.h> 
#include <windows.h>




namespace SF_Logger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for loggForm
	/// </summary>
	public ref class loggForm : public System::Windows::Forms::Form
	{
	public:
		loggForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~loggForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblFrom;
	protected:
	private: System::Windows::Forms::Label^  lblTo;
	private: System::Windows::Forms::Label^  lblMessage;
	private: System::Windows::Forms::TextBox^  txtFrom;
	private: System::Windows::Forms::TextBox^  txtTo;
	private: System::Windows::Forms::TextBox^  txtMessage;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Label^  lblDTG;

	private:

		
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblFrom = (gcnew System::Windows::Forms::Label());
			this->lblTo = (gcnew System::Windows::Forms::Label());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->txtFrom = (gcnew System::Windows::Forms::TextBox());
			this->txtTo = (gcnew System::Windows::Forms::TextBox());
			this->txtMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblDTG = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblFrom
			// 
			this->lblFrom->AutoSize = true;
			this->lblFrom->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFrom->Location = System::Drawing::Point(13, 36);
			this->lblFrom->Name = L"lblFrom";
			this->lblFrom->Size = System::Drawing::Size(34, 19);
			this->lblFrom->TabIndex = 0;
			this->lblFrom->Text = L"Fra";
			// 
			// lblTo
			// 
			this->lblTo->AutoSize = true;
			this->lblTo->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTo->Location = System::Drawing::Point(13, 81);
			this->lblTo->Name = L"lblTo";
			this->lblTo->Size = System::Drawing::Size(27, 19);
			this->lblTo->TabIndex = 1;
			this->lblTo->Text = L"Til";
			this->lblTo->UseWaitCursor = true;
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage->Location = System::Drawing::Point(13, 131);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(69, 19);
			this->lblMessage->TabIndex = 2;
			this->lblMessage->Text = L"Melding";
			// 
			// txtFrom
			// 
			this->txtFrom->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtFrom->Location = System::Drawing::Point(67, 36);
			this->txtFrom->Name = L"txtFrom";
			this->txtFrom->Size = System::Drawing::Size(100, 26);
			this->txtFrom->TabIndex = 3;
			// 
			// txtTo
			// 
			this->txtTo->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTo->Location = System::Drawing::Point(67, 77);
			this->txtTo->Name = L"txtTo";
			this->txtTo->Size = System::Drawing::Size(100, 26);
			this->txtTo->TabIndex = 4;
			// 
			// txtMessage
			// 
			this->txtMessage->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMessage->Location = System::Drawing::Point(17, 163);
			this->txtMessage->Multiline = true;
			this->txtMessage->Name = L"txtMessage";
			this->txtMessage->Size = System::Drawing::Size(305, 195);
			this->txtMessage->TabIndex = 5;
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->Location = System::Drawing::Point(17, 380);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(305, 32);
			this->btnSave->TabIndex = 6;
			this->btnSave->Text = L"Lagre";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &loggForm::btnSave_Click);
			// 
			// lblDTG
			// 
			this->lblDTG->AutoSize = true;
			this->lblDTG->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDTG->Location = System::Drawing::Point(63, 9);
			this->lblDTG->Name = L"lblDTG";
			this->lblDTG->Size = System::Drawing::Size(54, 19);
			this->lblDTG->TabIndex = 7;
			this->lblDTG->Text = L"label1";
			//this->lblDTG->Click += gcnew System::EventHandler(this, &loggForm::lblDTG_Click);
			// 
			// loggForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(338, 434);
			this->Controls->Add(this->lblDTG);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtMessage);
			this->Controls->Add(this->txtTo);
			this->Controls->Add(this->txtFrom);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->lblTo);
			this->Controls->Add(this->lblFrom);
			this->Name = L"loggForm";
			this->Text = L"SF Logger";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSave_Click(System::Object^  sender_save, System::EventArgs^  e) {
		using namespace System;
		using namespace System::Runtime::InteropServices;

		std::string fromStr = (const char*)(Marshal::StringToHGlobalAnsi(txtFrom->Text)).ToPointer();
		std::string toStr = (const char*)(Marshal::StringToHGlobalAnsi(txtTo->Text)).ToPointer();
		std::string fromMessage = (const char*)(Marshal::StringToHGlobalAnsi(txtMessage->Text)).ToPointer();
		System::String^ output = gcnew String(toStr.c_str());
		output += gcnew String(fromStr.c_str());
		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		std::string strDTG = std::to_string(1900 + timeinfo->tm_year) + "-" + std::to_string(1 + timeinfo->tm_mon) + "-" + std::to_string(timeinfo->tm_mday) + " " + std::to_string(1 + timeinfo->tm_hour) + ":" + std::to_string(1 + timeinfo->tm_min) + ":" + std::to_string(1 + timeinfo->tm_sec);
		System::String^ DTG = gcnew String(strDTG.c_str());
		output += DTG;
		txtMessage->Text = output;
		this->txtFrom->ResetText();
		this -> txtTo->ResetText();
		//this->txtMessage->ResetText();
		std::string saveCSV = strDTG + "," + fromStr + "," + toStr + "," + fromMessage;
	}


};
}
