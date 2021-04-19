#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

vector<double> loadPoints(ifstream& plik) {
	vector<double> points;
	int n;
	plik >> n;
	double tmp;
	double* A = new double[n];
	for (int i = 0; i < n; ++i) {
		plik >> tmp;;
		points.push_back(tmp);
	}
	return points;
}


int main() {
	//Menu();

	ifstream file1("data\\points1.txt");//punkty rownoodlegle z xlsx
	vector<double> A = loadPoints(file1);
	file1.close();

	ifstream file2("data\\points2.txt");//punkty nierownoodlegle z xlsx
	vector<double> B = loadPoints(file2);
	file2.close();

	ifstream cfile("data\\coefficientsL5.txt");//wspolczynniki wielomianu 1 arkusz xsls
	vector<double> coef = loadPoints(cfile);
	cfile.close();

	ifstream cfile2("data\\coefficients2L5.txt");//wspolczynniki wielomianu 2 arkusz xsls
	vector<double> coef2 = loadPoints(cfile2);
	cfile2.close();

	//Definicje funkcji z zad 1 oraz 2 znajduja sie w pliku integration.cpp

	//ZAD3
	cout << "Zadanie 3:";
	cout << "\nMetoda trapezow dla punktow rownoodleglych i podanego wielomianu(lewa strona 1 xlsx):\n";
	cout << TrapezoidalRule(A, coef);
	cout << "\nMetoda trapezow dla punktow nie rownoodleglych i podanego wielomianu(prawa strona 1 xlsx):\n";
	cout << TrapezoidalRule(B, coef);
	cout << "\nMetoda trapezow dla punktow rownoodleglych i podanego wielomianu(lewa strona 2 xlsx):\n";
	cout << TrapezoidalRule(A, coef2);

	//ZAD4i5
	cout << "\n\nZadanie 4:\n";
	cout << "\tWzor trapezow:\n";
	cout << "Precyzja = 10 :\t\t" << TrapezoidalRuleNC(10, 0, 4.5, f4) << endl;
	cout << "Precyzja = 100 :\t" << TrapezoidalRuleNC(100, 0, 4.5, f4) << endl;
	cout << "Precyzja = 1000 :\t" << TrapezoidalRuleNC(1000, 0, 4.5, f4) << endl;;
	cout << "Precyzja = 10000 :\t" << TrapezoidalRuleNC(10000, 0, 4.5, f4) << endl;
	cout << "\tWzor Simpsona:\n";
	cout << "Precyzja = 10 :\t\t" << SimpsonRule(10, 0, 4.5, f4) << endl;
	cout << "Precyzja = 100 :\t" << SimpsonRule(100, 0, 4.5, f4) << endl;
	cout << "Precyzja = 1000 :\t" << SimpsonRule(1000, 0, 4.5, f4) << endl;;
	cout << "Precyzja = 10000 :\t" << SimpsonRule(10000, 0, 4.5, f4) << endl;
	cout << "\nWynik Wolfram: \t-4.40258\n";

	cout << "\nZadanie 5:\n";
	cout << "\tWzor trapezow:\n";
	cout << "Precyzja = 10 :\t\t" << TrapezoidalRuleNC(10, -2, 2, f5) << endl;
	cout << "Precyzja = 100 :\t" << TrapezoidalRuleNC(100, -2, 2, f5) << endl;
	cout << "Precyzja = 1000 :\t" << TrapezoidalRuleNC(1000, -2, 2, f5) << endl;;
	cout << "Precyzja = 10000 :\t" << TrapezoidalRuleNC(10000, -2, 2, f5) << endl;
	cout << "\tWzor Simpsona:\n";
	cout << "Precyzja = 10 :\t\t" << SimpsonRule(10, -2, 2, f5) << endl;
	cout << "Precyzja = 100 :\t" << SimpsonRule(100, -2, 2, f5) << endl;
	cout << "Precyzja = 1000 :\t" << SimpsonRule(1000, -2, 2, f5) << endl;;
	cout << "Precyzja = 10000 :\t" << SimpsonRule(10000, -2, 2, f5) << endl;
	cout << "\nWynik Wolfram: \t-32.9053\n";
	cout << "\nWnioski:\n";
	cout << "Aby uzyskac wynik o zakladanej dokladnosci zblizonej do rzeczywistego wyniku w przypadku uzycia \
	metody trapezow musimy obrac precyzje na poziome 10^4 czyli przedzialy wartosci odpowiednio 0.00045 oraz 0.0004 dla funkcji f4 i f5.\
	W przypadku metody Simpsona wystarczajcae jest obranie precyzji na poziomie 10^2 w ktorej wartosci przedzialow wynosza odpowiednio 0.0045 oraz 0.004\n\n\n";
}
