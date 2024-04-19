#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Laba2::MenuForm form;
	Application::Run(% form);

}

Laba2::MenuForm::MenuForm(void)
{
	InitializeComponent();
}

System::Void Laba2::MenuForm::SimFig_Click(System::Object^ sender, System::EventArgs^ e)
{
	Objects^ f2 = gcnew Objects();
	f2->Show();
}

System::Void Laba2::MenuForm::ComFig_Click(System::Object^ sender, System::EventArgs^ e)
{
	Objects2^ f2 = gcnew Objects2();
	f2->Show();
}

Laba2::Objects::Objects(void)
{
	InitializeComponent();
	canvas = pictureBox1->CreateGraphics();
	canvas->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

Laba2::Objects2::Objects2(void)
{
	InitializeComponent();
	Canvas = pictureBox2->CreateGraphics();
	Canvas->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

System::Void Laba2::Objects::rectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
	rect = (Rect*)realloc(rect, nr * sizeof(Rect));
	rect[i] = Rect(x1, y1, x2, y2);
	rect[i].Show(canvas);
	i += 1;
	nr += 1;
}

System::Void Laba2::Objects::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
			ellips[j].Show(canvas);
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
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects::CurMove_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberCur->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			ellips[j].MoveTo(Convert::ToInt16(CXoffcet->Value), Convert::ToInt16(CYoffset->Value));
			ellips[j].Show(canvas);
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
		ellips[Convert::ToInt16(NumberCur->Value) - 1].MoveTo(Convert::ToInt16(CXoffcet->Value), Convert::ToInt16(CYoffset->Value));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects::buttonDel_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberRect->Value == 0) && (i != 0))
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		rect[0].SetX1(0);
		rect[0].SetY1(0);
		rect[0].SetX2(0);
		rect[0].SetY2(0);
		i = 0;
		rect = (Rect*)realloc(rect, sizeof(Ellips));
		nr = 1;
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else if ((Convert::ToInt16(NumberRect->Value) - 1 < i) && (i != 0))
	{
		if (Convert::ToInt16(NumberRect->Value) == i)
		{
			nr -= 1;
			rect = (Rect*)realloc(rect, nr * sizeof(Rect));
			rect[Convert::ToInt16(NumberRect->Value) - 1].SetX1(0);
			rect[Convert::ToInt16(NumberRect->Value) - 1].SetX2(0);
			rect[Convert::ToInt16(NumberRect->Value) - 1].SetY1(0);
			rect[Convert::ToInt16(NumberRect->Value) - 1].SetY2(0);
			i -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberRect->Value) - 1; j < i - 1; j++)
			{
				rect[j].SetX1(rect[j + 1].GetX1());
				rect[j].SetX2(rect[j + 1].GetX2());
				rect[j].SetY1(rect[j + 1].GetY1());
				rect[j].SetY2(rect[j + 1].GetY2());
			}
			nr -= 1;
			i -= 1;
			rect = (Rect*)realloc(rect, nr * sizeof(Rect));
		}

		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects::DelCur_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberCur->Value == 0) && (ic != 0))
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		ellips[0].SetX(0);
		ellips[0].SetY(0);
		ellips[0].Set_a(0);
		ellips[0].Set_b(0);
		ic = 0;
		ellips = (Ellips*)realloc(ellips, sizeof(Ellips));
		nc = 1;
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
	else if ((Convert::ToInt16(NumberCur->Value) - 1 < ic) && (ic != 0))
	{

		if (Convert::ToInt16(NumberCur->Value) == ic)
		{
			nc -= 1;
			ellips = (Ellips*)realloc(ellips, nc * sizeof(Ellips));
			ellips[Convert::ToInt16(NumberCur->Value) - 1].SetX(0);
			ellips[Convert::ToInt16(NumberCur->Value) - 1].SetY(0);
			ellips[Convert::ToInt16(NumberCur->Value) - 1].Set_a(0);
			ellips[Convert::ToInt16(NumberCur->Value) - 1].Set_b(0);
			ic -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberCur->Value) - 1; j < ic - 1; j++)
			{
				ellips[j].SetX(ellips[j + 1].GetX());
				ellips[j].SetY(ellips[j + 1].GetY());
				ellips[j].Set_a(ellips[j + 1].Get_a());
				ellips[j].Set_b(ellips[j + 1].Get_b());
			}
			nc -= 1;
			ic -= 1;
			ellips = (Ellips*)realloc(ellips, nc * sizeof(Ellips));
		}
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
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

