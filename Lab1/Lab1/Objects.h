#pragma once
#include <stdlib.h>
#include <time.h>
#include "RectClass.h"
#include "Line.h"
#include "Circle.h"

Rect* rect = new Rect[10];
Circle* circle = new Circle[10];
Line* line = new Line[10];
int i, ic, il = 0;

namespace Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Objects
	/// </summary>
	public ref class Objects : public System::Windows::Forms::Form
	{
	public:
		Objects(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Objects()
		{
			if (components)
			{
				delete components;
			}
			//delete[] rect;
			//delete[] circle;
			//delete[] line;
		}

	protected:

	protected:







	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ rectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createtToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createCurcleToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::GroupBox^ RectPar;














	private: System::Windows::Forms::Button^ button1;

















	private: System::Windows::Forms::NumericUpDown^ NumberRect;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ offsetX;

	private: System::Windows::Forms::NumericUpDown^ offsetY;

	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ buttonDel;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ LineDel;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ LineXoffset;
	private: System::Windows::Forms::NumericUpDown^ LIneYoffset;


	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::NumericUpDown^ NumberLine;

	private: System::Windows::Forms::Button^ CurMove;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ DelCur;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ CXoffcet;
	private: System::Windows::Forms::NumericUpDown^ CYoffset;


	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::NumericUpDown^ NumberCur;
private: System::Windows::Forms::Button^ LineMove;
private: System::Windows::Forms::Button^ TurnRect;
private: System::Windows::Forms::Button^ TurnLine;
private: System::Windows::Forms::NumericUpDown^ AngleOffset;
private: System::Windows::Forms::Button^ TurnCir;




	public:
	private:



	private: System::ComponentModel::IContainer^ components;

	private:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createtToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createCurcleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->RectPar = (gcnew System::Windows::Forms::GroupBox());
			this->TurnRect = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->buttonDel = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->offsetX = (gcnew System::Windows::Forms::NumericUpDown());
			this->offsetY = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NumberRect = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->AngleOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->TurnLine = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->LineDel = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->LineXoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->LIneYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->NumberLine = (gcnew System::Windows::Forms::NumericUpDown());
			this->LineMove = (gcnew System::Windows::Forms::Button());
			this->CurMove = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->TurnCir = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->DelCur = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->CXoffcet = (gcnew System::Windows::Forms::NumericUpDown());
			this->CYoffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->NumberCur = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1->SuspendLayout();
			this->RectPar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->offsetX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->offsetY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRect))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AngleOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LineXoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LIneYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberLine))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CXoffcet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CYoffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberCur))->BeginInit();
			this->SuspendLayout();
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->rectangleToolStripMenuItem,
					this->createtToolStripMenuItem, this->createCurcleToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// rectangleToolStripMenuItem
			// 
			this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
			this->rectangleToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->rectangleToolStripMenuItem->Text = L"Create Random Rectangle";
			this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::rectangleToolStripMenuItem_Click);
			// 
			// createtToolStripMenuItem
			// 
			this->createtToolStripMenuItem->Name = L"createtToolStripMenuItem";
			this->createtToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->createtToolStripMenuItem->Text = L"Create Random Line";
			this->createtToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::createtToolStripMenuItem_Click);
			// 
			// createCurcleToolStripMenuItem
			// 
			this->createCurcleToolStripMenuItem->Name = L"createCurcleToolStripMenuItem";
			this->createCurcleToolStripMenuItem->Size = System::Drawing::Size(265, 26);
			this->createCurcleToolStripMenuItem->Text = L"Create Random Circle";
			this->createCurcleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::createCurcleToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// RectPar
			// 
			this->RectPar->Controls->Add(this->TurnRect);
			this->RectPar->Controls->Add(this->label6);
			this->RectPar->Controls->Add(this->buttonDel);
			this->RectPar->Controls->Add(this->label5);
			this->RectPar->Controls->Add(this->offsetX);
			this->RectPar->Controls->Add(this->offsetY);
			this->RectPar->Controls->Add(this->label4);
			this->RectPar->Controls->Add(this->label3);
			this->RectPar->Controls->Add(this->label2);
			this->RectPar->Controls->Add(this->NumberRect);
			this->RectPar->Controls->Add(this->button1);
			this->RectPar->Location = System::Drawing::Point(12, 826);
			this->RectPar->Name = L"RectPar";
			this->RectPar->Size = System::Drawing::Size(670, 135);
			this->RectPar->TabIndex = 3;
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
			this->TurnRect->Click += gcnew System::EventHandler(this, &Objects::TurnRect_Click);
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
			// buttonDel
			// 
			this->buttonDel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDel->Location = System::Drawing::Point(506, 35);
			this->buttonDel->Name = L"buttonDel";
			this->buttonDel->Size = System::Drawing::Size(119, 40);
			this->buttonDel->TabIndex = 19;
			this->buttonDel->Text = L"Delete";
			this->buttonDel->UseVisualStyleBackColor = true;
			this->buttonDel->Click += gcnew System::EventHandler(this, &Objects::buttonDel_Click);
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
			// offsetX
			// 
			this->offsetX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->offsetX->Location = System::Drawing::Point(206, 35);
			this->offsetX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->offsetX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->offsetX->Name = L"offsetX";
			this->offsetX->Size = System::Drawing::Size(107, 34);
			this->offsetX->TabIndex = 17;
			// 
			// offsetY
			// 
			this->offsetY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->offsetY->Location = System::Drawing::Point(206, 90);
			this->offsetY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->offsetY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->offsetY->Name = L"offsetY";
			this->offsetY->Size = System::Drawing::Size(107, 34);
			this->offsetY->TabIndex = 16;
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
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(8, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 41);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Move";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Objects::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox1->Location = System::Drawing::Point(0, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(2048, 792);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->AngleOffset);
			this->groupBox2->Controls->Add(this->TurnLine);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->LineDel);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->LineXoffset);
			this->groupBox2->Controls->Add(this->LIneYoffset);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->NumberLine);
			this->groupBox2->Controls->Add(this->LineMove);
			this->groupBox2->Location = System::Drawing::Point(688, 826);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(670, 135);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Line Parameters";
			// 
			// AngleOffset
			// 
			this->AngleOffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AngleOffset->Location = System::Drawing::Point(583, 87);
			this->AngleOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 360, 0, 0, 0 });
			this->AngleOffset->Name = L"AngleOffset";
			this->AngleOffset->Size = System::Drawing::Size(81, 34);
			this->AngleOffset->TabIndex = 22;
			// 
			// TurnLine
			// 
			this->TurnLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnLine->Location = System::Drawing::Point(482, 86);
			this->TurnLine->Name = L"TurnLine";
			this->TurnLine->Size = System::Drawing::Size(95, 40);
			this->TurnLine->TabIndex = 21;
			this->TurnLine->Text = L"Turn on:";
			this->TurnLine->UseVisualStyleBackColor = true;
			this->TurnLine->Click += gcnew System::EventHandler(this, &Objects::TurnLine_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(384, 58);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(36, 29);
			this->label7->TabIndex = 20;
			this->label7->Text = L"є";
			// 
			// LineDel
			// 
			this->LineDel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LineDel->Location = System::Drawing::Point(515, 37);
			this->LineDel->Name = L"LineDel";
			this->LineDel->Size = System::Drawing::Size(109, 40);
			this->LineDel->TabIndex = 19;
			this->LineDel->Text = L"Delete";
			this->LineDel->UseVisualStyleBackColor = true;
			this->LineDel->Click += gcnew System::EventHandler(this, &Objects::LineDel_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(101, 92);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 29);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Y offset:";
			// 
			// LineXoffset
			// 
			this->LineXoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LineXoffset->Location = System::Drawing::Point(206, 35);
			this->LineXoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->LineXoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->LineXoffset->Name = L"LineXoffset";
			this->LineXoffset->Size = System::Drawing::Size(107, 34);
			this->LineXoffset->TabIndex = 17;
			// 
			// LIneYoffset
			// 
			this->LIneYoffset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LIneYoffset->Location = System::Drawing::Point(206, 90);
			this->LIneYoffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, 0 });
			this->LIneYoffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1533, 0, 0, System::Int32::MinValue });
			this->LIneYoffset->Name = L"LIneYoffset";
			this->LIneYoffset->Size = System::Drawing::Size(107, 34);
			this->LIneYoffset->TabIndex = 16;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(94, 37);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(106, 29);
			this->label9->TabIndex = 15;
			this->label9->Text = L" X offset:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(6, 35);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(97, 29);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Moving:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(370, 29);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(59, 29);
			this->label11->TabIndex = 13;
			this->label11->Text = L"Line";
			// 
			// NumberLine
			// 
			this->NumberLine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberLine->Location = System::Drawing::Point(345, 90);
			this->NumberLine->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberLine->Name = L"NumberLine";
			this->NumberLine->Size = System::Drawing::Size(124, 34);
			this->NumberLine->TabIndex = 12;
			// 
			// LineMove
			// 
			this->LineMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LineMove->Location = System::Drawing::Point(8, 86);
			this->LineMove->Name = L"LineMove";
			this->LineMove->Size = System::Drawing::Size(87, 41);
			this->LineMove->TabIndex = 10;
			this->LineMove->Text = L"Move";
			this->LineMove->UseVisualStyleBackColor = true;
			this->LineMove->Click += gcnew System::EventHandler(this, &Objects::LineMove_Click);
			// 
			// CurMove
			// 
			this->CurMove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CurMove->Location = System::Drawing::Point(8, 83);
			this->CurMove->Name = L"CurMove";
			this->CurMove->Size = System::Drawing::Size(87, 41);
			this->CurMove->TabIndex = 10;
			this->CurMove->Text = L"Move";
			this->CurMove->UseVisualStyleBackColor = true;
			this->CurMove->Click += gcnew System::EventHandler(this, &Objects::CurMove_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->TurnCir);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->DelCur);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->CXoffcet);
			this->groupBox3->Controls->Add(this->CYoffset);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->NumberCur);
			this->groupBox3->Controls->Add(this->CurMove);
			this->groupBox3->Location = System::Drawing::Point(1364, 826);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(670, 135);
			this->groupBox3->TabIndex = 21;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Circle Parameters";
			// 
			// TurnCir
			// 
			this->TurnCir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TurnCir->Location = System::Drawing::Point(507, 81);
			this->TurnCir->Name = L"TurnCir";
			this->TurnCir->Size = System::Drawing::Size(118, 40);
			this->TurnCir->TabIndex = 21;
			this->TurnCir->Text = L"Turn on 90";
			this->TurnCir->UseVisualStyleBackColor = true;
			this->TurnCir->Click += gcnew System::EventHandler(this, &Objects::TurnCir_Click);
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
			// DelCur
			// 
			this->DelCur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DelCur->Location = System::Drawing::Point(507, 35);
			this->DelCur->Name = L"DelCur";
			this->DelCur->Size = System::Drawing::Size(118, 40);
			this->DelCur->TabIndex = 19;
			this->DelCur->Text = L"Delete";
			this->DelCur->UseVisualStyleBackColor = true;
			this->DelCur->Click += gcnew System::EventHandler(this, &Objects::DelCur_Click);
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
			this->label16->Location = System::Drawing::Point(351, 28);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(76, 29);
			this->label16->TabIndex = 13;
			this->label16->Text = L"Circle";
			// 
			// NumberCur
			// 
			this->NumberCur->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NumberCur->Location = System::Drawing::Point(345, 90);
			this->NumberCur->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->NumberCur->Name = L"NumberCur";
			this->NumberCur->Size = System::Drawing::Size(124, 34);
			this->NumberCur->TabIndex = 12;
			// 
			// Objects
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->RectPar);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Objects";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Objects";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->RectPar->ResumeLayout(false);
			this->RectPar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->offsetX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->offsetY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberRect))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AngleOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LineXoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LIneYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberLine))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CXoffcet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CYoffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumberCur))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: Graphics^ canvas;
	private: Bitmap^ bmp;
	

	private: System::Void rectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void createtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void createCurcleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonDel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CurMove_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DelCur_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LineMove_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LineDel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TurnRect_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TurnLine_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TurnCir_Click(System::Object^ sender, System::EventArgs^ e);
};
}
