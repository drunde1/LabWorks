#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Points
{
public:
	Points()
	{
		X = 0;
		Y = 0;
		MessageBox::Show("Point is created.", "Alert!");

	}

	Points(int x, int y)
	{
		X = x;
		Y = y;
		MessageBox::Show("Point is created.", "Alert!");

	}

	~Points()
	{

	}

	void SetX(int x)
	{
		X = x;
	}

	void SetY(int y)
	{
		Y = y;
	}

	int GetX()
	{
		return X;
	}

	int GetY()
	{
		return Y;
	}

private:
	int X, Y;
};