System::Void Laba2::Objects::createtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	float length = rand() % 370 + 30;
	float angle = rand() % 360 + 1;
	int x1 = rand() % 1530 + 1;
	int y1 = rand() % 641 + 1;
	line = (Line*)realloc(line, nl * sizeof(Line));
	nl += 1;
	line[il] = Line(x1, y1, length, angle);
	line[il].Show(canvas);
	il += 1;
	
}

System::Void Laba2::Objects::createCurcleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
	ellips = (Ellips*)realloc(ellips, nc * sizeof(Ellips));
	nc += 1;
	a = nc * sizeof(Ellips);
	ellips[ic] = Ellips(x1, y1, a1, b1);
	ellips[ic].Show(canvas);
	ic += 1;
}

System::Void Laba2::Objects::LineMove_Click(System::Object^ sender, System::EventArgs^ e)
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
			ellips[j].Show(canvas);
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
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects::LineDel_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberLine->Value == 0) && (il!= 0))
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		line[0].SetX(0);
		line[0].SetY(0);
		line[0].SetLength(0);
		line[0].SetAngle(0);
		il = 0;
		line = (Line*)realloc(line, sizeof(Line));
		nl = 1;
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
		}
	}
	else if ((Convert::ToInt16(NumberLine->Value) - 1 < il) && (il != 0))
	{
		if (Convert::ToInt16(NumberLine->Value) == il)
		{
			nl -= 1;
			line = (Line*)realloc(line, nl * sizeof(Line));
			line[Convert::ToInt16(NumberLine->Value) - 1].SetX(0);
			line[Convert::ToInt16(NumberLine->Value) - 1].SetY(0);
			line[Convert::ToInt16(NumberLine->Value) - 1].SetLength(0);
			line[Convert::ToInt16(NumberLine->Value) - 1].SetAngle(0);
			il -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberLine->Value) - 1; j < il - 1; j++)
			{
				line[j].SetX(line[j + 1].GetX());
				line[j].SetY(line[j + 1].GetY());
				line[j].SetLength(line[j + 1].GetLength());
				line[j].SetAngle(line[j + 1].GetAngle());
			}
			nl -= 1;
			il -= 1;
			line = (Line*)realloc(line, nl * sizeof(Line));
		}
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
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

System::Void Laba2::Objects::TurnRect_Click(System::Object^ sender, System::EventArgs^ e)
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
			ellips[j].Show(canvas);
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
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects::TurnLine_Click(System::Object^ sender, System::EventArgs^ e)
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
			ellips[j].Show(canvas);
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
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects::TurnCir_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberCur->Value == 0)
	{
		canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			ellips[j].TurnTo90();
			ellips[j].Show(canvas);
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
		ellips[Convert::ToInt16(NumberCur->Value) - 1].TurnTo90();
		for (int j = 0; j < i; j++)
		{
			rect[j].Show(canvas);
		}
		for (int j = 0; j < ic; j++)
		{
			ellips[j].Show(canvas);
		}
		for (int j = 0; j < il; j++)
		{
			line[j].Show(canvas);
		}
	}
}

System::Void Laba2::Objects2::crateRandomRing_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool flag = true;
	srand(time(NULL));
	/*int fault;
	int massRr[10] = { 25, 50, 75, 100, 125, 150, 175, 200, 225, 250 };
	int massx[30] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
	850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
	int massy[12] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };*/
	int x1, y1, R1, r1, R, r, x, y;
	while (flag)
	{
		/*R = rand() % 9 + 1;
		r = rand() % 10;
		x = rand() % 30;
		y = rand() % 12;
		srand(time(NULL));
		fault = rand() % 26;
		if (rand() % 2 == 0)
			fault = -fault;*/
		/*x1 = massx[x] + fault;
		y1 = massy[y] + fault;
		R1 = massRr[R] + fault / 2;
		r1 = massRr[r] + fault / 2;*/
		R1 = rand() % 200;
		x1 = rand() % (1533 - R1) + R1;
		y1 = rand() % (700 - R1) + R1;
		int delta = R1 - R1 / 4;
		r1 = rand() % (R1 - delta) + delta;
		if (!((x1 + R1 > 1533) || (x1 - R1 < 0) || (y1 + R1 > 640) || (y1 - R1 < 0)))
			flag = false;
	}
	rings = (Ring*)realloc(rings, nring * sizeof(Ring));
	nring += 1;
	if (R1 > r1)
		rings[iring] = Ring(x1, y1, R1, r1);
	else
		rings[iring] = Ring(x1, y1, r1, R1);
	rings[iring].Show(Canvas);
	iring += 1;
	
	
}

