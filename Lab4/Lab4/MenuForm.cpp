#include "MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab4::MenuForm form;
	Application::Run(% form);

}

Lab4::MenuForm::MenuForm(void)
{
	InitializeComponent();
}

Lab4::Circles::Circles(void)
{
	InitializeComponent();
	canvas1 = pictureBox1->CreateGraphics();
	canvas1->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

Lab4::Quadrangles::Quadrangles(void)
{
	InitializeComponent();
	canvas3 = pictureBox3->CreateGraphics();
	canvas3->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

Lab4::Rectangles::Rectangles(void)
{
	InitializeComponent();
	canvas4 = pictureBox4->CreateGraphics();
	canvas4->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

Lab4::Rhombs::Rhombs(void)
{
	InitializeComponent();
	canvas5 = pictureBox5->CreateGraphics();
	canvas5->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

Lab4::Ellipses::Ellipses(void)
{
	InitializeComponent();
	canvas2 = pictureBox2->CreateGraphics();
	canvas2->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

Lab4::Trapezoids::Trapezoids(void)
{
	InitializeComponent();
	canvas6 = pictureBox6->CreateGraphics();
	canvas6->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
}

System::Void Lab4::Circles::createRandomCircleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));

	/*bool flag = true;
	int fault;
	int massr[10] = { 25, 50, 75, 100, 125, 150, 175, 200, 225, 250 };
	int massx[30] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
	850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
	int massy[12] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
	int x1, y1, r1, r, x, y;
	while (flag)
	{
		r = rand() % 10;
		x = rand() % 30;
		y = rand() % 12;
		srand(time(NULL));
		fault = rand() % 26;
		if (rand() % 2 == 0)
			fault = -fault;
		x1 = massx[x] + fault;
		y1 = massy[y] + fault;
		r1 = massr[r] + fault / 2;
		if (!((x1 + r1 > 1533) || (x1 - r1 < 0) || (y1 + r1 > 640) || (y1 - r1 < 0)))
			flag = false;
	}*/
	int y1 = rand() % 639 + 1;
	int x1 = rand() % 1500 + 1;
	int r1 = rand() % 200 + 1;
	y1 = rand() % 639 + 1;
	while (x1 + r1 > 1533)
		x1 -= 10;
	while (x1 - r1 < 0)
		x1 += 10;
	while (y1 + r1 > 641)
		y1 -= 10;
	while (y1 - r1 < 0)
		y1 += 10;
	//circles = (TCircle*)realloc(circles, nc * sizeof(TCircle));
	circles[ic] = TCircle(x1, y1, r1);
	/*TCircle mac = circles[ic];
	mac.Show(canvas1);*/
	circles[ic].Show(canvas1);
	ic += 1;
	//nc += 1;
}

System::Void Lab4::Ellipses::createRandomEllipseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));
	/*bool flag = true;
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
	}*/
	int y1 = rand() % 639 + 1;
	int x1 = rand() % 1500 + 1;
	int a1 = rand() % 200 + 40;
	int b1 = rand() % 200 + 40;
	y1 = rand() % 639 + 1;
	while (x1 + a1 > 1533)
		x1 -= 10;
	while (x1 - a1 < 0)
		x1 += 10;
	while (y1 + b1 > 641)
		y1 -= 10;
	while (y1 - b1 < 0)
		y1 += 10;
	//ellipses = (TEllipse*)realloc(ellipses, ne * sizeof(TEllipse));
	//ne += 1;
	ellipses[ie] = TEllipse(x1, y1, a1, b1);
	ellipses[ie].Show(canvas2);
	/*TEllipse mac = ellipses[ie];
	mac.Show(canvas2);*/
	ie += 1;
}

