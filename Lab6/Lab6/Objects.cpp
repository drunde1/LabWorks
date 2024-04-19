#include "Objects.h"
#include "Container.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab6::Objects form;
	Application::Run(% form);
}

Lab6::Objects::Objects(void)
{
	InitializeComponent();
	canvas = pictureBox1->CreateGraphics();
	canvas->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

System::Void Lab6::Objects::createToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		int r = rand() % 6 + 1;
		if (r == 1)
			figures[i] = new TCircle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1);
		else if (r == 2)
			figures[i] = new TEllipse(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1);
		else if (r == 3)
			figures[i] = new TQuadrangle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1,
				rand() % 200 + 1, rand() % 90 + 270, rand() % 60 + 1, rand() % 60 + 90);
		else if (r == 4)
			figures[i] = new TRectangle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1);
		else if (r == 5)
			figures[i] = new TRhomb(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1);
		else if (r == 6)
			figures[i] = new TTrapezoid(rand() % 1533 + 1, rand() % 1533 + 1, rand() % 1533 + 1, rand() % 1533 + 1, rand() % 641 + 1, rand() % 641 + 1);
	}
}

System::Void Lab6::Objects::destroyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	canvas->Clear(Color::FromArgb(145, 225, 86));
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL)
		{
			figures[i]->Free();
			figures[i]->~TFigure();
			figures[i] = NULL;
		}
	}
}

System::Void Lab6::Objects::eraseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	canvas->Clear(Color::FromArgb(145, 225, 86));
}

System::Void Lab6::Objects::showToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL)
			figures[i]->Show(canvas);
	}
}

System::Void Lab6::Objects::moveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	int newx = rand() % 100 + 1;
	int newy = rand() % 50 + 1;
	if (rand() % 2 + 1 == 1)
		newx = -newx;
	if (rand() % 2 + 1 == 2)
		newy = -newy;
	canvas->Clear(Color::FromArgb(145, 225, 86));
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL)
			figures[i]->MoveTo(newx, newy, canvas);
	}
}

System::Void Lab6::Objects::Objects_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode.ToString() == "Right")
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int i = 0; i < 30; i++)
		{
			if (figures[i] != NULL)
				figures[i]->MoveTo(10, 0, canvas);
		}
	}
	else if (e->KeyCode.ToString() == "Left")
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int i = 0; i < 30; i++)
		{
			if (figures[i] != NULL)
				figures[i]->MoveTo(-10, 0, canvas);
		}
	}
	else if (e->KeyCode.ToString() == "Up")
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int i = 0; i < 30; i++)
		{
			if (figures[i] != NULL)
				figures[i]->MoveTo(0, -10, canvas);
		}
	}
	else if (e->KeyCode.ToString() == "Down")
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int i = 0; i < 30; i++)
		{
			if (figures[i] != NULL)
				figures[i]->MoveTo(0, 10, canvas);
		}
	}
}

System::Void Lab6::Objects::circlesAndEllipsesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	int newx = rand() % 100 + 1;
	int newy = rand() % 50 + 1;
	if (rand() % 2 + 1 == 1)
		newx = -newx;
	if (rand() % 2 + 1 == 2)
		newy = -newy;
	canvas->Clear(Color::FromArgb(145, 225, 86));
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 1 || figures[i]->Type() == 2))
			figures[i]->MoveTo(newx, newy, canvas);
	}
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 3 || figures[i]->Type() == 4 || figures[i]->Type() == 5 || figures[i]->Type() == 6))
			figures[i]->Show(canvas);
	}
}

System::Void Lab6::Objects::quadranglesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	int newx = rand() % 100 + 1;
	int newy = rand() % 50 + 1;
	if (rand() % 2 + 1 == 1)
		newx = -newx;
	if (rand() % 2 + 1 == 2)
		newy = -newy;
	canvas->Clear(Color::FromArgb(145, 225, 86));
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 3 || figures[i]->Type() == 4 || figures[i]->Type() == 5 || figures[i]->Type() == 6))
			figures[i]->MoveTo(newx, newy, canvas);
	}
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 1 || figures[i]->Type() == 2))
			figures[i]->Show(canvas);
	}
}

System::Void Lab6::Objects::circleAndEllipsessToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	int newx = rand() % 100 + 1;
	if (rand() % 2 + 1 == 1)
		newx = -newx;
	canvas->Clear(Color::FromArgb(145, 225, 86));
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 1 || figures[i]->Type() == 2))
		{
			dynamic_cast <TCircle*>(figures[i]);
			figures[i]->Resize(newx, canvas);
		}

	}
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 3 || figures[i]->Type() == 4 || figures[i]->Type() == 5 || figures[i]->Type() == 6))
			figures[i]->Show(canvas);
	}
}

