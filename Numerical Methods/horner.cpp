#include "headers.h"
#include <iostream>
#include <string>
#include <fstream>
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
	double w1[] = { -1, -0.8, -0.4, -0.2, -0.1, 0, 0.4, 0.5, 0.8, 1 };
	double w2[] = { -1, 2, 5, -2, 4, -0.5, 8, -1, 0.01, 0.03 };
	double w3[] = { -1, 2, 4, -5, -0.1 };
	int n1 = 10;
	int n2 = 10;
	int n3 = 5;
	double x = -0.5;
	cout << "Przyklad 1:";
	cout << Horner(n1, w1, x);
	cout << "\nPrzyklad 2:";
	cout << Horner(n2, w2, x);
	cout << "\nPrzyklad 3:";
	cout << Horner(n3, w3, x);

}

//b - wartosci bi
double Horner_uog(int n, double b[], double x[], double p) {
	double y = b[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		y = y + (p - x[i]) + b[i];
	}
	return y;
}