System::Void Lab4::Quadrangles::createRandomQuadrangeleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(NULL));

	/*int y1 = rand() % 639 + 1;
	int x1 = rand() % 1500 + 1;
	int length = rand() % 100 + 1;
	int width = rand() % 50 + 1;
	int x2 = x1 + length;
	int y2;
	if (rand() % 2 == 0)
		y2 = y1 - width;
	else
		y2 = y1 + width;
	length = rand() % 100 + 1;
	width = rand() % 50 + 1;
	int y3 = y2 + width;
	int x3;
	if (rand() % 2 == 0)
		x3 = x2 - length;
	else
		x3 = y2 + length;
	length = rand() % 100 + 1;
	width = rand() % 50 + 1;
	int x4 = x3 - length;
	int y4;
	if (rand() % 2 == 0)
		y4 = y3 - width;
	else
		y4 = y3 + width;*/
	int x1;
	int t = rand() % 4;
	if (t == 0)
		x1 = rand() % 381 + 1;
	else if (t == 1)
		x1 = rand() % 381 + 382;
	else if (t == 2)
		x1 = rand() % 381 + 765;
	else if (t == 3)
		x1 = rand() % 381 + 1146;

	int y1 = rand() % 639 + 1;
	int x2 = rand() % 300 + x1;
	int delta = rand() % 100 + 1;
	int y2 = y1;
	if (rand() % 2 == 0)
		y2 += delta;
	else
		y2 -= delta;
	delta = rand() % 100 + 1;
	int x3 = x2;
	if (rand() % 2 == 0)
		x3 += delta;
	else
		x3 -= delta;
	delta = rand() % 100 + 1;
	int y3 = rand() % 300 + y2;
	int x4 = x1;
	if (rand() % 2 == 0)
		x4 += delta;
	else
		x4 -= delta;
	delta = rand() % 100 + 1;
	int y4 = y3;
	if (rand() % 2 == 0)
		y3 += delta;
	else
		y3 -= delta;

	//quadrangles = (TQuadrangle*)realloc(quadrangles, nq * sizeof(TQuadrangle));
	//nq += 1;
	quadrangles[iq] = TQuadrangle(x1, y1, x2, y2, x3, y3, x4, y4);
	quadrangles[iq].Show(canvas3);
	/*TQuadrangle mac = quadrangles[iq];
	mac.Show(canvas3);*/
	iq += 1;
}

System::Void Lab4::Rectangles::createRandomRectangleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
	//rectangles = (TRectangle*)realloc(rectangles, nr * sizeof(TRectangle));
	rectangles[ir] = TRectangle(x1, y1, x2, y2);
	rectangles[ir].Show(canvas4);
	/*TRectangle mac = rectangles[ir];
	mac.Show(canvas4);*/
	ir += 1;
	//nr += 1;
}

System::Void Lab4::Rhombs::createRandomRhombToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	int fault;
	int massx[30] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
	850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
	int x = rand() % 29 + 1;
	int massy[12] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
	int y = rand() % 11 + 1;
	srand(time(NULL));
	int d1, d2, x1, y1;
	fault = rand() % 26;
	if (rand() % 2 == 0)
		fault = -fault;
	x1 = massx[x] + fault;
	y1 = massy[y] + fault;
	d1 = rand() % 200 + 20;
	d2 = rand() % 200 + 20;
	//rhombs = (TRhomb*)realloc(rhombs, nrh * sizeof(TRhomb));
	rhombs[irh] = TRhomb(d1, d2, x1, y1);
	rhombs[irh].Show(canvas5);
	/*TRhomb mac = rhombs[irh];
	mac.Show(canvas5);*/
	irh += 1;
	//nrh += 1;
}

System::Void Lab4::Trapezoids::createRandomTrapezoidToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	int fault;
	int massx[30] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600, 650, 700, 750, 800,
	850, 900, 950, 1000, 1050, 1100,1150 ,1200, 1250, 1300, 1350, 1400, 1450, 1500 };
	int x = rand() % 29 + 1;
	int massy[12] = { 50, 100, 150, 200 ,250 ,300 ,350, 400 ,450 , 500 ,550, 600 };
	int y = rand() % 11 + 1;
	srand(time(NULL));
	int x1, x2, y1, y2, x3, x4;
	fault = rand() % 26;
	if (rand() % 2 == 0)
		fault = -fault;
	x3 = massx[x] + fault;
	y2 = massy[y] + fault;
	x1 = massx[rand() % x] + fault;
	y1 = massy[rand() % y] + fault;
	x2 = rand() % 400 + x1;
	x4 = rand() % x3;
	//trapezoids = (TTrapezoid*)realloc(trapezoids, ntr * sizeof(TTrapezoid));
	trapezoids[itr] = TTrapezoid(x1, x2, x3, x4, y1, y2);
	trapezoids[itr].Show(canvas6);
	/*TTrapezoid mac = trapezoids[itr];
	mac.Show(canvas6);*/
	itr += 1;
	//ntr += 1;
}

