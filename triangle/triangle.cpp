#include "triangle.h"
#include "windows.h"
#include <iostream>
#include <math.h>
using namespace std;

CTriangle::CTriangle()
:m_x0(0)
, m_x1(0)
, m_x2(0)
, m_y0(0)
, m_y1(0)
, m_y2(0){}

CTriangle::CTriangle(double a, double b, double c, double d, double e, double f)
:m_x0(a)
, m_x1(b)
, m_x2(c)
, m_y0(d)
, m_y1(e)
, m_y2(f){}

CTriangle::~CTriangle()
{
}

void CTriangle::show()
{
	cout << endl << "(x0;y0)=" << "(" << CTriangle::getX0() << ";" << CTriangle::getY0() << ")" << endl;
	cout << "(x1;y1)=" << "(" << CTriangle::getX1() << ";" << CTriangle::getY1() << ")" << endl;
	cout << "(x2;y2)=" << "(" << CTriangle::getX2() << ";" << CTriangle::getY2() << ")" << endl;
	//cout << "(x2;y2)=" << "(" << m_x2 << ";" << m_y2 << ")" << endl;
}

void CTriangle::move(double dx, double dy)
{
	m_x0 += dx;
	m_x1 += dx;
	m_x2 += dx;
	m_y0 += dy;
	m_y1 += dy;
	m_y2 += dy;
	CTriangle::show();
}

void CTriangle::rotationX0(double angle)
{
	m_x1 = (m_x1 - m_x0)*cos(angle) - (m_y1 - m_y0)*sin(angle) + m_x0;
	m_y1 = (m_x1 - m_x0)*sin(angle) + (m_y1 - m_y0)*cos(angle) + m_y0;
	m_x2 = (m_x2 - m_x0)*cos(angle) - (m_y2 - m_y0)*sin(angle) + m_x0;
	m_y2 = (m_x2 - m_x0)*sin(angle) + (m_y2 - m_y0)*cos(angle) + m_y0;
	CTriangle::show();
}

void CTriangle::rotationX1(double angle)
{
	m_x0 = (m_x0 - m_x1)*cos(angle) - (m_y0 - m_y1)*sin(angle) + m_x1;
	m_y0 = (m_x0 - m_x1)*sin(angle) + (m_y0 - m_y1)*cos(angle) + m_y1;
	m_x2 = (m_x2 - m_x1)*cos(angle) - (m_y2 - m_y1)*sin(angle) + m_x1;
	m_y2 = (m_x2 - m_x1)*sin(angle) + (m_y2 - m_y1)*cos(angle) + m_y1;
	CTriangle::show();
}

void CTriangle::rotationX2(double angle)
{
	m_x0 = (m_x0 - m_x2)*cos(angle) - (m_y0 - m_y2)*sin(angle) + m_x2;
	m_y0 = (m_x0 - m_x2)*sin(angle) + (m_y0 - m_y2)*cos(angle) + m_y2;
	m_x1 = (m_x1 - m_x2)*cos(angle) - (m_y1 - m_y2)*sin(angle) + m_x2;
	m_y1 = (m_x1 - m_x2)*sin(angle) + (m_y1 - m_y2)*cos(angle) + m_y2;
	CTriangle::show();
}


void CTriangle::length(double a, double b, double c)
{
	a = sqrt(pow((m_x1 - m_x0), 2) + pow((m_y1 - m_y0), 2));
	b = sqrt(pow((m_x2 - m_x1), 2) + pow((m_y2 - m_y1), 2));
	c = sqrt(pow((m_x2 - m_x0), 2) + pow((m_y2 - m_y0), 2));

	cout << endl << "The length of the first side: " << a << endl;
	cout << "The length of the second side: " << b << endl;
	cout << "The length of the third side: " << c << endl;
}

void CTriangle::area(double s)
{
	s = abs(.5*((m_x0 - m_x2)*(m_y1 - m_y2) - (m_x1 - m_x2)*(m_y0 - m_y2)));
	cout << endl << "Area of the triangle is equal to: " << s << endl;
}

void CTriangle::scale(double scale)
{
	m_x0 = (((m_x0 + m_x1 + m_x2) / 3) + (m_x0 - ((m_x0 + m_x1 + m_x2) / 3)))*scale;
	m_x1 = (((m_x0 + m_x1 + m_x2) / 3) + (m_x1 - ((m_x0 + m_x1 + m_x2) / 3)))*scale;
	m_x2 = (((m_x0 + m_x1 + m_x2) / 3) + (m_x2 - ((m_x0 + m_x1 + m_x2) / 3)))*scale;

	m_y0 = (((m_y0 + m_y1 + m_y2) / 3) + (m_y0 - ((m_y0 + m_y1 + m_y2) / 3)))*scale;
	m_y1 = (((m_y0 + m_y1 + m_y2) / 3) + (m_y1 - ((m_y0 + m_y1 + m_y2) / 3)))*scale;
	m_y2 = (((m_y0 + m_y1 + m_y2) / 3) + (m_y2 - ((m_y0 + m_y1 + m_y2) / 3)))*scale;

	CTriangle::show();
}

void CTriangle::draw()
{

	HWND hwnd;
	hwnd = FindWindow(NULL, TEXT("Triangle"));
	RECT rc;
	GetClientRect(hwnd, &rc);

	int oX = rc.right / 2;
	int oY = rc.bottom / 2;

	HDC hdc = GetDC(hwnd); // Получаем контекст для рисования
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(250, 50, 100)); // Создаем цвет пера
	p1 = (HPEN)SelectObject(hdc, p2);  // Заносим красное перо в контекст рисования

	MoveToEx(hdc, oX + m_x0, oY - m_y0, NULL);
	LineTo(hdc, oX + m_x1, oY - m_y1);
	LineTo(hdc, oX + m_x2, oY - m_y2);
	LineTo(hdc, oX + m_x0, oY - m_y0);

	/*
	SelectObject(hdc, p1);   // Возвращаем старое перо
	ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо
	*/
}

void CTriangle::setX0(double x)
{
	m_x0 = x;
}
void CTriangle::setX1(double x)
{
	m_x1 = x;
}
void CTriangle::setX2(double x)
{
	m_x2 = x;
}
void CTriangle::setY0(double y)
{
	m_y0 = y;
}
void CTriangle::setY1(double y)
{
	m_y1 = y;
}
void CTriangle::setY2(double y)
{
	m_y2 = y;
}

double CTriangle::getX0()
{
	return m_x0;
}
double CTriangle::getX1()
{
	return m_x1;
}
double CTriangle::getX2()
{
	return m_x2;
}
double CTriangle::getY0()
{
	return m_y0;
}
double CTriangle::getY1()
{
	return m_y1;
}
double CTriangle::getY2()
{
	return m_y2;
}