System::Void Lab6::Objects::quadranglesRectanglesRhombsAndTrapezoidsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	int newx = rand() % 100 + 1;
	if (rand() % 2 + 1 == 1)
		newx = -newx;

	canvas->Clear(Color::FromArgb(145, 225, 86));
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 3 || figures[i]->Type() == 4 || figures[i]->Type() == 5 || figures[i]->Type() == 6))
		{
			dynamic_cast <TQuadrangle*>(figures[i]);
			figures[i]->Resize(newx, canvas);
		}

	}
	for (int i = 0; i < 30; i++)
	{
		if (figures[i] != NULL && (figures[i]->Type() == 1 || figures[i]->Type() == 2))
			figures[i]->Show(canvas);
	}
}

// Контейнер1

System::Void Lab6::Objects::createToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tfigures == NULL)
	{
		tfigures = new TFigure* [2];
		MessageBox::Show("Container(dinamic array) is created!");
	}
	else
		MessageBox::Show("Container has already created!");
	
}

System::Void Lab6::Objects::addToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tfigures != NULL)
	{
		srand(time(NULL));
		int r = rand() % 6 + 1;
		if (r == 1)
			tfigures[it] = new TCircle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1);
		else if (r == 2)
			tfigures[it] = new TEllipse(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1);
		else if (r == 3)
			tfigures[it] = new TQuadrangle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1,
				rand() % 200 + 1, rand() % 90 + 270, rand() % 60 + 1, rand() % 60 + 90);
		else if (r == 4)
			tfigures[it] = new TRectangle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1);
		else if (r == 5)
			tfigures[it] = new TRhomb(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1);
		else if (r == 6)
			tfigures[it] = new TTrapezoid(rand() % 1533 + 1, rand() % 1533 + 1, rand() % 1533 + 1, rand() % 1533 + 1, rand() % 641 + 1, rand() % 641 + 1);
		for (int i = 0; i < nt - 2; i++)
		{
			tfigures[i]->Show(canvas);
		}
		it += 1;
		tfigures = (TFigure**)realloc(tfigures, nt * sizeof(TFigure**));
		nt += 1;
	}
	
}

System::Void Lab6::Objects::moveToPointToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tfigures != NULL)
	{
		srand(time(NULL));
		int newx = rand() % 100 + 1;
		int newy = rand() % 50 + 1;
		if (rand() % 2 + 1 == 1)
			newx = -newx;
		if (rand() % 2 + 1 == 2)
			newy = -newy;
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int i = 0; i < nt - 3; i++)
		{
			tfigures[i]->MoveTo(newx, newy, canvas);
		}
	}
}

System::Void Lab6::Objects::destroyToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tfigures != NULL)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for(int i = 0; i < nt - 3; i++)
		{
			tfigures[i]->Free();
			tfigures[i]->~TFigure();
		}
		it = 0;
		nt = 3;
		delete[] tfigures;
		tfigures = NULL;
		
	}
}

//Контейнер2

System::Void Lab6::Objects::createToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (container == NULL)
	{
		container = new MyContainer();
	}
	else
		MessageBox::Show("Container has already created!");
}

System::Void Lab6::Objects::addToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (container != NULL)
	{
		srand(time(NULL));
		int r = rand() % 6 + 1;
		if (r == 1)
			container->push_back(new TCircle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1));
		else if (r == 2)
			container->push_back(new TEllipse(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1));
		else if (r == 3)
			container->push_back(new TQuadrangle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1,
				rand() % 200 + 1, rand() % 90 + 270, rand() % 60 + 1, rand() % 60 + 90));
		else if (r == 4)
			container->push_back(new TRectangle(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1));
		else if (r == 5)
			container->push_back(new TRhomb(rand() % 1533 + 1, rand() % 641 + 1, rand() % 200 + 1, rand() % 200 + 1));
		else if (r == 6)
			container->push_back(new TTrapezoid(rand() % 1533 + 1, rand() % 1533 + 1, rand() % 1533 + 1, rand() % 1533 + 1, rand() % 641 + 1, rand() % 641 + 1));
		//container->Iterator(3, canvas);
		container->Iterator(1, canvas);
	}
}

System::Void Lab6::Objects::moveToPointToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (container != NULL)
	{
		srand(time(NULL));
		int newx = rand() % 100 + 1;
		int newy = rand() % 50 + 1;
		if (rand() % 2 + 1 == 1)
			newx = -newx;
		if (rand() % 2 + 1 == 2)
			newy = -newy;
		canvas->Clear(Color::FromArgb(145, 225, 86));
		container->Iterator(2, canvas, newx, newy);
	}
}

System::Void Lab6::Objects::destroyToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e)
{
	canvas->Clear(Color::FromArgb(145, 225, 86));
	container->Free();
	container->~MyContainer();
	container = NULL;
}