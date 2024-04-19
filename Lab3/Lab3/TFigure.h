#pragma once
#include <math.h>
#define _USE_MATH_DEFINES 
#include <cmath>
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
		//MessageBox::Show("Point is created.", "Alert!");

	}

	Points(int x, int y)
	{
		X = x;
		Y = y;
		//MessageBox::Show("Point is created.", "Alert!");

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

class TFigure abstract
{
public:
	TFigure(int x, int y)
	{
		O.SetX(x);
		O.SetY(y);
	}
	TFigure()
	{
		O.SetX(0);
		O.SetY(0);
	}
	virtual ~TFigure()
	{

	}
	void SetX(int x)
	{
		O.SetX(x);
	}
	void SetY(int y)
	{
		O.SetY(y);
	}
	int GetX()
	{
		return O.GetX();
	}
	int GetY()
	{
		return O.GetY();
	}
	virtual void Show(Graphics^ canvas) abstract;
	
	virtual void MoveTo(int newX, int newY) abstract;

private:
	Points O;
};

class TCircle : public TFigure
{
public:
	TCircle(int x, int y, int r) : TFigure(x,y)
	{
		R = r;
		//MessageBox::Show("Circle is created.", "Alert!");
	}
	TCircle() : TFigure()
	{
		R = 0;
		//MessageBox::Show("Circle is created.", "Alert!");
	}
	~TCircle() override
	{

	}
	int Get_R()
	{
		return R;
	}
	void Set_R(int r)
	{
		R = r;
	}
	void Show(Graphics^ canvas) override
	{
		Rectangle rec;
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		rec.X = GetX() - R;
		rec.Y = GetY() - R;
		rec.Width = 2 * R;
		rec.Height = 2 * R;
		canvas->DrawEllipse(pen, rec);
	}
	void MoveTo(int newX, int newY) override
	{
		SetX(GetX() + newX);
		SetY(GetY() + newY);
	}
	void Resize(int newR)
	{
		R = newR;
	}
protected:
	int R;
};

class TEllipse : public TCircle
{	
public:
	TEllipse(int x, int y, int R, int r) : TCircle(x, y , R)
	{
		this->r = r;
		//MessageBox::Show("Ellips is created.", "Alert!");
	}
	TEllipse() : TCircle()
	{
		r = 0;
		//MessageBox::Show("Ellips is created.", "Alert!");
		}
	~TEllipse() override
	{
		
	}
	int Get_r()
	{
		return r;
	}
	void Set_r(int r)
	{
		this->r = r;
	}
	void Show(Graphics^ canvas) override
	{
		Rectangle rec;
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		rec.X = GetX() - R;
		rec.Y = GetY() - r;
		rec.Width = 2 * R;
		rec.Height = 2 * r;
		canvas->DrawEllipse(pen, rec);
	}
	void TurnTo90()
	{
		int temp = R;
		R = r;
		r = temp;
	}

private:
	int r;
};

class TQuadrangle : public TFigure
{
public:
	TQuadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) : TFigure(x1, y1)
	{
		Sd.SetX(x2);
		Sd.SetY(y2);
		Td.SetX(x3);
		Td.SetY(y3);
		Fs.SetX(x4);
		Fs.SetY(y4);
		lenth1 = sqrt((Sd.GetX() - GetX()) * (Sd.GetX() - GetX()) + (Sd.GetY() - GetY()) * (Sd.GetY() - GetY()));
		lenth2 = sqrt((Td.GetX() - GetX()) * (Td.GetX() - GetX()) + (Td.GetY() - GetY()) * (Td.GetY() - GetY()));
		lenth3 = sqrt((Fs.GetX() - GetX()) * (Fs.GetX() - GetX()) + (Fs.GetY() - GetY()) * (Fs.GetY() - GetY()));
		float width1 = abs(Sd.GetY() - GetY());
		float width2 = abs(Td.GetY() - GetY());
		float width3 = abs(Fs.GetY() - GetY());
		float ssin1 = width1 / lenth1;
		float ssin2 = width2 / lenth2;
		float ssin3 = width3 / lenth3;
		angle1 = asin(ssin1);
		angle2 = asin(ssin2);
		angle3 = asin(ssin3);
		if (x4 < x1)
			angle3 += 2 * (M_PI/2 - angle3);
		//MessageBox::Show("Quadrangle is created.", "Alert!");
	}
	TQuadrangle() : TFigure()
	{
		Sd.SetX(0);
		Sd.SetY(0);
		Td.SetX(0);
		Td.SetY(0);
		Fs.SetX(0);
		Fs.SetY(0);
		//MessageBox::Show("Quadrangle is created.", "Alert!");
	}
	~TQuadrangle() override
	{

	}
	void Set_X2(int value)
	{
		Sd.SetX(value);
	}
	void Set_Y2(int value)
	{
		Sd.SetY(value);
	}
	void Set_X3(int value)
	{
		Td.SetX(value);
	}
	void Set_Y3(int value)
	{
		Td.SetY(value);
	}
	void Set_X4(int value)
	{
		Fs.SetX(value);
	}
	void Set_Y4(int value)
	{
		Fs.SetY(value);
	}
	int Get_X2()
	{
		return Sd.GetX();
	}
	int Get_Y2()
	{
		return Sd.GetY();
	}
	int Get_X3()
	{
		return Td.GetX();
	}
	int Get_Y3()
	{
		return Td.GetY();
	}
	int Get_X4()
	{
		return Fs.GetX();
	}
	int Get_Y4()
	{
		return Fs.GetY();
	}
	void Show(Graphics^ canvas) override
	{
		Pen^ pen = gcnew Pen(Color::FromArgb(18, 12, 89), 3.0f);
		PointF point1 = PointF(GetX(), GetY());
		PointF point2 = PointF(Sd.GetX(), Sd.GetY());
		PointF point3 = PointF(Td.GetX(), Td.GetY());
		PointF point4 = PointF(Fs.GetX(), Fs.GetY());
		array<PointF>^ points = { point1, point2, point3, point4 };
		canvas->DrawPolygon(pen, points);
	}
	void MoveTo(int newX, int newY) override
	{
		SetX(GetX() + newX);
		SetY(GetY() + newY);
		Sd.SetX(Sd.GetX() + newX);
		Sd.SetY(Sd.GetY() + newY);
		Td.SetX(Td.GetX() + newX);
		Td.SetY(Td.GetY() + newY);
		Fs.SetX(Fs.GetX() + newX);
		Fs.SetY(Fs.GetY() + newY);
	}
	void Resize(int newX, int newY)
	{
		SetX(GetX() + newX);
		SetY(GetY() + newY);
		Sd.SetX(Sd.GetX() - newX);
		Sd.SetY(Sd.GetY() + newY);
		Td.SetX(Td.GetX() - newX);
		Td.SetY(Td.GetY() - newY);
		Fs.SetX(Fs.GetX() + newX);
		Fs.SetY(Fs.GetY() - newY);
	}
	
	virtual void TurnOn90()
	{
		angle1 += M_PI / 2;
		angle2 += M_PI / 2;
		angle3 += M_PI / 2;
		Sd.SetX(GetX() + lenth1 * cos(angle1));
		Sd.SetY(GetY() + lenth1 * sin(angle1));
		Td.SetX(GetX() + lenth2 * cos(angle2));
		Td.SetY(GetY() + lenth2 * sin(angle2));
		Fs.SetX(GetX() + lenth3 * cos(angle3));
		Fs.SetY(GetY() + lenth3 * sin(angle3));
		
	}
protected:
	Points Sd, Td, Fs;
	float angle1, angle2, angle3, lenth1, lenth2, lenth3;
};

