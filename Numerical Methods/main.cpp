#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Definicje algorytmów znajdują sie w pliku approximation.cpp

	vector<func> base;
	base.push_back([](double x) {return 1.0; });
	base.push_back([](double x) { return x; });
	base.push_back([](double x) { return pow(x, 2); });
	base.push_back([](double x) { return pow(x, 3); });
	base.push_back([](double x) { return pow(x, 4); });

	//Aproksymacja w bazie standardowej | ZAD 1 - 2
	auto A1 = Approximation(base, fx);
	for (int i = 0; i < 5; i++)
		cout << A1[i] << "\n";
	//1.00003X^4	-1.99603X^3		+0.499352x^2	-1.01852x	+0.0435974
	cout << "\n\n";

	//Aproksymacja w bazie zortogonalizowanej metodą Grama Schmidta | ZAD 3
	auto GSbase = GramSchmidt(make_pair(-1, 1), base.data(), 5);
	auto A2 = ApproximationCustomBase(GSbase, fx);
	for (int i = 0; i < 5; i++)
		cout << A2[i] << "\n";

	cout << "\n\n";

	//Aproksymacja w bazie wygenerowanej metodą trójczłonową | ZAD 4
	auto TCBase = ThreePartRule(make_pair(-1, 1), 5);
	auto A3 = ApproximationCustomBase(TCBase, fx);
	for (int i = 0; i < 5; i++)
		cout << A3[i] << "\n";
	//Wykres w katalogu w pliku o nazwie chartapx.png
}
