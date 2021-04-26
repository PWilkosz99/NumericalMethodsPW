#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Menu();

	//implementacja zadania znajduje sie w pliku integration.cpp
	cout << "Funkcja 1:\n";
	cout << "2 wezly: " << GaussLegendre(1, 0, 4.5, f4) << "\n";
	cout << "3 wezly: " << GaussLegendre(2, 0, 4.5, f4) << "\n";
	cout << "4 wezly: " << GaussLegendre(3, 0, 4.5, f4) << "\n";
	cout << "5 wezlow: " << GaussLegendre(4, 0, 4.5, f4) << "\n";
	cout << "\nFunkcja 2:\n";
	cout << "2 wezly: " << GaussLegendre(1, -2, 2, f5) << "\n";
	cout << "3 wezly: " << GaussLegendre(2, -2, 2, f5) << "\n";
	cout << "4 wezly: " << GaussLegendre(3, -2, 2, f5) << "\n";
	cout << "5 wezlow: " << GaussLegendre(4, -2, 2, f5) << "\n";
	cout << "Porownawcze wyniki dla metody trapezow z dokladnoscia 10000:\n\n";
	cout << "Funkcja 1:" << TrapezoidalRuleNC(10000, 0, 4.5, f4) << endl;
	cout << "Funkcja 2:" << TrapezoidalRuleNC(10000, -2, 2, f5) << endl;
}
