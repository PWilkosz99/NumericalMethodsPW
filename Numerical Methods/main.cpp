#include <iostream>
#include "headers.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Polish");

	short choice = -1;
	short choice2 = -1;
	//short choice3 = -1;
	do
	{
		cout << "Menu programu\n" <<
			"0 - Wyjscie\n" <<
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
			cout << "Menu programu\n" <<
				"1 - Interpolacja Lagrangea\n" <<
				"2 - Ilorazy ró¿nicowe(b_k)\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				LagrangeInterpolationFromMain();
				break;
			case 2:
				CalculateBKFromMain();
				break;
			default:
				break;
			}
			break;
			break;
		case 9:
			cout << "Menu testów\n" <<
				"1 - Schemat Hornera\n" <<
				"2 - Uogólnony schemat Hornera\n" <<
				"3 - Interpolacja Langrangea\n" <<
				"4 - Ilorazy ró¿nicowe\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				HornerTest();
				break;
			case 2:
				HornerUOGTest();
				break;
			case 3:
				LagrangeInteprolationTest();
				break;
			case 4:
				CalculateBKTest();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	} while (choice != 0);

	return 0;
}