#pragma once
#include "TFigure.h"

TRectangle rectangles[100];
int ir = 0;
//int nr = 1;

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Rectangles
	/// </summary>
	public ref class Rectangles : public System::Windows::Forms::Form
	{
	public:
		Rectangles(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Rectangles()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox4;
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomRectangleToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ RectPar;
	private: System::Windows::Forms::Button^ TurnRect;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ DelRect;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ RecXoffset;
	private: System::Windows::Forms::NumericUpDown^ RecYoffset;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ NumberRect;
	private: System::Windows::Forms::Button^ MoveRec;
	public:
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
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomRectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RectPar = (gcnew System::Windows::Forms::GroupBox());
			this->TurnRect = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DelRect = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->RecXoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->RecYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NumberRect = (gcnew System::Windows::Forms::NumericUpDown());
			this->MoveRec = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->RectPar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RecXoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RecYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRect))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox4->Location = System::Drawing::Point(0, 31);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(2048, 792);
			this->pictureBox4->TabIndex = 17;
			this->pictureBox4->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createRandomRectangleToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomRectangleToolStripMenuItem
			// 
			this->createRandomRectangleToolStripMenuItem->Name = L"createRandomRectangleToolStripMenuItem";
			this->createRandomRectangleToolStripMenuItem->Size = System::Drawing::Size(196, 24);
			this->createRandomRectangleToolStripMenuItem->Text = L"Create Random Rectangle";
			this->createRandomRectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Rectangles::createRandomRectangleToolStripMenuItem_Click);
			// 
			// RectPar
			// 
			this->RectPar->Controls->Add(this->TurnRect);
			this->RectPar->Controls->Add(this->label6);
			this->RectPar->Controls->Add(this->DelRect);
			this->RectPar->Controls->Add(this->label5);
			this->RectPar->Controls->Add(this->RecXoffset);
			this->RectPar->Controls->Add(this->RecYoffset);
			this->RectPar->Controls->Add(this->label4);
			this->RectPar->Controls->Add(this->label3);
			this->RectPar->Controls->Add(this->label2);
			this->RectPar->Controls->Add(this->NumberRect);
			this->RectPar->Controls->Add(this->MoveRec);
			this->RectPar->Location = System::Drawing::Point(650, 829);
			this->RectPar->Name = L"RectPar";
			this->RectPar->Size = System::Drawing::Size(670, 135);
			this->RectPar->TabIndex = 19;
			this->RectPar->TabStop = false;
			this->RectPar->Text = L"Rectangle Parameters";
			// 
			// TurnRect
			// 
			this->TurnRect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnRect->Location = System::Drawing::Point(506, 86);
			this->TurnRect->Name = L"TurnRect";
			this->TurnRect->Size = System::Drawing::Size(119, 40);
			this->TurnRect->TabIndex = 21;
			this->TurnRect->Text = L"Turn on 90";
			this->TurnRect->UseVisualStyleBackColor = true;
			this->TurnRect->Click += gcnew System::EventHandler(this, &Rectangles::TurnRect_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(384, 58);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(36, 29);
			this->label6->TabIndex = 20;
			this->label6->Text = L"є";
			// 
			// DelRect
			// 
			this->DelRect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelRect->Location = System::Drawing::Point(506, 35);
			this->DelRect->Name = L"DelRect";
			this->DelRect->Size = System::Drawing::Size(119, 40);
			this->DelRect->TabIndex = 19;
			this->DelRect->Text = L"Delete";
			this->DelRect->UseVisualStyleBackColor = true;
			this->DelRect->Click += gcnew System::EventHandler(this, &Rectangles::DelRect_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(101, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 29);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Y offset:";
			// 
			// RecXoffset
			// 
			this->RecXoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RecXoffset->Location = System::Drawing::Point(206, 35);
			this->RecXoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->RecXoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->RecXoffset->Name = L"RecXoffset";
			this->RecXoffset->Size = System::Drawing::Size(107, 34);
			this->RecXoffset->TabIndex = 17;
			// 
			// RecYoffset
			// 
			this->RecYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RecYoffset->Location = System::Drawing::Point(206, 90);
			this->RecYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->RecYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->RecYoffset->Name = L"RecYoffset";
			this->RecYoffset->Size = System::Drawing::Size(107, 34);
			this->RecYoffset->TabIndex = 16;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(94, 37);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 29);
			this->label4->TabIndex = 15;
			this->label4->Text = L" X offset:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 29);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Moving:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(340, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 29);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Rectangle";
			// 
			// NumberRect
			// 
			this->NumberRect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberRect->Location = System::Drawing::Point(345, 90);
			this->NumberRect->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberRect->Name = L"NumberRect";
			this->NumberRect->Size = System::Drawing::Size(124, 34);
			this->NumberRect->TabIndex = 12;
			// 
			// MoveRec
			// 
			this->MoveRec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MoveRec->Location = System::Drawing::Point(8, 86);
			this->MoveRec->Name = L"MoveRec";
			this->MoveRec->Size = System::Drawing::Size(87, 41);
			this->MoveRec->TabIndex = 10;
			this->MoveRec->Text = L"Move";
			this->MoveRec->UseVisualStyleBackColor = true;
			this->MoveRec->Click += gcnew System::EventHandler(this, &Rectangles::MoveRec_Click);
			// 
			// Rectangles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->RectPar);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Rectangles";
			this->Text = L"Rectangles";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->RectPar->ResumeLayout(false);
			this->RectPar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RecXoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RecYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRect))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ canvas4;

	private: System::Void createRandomRectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MoveRec_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelRect_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TurnRect_Click(System::Object^ sender, System::EventArgs^ e);
};
}