System::Void Lab4::MenuForm::CirBut_Click(System::Object^ sender, System::EventArgs^ e)
{
	Circles^ f2 = gcnew Circles();
	f2->Show();
}

System::Void Lab4::MenuForm::ElBut_Click(System::Object^ sender, System::EventArgs^ e)
{
	Ellipses^ f2 = gcnew Ellipses();
	f2->Show();
}

System::Void Lab4::MenuForm::QuaBut_Click(System::Object^ sender, System::EventArgs^ e)
{
	Quadrangles^ f2 = gcnew Quadrangles();
	f2->Show();
}

System::Void Lab4::MenuForm::RecBut_Click(System::Object^ sender, System::EventArgs^ e)
{
	Rectangles^ f2 = gcnew Rectangles();
	f2->Show();
}

System::Void Lab4::MenuForm::RhBut_Click(System::Object^ sender, System::EventArgs^ e)
{
	Rhombs^ f2 = gcnew Rhombs();
	f2->Show();
}

System::Void Lab4::MenuForm::TrapBut_Click(System::Object^ sender, System::EventArgs^ e)
{
	Trapezoids^ f2 = gcnew Trapezoids();
	f2->Show();
}

System::Void Lab4::Circles::CirMove_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberCir->Value == 0)
	{
		canvas1->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circles[j].MoveTo(Convert::ToInt16(CXoffcet->Value), Convert::ToInt16(CYoffset->Value), canvas1);
		}
	}
	else
	{
		canvas1->Clear(Color::FromArgb(145, 225, 86));
		circles[Convert::ToInt16(NumberCir->Value) - 1].MoveTo(Convert::ToInt16(CXoffcet->Value), Convert::ToInt16(CYoffset->Value), canvas1);
		for (int j = 0; j < ic; j++)
		{
			circles[j].Show(canvas1);
		}
	}
}

System::Void Lab4::Circles::DelCir_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberCir->Value == 0) && (ic != 0))
	{
		canvas1->Clear(Color::FromArgb(145, 225, 86));
		circles[0].SetX(0);
		circles[0].SetY(0);
		circles[0].Set_R(0);
		ic = 0;
	}
	else if ((Convert::ToInt16(NumberCir->Value) - 1 < ic) && (ic != 0))
	{

		if (Convert::ToInt16(NumberCir->Value) == ic)
		{
			circles[Convert::ToInt16(NumberCir->Value) - 1].SetX(0);
			circles[Convert::ToInt16(NumberCir->Value) - 1].SetY(0);
			circles[Convert::ToInt16(NumberCir->Value) - 1].Set_R(0);
			ic -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberCir->Value) - 1; j < ic - 1; j++)
			{
				circles[j] = circles[j + 1];
			}
			ic -= 1;
		}
		canvas1->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			circles[j].Show(canvas1);
		}
	}
}

System::Void Lab4::Circles::ResCir_Click(System::Object^ sender, System::EventArgs^ e)
{
	int R1;
	srand(time(NULL));
	if (NumberCir->Value == 0)
	{
		canvas1->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ic; j++)
		{
			R1 = rand() % 250 + 50;
			circles[j].Resize(R1);
			circles[j].Show(canvas1);
		}

	}
	else
	{
		canvas1->Clear(Color::FromArgb(145, 225, 86));
		R1 = rand() % 250 + 50;
		circles[Convert::ToInt16(NumberCir->Value) - 1].Resize(R1);
		for (int j = 0; j < ic; j++)
		{
			circles[j].Show(canvas1);
		}
	}
}

System::Void Lab4::Ellipses::EllMove_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberEll->Value == 0)
	{
		canvas2->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ie; j++)
		{
			ellipses[j].MoveTo(Convert::ToInt16(EllXoffcet->Value), Convert::ToInt16(EllYoffset->Value), canvas2);
			ellipses[j].Show(canvas2);
		}
	}
	else
	{
		canvas2->Clear(Color::FromArgb(145, 225, 86));
		ellipses[Convert::ToInt16(NumberEll->Value) - 1].MoveTo(Convert::ToInt16(EllXoffcet->Value), Convert::ToInt16(EllYoffset->Value), canvas2);
		for (int j = 0; j < ie; j++)
		{
			ellipses[j].Show(canvas2);
		}
	}
}

