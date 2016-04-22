#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	struct AEROFLOT
	{
		char destination[20];
		int num;
		char type[20];
	};

	char destination[7][14] = { "moscow", "spb", "novosibirsk", "berlin", "paris", "rome", "london" };

	AEROFLOT group[7];
	for (int i(0); i < 7; i++)
	{
		cout << "Destination: ";
		cin >> group[i].destination;
		cout << "Flight number: ";
		cin >> group[i].num;
		cout << "Type of aircraft: ";
		cin >> group[i].type;
		cout << endl;
	}

	int amount = 0;

	for (int i(0); i < 7; ++i)
	for (int j(i + 1); j < 7; ++j)
	if (group[j].num < group[i].num) swap(group[i], group[j]);

	for (int i(0); i < 7; i++)
	{
		for (int j(0); j < 7; j++)
		{
			if (!(strcmp(destination[j], group[i].destination)))
			{
				cout << endl << "Destination -> " << group[i].destination << endl;
				cout << "Flight number -> " << group[i].num << endl;
				cout << "Type of aircraft -> " << group[i].type << endl;
				amount++;
			}
		}
	}
	if (amount == 0)	cout << "You entered wrong destinations." << endl;
	_getch();
	return 0;
}