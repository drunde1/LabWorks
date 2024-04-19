#pragma once
#include "Points.h"
#include "Circle.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Ring
{
public:
	Ring(int x, int y, int R, int r)
	{
		Cir.SetX(x);
		Cir.SetY(y);
		Cir.Set_r(R);
		cir.SetX(x);
		cir.SetY(y);
		cir.Set_r(r);
		MessageBox::Show("Ring is created.", "Alert!");
	}
	Ring()
	{
		Cir.SetX(0);
		Cir.SetY(0);
		Cir.Set_r(0);
		cir.SetX(0);
		cir.SetY(0);
		cir.Set_r(0);
		MessageBox::Show("Ring is created.", "Alert!");
	}
	~Ring()
	{

	}
	int GetX()
	{
		return Cir.GetX();
	}
	int GetY()
	{
		return Cir.GetY();
	}
	int Get_R()
	{
		return Cir.Get_r();
	}
	int Get_r()
	{
		return cir.Get_r();
	}
	void SetX(int X)
	{
		Cir.SetX(X);
		cir.SetX(X);
	}
	void SetY(int Y)
	{
		Cir.SetY(Y);
		cir.SetY(Y);
	}
	void Set_R(int R)
	{
		Cir.Set_r(R);
	}
	void Set_r(int r)
	{
		cir.Set_r(r);
	}
	void Show(Graphics^ canvas)
	{
		Cir.Show(canvas);
		cir.Show(canvas);
	}
	void MoveTo(int newX, int newY)
	{
		Cir.MoveTo(newX, newY);
		cir.MoveTo(newX, newY);
	}
	void Resize(int newR, int newr)
	{
		Cir.Set_r(newR);
		cir.Set_r(newr);
	}
private:
	Circle Cir;
	Circle cir;
};