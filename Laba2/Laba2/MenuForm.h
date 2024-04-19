#pragma once
#include "Objects.h"
#include "Objects2.h"
#include <cstdlib>
//#include <stdlib.h>
#include <time.h>

namespace Laba2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void);
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ SimFig;
	private: System::Windows::Forms::Button^ ComFig;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SimFig = (gcnew System::Windows::Forms::Button());
			this->ComFig = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SimFig
			// 
			this->SimFig->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SimFig->Location = System::Drawing::Point(258, 192);
			this->SimFig->Name = L"SimFig";
			this->SimFig->Size = System::Drawing::Size(148, 84);
			this->SimFig->TabIndex = 0;
			this->SimFig->Text = L"Simple Figure";
			this->SimFig->UseVisualStyleBackColor = true;
			this->SimFig->Click += gcnew System::EventHandler(this, &MenuForm::SimFig_Click);
			// 
			// ComFig
			// 
			this->ComFig->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ComFig->Location = System::Drawing::Point(519, 192);
			this->ComFig->Name = L"ComFig";
			this->ComFig->Size = System::Drawing::Size(163, 84);
			this->ComFig->TabIndex = 1;
			this->ComFig->Text = L"Complex Figure";
			this->ComFig->UseVisualStyleBackColor = true;
			this->ComFig->Click += gcnew System::EventHandler(this, &MenuForm::ComFig_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->ClientSize = System::Drawing::Size(920, 464);
			this->Controls->Add(this->ComFig);
			this->Controls->Add(this->SimFig);
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SimFig_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ComFig_Click(System::Object^ sender, System::EventArgs^ e);
	
	};
}
