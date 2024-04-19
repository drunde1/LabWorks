#include "Objects.h"
#include <random>


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab1::Objects form;
	Application::Run(% form);
	
}

Lab1::Objects::Objects(void)
{
	InitializeComponent();
	WindowState = FormWindowState::Maximized;
	canvas = pictureBox1->CreateGraphics();
	canvas->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

System::Void Lab1::Objects::rectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (i != 10)
	{
		int fault;
		int massx[30] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
		850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
		int x = rand() % 29 + 1;
		int massy[12] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
		int y = rand() % 11 + 1;
		srand(time(NULL));
		int x1, x2, y1, y2;
		fault = rand() % 26;
		if (rand() % 2 == 0)
			fault = -fault;
		x2 = massx[x] + fault;
		y2 = massy[y] + fault;
		x1 = massx[rand() % x] + fault;
		y1 = massy[rand() % y] + fault;

		rect[i].SetX1(x1);
		rect[i].SetY1(y1);
		rect[i].SetX2(x2);
		rect[i].SetY2(y2);
		rect[i].Show(canvas);
		i += 1;
	}
}

System::Void Lab1::Objects::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRect->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < i; j++)
		{
			rect[j].MoveTo(Convert::ToInt16(offsetX->Value), Convert::ToInt16(offsetY->Value));
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		rect[Convert::ToInt16(NumberRect->Value) - 1].MoveTo(Convert::ToInt16(offsetX->Value), Convert::ToInt16(offsetY->Value));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::CurMove_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberCur->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circle[j].MoveTo(Convert::ToInt16(CXoffcet->Value), Convert::ToInt16(CYoffset->Value));
			circle[j].Show(canvas);
		}
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		circle[Convert::ToInt16(NumberCur->Value) - 1].MoveTo(Convert::ToInt16(CXoffcet->Value), Convert::ToInt16(CYoffset->Value));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::buttonDel_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRect->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < i; j++)
		{
			rect[i].SetX1(0);
			rect[i].SetY1(0);
			rect[i].SetX2(0);
			rect[i].SetY2(0);
		}
		i = 0;
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else if (Convert::ToInt16(NumberRect->Value) - 1 < i)
	{
		rect[Convert::ToInt16(NumberRect->Value) - 1].SetX1(0);
		rect[Convert::ToInt16(NumberRect->Value) - 1].SetY1(0);
		rect[Convert::ToInt16(NumberRect->Value) - 1].SetX2(0);
		rect[Convert::ToInt16(NumberRect->Value) - 1].SetY2(0);
		Rect* temp = new Rect[10];
		for (int j = 0; j < Convert::ToInt16(NumberRect->Value) - 1; j++)
		{
			temp[j] = rect[j];
		}
		for (int j = Convert::ToInt16(NumberRect->Value) - 1; j < 9; j++)
		{
			temp[j] = rect[j + 1];
		}
		rect = temp;
		temp = NULL;
		i -= 1;
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::DelCur_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberCur->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circle[ic].SetX(0);
			circle[ic].SetY(0);
			circle[ic].Set_a(0);
			circle[ic].Set_b(0);
		}
		ic = 0;
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else if (Convert::ToInt16(NumberCur->Value) - 1 < ic)
	{
		circle[Convert::ToInt16(NumberCur->Value) - 1].SetX(0);
		circle[Convert::ToInt16(NumberCur->Value) - 1].SetY(0);
		circle[Convert::ToInt16(NumberCur->Value) - 1].Set_a(0);
		circle[Convert::ToInt16(NumberCur->Value) - 1].Set_b(0);
		Circle* temp = new Circle[10];
		for (int j = 0; j < Convert::ToInt16(NumberCur->Value) - 1; j++)
		{
			temp[j] = circle[j];
		}
		for (int j = Convert::ToInt16(NumberCur->Value) - 1; j < 9; j++)
		{
			temp[j] = circle[j + 1];
		}
		circle = temp;
		temp = NULL;
		ic -= 1;
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::createtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (il != 10)
	{
		int fault;
		int massx[31] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
		850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
		int x = rand() % 29 + 1;
		int massy[13] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
		int y = rand() % 11 + 1;
		srand(time(NULL));
		int x1, x2, y1, y2;
		fault = rand() % 26;
		if (rand() % 2 == 0)
			fault = -fault;
		x2 = massx[x] + fault;
		y2 = massy[y] + fault;
		x1 = massx[rand() % x] + fault;
		y1 = massy[rand() % y] + fault;
		int length = sqrt(abs(y2 - y1) * abs(y2 - y1) + abs(x2 - x1) * abs(x2 - x1));
		int angle = atan((float)abs(y2 - y1) / abs(x2 - x1)) * 180 / M_PI;
		
		if (rand() % 2 == 0)
		{
			line[il].SetY(y2);
			angle = -angle;
		}
		else
		{
			line[il].SetY(y1);
		}
		line[il].SetX(x1);
		line[il].SetLength(length);
		line[il].SetAngle(angle);
		line[il].Show(canvas);
		il += 1;
		
	}
}

