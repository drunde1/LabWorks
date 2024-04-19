#pragma once
//#include "TFigure.h"
#include "Circles.h"
#include "Ellipses.h"
#include "Quadrangles.h"
#include "Rectangles.h"
#include "Rhombs.h"
#include "Trapezoids.h"
#include <time.h>
#include <stdlib.h>


namespace Lab3 {

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

	protected:

	public:



	private: System::Windows::Forms::ToolStripMenuItem^ createCurcleToolStripMenuItem;












	private: System::Windows::Forms::ToolStripMenuItem^ createRandomCircleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomEllipseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomQuadrangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomRectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomRhombToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomTrapezoidToolStripMenuItem;
	private: System::Windows::Forms::Button^ CirBut;
	private: System::Windows::Forms::Button^ ElBut;
	private: System::Windows::Forms::Button^ QuaBut;
	private: System::Windows::Forms::Button^ RecBut;
	private: System::Windows::Forms::Button^ RhBut;
	private: System::Windows::Forms::Button^ TrapBut;



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
			this->createRandomCircleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createRandomEllipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createRandomQuadrangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createRandomRectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createRandomRhombToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createRandomTrapezoidToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CirBut = (gcnew System::Windows::Forms::Button());
			this->ElBut = (gcnew System::Windows::Forms::Button());
			this->QuaBut = (gcnew System::Windows::Forms::Button());
			this->RecBut = (gcnew System::Windows::Forms::Button());
			this->RhBut = (gcnew System::Windows::Forms::Button());
			this->TrapBut = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// createRandomCircleToolStripMenuItem
			// 
			this->createRandomCircleToolStripMenuItem->Name = L"createRandomCircleToolStripMenuItem";
			this->createRandomCircleToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// createRandomEllipseToolStripMenuItem
			// 
			this->createRandomEllipseToolStripMenuItem->Name = L"createRandomEllipseToolStripMenuItem";
			this->createRandomEllipseToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// createRandomQuadrangleToolStripMenuItem
			// 
			this->createRandomQuadrangleToolStripMenuItem->Name = L"createRandomQuadrangleToolStripMenuItem";
			this->createRandomQuadrangleToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// createRandomRectangleToolStripMenuItem
			// 
			this->createRandomRectangleToolStripMenuItem->Name = L"createRandomRectangleToolStripMenuItem";
			this->createRandomRectangleToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// createRandomRhombToolStripMenuItem
			// 
			this->createRandomRhombToolStripMenuItem->Name = L"createRandomRhombToolStripMenuItem";
			this->createRandomRhombToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// createRandomTrapezoidToolStripMenuItem
			// 
			this->createRandomTrapezoidToolStripMenuItem->Name = L"createRandomTrapezoidToolStripMenuItem";
			this->createRandomTrapezoidToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// CirBut
			// 
			this->CirBut->Font = (gcnew System::Drawing::Font(L"Mistral", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CirBut->Location = System::Drawing::Point(180, 184);
			this->CirBut->Name = L"CirBut";
			this->CirBut->Size = System::Drawing::Size(179, 93);
			this->CirBut->TabIndex = 0;
			this->CirBut->Text = L"Circles";
			this->CirBut->UseVisualStyleBackColor = true;
			this->CirBut->Click += gcnew System::EventHandler(this, &MenuForm::CirBut_Click);
			// 
			// ElBut
			// 
			this->ElBut->Font = (gcnew System::Drawing::Font(L"Mistral", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ElBut->Location = System::Drawing::Point(402, 184);
			this->ElBut->Name = L"ElBut";
			this->ElBut->Size = System::Drawing::Size(179, 93);
			this->ElBut->TabIndex = 1;
			this->ElBut->Text = L"Ellipses";
			this->ElBut->UseVisualStyleBackColor = true;
			this->ElBut->Click += gcnew System::EventHandler(this, &MenuForm::ElBut_Click);
			// 
			// QuaBut
			// 
			this->QuaBut->Font = (gcnew System::Drawing::Font(L"Mistral", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QuaBut->Location = System::Drawing::Point(615, 184);
			this->QuaBut->Name = L"QuaBut";
			this->QuaBut->Size = System::Drawing::Size(192, 93);
			this->QuaBut->TabIndex = 2;
			this->QuaBut->Text = L"Quadrangles";
			this->QuaBut->UseVisualStyleBackColor = true;
			this->QuaBut->Click += gcnew System::EventHandler(this, &MenuForm::QuaBut_Click);
			// 
			// RecBut
			// 
			this->RecBut->Font = (gcnew System::Drawing::Font(L"Mistral", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RecBut->Location = System::Drawing::Point(180, 354);
			this->RecBut->Name = L"RecBut";
			this->RecBut->Size = System::Drawing::Size(179, 93);
			this->RecBut->TabIndex = 3;
			this->RecBut->Text = L"Rectangles";
			this->RecBut->UseVisualStyleBackColor = true;
			this->RecBut->Click += gcnew System::EventHandler(this, &MenuForm::RecBut_Click);
			// 
			// RhBut
			// 
			this->RhBut->Font = (gcnew System::Drawing::Font(L"Mistral", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RhBut->Location = System::Drawing::Point(402, 354);
			this->RhBut->Name = L"RhBut";
			this->RhBut->Size = System::Drawing::Size(179, 93);
			this->RhBut->TabIndex = 4;
			this->RhBut->Text = L"Rhombs";
			this->RhBut->UseVisualStyleBackColor = true;
			this->RhBut->Click += gcnew System::EventHandler(this, &MenuForm::RhBut_Click);
			// 
			// TrapBut
			// 
			this->TrapBut->Font = (gcnew System::Drawing::Font(L"Mistral", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TrapBut->Location = System::Drawing::Point(615, 354);
			this->TrapBut->Name = L"TrapBut";
			this->TrapBut->Size = System::Drawing::Size(192, 93);
			this->TrapBut->TabIndex = 5;
			this->TrapBut->Text = L"Trapezoids";
			this->TrapBut->UseVisualStyleBackColor = true;
			this->TrapBut->Click += gcnew System::EventHandler(this, &MenuForm::TrapBut_Click);
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Controls->Add(this->TrapBut);
			this->Controls->Add(this->RhBut);
			this->Controls->Add(this->RecBut);
			this->Controls->Add(this->QuaBut);
			this->Controls->Add(this->ElBut);
			this->Controls->Add(this->CirBut);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuForm";
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void CirBut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ElBut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void QuaBut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void RecBut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void RhBut_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TrapBut_Click(System::Object^ sender, System::EventArgs^ e);
};
}
