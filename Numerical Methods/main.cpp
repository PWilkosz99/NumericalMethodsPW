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
				//CalculateBKFromMain();
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
				"4 - Ilorazy ró¿nicowe\n"<<
				"5 - Ilorazy ró¿nicowe postaci Newtona na postaæ naturaln¹\n";
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
			case 5:
				BKToNaturalFormTest();
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


//double x[] = { 1, 2, 3};
//double y[] = { 3,5,1 }; 
//CalculateBK(3, x, y);

/*
polynomial-1-v2.csv - dane do obliczania schematu Hornera, przyk³adowe wyniki: x = -0.500000    y = -0.677734
polynomial-2-v2.csv - dane do obliczania uogólnionego schematu Hornera, przyk³adowe wyniki: x = -0.500000    y = 4.976483
polynomial-3-v2.csv - dane do wyznaczania wielomianu Lagrange'a, przyk³adowe wyniki: x = -0.500000    y = 2.820313
polynomial-4-v2.csv - dane do obliczania ilorazów ró¿nicowych - wspó³czynników b_k dla postaci Newtona, przyk³adowe wyniki: b = 0.100000 0.500000 20.416667 -61.458333 37.202381 148.809524 -240.575397 170.134649 -15.538530 -38.732206; x = 0.200000     y = -0.215715
Postaæ naturalna dla powy¿szego wiel. w postaci Newtona: a = 0.600000 -16.098312 42.478886 123.756241 -135.092299 -252.016117 144.587708 189.040394 -46.524295 -38.732206
*/