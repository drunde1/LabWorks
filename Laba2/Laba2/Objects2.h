#pragma once
#include "Ring.h"
#include "Triangle.h"

int iring = 0, itr = 0;
int nring = 1, ntr = 1;
Ring* rings;
Triangle* triangles;

namespace Laba2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Objects2
	/// </summary>
	public ref class Objects2 : public System::Windows::Forms::Form
	{
	public:
		Objects2(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Objects2()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ crateRandomRing;
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomTriangle;
	public: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::GroupBox^ RingPar;
	public:
	private: System::Windows::Forms::Button^ ResizeRing;
	private: System::Windows::Forms::Label^ label66;
	private: System::Windows::Forms::Button^ DelRing;
	private: System::Windows::Forms::Label^ label55;
	private: System::Windows::Forms::NumericUpDown^ RingoffsetX;
	private: System::Windows::Forms::NumericUpDown^ RingoffsetY;


	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::NumericUpDown^ NumberRing;
	private: System::Windows::Forms::Button^ MoveRing;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::NumericUpDown^ TrAngleOffset;

	private: System::Windows::Forms::Button^ TurnTriangle;

	private: System::Windows::Forms::Label^ label71;
	private: System::Windows::Forms::Button^ TriangleDel;


	private: System::Windows::Forms::Label^ label81;
	private: System::Windows::Forms::NumericUpDown^ TriangleXoffset;
	private: System::Windows::Forms::NumericUpDown^ TriangleYoffset;



	private: System::Windows::Forms::Label^ label91;

	private: System::Windows::Forms::Label^ label101;
	private: System::Windows::Forms::Label^ label111;
	private: System::Windows::Forms::NumericUpDown^ NumberTriangle;



	private: System::Windows::Forms::Button^ TriangleMove;

	private:
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
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->crateRandomRing = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createRandomTriangle = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->RingPar = (gcnew System::Windows::Forms::GroupBox());
			this->ResizeRing = (gcnew System::Windows::Forms::Button());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->DelRing = (gcnew System::Windows::Forms::Button());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->RingoffsetX = (gcnew System::Windows::Forms::NumericUpDown());
			this->RingoffsetY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->NumberRing = (gcnew System::Windows::Forms::NumericUpDown());
			this->MoveRing = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->TrAngleOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->TurnTriangle = (gcnew System::Windows::Forms::Button());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->TriangleDel = (gcnew System::Windows::Forms::Button());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->TriangleXoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->TriangleYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->NumberTriangle = (gcnew System::Windows::Forms::NumericUpDown());
			this->TriangleMove = (gcnew System::Windows::Forms::Button());
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->RingPar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RingoffsetX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RingoffsetY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRing))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrAngleOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TriangleXoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TriangleYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberTriangle))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1924, 28);
			this->menuStrip2->TabIndex = 17;
			this->menuStrip2->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->crateRandomRing,
					this->createRandomTriangle
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// crateRandomRing
			// 
			this->crateRandomRing->Name = L"crateRandomRing";
			this->crateRandomRing->Size = System::Drawing::Size(252, 26);
			this->crateRandomRing->Text = L"Create Random Ring";
			this->crateRandomRing->Click += gcnew System::EventHandler(this, &Objects2::crateRandomRing_Click);
			// 
			// createRandomTriangle
			// 
			this->createRandomTriangle->Name = L"createRandomTriangle";
			this->createRandomTriangle->Size = System::Drawing::Size(252, 26);
			this->createRandomTriangle->Text = L"Create Random Triangle";
			this->createRandomTriangle->Click += gcnew System::EventHandler(this, &Objects2::createRandomTriangle_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox2->Location = System::Drawing::Point(0, 31);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(2048, 792);
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// RingPar
			// 
			this->RingPar->Controls->Add(this->ResizeRing);
			this->RingPar->Controls->Add(this->label66);
			this->RingPar->Controls->Add(this->DelRing);
			this->RingPar->Controls->Add(this->label55);
			this->RingPar->Controls->Add(this->RingoffsetX);
			this->RingPar->Controls->Add(this->RingoffsetY);
			this->RingPar->Controls->Add(this->label44);
			this->RingPar->Controls->Add(this->label33);
			this->RingPar->Controls->Add(this->label22);
			this->RingPar->Controls->Add(this->NumberRing);
			this->RingPar->Controls->Add(this->MoveRing);
			this->RingPar->Location = System::Drawing::Point(12, 829);
			this->RingPar->Name = L"RingPar";
			this->RingPar->Size = System::Drawing::Size(670, 135);
			this->RingPar->TabIndex = 18;
			this->RingPar->TabStop = false;
			this->RingPar->Text = L"Ring Parameters";
			// 
			// ResizeRing
			// 
			this->ResizeRing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResizeRing->Location = System::Drawing::Point(506, 86);
			this->ResizeRing->Name = L"ResizeRing";
			this->ResizeRing->Size = System::Drawing::Size(119, 40);
			this->ResizeRing->TabIndex = 21;
			this->ResizeRing->Text = L"Resize";
			this->ResizeRing->UseVisualStyleBackColor = true;
			this->ResizeRing->Click += gcnew System::EventHandler(this, &Objects2::ResizeRing_Click);
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label66->Location = System::Drawing::Point(384, 58);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(36, 29);
			this->label66->TabIndex = 20;
			this->label66->Text = L"є";
			// 
			// DelRing
			// 
			this->DelRing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelRing->Location = System::Drawing::Point(506, 35);
			this->DelRing->Name = L"DelRing";
			this->DelRing->Size = System::Drawing::Size(119, 40);
			this->DelRing->TabIndex = 19;
			this->DelRing->Text = L"Delete";
			this->DelRing->UseVisualStyleBackColor = true;
			this->DelRing->Click += gcnew System::EventHandler(this, &Objects2::DelRing_Click);
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label55->Location = System::Drawing::Point(101, 92);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(99, 29);
			this->label55->TabIndex = 18;
			this->label55->Text = L"Y offset:";
			// 
			// RingoffsetX
			// 
			this->RingoffsetX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RingoffsetX->Location = System::Drawing::Point(206, 35);
			this->RingoffsetX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->RingoffsetX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->RingoffsetX->Name = L"RingoffsetX";
			this->RingoffsetX->Size = System::Drawing::Size(107, 34);
			this->RingoffsetX->TabIndex = 17;
			// 
			// RingoffsetY
			// 
			this->RingoffsetY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RingoffsetY->Location = System::Drawing::Point(206, 90);
			this->RingoffsetY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->RingoffsetY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->RingoffsetY->Name = L"RingoffsetY";
			this->RingoffsetY->Size = System::Drawing::Size(107, 34);
			this->RingoffsetY->TabIndex = 16;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label44->Location = System::Drawing::Point(94, 37);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(106, 29);
			this->label44->TabIndex = 15;
			this->label44->Text = L" X offset:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label33->Location = System::Drawing::Point(6, 35);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(97, 29);
			this->label33->TabIndex = 14;
			this->label33->Text = L"Moving:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(368, 29);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(63, 29);
			this->label22->TabIndex = 13;
			this->label22->Text = L"Ring";
			// 
			// NumberRing
			// 
			this->NumberRing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberRing->Location = System::Drawing::Point(345, 90);
			this->NumberRing->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberRing->Name = L"NumberRing";
			this->NumberRing->Size = System::Drawing::Size(124, 34);
			this->NumberRing->TabIndex = 12;
			// 
			// MoveRing
			// 
			this->MoveRing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MoveRing->Location = System::Drawing::Point(8, 86);
			this->MoveRing->Name = L"MoveRing";
			this->MoveRing->Size = System::Drawing::Size(87, 41);
			this->MoveRing->TabIndex = 10;
			this->MoveRing->Text = L"Move";
			this->MoveRing->UseVisualStyleBackColor = true;
			this->MoveRing->Click += gcnew System::EventHandler(this, &Objects2::MoveRing_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->TrAngleOffset);
			this->groupBox2->Controls->Add(this->TurnTriangle);
			this->groupBox2->Controls->Add(this->label71);
			this->groupBox2->Controls->Add(this->TriangleDel);
			this->groupBox2->Controls->Add(this->label81);
			this->groupBox2->Controls->Add(this->TriangleXoffset);
			this->groupBox2->Controls->Add(this->TriangleYoffset);
			this->groupBox2->Controls->Add(this->label91);
			this->groupBox2->Controls->Add(this->label101);
			this->groupBox2->Controls->Add(this->label111);
			this->groupBox2->Controls->Add(this->NumberTriangle);
			this->groupBox2->Controls->Add(this->TriangleMove);
			this->groupBox2->Location = System::Drawing::Point(698, 829);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(670, 135);
			this->groupBox2->TabIndex = 24;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Triangle Parameters";
			// 
			// TrAngleOffset
			// 
			this->TrAngleOffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TrAngleOffset->Location = System::Drawing::Point(583, 87);
			this->TrAngleOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->TrAngleOffset->Name = L"TrAngleOffset";
			this->TrAngleOffset->Size = System::Drawing::Size(81, 34);
			this->TrAngleOffset->TabIndex = 22;
			// 
			// TurnTriangle
			// 
			this->TurnTriangle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnTriangle->Location = System::Drawing::Point(482, 86);
			this->TurnTriangle->Name = L"TurnTriangle";
			this->TurnTriangle->Size = System::Drawing::Size(95, 40);
			this->TurnTriangle->TabIndex = 21;
			this->TurnTriangle->Text = L"Turn on:";
			this->TurnTriangle->UseVisualStyleBackColor = true;
			this->TurnTriangle->Click += gcnew System::EventHandler(this, &Objects2::TurnTriangle_Click);
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label71->Location = System::Drawing::Point(384, 58);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(36, 29);
			this->label71->TabIndex = 20;
			this->label71->Text = L"є";
			// 
			// TriangleDel
			// 
			this->TriangleDel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TriangleDel->Location = System::Drawing::Point(515, 37);
			this->TriangleDel->Name = L"TriangleDel";
			this->TriangleDel->Size = System::Drawing::Size(109, 40);
			this->TriangleDel->TabIndex = 19;
			this->TriangleDel->Text = L"Delete";
			this->TriangleDel->UseVisualStyleBackColor = true;
			this->TriangleDel->Click += gcnew System::EventHandler(this, &Objects2::TriangleDel_Click);
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label81->Location = System::Drawing::Point(101, 92);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(99, 29);
			this->label81->TabIndex = 18;
			this->label81->Text = L"Y offset:";
			// 
			// TriangleXoffset
			// 
			this->TriangleXoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TriangleXoffset->Location = System::Drawing::Point(206, 35);
			this->TriangleXoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->TriangleXoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->TriangleXoffset->Name = L"TriangleXoffset";
			this->TriangleXoffset->Size = System::Drawing::Size(107, 34);
			this->TriangleXoffset->TabIndex = 17;
			// 
			// TriangleYoffset
			// 
			this->TriangleYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TriangleYoffset->Location = System::Drawing::Point(206, 90);
			this->TriangleYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->TriangleYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->TriangleYoffset->Name = L"TriangleYoffset";
			this->TriangleYoffset->Size = System::Drawing::Size(107, 34);
			this->TriangleYoffset->TabIndex = 16;
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label91->Location = System::Drawing::Point(94, 37);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(106, 29);
			this->label91->TabIndex = 15;
			this->label91->Text = L" X offset:";
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label101->Location = System::Drawing::Point(6, 35);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(97, 29);
			this->label101->TabIndex = 14;
			this->label101->Text = L"Moving:";
			// 
			// label111
			// 
			this->label111->AutoSize = true;
			this->label111->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label111->Location = System::Drawing::Point(353, 29);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(103, 29);
			this->label111->TabIndex = 13;
			this->label111->Text = L"Triangle";
			// 
			// NumberTriangle
			// 
			this->NumberTriangle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberTriangle->Location = System::Drawing::Point(345, 90);
			this->NumberTriangle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberTriangle->Name = L"NumberTriangle";
			this->NumberTriangle->Size = System::Drawing::Size(124, 34);
			this->NumberTriangle->TabIndex = 12;
			// 
			// TriangleMove
			// 
			this->TriangleMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TriangleMove->Location = System::Drawing::Point(8, 86);
			this->TriangleMove->Name = L"TriangleMove";
			this->TriangleMove->Size = System::Drawing::Size(87, 41);
			this->TriangleMove->TabIndex = 10;
			this->TriangleMove->Text = L"Move";
			this->TriangleMove->UseVisualStyleBackColor = true;
			this->TriangleMove->Click += gcnew System::EventHandler(this, &Objects2::TriangleMove_Click);
			// 
			// Objects2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->RingPar);
			this->Controls->Add(this->menuStrip2);
			this->Controls->Add(this->pictureBox2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Objects2";
			this->Text = L"Objects2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->RingPar->ResumeLayout(false);
			this->RingPar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RingoffsetX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RingoffsetY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRing))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TrAngleOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TriangleXoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TriangleYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberTriangle))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: Graphics^ Canvas;
private: Bitmap^ Bmp;

private: System::Void crateRandomRing_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void createRandomTriangle_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void MoveRing_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DelRing_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ResizeRing_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void TriangleMove_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TriangleDel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TurnTriangle_Click(System::Object^ sender, System::EventArgs^ e);
};
}
