#include "headers.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <vector>
using namespace std;

double Horner(int n, double w[], double p) {
	double y = w[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		y = y * p + w[i];
	}
	return y;
}

//n - stopien wspolczynnikow
//w - tablica wartoœci przed x
//p - wartosc punktu

void HornerFromMain() {
	cout << "\nPodaj stopien wielomianu\n";
	int n = 0;
	cin >> n;
	double* w = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Podaj wartosc przy x^" << i << "\n";
		cin >> w[i];
	}
	cout << "Dla jakiego x policzyc?";
	int x = 0;
	cin >> x;
	cout << "Wynik to: " << Horner(n, w, x) << "\n";
}


//csv: 1 - liczba wspolczynnikow, 2-11 wyrazy
//x ma byc -0.5
void HornerTest() {
	ifstream data("polynomial-1-v2.csv");
	vector<double> row;
	string line;
	if (data.good()) {
		while (!data.eof()) {
			row.clear();
			getline(data, line, ';');
			if (line != "") {
				row.push_back(stod(line));
			}
		}
	}
}

//b - wartosci bi
double Horner_uog(int n, double b[], double x[],double p) {
	double y = b[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		y = y + (p - x[i]) + b[i];
	}
	return y;
}