#pragma once
#include <math.h>
#define _USE_MATH_DEFINES 
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Line
{
public:
	Line(int x, int y, int length, int angle)
	{
		X = x;
		Y = y;
		Length = length;
		Angle = angle;
	}

	Line()
	{
		X = 0;
		Y = 0;
		Length = 0;
		Angle = 0;
	}

	~Line()
	{

	}

	void SetX(int X)
	{
		this->X = X;
	}
	void SetY(int Y)
	{
		this->Y = Y;
	}
	void SetLength(int Length)
	{
		this->Length = Length;
	}
	void SetAngle(int Angle)
	{
		this->Angle = Angle;
	}

	void Show(Graphics^ canvas)
	{
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		int X2 = X + Length * cos(Angle * M_PI / 180);
		int Y2 = Y + Length * sin(Angle * M_PI / 180);
		canvas->DrawLine(pen, X, Y, X2, Y2);
	}

	void MoveTo(int newX, int newY)
	{
		X += newX;
		Y += newY;
	}

	void TurnTo(int Value)
	{
		Angle += Value;
	}
private:
	int X, Y, Length, Angle;
};