#pragma once
#include "TFigure.h"

TTrapezoid trapezoids[100];
int itr = 0;
//int ntr = 1;

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Trapezoids
	/// </summary>
	public ref class Trapezoids : public System::Windows::Forms::Form
	{
	public:
		Trapezoids(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Trapezoids()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox6;
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomTrapezoidToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ RectPar;
	private: System::Windows::Forms::Button^ ResTrap;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ DelTrap;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ TrXoffset;
	private: System::Windows::Forms::NumericUpDown^ TrYoffset;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ NumberTrap;
	private: System::Windows::Forms::Button^ MoveTrap;
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
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomTrapezoidToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RectPar = (gcnew System::Windows::Forms::GroupBox());
			this->ResTrap = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DelTrap = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->TrXoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->TrYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NumberTrap = (gcnew System::Windows::Forms::NumericUpDown());
			this->MoveTrap = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->RectPar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrXoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberTrap))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox6->Location = System::Drawing::Point(0, 31);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(2048, 792);
			this->pictureBox6->TabIndex = 17;
			this->pictureBox6->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createRandomTrapezoidToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomTrapezoidToolStripMenuItem
			// 
			this->createRandomTrapezoidToolStripMenuItem->Name = L"createRandomTrapezoidToolStripMenuItem";
			this->createRandomTrapezoidToolStripMenuItem->Size = System::Drawing::Size(196, 24);
			this->createRandomTrapezoidToolStripMenuItem->Text = L"Create Random Trapezoid";
			this->createRandomTrapezoidToolStripMenuItem->Click += gcnew System::EventHandler(this, &Trapezoids::createRandomTrapezoidToolStripMenuItem_Click);
			// 
			// RectPar
			// 
			this->RectPar->Controls->Add(this->ResTrap);
			this->RectPar->Controls->Add(this->label6);
			this->RectPar->Controls->Add(this->DelTrap);
			this->RectPar->Controls->Add(this->label5);
			this->RectPar->Controls->Add(this->TrXoffset);
			this->RectPar->Controls->Add(this->TrYoffset);
			this->RectPar->Controls->Add(this->label4);
			this->RectPar->Controls->Add(this->label3);
			this->RectPar->Controls->Add(this->label2);
			this->RectPar->Controls->Add(this->NumberTrap);
			this->RectPar->Controls->Add(this->MoveTrap);
			this->RectPar->Location = System::Drawing::Point(655, 829);
			this->RectPar->Name = L"RectPar";
			this->RectPar->Size = System::Drawing::Size(670, 135);
			this->RectPar->TabIndex = 20;
			this->RectPar->TabStop = false;
			this->RectPar->Text = L"Rectangle Parameters";
			// 
			// ResTrap
			// 
			this->ResTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResTrap->Location = System::Drawing::Point(506, 86);
			this->ResTrap->Name = L"ResTrap";
			this->ResTrap->Size = System::Drawing::Size(119, 40);
			this->ResTrap->TabIndex = 21;
			this->ResTrap->Text = L"Resize";
			this->ResTrap->UseVisualStyleBackColor = true;
			this->ResTrap->Click += gcnew System::EventHandler(this, &Trapezoids::ResTrap_Click);
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
			// DelTrap
			// 
			this->DelTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelTrap->Location = System::Drawing::Point(506, 35);
			this->DelTrap->Name = L"DelTrap";
			this->DelTrap->Size = System::Drawing::Size(119, 40);
			this->DelTrap->TabIndex = 19;
			this->DelTrap->Text = L"Delete";
			this->DelTrap->UseVisualStyleBackColor = true;
			this->DelTrap->Click += gcnew System::EventHandler(this, &Trapezoids::DelTrap_Click);
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
			// TrXoffset
			// 
			this->TrXoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TrXoffset->Location = System::Drawing::Point(206, 35);
			this->TrXoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->TrXoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->TrXoffset->Name = L"TrXoffset";
			this->TrXoffset->Size = System::Drawing::Size(107, 34);
			this->TrXoffset->TabIndex = 17;
			// 
			// TrYoffset
			// 
			this->TrYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TrYoffset->Location = System::Drawing::Point(206, 90);
			this->TrYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->TrYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->TrYoffset->Name = L"TrYoffset";
			this->TrYoffset->Size = System::Drawing::Size(107, 34);
			this->TrYoffset->TabIndex = 16;
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
			this->label2->Size = System::Drawing::Size(123, 29);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Trapezoid";
			// 
			// NumberTrap
			// 
			this->NumberTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberTrap->Location = System::Drawing::Point(345, 90);
			this->NumberTrap->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberTrap->Name = L"NumberTrap";
			this->NumberTrap->Size = System::Drawing::Size(124, 34);
			this->NumberTrap->TabIndex = 12;
			// 
			// MoveTrap
			// 
			this->MoveTrap->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MoveTrap->Location = System::Drawing::Point(8, 86);
			this->MoveTrap->Name = L"MoveTrap";
			this->MoveTrap->Size = System::Drawing::Size(87, 41);
			this->MoveTrap->TabIndex = 10;
			this->MoveTrap->Text = L"Move";
			this->MoveTrap->UseVisualStyleBackColor = true;
			this->MoveTrap->Click += gcnew System::EventHandler(this, &Trapezoids::MoveTrap_Click);
			// 
			// Trapezoids
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->RectPar);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Trapezoids";
			this->Text = L"Trapezoids";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->RectPar->ResumeLayout(false);
			this->RectPar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrXoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberTrap))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ canvas6;

	private: System::Void createRandomTrapezoidToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MoveTrap_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelTrap_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ResTrap_Click(System::Object^ sender, System::EventArgs^ e);
};
}