class TRectangle : public TQuadrangle
{
public:
	TRectangle(int x1, int y1, int x2, int y2) : TQuadrangle(x1, y1, x2, y1, x2, y2, x1, y2)
	{

	}
	TRectangle() : TQuadrangle()
	{

	}
	~TRectangle() override
	{

	}	
	void TurnOn90() override
	{
		int heigth = Get_Y3() - GetY();
		int width = Get_X3() - GetX();
		SetX(GetX() + (Get_X3() - GetX() - heigth) / 2);
		SetY(GetY() - (Get_X3() - GetX() - heigth));
		Set_X3(GetX() + heigth);
		Set_Y3(GetY() + width);
		heigth = Get_Y4() - Get_Y2();
		width = Get_X4() - Get_X2();
		Set_X2(Get_X2() + (Get_X4() - Get_X2() - heigth) / 2);
		Set_Y2(Get_Y2() - (Get_X4() - Get_X2() - heigth));
		Set_X4(Get_X2() + heigth);
		Set_Y4(Get_Y2() + width);
	}
};

class TRhomb : public TQuadrangle
{
public:
	TRhomb(int d1, int d2, int x, int y) : TQuadrangle(x, (y - d1 / 2), (x + d2 / 2), y, x, (y + d1 / 2), (x - d2 / 2), y)
	{
		
	}
	TRhomb() : TQuadrangle()
	{

	}
	~TRhomb() override
	{

	}
	void TurnOn90() override
	{
		int heigth = Get_Y3() - GetY();
		int width = Get_X3() - GetX();
		SetX(GetX() + (Get_X3() - GetX() - heigth) / 2);
		SetY(GetY() - (Get_X3() - GetX() - heigth));
		Set_X3(GetX() + heigth);
		Set_Y3(GetY() + width);
		heigth = Get_Y4() - Get_Y2();
		width = Get_X4() - Get_X2();
		Set_X2(Get_X2() + (Get_X4() - Get_X2() - heigth) / 2);
		Set_Y2(Get_Y2() - (Get_X4() - Get_X2() - heigth));
		Set_X4(Get_X2() + heigth);
		Set_Y4(Get_Y2() + width);
	}
};

class TTrapezoid : public TQuadrangle
{
public:
	TTrapezoid(int x1, int x2, int x3, int x4, int y1, int y2) : TQuadrangle(x1, y1, x2, y1, x3, y2, x4, y2)
	{

	}
	TTrapezoid() : TQuadrangle()
	{

	}
	~TTrapezoid() override
	{

	}
};