#pragma once
#include "TFigure.h"
#include <time.h>
TFigure* figures[30];

namespace Lab5 {

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
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ createRandomCircleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ destroyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eraseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ moveToolStripMenuItem;
	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ moveToOnlyToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ circlesAndEllipsesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quadranglesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ resizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ circleAndEllipsessToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem;
	private:


	public:
	private:

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->createRandomCircleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->destroyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eraseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->moveToOnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circlesAndEllipsesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quadranglesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleAndEllipsessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->createRandomCircleToolStripMenuItem,
					this->moveToOnlyToolStripMenuItem, this->resizeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 30);
			this->menuStrip1->TabIndex = 20;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// createRandomCircleToolStripMenuItem
			// 
			this->createRandomCircleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->createToolStripMenuItem,
					this->destroyToolStripMenuItem, this->eraseToolStripMenuItem, this->showToolStripMenuItem, this->moveToolStripMenuItem
			});
			this->createRandomCircleToolStripMenuItem->Name = L"createRandomCircleToolStripMenuItem";
			this->createRandomCircleToolStripMenuItem->Size = System::Drawing::Size(58, 24);
			this->createRandomCircleToolStripMenuItem->Text = L"Array";
			// 
			// createToolStripMenuItem
			// 
			this->createToolStripMenuItem->Name = L"createToolStripMenuItem";
			this->createToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->createToolStripMenuItem->Text = L"Create";
			this->createToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::createToolStripMenuItem_Click);
			// 
			// destroyToolStripMenuItem
			// 
			this->destroyToolStripMenuItem->Name = L"destroyToolStripMenuItem";
			this->destroyToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->destroyToolStripMenuItem->Text = L"Destroy";
			this->destroyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::destroyToolStripMenuItem_Click);
			// 
			// eraseToolStripMenuItem
			// 
			this->eraseToolStripMenuItem->Name = L"eraseToolStripMenuItem";
			this->eraseToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->eraseToolStripMenuItem->Text = L"Erase";
			this->eraseToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::eraseToolStripMenuItem_Click);
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->showToolStripMenuItem->Text = L"Show";
			this->showToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::showToolStripMenuItem_Click);
			// 
			// moveToolStripMenuItem
			// 
			this->moveToolStripMenuItem->Name = L"moveToolStripMenuItem";
			this->moveToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->moveToolStripMenuItem->Text = L"Move to point";
			this->moveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::moveToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox1->Location = System::Drawing::Point(0, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(2048, 942);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// moveToOnlyToolStripMenuItem
			// 
			this->moveToOnlyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->circlesAndEllipsesToolStripMenuItem,
					this->quadranglesToolStripMenuItem
			});
			this->moveToOnlyToolStripMenuItem->Name = L"moveToOnlyToolStripMenuItem";
			this->moveToOnlyToolStripMenuItem->Size = System::Drawing::Size(110, 24);
			this->moveToOnlyToolStripMenuItem->Text = L"Move to only";
			// 
			// circlesAndEllipsesToolStripMenuItem
			// 
			this->circlesAndEllipsesToolStripMenuItem->Name = L"circlesAndEllipsesToolStripMenuItem";
			this->circlesAndEllipsesToolStripMenuItem->Size = System::Drawing::Size(421, 26);
			this->circlesAndEllipsesToolStripMenuItem->Text = L"Circles and Ellipses";
			this->circlesAndEllipsesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::circlesAndEllipsesToolStripMenuItem_Click);
			// 
			// quadranglesToolStripMenuItem
			// 
			this->quadranglesToolStripMenuItem->Name = L"quadranglesToolStripMenuItem";
			this->quadranglesToolStripMenuItem->Size = System::Drawing::Size(421, 26);
			this->quadranglesToolStripMenuItem->Text = L"Quadrangles, Rectangles, Rhombs and Trapezoids";
			this->quadranglesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::quadranglesToolStripMenuItem_Click);
			// 
			// resizeToolStripMenuItem
			// 
			this->resizeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->circleAndEllipsessToolStripMenuItem,
					this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem
			});
			this->resizeToolStripMenuItem->Name = L"resizeToolStripMenuItem";
			this->resizeToolStripMenuItem->Size = System::Drawing::Size(97, 26);
			this->resizeToolStripMenuItem->Text = L"Resize only";
			// 
			// circleAndEllipsessToolStripMenuItem
			// 
			this->circleAndEllipsessToolStripMenuItem->Name = L"circleAndEllipsessToolStripMenuItem";
			this->circleAndEllipsessToolStripMenuItem->Size = System::Drawing::Size(421, 26);
			this->circleAndEllipsessToolStripMenuItem->Text = L"Circle and Ellipsess";
			this->circleAndEllipsessToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::circleAndEllipsessToolStripMenuItem_Click);
			// 
			// quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem
			// 
			this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem->Name = L"quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem";
			this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem->Size = System::Drawing::Size(421, 26);
			this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem->Text = L"Quadrangles, Rectangles, Rhombs and Trapezoids";
			this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem_Click);
			// 
			// Objects
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 973);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Objects";
			this->Text = L"Objects";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Objects::Objects_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: Graphics^ canvas;
private: System::Void createToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void destroyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void eraseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void showToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void moveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void Objects_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);

private: System::Void circlesAndEllipsesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void quadranglesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void circleAndEllipsessToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
