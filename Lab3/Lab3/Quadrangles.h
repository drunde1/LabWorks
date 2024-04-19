#pragma once
#include "TFigure.h"

TQuadrangle quadrangles[100];
int iq = 0;
//int nq = 1;

namespace Lab3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Quadrangles
	/// </summary>
	public ref class Quadrangles : public System::Windows::Forms::Form
	{
	public:
		Quadrangles(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Quadrangles()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox3;
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomQuadrangeleToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ ResQuadr;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ DelQuadr;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ QXoffcet;
	private: System::Windows::Forms::NumericUpDown^ QYoffset;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::NumericUpDown^ NumberQ;
	private: System::Windows::Forms::Button^ QuadrMove;
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
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomQuadrangeleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->ResQuadr = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->DelQuadr = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->QXoffcet = (gcnew System::Windows::Forms::NumericUpDown());
			this->QYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->NumberQ = (gcnew System::Windows::Forms::NumericUpDown());
			this->QuadrMove = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QXoffcet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberQ))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox3->Location = System::Drawing::Point(0, 31);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(2048, 792);
			this->pictureBox3->TabIndex = 17;
			this->pictureBox3->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createRandomQuadrangeleToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 18;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomQuadrangeleToolStripMenuItem
			// 
			this->createRandomQuadrangeleToolStripMenuItem->Name = L"createRandomQuadrangeleToolStripMenuItem";
			this->createRandomQuadrangeleToolStripMenuItem->Size = System::Drawing::Size(216, 24);
			this->createRandomQuadrangeleToolStripMenuItem->Text = L"Create Random Quadrangele";
			this->createRandomQuadrangeleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Quadrangles::createRandomQuadrangeleToolStripMenuItem_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->ResQuadr);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->DelQuadr);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->QXoffcet);
			this->groupBox3->Controls->Add(this->QYoffset);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->NumberQ);
			this->groupBox3->Controls->Add(this->QuadrMove);
			this->groupBox3->Location = System::Drawing::Point(665, 829);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(670, 135);
			this->groupBox3->TabIndex = 26;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Quadrangle Parameters";
			// 
			// ResQuadr
			// 
			this->ResQuadr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResQuadr->Location = System::Drawing::Point(507, 81);
			this->ResQuadr->Name = L"ResQuadr";
			this->ResQuadr->Size = System::Drawing::Size(118, 40);
			this->ResQuadr->TabIndex = 21;
			this->ResQuadr->Text = L"Resize";
			this->ResQuadr->UseVisualStyleBackColor = true;
			this->ResQuadr->Click += gcnew System::EventHandler(this, &Quadrangles::ResQuadr_Click);
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
			// DelQuadr
			// 
			this->DelQuadr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelQuadr->Location = System::Drawing::Point(507, 35);
			this->DelQuadr->Name = L"DelQuadr";
			this->DelQuadr->Size = System::Drawing::Size(118, 40);
			this->DelQuadr->TabIndex = 19;
			this->DelQuadr->Text = L"Delete";
			this->DelQuadr->UseVisualStyleBackColor = true;
			this->DelQuadr->Click += gcnew System::EventHandler(this, &Quadrangles::DelQuadr_Click);
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
			// QXoffcet
			// 
			this->QXoffcet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QXoffcet->Location = System::Drawing::Point(206, 35);
			this->QXoffcet->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->QXoffcet->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->QXoffcet->Name = L"QXoffcet";
			this->QXoffcet->Size = System::Drawing::Size(107, 34);
			this->QXoffcet->TabIndex = 17;
			// 
			// QYoffset
			// 
			this->QYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QYoffset->Location = System::Drawing::Point(206, 90);
			this->QYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->QYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->QYoffset->Name = L"QYoffset";
			this->QYoffset->Size = System::Drawing::Size(107, 34);
			this->QYoffset->TabIndex = 16;
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
			this->label16->Location = System::Drawing::Point(329, 29);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(140, 29);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Quadrangle";
			// 
			// NumberQ
			// 
			this->NumberQ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberQ->Location = System::Drawing::Point(345, 90);
			this->NumberQ->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberQ->Name = L"NumberQ";
			this->NumberQ->Size = System::Drawing::Size(124, 34);
			this->NumberQ->TabIndex = 12;
			// 
			// QuadrMove
			// 
			this->QuadrMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QuadrMove->Location = System::Drawing::Point(8, 83);
			this->QuadrMove->Name = L"QuadrMove";
			this->QuadrMove->Size = System::Drawing::Size(87, 41);
			this->QuadrMove->TabIndex = 10;
			this->QuadrMove->Text = L"Move";
			this->QuadrMove->UseVisualStyleBackColor = true;
			this->QuadrMove->Click += gcnew System::EventHandler(this, &Quadrangles::QuadrMove_Click);
			// 
			// Quadrangles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox3);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Quadrangles";
			this->Text = L"Quadrangles";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QXoffcet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberQ))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Graphics^ canvas3;

	private: System::Void createRandomQuadrangeleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void QuadrMove_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DelQuadr_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ResQuadr_Click(System::Object^ sender, System::EventArgs^ e);
};
}
