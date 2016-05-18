#include "triangle.h"
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	SetConsoleTitle(TEXT("Triangle"));

	CTriangle one(-25, 0, 25, 0, 50, 0);

	double x0, x1, x2, y0, y1, y2;
	double move_x, move_y;
	double rotation_angle;
	char rotation_point;
	double length1 = 0, length2 = 0, length3 = 0;
	double scale, s = 0;
	char choice;

	cout << "1 Enter new coordinats" << endl;
	cout << "2 Show coordinats" << endl;
	cout << "3 Move the triangle" << endl;
	cout << "4 Show lengths of sides" << endl;
	cout << "5 Show area of a triangle" << endl;
	cout << "6 Rotate the triangle" << endl;
	cout << "7 Scale the triangle" << endl;
	cout << "8 Draw the triangle" << endl;
	cout << "9 Show menu" << endl;
	cout << "0 Exit" << endl;

	do {

		cout << endl << "Enter command: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
					cout << "x0 = ";
					cin >> x0;
					cout << "y0 = ";
					cin >> y0;

					cout << "x1 = ";
					cin >> x1;
					cout << "y1 = ";
					cin >> y1;

					cout << "x2 = ";
					cin >> x2;
					cout << "y2 = ";
					cin >> y2;

					one.setX0(x0);
					one.setX1(x1);
					one.setX2(x2);
					one.setY0(y0);
					one.setY1(y1);
					one.setY2(y2);
					break;
		}
		case '2':
		{

					one.show();
					break;
		}
		case '3':
		{
					cout << "Enter movement x: ";
					cin >> move_x;
					cout << "Enter movement y: ";
					cin >> move_y;

					one.move(move_x, move_y);
					break;
		}
		case '4':
		{
					one.length(length1, length2, length3);
					break;
		}
		case '5':
		{
					one.area(s);
					break;
		}
		case '6':
		{
					cout << "Enter angle of rotation (radian): ";
					cin >> rotation_angle;

					do
					{
						cout << "Enter point of rotation of triangle: ";
						cin >> rotation_point;

						if (rotation_point == '1')
							one.rotationX0(rotation_angle);
						else if (rotation_point == '2')
							one.rotationX1(rotation_angle);
						else if (rotation_point == '3')
							one.rotationX2(rotation_angle);
						else cout << "You must enter 1/2/3 apex of triangle. Try again.";
					} while (((rotation_point == '1') || (rotation_point == '2') || (rotation_point == '3')) == 0);
					break;
		}
		case '7':
		{
					cout << "Enter scale: ";
					cin >> scale;

					one.scale(scale);
					break;
		}
		case '8':
		{
					one.draw();
					break;

		}
		case '9':
		{
					cout << endl << "1 Enter new coordinats" << endl;
					cout << "2 Show coordinats" << endl;
					cout << "3 Move the triangle" << endl;
					cout << "4 Show lengths of sides" << endl;
					cout << "5 Show area of a triangle" << endl;
					cout << "6 Rotate the triangle" << endl;
					cout << "7 Scale the triangle" << endl;
					cout << "8 Draw the triangle" << endl;
					cout << "9 Show menu" << endl;
					cout << "0 Exit" << endl;
					break;
		}
		}
	} while (choice != '0');
	return 0;
}