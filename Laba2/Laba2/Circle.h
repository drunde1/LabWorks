#pragma once

#include "Points.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Circle
{
public:
	Circle(int x, int y, int r)
	{
		XY.SetX(x);
		XY.SetY(y);
		this->r = r;
		MessageBox::Show("Circle is created.", "Alert!");
	}
	Circle()
	{
		XY.SetX(0);
		XY.SetY(0);
		r = 0;
		MessageBox::Show("Circle is created.", "Alert!");
	}
	~Circle()
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
	int Get_r()
	{
		return r;
	}
	
	void SetX(int X)
	{
		XY.SetX(X);
	}
	void SetY(int Y)
	{
		XY.SetY(Y);
	}
	
	void Set_r(int r)
	{
		this->r = r;
	}
	void Show(Graphics^ canvas)
	{
		Rectangle rec;
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		rec.X = XY.GetX() - r;
		rec.Y = XY.GetY() - r;
		rec.Width = 2 * r;
		rec.Height = 2 * r;
		canvas->DrawEllipse(pen, rec);
	}
	void MoveTo(int newX, int newY)
	{
		XY.SetX(XY.GetX() + newX);
		XY.SetY(XY.GetY() + newY);
	}

private:
	int r;
	Points XY;
};