System::Void Laba2::Objects2::createRandomTriangle_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	/*int fault;
	int newx, newy;
	bool flag = true;
	srand(time(NULL));
	int massx[31] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
	850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
	int x = rand() % 29 + 1;
	int massy[13] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
	int y = rand() % 11 + 1;
	while (flag)
	{
		int newx = rand() % 29 + 1;
		int newy = rand() % 11 + 1;
		if (x != newx || y != newy)
			flag = false;
	}
	int x1, x2, y1, y2, x3, y3;
	fault = rand() % 26;
	if (rand() % 2 == 0)
		fault = -fault;
	x2 = massx[newx] + fault;
	y2 = massy[newy] + fault;
	x2 = massx[x] + fault;
	y2 = massy[y] + fault;
	x1 = massx[rand() % x] + fault;
	y1 = massy[rand() % y] + fault;
	float length1 = (float)sqrt(abs(y2 - y1) * abs(y2 - y1) + abs(x2 - x1) * abs(x2 - x1));
	float angle1 = (float)atan(abs(y2 - y1) / abs(x2 - x1)) * 180 / M_PI;
	float length2 = (float)sqrt(abs(y3 - y1) * abs(y3 - y1) + abs(x3 - x1) * abs(x3 - x1));
	float angle2 = (float)atan(abs(y3 - y1) / abs(x3 - x1)) * 180 / M_PI;
	int Y = 0, Y2 = 0;
	triangles = (Triangle*)realloc(triangles, ntr * sizeof(Triangle));
	ntr += 1;
	if (rand() % 2 == 0)
	{
		Y = y2;
		angle1 = -angle1;
	}
	else
	{
		Y = y1;
	}
	if (rand() % 2 == 0)
	{
		Y2 = y3;
		angle2 = -angle2;
	}
	else
	{
		Y2 = y1;
	}*/
	int x1, x2, y1, y2, x3, y3;
	float length1, angle1, length2, angle2;
	length1 = rand() % 370 + 30;
	angle1 = rand() % 360 + 1;
	x1 = rand() % 1530 + 1;
	y1 = rand() % 641 + 1;
	length2 = rand() % 370 + 30;
	angle2 = rand() % 360 + 1;
	triangles = (Triangle*)realloc(triangles, ntr * sizeof(Triangle));
	ntr += 1;
	triangles[itr] = Triangle(x1, y1, length1, angle1, length2, angle2);
	triangles[itr].Show(Canvas);
	itr += 1;
}

System::Void Laba2::Objects2::MoveRing_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRing->Value == 0)
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iring; j++)
		{
			rings[j].MoveTo(Convert::ToInt16(RingoffsetX->Value), Convert::ToInt16(RingoffsetY->Value));
			rings[j].Show(Canvas);
		}
		
	}
	else
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		rings[Convert::ToInt16(NumberRing->Value) - 1].MoveTo(Convert::ToInt16(RingoffsetX->Value), Convert::ToInt16(RingoffsetY->Value));
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
		
		
	}
}

System::Void Laba2::Objects2::DelRing_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberRing->Value == 0) && (iring!=0))
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		rings[0].SetX(0);
		rings[0].SetY(0);
		rings[0].Set_R(0);
		rings[0].Set_r(0);
		iring = 0;
		rings = (Ring*)realloc(rings, sizeof(Ring));
		nring = 1;
		for (int j = 0; j < itr; j++)
		{
			triangles[j].Show(Canvas);
		}
	}
	else if ((Convert::ToInt16(NumberRing->Value) - 1 < iring) && (iring != 0))
	{

		if (Convert::ToInt16(NumberRing->Value) == iring)
		{
			nring -= 1;
			rings = (Ring*)realloc(rings, nring * sizeof(Ring));
			rings[Convert::ToInt16(NumberRing->Value) - 1].SetX(0);
			rings[Convert::ToInt16(NumberRing->Value) - 1].SetY(0);
			rings[Convert::ToInt16(NumberRing->Value) - 1].Set_R(0);
			rings[Convert::ToInt16(NumberRing->Value) - 1].Set_r(0);
			iring -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberRing->Value) - 1; j < iring - 1; j++)
			{
				rings[j].SetX(rings[j + 1].GetX());
				rings[j].SetY(rings[j + 1].GetY());
				rings[j].Set_R(rings[j + 1].Get_R());
				rings[j].Set_r(rings[j + 1].Get_r());
			}
			nring-= 1;
			iring -= 1;
			rings = (Ring*)realloc(rings, nring * sizeof(Ring));
		}
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
		for (int j = 0; j < itr; j++)
		{
			triangles[j].Show(Canvas);
		}
	}
}

