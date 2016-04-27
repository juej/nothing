#include <iostream>
#include "person.h"
#include "students.h"
#include "professor.h"
using namespace std;
int main()
{
	CPerson* t;

	CStudents one("Orwell", "George", "Arthur", "Britain", 1903, 4, 2015);

	CProfessor* two;
	two = new CProfessor("London", "Jack", "Griffith", "USA", 1876, 10, "Master");

	char i;
	do
	{
		cout << "1 view CStudents" << endl;
		cout << "2 pure virtual function CStudents" << endl;
		cout << "3 view CProfessor" << endl;
		cout << "4 pure virtual function CProfessor" << endl;
		cout << "0 exit" << endl;


		cin >> i;
		switch (i)
		{
		case '1':
		{
					t = &one;
					t->show();
					break;
		}
		case '2':
		{
					one.correctStatus(0);
					break;
		}
		case '3':
		{
					t = two;
					t->show();
					break;

		}
		case '4':
		{
					two->correctStatus(0);
					break;
		}

		default:
		{
				   cout << "oh!" << endl;
		}
		}
	} while (i != '0');
	return 0;
}