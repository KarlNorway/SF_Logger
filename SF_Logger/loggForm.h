#pragma once
#include <string>
#include <msclr\marshal.h> 
#include <time.h>
#include <locale.h> 
#include <fstream>
#include <Windows.h>
#include <atlstr.h>

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
		
	public: System::Windows::Forms::TextBox^  txtFrom;
	public: System::Windows::Forms::TextBox^  txtTo;
	public: System::Windows::Forms::TextBox^  txtMessage;
	public: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Label^  lblDTG;
	private: System::Windows::Forms::Label^  lblFrom;
	private: System::Windows::Forms::Label^  lblTo;
	private: System::Windows::Forms::Button^  btnShow;
	private: System::Windows::Forms::Label^  lblMessage;

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
			this->btnShow = (gcnew System::Windows::Forms::Button());
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
			this->txtMessage->TextChanged += gcnew System::EventHandler(this, &loggForm::txtMessage_TextChanged);
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
			this->lblDTG->Location = System::Drawing::Point(0, 0);
			this->lblDTG->Name = L"lblDTG";
			this->lblDTG->Size = System::Drawing::Size(100, 23);
			this->lblDTG->TabIndex = 0;
			// 
			// btnShow
			// 
			this->btnShow->Location = System::Drawing::Point(209, 36);
			this->btnShow->Name = L"btnShow";
			this->btnShow->Size = System::Drawing::Size(40, 40);
			this->btnShow->TabIndex = 7;
			this->btnShow->Text = L"Show";
			this->btnShow->UseVisualStyleBackColor = true;
			this->btnShow->Click += gcnew System::EventHandler(this, &loggForm::btnShow_Click);
			// 
			// loggForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(338, 434);
			this->Controls->Add(this->btnShow);
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
		private:
    System::Void txtMessage_TextChanged(System::Object^  sender_txtMessChange, System::EventArgs^  e);
	System::Void btnSave_Click(System::Object^  sender_save, System::EventArgs^  e); 
	System::Void btnShow_Click(System::Object^  sender_show, System::EventArgs^  e);
};
}
