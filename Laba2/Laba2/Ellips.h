#pragma once
#include "Points.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Ellips
{
public:
	Ellips(int x, int y, int a, int b)
	{
		XY.SetX(x);
		XY.SetY(y);
		this->a = a;
		this->b = b;
		MessageBox::Show("Ellips is created.", "Alert!");
	}
	Ellips()
	{
		XY.SetX(0);
		XY.SetY(0);
		a = 0;
		b = 0;
		MessageBox::Show("Ellips is created.", "Alert!");

	}
	~Ellips()
	{

	}

	int GetX()
	{
		return XY.GetX();
	}
	int GetY()
	{
		return XY.GetY();
	}
	int Get_a()
	{
		return a;
	}
	int Get_b()
	{
		return b;
	}

	void SetX(int X)
	{
		XY.SetX(X);
	}
	void SetY(int Y)
	{
		XY.SetY(Y);
	}
	void Set_a(int a)
	{
		this->a = a;
	}
	void Set_b(int b)
	{
		this->b = b;
	}

	void Show(Graphics^ canvas)
	{
		Rectangle rec;
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		rec.X = XY.GetX() - a;
		rec.Y = XY.GetY() - b;
		rec.Width = 2 * a;
		rec.Height = 2 * b;
		canvas->DrawEllipse(pen, rec);
	}

	void MoveTo(int newX, int newY)
	{
		XY.SetX(XY.GetX() + newX);
		XY.SetY(XY.GetY() + newY);
	}

	void TurnTo90()
	{
		int temp = a;
		a = b;
		b = temp;
	}

private:
	int a, b;
	Points XY;
};