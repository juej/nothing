#include <iostream>
#include "person.h"
using namespace std;
int main()
{	// явное объявление объекта (вызывается конструктор с параметрами)
	CPerson big("Orwell", "George", "Arthur", "Britain", 1903);
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
		char* patronymic = new char[20];
		char* country = new char[20];
		int year;
		switch (i)
		{
		case 1:
		{
				  cout << big.getSurName() << '\t';
				  cout << big.getName() << '\t';
				  cout << big.getPatronymic() << '\t';
				  cout << big.getCountry() << '\t';
				  cout << big.getYear() << '\n';
				  break;
		}
		case 2:
		{
				  cout << "SurName: ";
				  cin >> surname;
				  cout << "Name: ";
				  cin >> name;
				  cout << "Patronymic: ";
				  cin >> patronymic;
				  cout << "Country: ";
				  cin >> country;
				  cout << "Year: ";
				  cin >> year;

				  big.setSurName(surname);
				  big.setName(name);
				  big.setPatronymic(patronymic);
				  big.setCountry(country);
				  big.setYear(year);

				  cout << big.getSurName() << '\t';
				  cout << big.getName() << '\t';
				  cout << big.getPatronymic() << '\t';
				  cout << big.getCountry() << '\t';
				  cout << big.getYear() << '\n';
				  break;
		}
		case 3:
		{
				  cout << "SurName: ";
				  cin >> surname;
				  cout << "Name: ";
				  cin >> name;
				  cout << "Patronymic: ";
				  cin >> patronymic;
				  cout << "Country: ";
				  cin >> country;
				  cout << "Year: ";
				  cin >> year;

				  CPerson* One;
				  One = new CPerson("Orwell", "George", "Arthur", "Britain", 1903);

				  One->setSurName(surname);
				  One->setName(name);
				  One->setPatronymic(patronymic);
				  One->setCountry(country);
				  One->setYear(year);

				  cout << One->getSurName() << '\t';
				  cout << One->getName() << '\t';
				  cout << One->getPatronymic() << '\t';
				  cout << One->getCountry() << '\t';
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
