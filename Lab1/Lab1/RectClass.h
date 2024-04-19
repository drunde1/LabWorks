#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Rect
{
public:
	Rect(int X1, int Y1, int X2, int Y2)
	{
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		y2 = Y2;
	}

	Rect()
	{
		x1, x2, y1, y2 = 0;
	}

	~Rect()
	{

	}

	void SetX1(int x1)
	{
		this->x1 = x1;
	}
	void SetY1(int y1)
	{
		this->y1 = y1;
	}
	void SetX2(int x2)
	{
		this->x2 = x2;
	}
	void SetY2(int y2)
	{
		this->y2 = y2;
	}

	void Show(Graphics^ canvas)
	{
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		Rectangle rec;
		rec.X = x1;
		rec.Y = y1;
		rec.Width = x2 - x1;
		rec.Height = y2 - y1;
		canvas->DrawRectangle(pen, rec);
	}

	void MoveTo(int newX, int newY)
	{
		x1 += newX;
		y1 += newY;
		x2 += newX;
		y2 += newY;
	}

	void TurnOn90()
	{
		int heigth = y2 - y1;
		int width = x2 - x1;
		x1 = x1 + (x2 - x1 - heigth) / 2;
		y1 = y1 - (x2 - x1 - heigth);
		x2 = x1 + heigth;
		y2 = y1 + width;
	}

private:
	int x1, y1, x2, y2;

};