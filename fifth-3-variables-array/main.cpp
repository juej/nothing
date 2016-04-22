#include <iostream>
#include "person.h"
using namespace std;
int main()
{	// явное объявление объекта (вызывается конструктор с параметрами)
	CPerson big("Orwell", "George", 1903);
	int i;
	do
	{
		cout << endl << "1 view the status of the object" << endl;
		cout << "2 change" << endl;
		cout << "3 create new object" << endl;
		cout << "0 exit" << endl;
		cin >> i;
		char* name = new char[20];
		char* surname = new char[20];
		int year = 1903;
		switch (i)
		{
		case 1:
		{
				  cout << big.getSurName() << '\t';
				  cout << big.getName() << '\t';
				  cout << big.getYear() << '\n';
				  break;
		}
		case 2:
		{
				  cout << "SurName: ";
				  cin >> surname;
				  big.setSurName(surname);
				  cout << "Name: ";
				  cin >> name;
				  big.setName(name);
				  cout << "Year: ";
				  cin >> year;
				  big.setYear(year);
				  cout << big.getSurName() << '\t';
				  cout << big.getName() << '\t';
				  cout << big.getYear() << '\n';
				  break;
		}
		case 3:
		{
				  CPerson* One;
				  One = new CPerson("Orwell", "George", 1903);
				  cout << "SurName: ";
				  cin >> surname;
				  One->setSurName(surname);
				  cout << "Name: ";
				  cin >> name;
				  One->setName(name);
				  cout << "Year: ";
				  cin >> year;
				  One->setYear(year);
				  cout << One->getSurName() << '\t';
				  cout << One->getName() << '\t';
				  cout << One->getYear() << '\n';
				  break;

		}
		default:
		{
				   cout << "oh!" << endl;
		}
		}
	} while (i != 0);
	return 0;
}