System::Void Lab4::Ellipses::DelEll_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberEll->Value == 0) && (ie != 0))
	{
		canvas2->Clear(Color::FromArgb(145, 225, 86));
		ellipses[0].SetX(0);
		ellipses[0].SetY(0);
		ellipses[0].Set_R(0);
		ellipses[0].Set_r(0);
		ie = 0;
	}
	else if ((Convert::ToInt16(NumberEll->Value) - 1 < ie) && (ie != 0))
	{

		if (Convert::ToInt16(NumberEll->Value) == ie)
		{
			ellipses[Convert::ToInt16(NumberEll->Value) - 1].SetX(0);
			ellipses[Convert::ToInt16(NumberEll->Value) - 1].SetY(0);
			ellipses[Convert::ToInt16(NumberEll->Value) - 1].Set_R(0);
			ellipses[Convert::ToInt16(NumberEll->Value) - 1].Set_r(0);
			ie -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberEll->Value) - 1; j < ie - 1; j++)
			{
				ellipses[j] = ellipses[j + 1];
			}
			ie -= 1;
		}
		canvas2->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ie; j++)
		{
			ellipses[j].Show(canvas2);
		}
	}
}

System::Void Lab4::Ellipses::TurnEll_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberEll->Value == 0)
	{
		canvas2->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ie; j++)
		{
			ellipses[j].TurnTo90();
			ellipses[j].Show(canvas2);
		}
	}
	else
	{
		canvas2->Clear(Color::FromArgb(145, 225, 86));
		ellipses[Convert::ToInt16(NumberEll->Value) - 1].TurnTo90();
		for (int j = 0; j < ie; j++)
		{
			ellipses[j].Show(canvas2);
		}
	}
}

System::Void Lab4::Quadrangles::QuadrMove_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberQ->Value == 0)
	{
		canvas3->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iq; j++)
		{
			quadrangles[j].MoveTo(Convert::ToInt16(QXoffcet->Value), Convert::ToInt16(QYoffset->Value));
			quadrangles[j].Show(canvas3);
		}
	}
	else
	{
		canvas3->Clear(Color::FromArgb(145, 225, 86));
		quadrangles[Convert::ToInt16(NumberQ->Value) - 1].MoveTo(Convert::ToInt16(QXoffcet->Value), Convert::ToInt16(QYoffset->Value));
		for (int j = 0; j < iq; j++)
		{
			quadrangles[j].Show(canvas3);
		}
	}
}

System::Void Lab4::Quadrangles::DelQuadr_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberQ->Value == 0) && (iq != 0))
	{
		canvas3->Clear(Color::FromArgb(145, 225, 86));
		quadrangles[0].SetX(0);
		quadrangles[0].SetY(0);
		quadrangles[0].Set_X2(0);
		quadrangles[0].Set_Y2(0);
		quadrangles[0].Set_X3(0);
		quadrangles[0].Set_Y3(0);
		quadrangles[0].Set_X4(0);
		quadrangles[0].Set_Y4(0);
		iq = 0;
	}
	else if ((Convert::ToInt16(NumberQ->Value) - 1 < iq) && (iq != 0))
	{

		if (Convert::ToInt16(NumberQ->Value) == iq)
		{
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].SetX(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].SetY(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Set_X2(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Set_Y2(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Set_X3(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Set_Y3(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Set_X4(0);
			quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Set_Y4(0);
			iq -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberQ->Value) - 1; j < iq - 1; j++)
			{
				quadrangles[j] = quadrangles[j + 1];
			}
			iq -= 1;
		}
		canvas3->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iq; j++)
		{
			quadrangles[j].Show(canvas3);
		}
	}
}

System::Void Lab4::Quadrangles::ResQuadr_Click(System::Object^ sender, System::EventArgs^ e)
{
	int x1, y1;
	srand(time(NULL));
	if (NumberQ->Value == 0)
	{
		canvas3->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < iq; j++)
		{
			x1 = rand() % 20 + 1;
			y1 = rand() % 20 + 1;
			if (rand() % 2 == 0)
				x1 = -x1;
			if (rand() % 2 == 1)
				y1 = -y1;
			quadrangles[j].Resize(x1, y1);
			quadrangles[j].Show(canvas3);
		}

	}
	else
	{
		canvas3->Clear(Color::FromArgb(145, 225, 86));
		x1 = rand() % 20 + 1;
		y1 = rand() % 20 + 1;
		if (rand() % 2 == 0)
			x1 = -x1;
		if (rand() % 2 == 1)
			y1 = -y1;
		quadrangles[Convert::ToInt16(NumberQ->Value) - 1].Resize(x1, y1);
		for (int j = 0; j < iq; j++)
		{
			quadrangles[j].Show(canvas3);
		}
	}
}