System::Void Lab1::Objects::createCurcleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ic != 10)
	{
		bool flag = true;
		int fault;
		int massab[10] = { 25, 50, 75, 100, 125, 150, 175, 200, 225, 250 };
		int massx[30] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
		850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
		int massy[12] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
		int x1, y1, a1, b1, a, b, x, y;

		while (flag)
		{
			a = rand() % 10;
			b = rand() % 10;
			x = rand() % 30;
			y = rand() % 12;
			srand(time(NULL));
			fault = rand() % 26;
			if (rand() % 2 == 0)
				fault = -fault;
			x1 = massx[x] + fault;
			y1 = massy[y] + fault;
			a1 = massab[a] + fault / 2;
			b1 = massab[b] + fault / 2;
			if (!((x1 + a1 > 1533) || (x1 - a1 < 0) || (y1 + b1 > 640) || (y1 - b1 < 0)))
				flag = false;
		}
		circle[ic].SetX(x1);
		circle[ic].SetY(y1);
		circle[ic].Set_a(a1);
		circle[ic].Set_b(b1);
		circle[ic].Show(canvas);
		ic += 1;
	}
}

System::Void Lab1::Objects::LineMove_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (NumberLine->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < il; j++)
		{
			line[j].MoveTo(Convert::ToInt16(LineXoffset->Value), Convert::ToInt16(LIneYoffset->Value));
			line[j].Show(canvas);
		}
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
	}
	else
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		line[Convert::ToInt16(NumberLine->Value) - 1].MoveTo(Convert::ToInt16(LineXoffset->Value), Convert::ToInt16(LIneYoffset->Value));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::LineDel_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberLine->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < il; j++)
		{
			line[il].SetX(0);
			line[il].SetY(0);
			line[il].SetLength(0);
			line[il].SetAngle(0);
		}
		il = 0;
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
	}
	else if (Convert::ToInt16(NumberLine->Value) - 1 < il)
	{
		line[Convert::ToInt16(NumberLine->Value) - 1].SetX(0);
		line[Convert::ToInt16(NumberLine->Value) - 1].SetY(0);
		line[Convert::ToInt16(NumberLine->Value) - 1].SetLength(0);
		line[Convert::ToInt16(NumberLine->Value) - 1].SetAngle(0);
		Line* temp = new Line[10];
		for (int j = 0; j < Convert::ToInt16(NumberLine->Value) - 1; j++)
		{
			temp[j] = line[j];
		}
		for (int j = Convert::ToInt16(NumberLine->Value) - 1; j < 9; j++)
		{
			temp[j] = line[j + 1];
		}
		line = temp;
		temp = NULL;
		il -= 1;
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::TurnRect_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRect->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < i; j++)
		{
			rect[j].TurnOn90();
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		rect[Convert::ToInt16(NumberRect->Value) - 1].TurnOn90();
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::TurnLine_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberLine->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < il; j++)
		{
			line[j].TurnTo(Convert::ToInt16(AngleOffset->Value));
			line[j].Show(canvas);
		}
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
	}
	else
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		line[Convert::ToInt16(NumberLine->Value) - 1].TurnTo(Convert::ToInt16(AngleOffset->Value));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Lab1::Objects::TurnCir_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberCur->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circle[j].TurnTo90();
			circle[j].Show(canvas);
		}
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		circle[Convert::ToInt16(NumberCur->Value) - 1].TurnTo90();
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			circle[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}