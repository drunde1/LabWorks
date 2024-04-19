#pragma once
#include "TFigure.h"

TRhomb rhombs[100];
int irh = 0;
//int nrh = 1;

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Rhombs
	/// </summary>
	public ref class Rhombs : public System::Windows::Forms::Form
	{
	public:
		Rhombs(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Rhombs()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox5;
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomRhombToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ RectPar;
	private: System::Windows::Forms::Button^ TurnRhomb;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ DelRhomb;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ RhXoffset;
	private: System::Windows::Forms::NumericUpDown^ RhYoffset;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ NumberRhomb;

	private: System::Windows::Forms::Button^ MoveRhomb;

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
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomRhombToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RectPar = (gcnew System::Windows::Forms::GroupBox());
			this->TurnRhomb = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DelRhomb = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->RhXoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->RhYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NumberRhomb = (gcnew System::Windows::Forms::NumericUpDown());
			this->MoveRhomb = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->RectPar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RhXoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RhYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRhomb))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox5->Location = System::Drawing::Point(0, 31);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(2048, 792);
			this->pictureBox5->TabIndex = 17;
			this->pictureBox5->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createRandomRhombToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomRhombToolStripMenuItem
			// 
			this->createRandomRhombToolStripMenuItem->Name = L"createRandomRhombToolStripMenuItem";
			this->createRandomRhombToolStripMenuItem->Size = System::Drawing::Size(178, 24);
			this->createRandomRhombToolStripMenuItem->Text = L"Create Random Rhomb";
			this->createRandomRhombToolStripMenuItem->Click += gcnew System::EventHandler(this, &Rhombs::createRandomRhombToolStripMenuItem_Click);
			// 
			// RectPar
			// 
			this->RectPar->Controls->Add(this->TurnRhomb);
			this->RectPar->Controls->Add(this->label6);
			this->RectPar->Controls->Add(this->DelRhomb);
			this->RectPar->Controls->Add(this->label5);
			this->RectPar->Controls->Add(this->RhXoffset);
			this->RectPar->Controls->Add(this->RhYoffset);
			this->RectPar->Controls->Add(this->label4);
			this->RectPar->Controls->Add(this->label3);
			this->RectPar->Controls->Add(this->label2);
			this->RectPar->Controls->Add(this->NumberRhomb);
			this->RectPar->Controls->Add(this->MoveRhomb);
			this->RectPar->Location = System::Drawing::Point(636, 829);
			this->RectPar->Name = L"RectPar";
			this->RectPar->Size = System::Drawing::Size(670, 135);
			this->RectPar->TabIndex = 20;
			this->RectPar->TabStop = false;
			this->RectPar->Text = L"Rhomb Parameters";
			// 
			// TurnRhomb
			// 
			this->TurnRhomb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnRhomb->Location = System::Drawing::Point(506, 86);
			this->TurnRhomb->Name = L"TurnRhomb";
			this->TurnRhomb->Size = System::Drawing::Size(119, 40);
			this->TurnRhomb->TabIndex = 21;
			this->TurnRhomb->Text = L"Turn on 90";
			this->TurnRhomb->UseVisualStyleBackColor = true;
			this->TurnRhomb->Click += gcnew System::EventHandler(this, &Rhombs::TurnRhomb_Click);
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
			// DelRhomb
			// 
			this->DelRhomb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelRhomb->Location = System::Drawing::Point(506, 35);
			this->DelRhomb->Name = L"DelRhomb";
			this->DelRhomb->Size = System::Drawing::Size(119, 40);
			this->DelRhomb->TabIndex = 19;
			this->DelRhomb->Text = L"Delete";
			this->DelRhomb->UseVisualStyleBackColor = true;
			this->DelRhomb->Click += gcnew System::EventHandler(this, &Rhombs::DelRhomb_Click);
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
			// RhXoffset
			// 
			this->RhXoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RhXoffset->Location = System::Drawing::Point(206, 35);
			this->RhXoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->RhXoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->RhXoffset->Name = L"RhXoffset";
			this->RhXoffset->Size = System::Drawing::Size(107, 34);
			this->RhXoffset->TabIndex = 17;
			// 
			// RhYoffset
			// 
			this->RhYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RhYoffset->Location = System::Drawing::Point(206, 90);
			this->RhYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->RhYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->RhYoffset->Name = L"RhYoffset";
			this->RhYoffset->Size = System::Drawing::Size(107, 34);
			this->RhYoffset->TabIndex = 16;
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
			this->label2->Location = System::Drawing::Point(354, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 29);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Rhomb";
			// 
			// NumberRhomb
			// 
			this->NumberRhomb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberRhomb->Location = System::Drawing::Point(345, 90);
			this->NumberRhomb->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberRhomb->Name = L"NumberRhomb";
			this->NumberRhomb->Size = System::Drawing::Size(124, 34);
			this->NumberRhomb->TabIndex = 12;
			// 
			// MoveRhomb
			// 
			this->MoveRhomb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MoveRhomb->Location = System::Drawing::Point(8, 86);
			this->MoveRhomb->Name = L"MoveRhomb";
			this->MoveRhomb->Size = System::Drawing::Size(87, 41);
			this->MoveRhomb->TabIndex = 10;
			this->MoveRhomb->Text = L"Move";
			this->MoveRhomb->UseVisualStyleBackColor = true;
			this->MoveRhomb->Click += gcnew System::EventHandler(this, &Rhombs::MoveRhomb_Click);
			// 
			// Rhombs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->RectPar);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Rhombs";
			this->Text = L"Rhombs";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->RectPar->ResumeLayout(false);
			this->RectPar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RhXoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RhYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRhomb))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ canvas5;

	private: System::Void createRandomRhombToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MoveRhomb_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelRhomb_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TurnRhomb_Click(System::Object^ sender, System::EventArgs^ e);
};
}
