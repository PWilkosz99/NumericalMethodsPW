#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Definicje algorytmów znajdują sie w pliku approximation.cpp

	func base[5];
	base[0] = [](double x) {return 1.0; };
	base[1] = [](double x) { return x; };
	base[2] = [](double x) { return pow(x, 2); };
	base[3] = [](double x) { return pow(x, 3); };

	///Gram Schmidt dla -1, 1
	auto resbase1 = GramSchmidt(make_pair(-1, 1), base, 4);
	PrintBase(resbase1);
	ScalarTest(0.001, make_pair(-1, 1), resbase1, base);
	cout << endl;

	//Metoda Trojczlonowa dla -1, 1
	auto resbase3 = ThreePartRule(make_pair(-1, 1), 3);
	PrintBase(resbase3);
	ScalarTest(0.001, make_pair(-1, 1), resbase3, base);
	cout << endl;

	///Gram Schmidt dla 0, 1
	auto resbase2 = GramSchmidt(make_pair(0, 1), base, 4);
	PrintBase(resbase2);
	ScalarTest(0.001, make_pair(0, 1), resbase1, base);
	cout << endl;

	///Gram Schmidt dla -1, 1
	auto resbase4 = ThreePartRule(make_pair(0, 1), 3);
	PrintBase(resbase4);
	ScalarTest(0.001, make_pair(0, 1), resbase4, base);
	cout << endl;

	//Dla każdego przypadku wynikiem iloczynu sklaarnego wielomianów bazy jest liczba mniejsza niż 0.01 więc uznaję że wyniki są poprawne
	//Dla zakresu -1, 1 i rozmiaru 4 wynikiem działania są wielomiany Legendre’a: 1, x, x^2 - 1/3, x^3 - 3/5x 
}
