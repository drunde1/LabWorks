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
	virtual void Show(Graphics^ canvas) = 0;

	virtual void Free() = 0;

	virtual int Type() = 0;

	virtual void MoveTo(int newX, int newY, Graphics^ canvas)
	{
		SetX(GetX() + newX);
		SetY(GetY() + newY);
		Show(canvas);
	}

	virtual void Resize(int value, Graphics^ canvas) = 0;

private:
	Points O;
};

class TCircle : public TFigure
{
public:
	TCircle(int x, int y, int r) : TFigure(x, y)
	{
		R = r;
	}
	TCircle() : TFigure()
	{
		R = 0;
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
	void Free() override
	{
		SetX(0);
		SetY(0);
		R = 0;
	}
	void Resize(int value, Graphics^ canvas) override
	{
		R += value;
		Show(canvas);
	}

	int Type() override
	{
		return 1;
	}
protected:
	int R;
};

class TEllipse : public TCircle
{
public:
	TEllipse(int x, int y, int R, int r) : TCircle(x, y, R)
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
	void Free() override
	{
		TCircle::Free();
		r = 0;
	}
	void TurnTo90()
	{
		int temp = R;
		R = r;
		r = temp;
	}

	int Type() override
	{
		return 2;
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
	void MoveTo(int newX, int newY, Graphics^ canvas) override
	{
		SetX(GetX() + newX);
		SetY(GetY() + newY);
		Sd.SetX(Sd.GetX() + newX);
		Sd.SetY(Sd.GetY() + newY);
		Td.SetX(Td.GetX() + newX);
		Td.SetY(Td.GetY() + newY);
		Fs.SetX(Fs.GetX() + newX);
		Fs.SetY(Fs.GetY() + newY);
		Show(canvas);
	}
	void Free() override
	{
		SetX(0);
		SetY(0);
		Sd.SetX(0);
		Sd.SetY(0);
		Td.SetX(0);
		Td.SetY(0);
		Fs.SetX(0);
		Fs.SetY(0);
	}
	void Resize(int value, Graphics^ canvas) override
	{
		SetX(GetX() + value);
		SetY(GetY() + value);
		Sd.SetX(Sd.GetX() - value);
		Sd.SetY(Sd.GetY() + value);
		Td.SetX(Td.GetX() - value);
		Td.SetY(Td.GetY() - value);
		Fs.SetX(Fs.GetX() + value);
		Fs.SetY(Fs.GetY() - value);
		Show(canvas);
	}
	void TurnOn90()
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
	int Type() override
	{
		return 3;
	}
protected:
	Points Sd, Td, Fs;
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
	int Type() override
	{
		return 4;
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
	int Type() override
	{
		return 5;
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
	int Type() override
	{
		return 6;
	}
};