System::Void Lab4::Rectangles::MoveRec_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRect->Value == 0)
	{
		canvas4->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ir; j++)
		{
			rectangles[j].MoveTo(Convert::ToInt16(RecXoffset->Value), Convert::ToInt16(RecYoffset->Value));
			rectangles[j].Show(canvas4);
		}
	}
	else
	{
		canvas4->Clear(Color::FromArgb(145, 225, 86));
		rectangles[Convert::ToInt16(NumberRect->Value) - 1].MoveTo(Convert::ToInt16(RecXoffset->Value), Convert::ToInt16(RecYoffset->Value));
		for (int j = 0; j < ir; j++)
		{
			rectangles[j].Show(canvas4);
		}
	}
}

System::Void Lab4::Rectangles::DelRect_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberRect->Value == 0) && (ir != 0))
	{
		canvas4->Clear(Color::FromArgb(145, 225, 86));
		rectangles[0].SetX(0);
		rectangles[0].SetY(0);
		rectangles[0].Set_X2(0);
		rectangles[0].Set_Y2(0);
		rectangles[0].Set_X3(0);
		rectangles[0].Set_Y3(0);
		rectangles[0].Set_X4(0);
		rectangles[0].Set_Y4(0);
		ir = 0;
	}
	else if ((Convert::ToInt16(NumberRect->Value) - 1 < ir) && (ir != 0))
	{

		if (Convert::ToInt16(NumberRect->Value) == ir)
		{
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].SetX(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].SetY(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].Set_X2(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].Set_Y2(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].Set_X3(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].Set_Y3(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].Set_X4(0);
			rectangles[Convert::ToInt16(NumberRect->Value) - 1].Set_Y4(0);
			ir -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberRect->Value) - 1; j < ir - 1; j++)
			{
				rectangles[j] = rectangles[j + 1];
			}
			ir -= 1;
		}
		canvas4->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ir; j++)
		{
			rectangles[j].Show(canvas4);
		}
	}
}

System::Void Lab4::Rectangles::TurnRect_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRect->Value == 0)
	{
		canvas4->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < ir; j++)
		{
			rectangles[j].TurnOn90();
			rectangles[j].Show(canvas4);
		}

	}
	else
	{
		canvas4->Clear(Color::FromArgb(145, 225, 86));
		rectangles[Convert::ToInt16(NumberRect->Value) - 1].TurnOn90();
		for (int j = 0; j < ir; j++)
		{
			rectangles[j].Show(canvas4);
		}
	}
}

System::Void Lab4::Rhombs::MoveRhomb_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRhomb->Value == 0)
	{
		canvas5->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < irh; j++)
		{
			rhombs[j].MoveTo(Convert::ToInt16(RhXoffset->Value), Convert::ToInt16(RhYoffset->Value));
			rhombs[j].Show(canvas5);
		}
	}
	else
	{
		canvas5->Clear(Color::FromArgb(145, 225, 86));
		rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].MoveTo(Convert::ToInt16(RhXoffset->Value), Convert::ToInt16(RhYoffset->Value));
		for (int j = 0; j < irh; j++)
		{
			rhombs[j].Show(canvas5);
		}
	}
}

System::Void Lab4::Rhombs::DelRhomb_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberRhomb->Value == 0) && (irh != 0))
	{
		canvas5->Clear(Color::FromArgb(145, 225, 86));
		rhombs[0].SetX(0);
		rhombs[0].SetY(0);
		rhombs[0].Set_X2(0);
		rhombs[0].Set_Y2(0);
		rhombs[0].Set_X3(0);
		rhombs[0].Set_Y3(0);
		rhombs[0].Set_X4(0);
		rhombs[0].Set_Y4(0);
		irh = 0;
	}
	else if ((Convert::ToInt16(NumberRhomb->Value) - 1 < irh) && (irh != 0))
	{

		if (Convert::ToInt16(NumberRhomb->Value) == irh)
		{
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].SetX(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].SetY(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].Set_X2(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].Set_Y2(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].Set_X3(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].Set_Y3(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].Set_X4(0);
			rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].Set_Y4(0);
			irh -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberRhomb->Value) - 1; j < irh - 1; j++)
			{
				rhombs[j] = rhombs[j + 1];
			}
			irh -= 1;
		}
		canvas5->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < irh; j++)
		{
			rhombs[j].Show(canvas5);
		}
	}
}

