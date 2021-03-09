#include <iostream>
#include "headers.h"

using namespace std;

int main() {
	short choice = 0;
	do
	{
		cout << "Menu programu\n" <<
			"0 - wyjscie\n" <<
			"1 - Horner\n" <<
			"2 - Interpolacja\n";
		cin >> choice;
		if (!cin.good())
			choice = 0;
		switch (choice)
		{
		case 0:
			cout << "\nWychodze z programu\n";
			break;
		case 1:
			HornerFromMain();
			break;		
		case 2:
			//interpolacja
			break;
		default:
			break;
		}
	} while (choice != 0);
	return 0;
}