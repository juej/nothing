#pragma once

class CTriangle
{
protected:
	double m_x0, m_x1, m_x2, m_y0, m_y1, m_y2;
public:
	CTriangle();
	CTriangle(double, double, double, double, double, double);
	~CTriangle();

	void show();

	void move(double, double);

	void rotationX0(double);
	void rotationX1(double);
	void rotationX2(double);

	void length(double, double, double);
	void area(double);
	void scale(double);
	void draw();

	void setX0(double);
	void setX1(double);
	void setX2(double);
	void setY0(double);
	void setY1(double);
	void setY2(double);

	double getX0();
	double getX1();
	double getX2();
	double getY0();
	double getY1();
	double getY2();
};