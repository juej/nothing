#include <iostream>
#include <conio.h>
using namespace std;
enum day{m, t, w, th, f, sat, sun};
char s[7][14] = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
int main()
{	
	int i;
	bool exit = true;
	day num;
	cout << "enter day:" << endl;
	while (exit == true)
	{
		cin >> i;
		num=(day)(i-1);
		switch (num)
		{
		case (t) : cout << s[num] << endl; break;
		case (w) : cout << s[num] << endl; break;
		case (th) : cout << s[num] << endl; break;
		case (f) : cout << s[num] << endl; break;
		case (m) : cout << s[num] << endl; break;
		case (sat) : cout << s[num]<< endl; break;
		case (sun) : cout << s[num]<< endl; break;
		default: cout << "error" << endl; exit = false;
		}
	}
	_getch();
	return 0;
}