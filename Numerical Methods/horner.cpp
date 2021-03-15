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
//w - tablica warto�ci przed x
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
	cout << "Wynik dla danych polynomial-1-v2.csv:\n";
	cout << "Przyklad 1:";
	cout << Horner(n1, w1, x);
	cout << "\nPrzyklad 2:";
	cout << Horner(n2, w2, x);
	cout << "\nPrzyklad 3:";
	cout << Horner(n3, w3, x) << "\n\n";

}

//b - wartosci bi
double HornerUOG(int n, double b[], double x[], double p) {
	double y = b[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		y = y + (p - x[i]) + b[i];
	}
	return y;
}

void HornerUOGFromMain() {
	cout << "\nPodaj stopien wielomianu\n";
	int n = 0;
	cin >> n;
	double* w = new double[n];
	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Podaj wartosc przy x^" << i << "\n";
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cout << "Podaj wartosc przy wsp�czynnika b dla " << i << " stopnia\n";
		cin >> b[i];
	}
	cout << "Dla jakiego x policzyc?";
	int x = 0;
	cin >> x;
	cout << "Wynik to: " << HornerUOG(n, b, w, x) << "\n";
}

void HornerUOGTest() {
	double x_u[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.8, 0.8, 0.9, 1 };
	double a_i[] = { -1, 2, 5, -2, 4, -0.5, 8, -1, 0.01, 0.03 };
	int n = 10;
	double x = -0.5;
	cout << "Wynik dla danych polynomial-2-v2.csv:\n";
	cout << HornerUOG(n, a_i, x_u, x) << "\n\n";
}
