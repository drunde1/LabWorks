#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Circle
{
public:
	Circle(int x, int y, int a, int b)
	{
		X = x;
		Y = y;
		this->a = a;
		this->b = b;
	}
	Circle()
	{
		X = 0;
		Y = 0;
		a = 0;
		b = 0;
	}
	~Circle()
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
		rec.X = X - a;
		rec.Y = Y - b;
		rec.Width = 2 * a;
		rec.Height = 2 * b;
		canvas->DrawEllipse(pen, rec);
	}

	void MoveTo(int newX, int newY)
	{
		X += newX;
		Y += newY;
	}

	void TurnTo90()
	{
		int temp = a;
		a = b;
		b = temp;
	}

private:
	int X, Y, a, b;
};