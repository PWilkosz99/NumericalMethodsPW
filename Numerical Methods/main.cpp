#include <iostream>
#include "headers.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Polish");

	short choice = -1;
	short choice2 = -1;
	do
	{
		cout << "Menu programu\n" <<
			"0 - Wyjscie\n" <<
			"1 - Horner\n" <<
			"2 - Interpolacja\n" <<
			"3 - Uk�ady r�wna� liniowych\n" <<
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
				"2 - Uog�lnony schemat Hornera\n";
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
				"2 - Ilorazy r�nicowe(b_k)\n" <<
				"3 - Posta� naturalna z postaci Newtona\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				LagrangeInterpolationFromMain();
				break;
			case 2:
				CalculateBKFromMain();
				break;
			case 3:
				BkToNaturalFormFromMain();
				break;
			default:
				break;
			}
			break;
		case 3:
			cout << "Menu programu\n" <<
				"1 - Metoda Gaussa\n" <<
				"2 - Metoda Gaussa-Crouta\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				ElimGaussFromMain();
				break;
			case 2:
				ElimGaussCroutFromMain();
				break;
			default:
				break;
			}
			break;
			break;
		case 9:
			cout << "Menu test�w\n" <<
				"1 - Schemat Hornera\n" <<
				"2 - Uog�lnony schemat Hornera\n" <<
				"3 - Interpolacja Langrangea\n" <<
				"4 - Ilorazy r�nicowe\n" <<
				"5 - Ilorazy r�nicowe postaci Newtona na posta� naturaln�\n" <<
				"6 - Metoda Gaussa\n" <<
				"7 - Metoda Gaussa-Crouta\n" <<
				"91 - Laboratoria 1-2\n" <<
				"92 - Laboratoria 1-2\n";
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
			case 6:
				ElimGaussTest();
				break;
			case 7:
				ElimGaussCroutTest();
				break;
			case 91:
				cout << "Wyniki dla danych z pliku csv:\n";
				cout << "\nZad 1 Obliczanie warto�ci wielomianu zadanego w postaci naturalnej dla dowolnej warto�ci x z wykorzystaniem schematu Hornera\n";
				HornerTest();
				cout << "\nZad 2 Obliczanie warto�ci wielomianu zadanego w postaci Newtona dla dowolnej warto�ci x z wykorzystaniem uog�lnionego schematu Hornera\n";
				HornerUOGTest();
				cout << "\nZad 3 Przekszta�cenie wielomianu z postaci Newtona na posta� naturaln�(przeliczenie wsp�czynnik�w)\n";
				LagrangeInteprolationTest();
				cout << "\nZad 4 Interpolacja Lagrange�a\n";
				CalculateBKTest();
				cout << "\nZad 5 Posta� Newtona wielomianu Lagrange�a - wyznaczanie iloraz�w r�nicowych\n";
				BKToNaturalFormTest();
				break;
			case 92:
				cout << "Wyniki dla macierzy z tre�ci zadania:\n";
				cout << "Metoda eliminacji Gaussa:\n";
				ElimGaussTest();
				cout << "Metoda eliminacji Gaussa-Crouta:\n";
				ElimGaussCroutTest();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	} while (choice != 0);
}

/*
polynomial-1-v2.csv - dane do obliczania schematu Hornera, przyk�adowe wyniki: x = -0.500000    y = -0.677734
polynomial-2-v2.csv - dane do obliczania uog�lnionego schematu Hornera, przyk�adowe wyniki: x = -0.500000    y = 4.976483
polynomial-3-v2.csv - dane do wyznaczania wielomianu Lagrange'a, przyk�adowe wyniki: x = -0.500000    y = 2.820313
polynomial-4-v2.csv - dane do obliczania iloraz�w r�nicowych - wsp�czynnik�w b_k dla postaci Newtona, przyk�adowe wyniki: b = 0.100000 0.500000 20.416667 -61.458333 37.202381 148.809524 -240.575397 170.134649 -15.538530 -38.732206; x = 0.200000     y = -0.215715
Posta� naturalna dla powy�szego wiel. w postaci Newtona: a = 0.600000 -16.098312 42.478886 123.756241 -135.092299 -252.016117 144.587708 189.040394 -46.524295 -38.732206
*/