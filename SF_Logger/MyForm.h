#pragma once
#include "loggForm.h"

namespace SF_Logger {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnNew;
	protected:
	private: System::Windows::Forms::Button^  btnArchive;
	private: System::Windows::Forms::Button^  btnEnd;
	private: System::Windows::Forms::Label^  label1;

	protected:

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
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnArchive = (gcnew System::Windows::Forms::Button());
			this->btnEnd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(69, 117);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(196, 53);
			this->btnNew->TabIndex = 0;
			this->btnNew->Text = L"Ny Aksjon";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &MyForm::btnNew_Click);
			// 
			// btnArchive
			// 
			this->btnArchive->Location = System::Drawing::Point(69, 203);
			this->btnArchive->Name = L"btnArchive";
			this->btnArchive->Size = System::Drawing::Size(196, 53);
			this->btnArchive->TabIndex = 1;
			this->btnArchive->Text = L"Aksjons arkiv";
			this->btnArchive->UseVisualStyleBackColor = true;
			// 
			// btnEnd
			// 
			this->btnEnd->Location = System::Drawing::Point(69, 292);
			this->btnEnd->Name = L"btnEnd";
			this->btnEnd->Size = System::Drawing::Size(196, 53);
			this->btnEnd->TabIndex = 2;
			this->btnEnd->Text = L"Avslutt";
			this->btnEnd->UseVisualStyleBackColor = true;
			this->btnEnd->Click += gcnew System::EventHandler(this, &MyForm::btnEnd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(228, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Velg for å gå videre. for ny logg velg Ny Aksjon";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(340, 368);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnEnd);
			this->Controls->Add(this->btnArchive);
			this->Controls->Add(this->btnNew);
			this->Name = L"MyForm";
			this->Text = L"SF Logger";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnEnd_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ message = "Er du sikker på at du vil avslutte?";
	String^ caption = "Avslutt";
	MessageBoxButtons buttons = MessageBoxButtons::YesNo;
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show(this, message, caption, buttons, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		// Closes the parent form.
		this->Close();
	}
	}
 private:System::Void btnNew_Click(System::Object^  sender, System::EventArgs^  e); 
};
}