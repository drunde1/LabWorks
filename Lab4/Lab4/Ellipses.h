#pragma once
#include "TFigure.h"

TEllipse ellipses[100];
int ie = 0;

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Ellipses
	/// </summary>
	public ref class Ellipses : public System::Windows::Forms::Form
	{
	public:
		Ellipses(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Ellipses()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox2;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomEllipseToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ TurnEll;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ DelEll;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ EllXoffcet;
	private: System::Windows::Forms::NumericUpDown^ EllYoffset;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::NumericUpDown^ NumberEll;
	private: System::Windows::Forms::Button^ EllMove;

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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomEllipseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->TurnEll = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->DelEll = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->EllXoffcet = (gcnew System::Windows::Forms::NumericUpDown());
			this->EllYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->NumberEll = (gcnew System::Windows::Forms::NumericUpDown());
			this->EllMove = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EllXoffcet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EllYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberEll))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox2->Location = System::Drawing::Point(0, 31);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(2048, 792);
			this->pictureBox2->TabIndex = 18;
			this->pictureBox2->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createRandomEllipseToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomEllipseToolStripMenuItem
			// 
			this->createRandomEllipseToolStripMenuItem->Name = L"createRandomEllipseToolStripMenuItem";
			this->createRandomEllipseToolStripMenuItem->Size = System::Drawing::Size(173, 24);
			this->createRandomEllipseToolStripMenuItem->Text = L"Create Random Ellipse";
			this->createRandomEllipseToolStripMenuItem->Click += gcnew System::EventHandler(this, &Ellipses::createRandomEllipseToolStripMenuItem_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->TurnEll);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->DelEll);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->EllXoffcet);
			this->groupBox3->Controls->Add(this->EllYoffset);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->NumberEll);
			this->groupBox3->Controls->Add(this->EllMove);
			this->groupBox3->Location = System::Drawing::Point(688, 829);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(670, 135);
			this->groupBox3->TabIndex = 27;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ellips Parameters";
			// 
			// TurnEll
			// 
			this->TurnEll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnEll->Location = System::Drawing::Point(507, 81);
			this->TurnEll->Name = L"TurnEll";
			this->TurnEll->Size = System::Drawing::Size(118, 40);
			this->TurnEll->TabIndex = 21;
			this->TurnEll->Text = L"Turn on 90";
			this->TurnEll->UseVisualStyleBackColor = true;
			this->TurnEll->Click += gcnew System::EventHandler(this, &Ellipses::TurnEll_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(384, 58);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 29);
			this->label12->TabIndex = 20;
			this->label12->Text = L"є";
			// 
			// DelEll
			// 
			this->DelEll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelEll->Location = System::Drawing::Point(507, 35);
			this->DelEll->Name = L"DelEll";
			this->DelEll->Size = System::Drawing::Size(118, 40);
			this->DelEll->TabIndex = 19;
			this->DelEll->Text = L"Delete";
			this->DelEll->UseVisualStyleBackColor = true;
			this->DelEll->Click += gcnew System::EventHandler(this, &Ellipses::DelEll_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(101, 92);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(99, 29);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Y offset:";
			// 
			// EllXoffcet
			// 
			this->EllXoffcet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EllXoffcet->Location = System::Drawing::Point(206, 35);
			this->EllXoffcet->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->EllXoffcet->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->EllXoffcet->Name = L"EllXoffcet";
			this->EllXoffcet->Size = System::Drawing::Size(107, 34);
			this->EllXoffcet->TabIndex = 17;
			// 
			// EllYoffset
			// 
			this->EllYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EllYoffset->Location = System::Drawing::Point(206, 90);
			this->EllYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->EllYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->EllYoffset->Name = L"EllYoffset";
			this->EllYoffset->Size = System::Drawing::Size(107, 34);
			this->EllYoffset->TabIndex = 16;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(94, 37);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(106, 29);
			this->label14->TabIndex = 15;
			this->label14->Text = L" X offset:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(6, 35);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(97, 29);
			this->label15->TabIndex = 14;
			this->label15->Text = L"Moving:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(354, 29);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(87, 29);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Ellipse";
			// 
			// NumberEll
			// 
			this->NumberEll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberEll->Location = System::Drawing::Point(345, 90);
			this->NumberEll->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberEll->Name = L"NumberEll";
			this->NumberEll->Size = System::Drawing::Size(124, 34);
			this->NumberEll->TabIndex = 12;
			// 
			// EllMove
			// 
			this->EllMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EllMove->Location = System::Drawing::Point(8, 83);
			this->EllMove->Name = L"EllMove";
			this->EllMove->Size = System::Drawing::Size(87, 41);
			this->EllMove->TabIndex = 10;
			this->EllMove->Text = L"Move";
			this->EllMove->UseVisualStyleBackColor = true;
			this->EllMove->Click += gcnew System::EventHandler(this, &Ellipses::EllMove_Click);
			// 
			// Ellipses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Ellipses";
			this->Text = L"Ellipses";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EllXoffcet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EllYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberEll))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ canvas2;

private: System::Void createRandomEllipseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EllMove_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DelEll_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TurnEll_Click(System::Object^ sender, System::EventArgs^ e);
};
}
