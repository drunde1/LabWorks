#pragma once
#include "Points.h"
#include <math.h>
#define _USE_MATH_DEFINES 
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Line
{
public:
	Line(int x, int y, float length, float angle)
	{
		
		if (angle > 0 && angle < 180)
		{
			while (y + length * sin(angle * M_PI / 180) >= 640)
				y -= 10;
		}
		if (angle > 90 && angle < 270)
		{
			while (x + length * cos(angle * M_PI / 180) <= 4)
				x += 10;
		}
		if (angle > 180 && angle < 360)
		{
			while (y + length * sin(angle * M_PI / 180) <= 4)
				y += 10;
		}
		if (angle > 270 || angle < 90)
		{
			while (x + length * cos(angle * M_PI / 180) >= 1500)
				x -= 10;
		}
		XY.SetX(x);
		XY.SetY(y);
		Length = length;
		Angle = angle;
		MessageBox::Show("Line is created.", "Alert!");
	}

	Line()
	{
		XY.SetX(0);
		XY.SetY(0);
		Length = 0;
		Angle = 0;
		MessageBox::Show("Line is created.", "Alert!");
	}

	~Line()
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
	float GetLength()
	{
		return Length;
	}
	float GetAngle()
	{
		return Angle;
	}
	void SetX(int X)
	{
		XY.SetX(X);
	}
	void SetY(int Y)
	{
		XY.SetY(Y);
	}
	void SetLength(float Length)
	{
		this->Length = Length;
	}
	void SetAngle(float Angle)
	{
		this->Angle = Angle;
	}

	void Show(Graphics^ canvas)
	{
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		int x2, y2;
		x2 = XY.GetX() + Length * cos(Angle * M_PI / 180);
		y2 = XY.GetY() + Length * sin(Angle * M_PI / 180);
		canvas->DrawLine(pen, XY.GetX(), XY.GetY(), x2, y2);
	}

	void MoveTo(int newX, int newY)
	{
		XY.SetX(XY.GetX() + newX);
		XY.SetY(XY.GetY() + newY);
	}

	void TurnTo(int Value)
	{
		Angle += Value;
	}
private:
	float Length, Angle;
	Points XY;
};