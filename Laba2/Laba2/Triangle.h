#pragma once
#include "Line.h"
#include <math.h>
#define _USE_MATH_DEFINES 
#include <cmath>

class Triangle
{
public:
	Triangle(int x1, int y1, float length1, float angle1, float length2, float angle2)
	{
		if (angle1 > 0 && angle1 < 180)
		{
			while (y1 + length1 * sin(angle1 * M_PI / 180) >= 640)
				y1 -= 10;
		}
		if (angle1 > 90 && angle1 < 270)
		{
			while (x1 + length1 * cos(angle1 * M_PI / 180) <= 4)
				x1 += 10;
		}
		if (angle1 > 180 && angle1 < 360)
		{
			while (y1 + length1 * sin(angle1 * M_PI / 180) <= 4)
				y1 += 10;
		}
		if (angle1 > 270 || angle1 < 90)
		{
			while (x1 + length1 * cos(angle1 * M_PI / 180) >= 1500)
				x1 -= 10;
		}
		if (angle2 > 0 && angle2 < 180)
		{
			while (y1 + length2 * sin(angle2 * M_PI / 180) >= 640)
				y1 -= 10;
		}
		if (angle2 > 90 && angle2 < 270)
		{
			while (x1 + length2 * cos(angle2 * M_PI / 180) <= 4)
				x1 += 10;
		}
		if (angle2 > 180 && angle2 < 360)
		{
			while (y1 + length2 * sin(angle2 * M_PI / 180) <= 4)
				y1 += 10;
		}
		if (angle2 > 270 || angle2 < 90)
		{
			while (x1 + length2 * cos(angle2 * M_PI / 180) >= 1500)
				x1 -= 10;
		}
		Ft.SetAngle(angle1);
		Ft.SetLength(length1);
		Ft.SetX(x1);
		Ft.SetY(y1);
		Sd.SetAngle(angle2);
		Sd.SetLength(length2);
		Sd.SetX(x1);
		Sd.SetY(y1);
		int X;
		MessageBox::Show("Triangle is created.", "Alert!");
	}
	Triangle()
	{
		Ft.SetAngle(0);
		Ft.SetLength(0);
		Ft.SetX(0);
		Ft.SetY(0);
		Sd.SetAngle(0);
		Sd.SetLength(0);
		Sd.SetX(0);
		Sd.SetY(0);
		MessageBox::Show("Triangle is created.", "Alert!");
	}
	~Triangle()
	{

	}

	int GetX()
	{
		return Sd.GetX();
	}
	int GetY()
	{
		return Sd.GetY();
	}
	float GetLength1()
	{
		return Ft.GetLength();
	}
	float GetAngle1()
	{
		return Ft.GetAngle();
	}
	float GetLength2()
	{
		return Sd.GetLength();
	}
	float GetAngle2()
	{
		return Sd.GetAngle();
	}
	void SetX(int X)
	{
		Ft.SetX(X);
		Sd.SetX(X);
	}
	void SetY(int Y)
	{
		Ft.SetY(Y);
		Sd.SetY(Y);
	}
	void SetLength1(float Length)
	{
		Ft.SetLength(Length);
	}
	void SetAngle1(float Angle)
	{
		Ft.SetAngle(Angle);
	}
	void SetLength2(float Length)
	{
		Sd.SetLength(Length);
	}
	void SetAngle2(float Angle)
	{
		Sd.SetAngle(Angle);
	}
	void Show(Graphics^ canvas)
	{
		Ft.Show(canvas);
		Sd.Show(canvas);
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		x1 = Ft.GetX() + Ft.GetLength() * cos(Ft.GetAngle() * M_PI / 180);
		y1 = Ft.GetY() + Ft.GetLength() * sin(Ft.GetAngle() * M_PI / 180); 
		x2 = Ft.GetX() + Sd.GetLength() * cos(Sd.GetAngle() * M_PI / 180);
		y2 = Ft.GetY() + Sd.GetLength() * sin(Sd.GetAngle() * M_PI / 180);
		canvas->DrawLine(pen, x1, y1, x2, y2);
	}
	void MoveTo(int newX, int newY)
	{
		Ft.SetX(Ft.GetX() + newX);
		Ft.SetY(Ft.GetY() + newY);
		Sd.SetX(Sd.GetX() + newX);
		Sd.SetY(Sd.GetY() + newY);
	}
	void TurnTo(int Value)
	{
		Ft.SetAngle(Ft.GetAngle() + Value);
		Sd.SetAngle(Sd.GetAngle() + Value);
	}
private:
	Line Ft, Sd;

};