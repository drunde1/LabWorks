#pragma once
#include "TFigure.h"

TCircle circles[100];
int ic = 0;
namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Circles
	/// </summary>
	public ref class Circles : public System::Windows::Forms::Form
	{
	public:
		Circles(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Circles()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomCircleToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ ResCir;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ DelCir;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ CXoffcet;
	private: System::Windows::Forms::NumericUpDown^ CYoffset;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::NumericUpDown^ NumberCir;
	private: System::Windows::Forms::Button^ CirMove;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomCircleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->ResCir = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->DelCir = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->CXoffcet = (gcnew System::Windows::Forms::NumericUpDown());
			this->CYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->NumberCir = (gcnew System::Windows::Forms::NumericUpDown());
			this->CirMove = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CXoffcet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberCir))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox1->Location = System::Drawing::Point(0, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(2048, 792);
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createRandomCircleToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomCircleToolStripMenuItem
			// 
			this->createRandomCircleToolStripMenuItem->Name = L"createRandomCircleToolStripMenuItem";
			this->createRandomCircleToolStripMenuItem->Size = System::Drawing::Size(167, 24);
			this->createRandomCircleToolStripMenuItem->Text = L"Create Random Circle";
			this->createRandomCircleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Circles::createRandomCircleToolStripMenuItem_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->ResCir);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->DelCir);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->CXoffcet);
			this->groupBox3->Controls->Add(this->CYoffset);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->NumberCir);
			this->groupBox3->Controls->Add(this->CirMove);
			this->groupBox3->Location = System::Drawing::Point(649, 829);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(670, 135);
			this->groupBox3->TabIndex = 26;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Circle Parameters";
			// 
			// ResCir
			// 
			this->ResCir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResCir->Location = System::Drawing::Point(507, 81);
			this->ResCir->Name = L"ResCir";
			this->ResCir->Size = System::Drawing::Size(118, 40);
			this->ResCir->TabIndex = 21;
			this->ResCir->Text = L"Resize";
			this->ResCir->UseVisualStyleBackColor = true;
			this->ResCir->Click += gcnew System::EventHandler(this, &Circles::ResCir_Click);
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
			// DelCir
			// 
			this->DelCir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelCir->Location = System::Drawing::Point(507, 35);
			this->DelCir->Name = L"DelCir";
			this->DelCir->Size = System::Drawing::Size(118, 40);
			this->DelCir->TabIndex = 19;
			this->DelCir->Text = L"Delete";
			this->DelCir->UseVisualStyleBackColor = true;
			this->DelCir->Click += gcnew System::EventHandler(this, &Circles::DelCir_Click);
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
			// CXoffcet
			// 
			this->CXoffcet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CXoffcet->Location = System::Drawing::Point(206, 35);
			this->CXoffcet->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->CXoffcet->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->CXoffcet->Name = L"CXoffcet";
			this->CXoffcet->Size = System::Drawing::Size(107, 34);
			this->CXoffcet->TabIndex = 17;
			// 
			// CYoffset
			// 
			this->CYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CYoffset->Location = System::Drawing::Point(206, 90);
			this->CYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->CYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->CYoffset->Name = L"CYoffset";
			this->CYoffset->Size = System::Drawing::Size(107, 34);
			this->CYoffset->TabIndex = 16;
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
			this->label16->Location = System::Drawing::Point(363, 29);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(76, 29);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Circle";
			// 
			// NumberCir
			// 
			this->NumberCir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberCir->Location = System::Drawing::Point(345, 90);
			this->NumberCir->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberCir->Name = L"NumberCir";
			this->NumberCir->Size = System::Drawing::Size(124, 34);
			this->NumberCir->TabIndex = 12;
			// 
			// CirMove
			// 
			this->CirMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CirMove->Location = System::Drawing::Point(8, 83);
			this->CirMove->Name = L"CirMove";
			this->CirMove->Size = System::Drawing::Size(87, 41);
			this->CirMove->TabIndex = 10;
			this->CirMove->Text = L"Move";
			this->CirMove->UseVisualStyleBackColor = true;
			this->CirMove->Click += gcnew System::EventHandler(this, &Circles::CirMove_Click);
			// 
			// Circles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Circles";
			this->Text = L"Circles";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CXoffcet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberCir))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ canvas1;

private: System::Void createRandomCircleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CirMove_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DelCir_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ResCir_Click(System::Object^ sender, System::EventArgs^ e);
};
}