System::Void Lab4::Rhombs::TurnRhomb_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberRhomb->Value == 0)
	{
		canvas5->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < irh; j++)
		{
			rhombs[j].TurnOn90();
			rhombs[j].Show(canvas5);
		}

	}
	else
	{
		canvas5->Clear(Color::FromArgb(145, 225, 86));
		rhombs[Convert::ToInt16(NumberRhomb->Value) - 1].TurnOn90();
		for (int j = 0; j < irh; j++)
		{
			rhombs[j].Show(canvas5);
		}
	}
}

System::Void Lab4::Trapezoids::MoveTrap_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (NumberTrap->Value == 0)
	{
		canvas6->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < itr; j++)
		{
			trapezoids[j].MoveTo(Convert::ToInt16(TrXoffset->Value), Convert::ToInt16(TrYoffset->Value));
			trapezoids[j].Show(canvas6);
		}
	}
	else
	{
		canvas6->Clear(Color::FromArgb(145, 225, 86));
		trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].MoveTo(Convert::ToInt16(TrXoffset->Value), Convert::ToInt16(TrYoffset->Value));
		for (int j = 0; j < itr; j++)
		{
			trapezoids[j].Show(canvas6);
		}
	}
}

System::Void Lab4::Trapezoids::DelTrap_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((NumberTrap->Value == 0) && (itr != 0))
	{
		canvas6->Clear(Color::FromArgb(145, 225, 86));
		trapezoids[0].SetX(0);
		trapezoids[0].SetY(0);
		trapezoids[0].Set_X2(0);
		trapezoids[0].Set_Y2(0);
		trapezoids[0].Set_X3(0);
		trapezoids[0].Set_Y3(0);
		trapezoids[0].Set_X4(0);
		trapezoids[0].Set_Y4(0);
		itr = 0;
	}
	else if ((Convert::ToInt16(NumberTrap->Value) - 1 < itr) && (itr != 0))
	{

		if (Convert::ToInt16(NumberTrap->Value) == itr)
		{
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].SetX(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].SetY(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Set_X2(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Set_Y2(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Set_X3(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Set_Y3(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Set_X4(0);
			trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Set_Y4(0);
			itr -= 1;
		}
		else
		{
			for (int j = Convert::ToInt16(NumberTrap->Value) - 1; j < itr - 1; j++)
			{
				trapezoids[j] = trapezoids[j + 1];
			}
			itr -= 1;
		}
		canvas6->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < itr; j++)
		{
			trapezoids[j].Show(canvas6);
		}
	}
}

System::Void Lab4::Trapezoids::ResTrap_Click(System::Object^ sender, System::EventArgs^ e)
{
	int x1, y1;
	srand(time(NULL));
	if (NumberTrap->Value == 0)
	{
		canvas6->Clear(Color::FromArgb(145, 225, 86));
		for (int j = 0; j < itr; j++)
		{
			x1 = rand() % 20 + 1;
			y1 = rand() % 20 + 1;
			if (rand() % 2 == 0)
				x1 = -x1;
			if (rand() % 2 == 1)
				y1 = -y1;
			trapezoids[j].Resize(x1, y1);
			trapezoids[j].Show(canvas6);
		}

	}
	else
	{
		canvas6->Clear(Color::FromArgb(145, 225, 86));
		x1 = rand() % 20 + 1;
		y1 = rand() % 20 + 1;
		if (rand() % 2 == 0)
			x1 = -x1;
		if (rand() % 2 == 1)
			y1 = -y1;
		trapezoids[Convert::ToInt16(NumberTrap->Value) - 1].Resize(x1, y1);
		for (int j = 0; j < itr; j++)
		{
			trapezoids[j].Show(canvas6);
		}
	}
}