System::Void Laba2::Objects2::ResizeRing_Click(System::Object^ sender, System::EventArgs^ e)
{
	int R1, r1;
	if (NumberRing->Value == 0)
	{
		srand(time(NULL));
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iring; j++)
		{
			R1 = rand() % 150 + 50;
			int delta = R1 - R1 / 3;
			r1 = rand() % (R1 - delta) + delta;
			rings[j].Resize(R1,r1);
			rings[j].Show(Canvas);
		}
		
	}
	else
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		R1 = rand() % 150 + 50;
		int delta = R1 - R1 / 3;
		r1 = rand() % (R1 - delta) + delta;
		rings[Convert::ToInt16(NumberRing->Value) - 1].Resize(R1,r1);
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
	}

}

System::Void Laba2::Objects2::TriangleMove_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberTriangle->Value == 0)
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < itr; j++)
		{
			triangles[j].MoveTo(Convert::ToInt16(TriangleXoffset->Value), Convert::ToInt16(TriangleYoffset->Value));
			triangles[j].Show(Canvas);
		}
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
	}
	else
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		triangles[Convert::ToInt16(NumberTriangle->Value) - 1].MoveTo(Convert::ToInt16(TriangleXoffset->Value), Convert::ToInt16(TriangleYoffset->Value));
		for (int j = 0; j < itr; j++)
		{
			triangles[j].Show(Canvas);
		}
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
	}
}

System::Void Laba2::Objects2::TriangleDel_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberTriangle->Value == 0) && (itr != 0))
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		triangles[0].SetX(0);
		triangles[0].SetY(0);
		triangles[0].SetLength1(0);
		triangles[0].SetAngle1(0);
		triangles[0].SetLength2(0);
		triangles[0].SetAngle2(0);
		itr = 0;
		triangles = (Triangle*)realloc(triangles, sizeof(Triangle));
		ntr = 1;
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
	}
	else if ((Convert::ToInt16(NumberTriangle->Value) - 1 < itr) && (itr != 0))
	{

		if (Convert::ToInt16(NumberTriangle->Value) == itr)
		{
			ntr -= 1;
			triangles = (Triangle*)realloc(triangles, ntr * sizeof(Triangle));
			triangles[Convert::ToInt16(NumberTriangle->Value) - 1].SetX(0);
			triangles[Convert::ToInt16(NumberTriangle->Value) - 1].SetY(0);
			triangles[Convert::ToInt16(NumberTriangle->Value) - 1].SetLength1(0);
			triangles[Convert::ToInt16(NumberTriangle->Value) - 1].SetAngle1(0);
			triangles[Convert::ToInt16(NumberTriangle->Value) - 1].SetLength2(0);
			triangles[Convert::ToInt16(NumberTriangle->Value) - 1].SetAngle2(0);
			itr -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberTriangle->Value) - 1; j < itr - 1; j++)
			{
				triangles[j] = triangles[j + 1];
			}
			ntr -= 1;
			itr -= 1;
			triangles = (Triangle*)realloc(triangles, ntr * sizeof(Triangle));
		}
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
		for (int j = 0; j < itr; j++)
		{
			triangles[j].Show(Canvas);
		}
	}
}

System::Void Laba2::Objects2::TurnTriangle_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberTriangle->Value == 0)
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < itr; j++)
		{
			triangles[j].TurnTo(Convert::ToInt16(TrAngleOffset->Value));
			triangles[j].Show(Canvas);
		}
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
	}
	else
	{
		Canvas->Clear(Color::FromArgb(145, 225, 86));
		line[Convert::ToInt16(NumberTriangle->Value) - 1].TurnTo(Convert::ToInt16(TrAngleOffset->Value));
		for (int j = 0; j < iring; j++)
		{
			rings[j].Show(Canvas);
		}
		for (int j = 0; j < itr; j++)
		{
			triangles[j].Show(Canvas);
		}
	}
}
