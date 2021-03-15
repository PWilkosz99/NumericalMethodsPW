#include <iostream>
#include "headers.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Polish");

	short choice = -1;
	short choice2 = -1;
	short choice3 = -1;
	do
	{
		cout << "Menu programu\n" <<
			"0 - wyjscie\n" <<
			"1 - Horner\n" <<
			"2 - Interpolacja\n" <<
			"9 - Testy\n";
		cin >> choice;
		if (!cin.good())
			choice = 0;
		switch (choice)
		{
		case 0:
			cout << "\nWychodze z programu\n";
			break;
		case 1:
			cout << "Menu programu\n" <<
				"1 - Schemat Hornera\n" <<
				"2 - Uogólnony schemat Hornera\n";
			cin >> choice2;
			switch (choice2) 
			{
			case 1:
				HornerFromMain();
				break;
			case 2:
				HornerUOGFromMain();
				break;
			default:
				break;
			}
			break;		
		case 2:
			//interpolacja
			break;
		case 9:
			cout << "Menu testów\n" <<
				"1 - Schemat Hornera\n" <<
				"2 - Uogólnony schemat Hornera\n";
			cin >> choice3;
			switch (choice3)
			{
			case 1:
				HornerTest();
				break;
			case 2:
				HornerUOGTest();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	} while (choice != 0);

	HornerUOGTest();

	return 0;
}