#pragma once
#include "Points.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Rect
{
public:
	Rect(int X1, int Y1, int X2, int Y2)
	{
		One.SetX(X1);
		One.SetY(Y1);
		Two.SetX(X2);
		Two.SetY(Y2);
		MessageBox::Show("Rectangle is created.", "Alert!");
	}

	Rect()
	{
		One.SetX(0);
		One.SetY(0);
		Two.SetX(0);
		Two.SetY(0);
		MessageBox::Show("Rectangle is created.", "Alert!");
	}

	~Rect()
	{

	}
	int GetX1()
	{
		return One.GetX();
	}
	int GetX2()
	{
		return Two.GetX();
	}
	int GetY1()
	{
		return One.GetY();
	}
	int GetY2()
	{
		return Two.GetY();
	}
	void SetX1(int x1)
	{
		One.SetX(x1);
	}
	void SetY1(int y1)
	{
		One.SetY(y1);
	}
	void SetX2(int x2)
	{
		Two.SetX(x2);
	}
	void SetY2(int y2)
	{
		Two.SetY(y2);
	}

	void Show(Graphics^ canvas)
	{
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		Rectangle rec;
		rec.X = One.GetX();
		rec.Y = One.GetY();
		rec.Width = Two.GetX() - One.GetX();
		rec.Height = Two.GetY() - One.GetY();
		canvas->DrawRectangle(pen, rec);
	}

	void MoveTo(int newX, int newY)
	{
		One.SetX(One.GetX() + newX);
		One.SetY(One.GetY() + newY);
		Two.SetX(Two.GetX() + newX);
		Two.SetY(Two.GetY() + newY);
	}

	void TurnOn90()
	{
		int heigth = Two.GetY() - One.GetY();
		int width = Two.GetX() - One.GetX();
		One.SetX(One.GetX() + (Two.GetX() - One.GetX() - heigth) / 2);
		One.SetY(One.GetY() - (Two.GetX() - One.GetX() - heigth));
		Two.SetX(One.GetX() + heigth);
		Two.SetY(One.GetY() + width);
	}

private:
	Points One;
	Points Two;
};