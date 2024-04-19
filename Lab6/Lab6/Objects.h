#pragma once
#include "Container.h"
#include "TFigure.h"
#include <time.h>
TFigure* figures[30];
MyContainer* container = NULL;
int nt = 3;
int it = 0;
namespace Lab6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Objects
	/// </summary>
	public ref class Objects : public System::Windows::Forms::Form
	{
	public:
		Objects(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::ToolStripMenuItem^ moveToOnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ circlesAndEllipsesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quadranglesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ resizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ circleAndEllipsessToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem;
	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ сontainer1ToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ createToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ moveToPointToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ destroyToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ container2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ moveToPointToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ destroyToolStripMenuItem2;
	private:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
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
			this->moveToOnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circlesAndEllipsesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quadranglesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleAndEllipsessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сontainer1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveToPointToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->destroyToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->container2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveToPointToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->destroyToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->createRandomCircleToolStripMenuItem,
					this->moveToOnlyToolStripMenuItem, this->resizeToolStripMenuItem, this->сontainer1ToolStripMenuItem, this->container2ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 28);
			this->menuStrip1->TabIndex = 21;
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
			this->resizeToolStripMenuItem->Size = System::Drawing::Size(97, 24);
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
			// сontainer1ToolStripMenuItem
			// 
			this->сontainer1ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->createToolStripMenuItem1,
					this->addToolStripMenuItem, this->moveToPointToolStripMenuItem, this->destroyToolStripMenuItem1
			});
			this->сontainer1ToolStripMenuItem->Name = L"сontainer1ToolStripMenuItem";
			this->сontainer1ToolStripMenuItem->Size = System::Drawing::Size(112, 24);
			this->сontainer1ToolStripMenuItem->Text = L"Сontainer№1";
			// 
			// createToolStripMenuItem1
			// 
			this->createToolStripMenuItem1->Name = L"createToolStripMenuItem1";
			this->createToolStripMenuItem1->Size = System::Drawing::Size(186, 26);
			this->createToolStripMenuItem1->Text = L"Create";
			this->createToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Objects::createToolStripMenuItem1_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->addToolStripMenuItem->Text = L"Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::addToolStripMenuItem_Click);
			// 
			// moveToPointToolStripMenuItem
			// 
			this->moveToPointToolStripMenuItem->Name = L"moveToPointToolStripMenuItem";
			this->moveToPointToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->moveToPointToolStripMenuItem->Text = L"Move to point";
			this->moveToPointToolStripMenuItem->Click += gcnew System::EventHandler(this, &Objects::moveToPointToolStripMenuItem_Click);
			// 
			// destroyToolStripMenuItem1
			// 
			this->destroyToolStripMenuItem1->Name = L"destroyToolStripMenuItem1";
			this->destroyToolStripMenuItem1->Size = System::Drawing::Size(186, 26);
			this->destroyToolStripMenuItem1->Text = L"Destroy";
			this->destroyToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Objects::destroyToolStripMenuItem1_Click);
			// 
			// container2ToolStripMenuItem
			// 
			this->container2ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->createToolStripMenuItem2,
					this->addToolStripMenuItem1, this->moveToPointToolStripMenuItem1, this->destroyToolStripMenuItem2
			});
			this->container2ToolStripMenuItem->Name = L"container2ToolStripMenuItem";
			this->container2ToolStripMenuItem->Size = System::Drawing::Size(112, 24);
			this->container2ToolStripMenuItem->Text = L"Container№2";
			// 
			// createToolStripMenuItem2
			// 
			this->createToolStripMenuItem2->Name = L"createToolStripMenuItem2";
			this->createToolStripMenuItem2->Size = System::Drawing::Size(224, 26);
			this->createToolStripMenuItem2->Text = L"Create";
			this->createToolStripMenuItem2->Click += gcnew System::EventHandler(this, &Objects::createToolStripMenuItem2_Click);
			// 
			// addToolStripMenuItem1
			// 
			this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
			this->addToolStripMenuItem1->Size = System::Drawing::Size(224, 26);
			this->addToolStripMenuItem1->Text = L"Add";
			this->addToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Objects::addToolStripMenuItem1_Click);
			// 
			// moveToPointToolStripMenuItem1
			// 
			this->moveToPointToolStripMenuItem1->Name = L"moveToPointToolStripMenuItem1";
			this->moveToPointToolStripMenuItem1->Size = System::Drawing::Size(224, 26);
			this->moveToPointToolStripMenuItem1->Text = L"Move to point";
			this->moveToPointToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Objects::moveToPointToolStripMenuItem1_Click);
			// 
			// destroyToolStripMenuItem2
			// 
			this->destroyToolStripMenuItem2->Name = L"destroyToolStripMenuItem2";
			this->destroyToolStripMenuItem2->Size = System::Drawing::Size(224, 26);
			this->destroyToolStripMenuItem2->Text = L"Destroy";
			this->destroyToolStripMenuItem2->Click += gcnew System::EventHandler(this, &Objects::destroyToolStripMenuItem2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(86)));
			this->pictureBox1->Location = System::Drawing::Point(0, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(2048, 942);
			this->pictureBox1->TabIndex = 22;
			this->pictureBox1->TabStop = false;
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
private: System::Void circlesAndEllipsesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void quadranglesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void circleAndEllipsessToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Objects_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);


private: System::Void createToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void addToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void moveToPointToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void destroyToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void createToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void addToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void moveToPointToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void destroyToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
