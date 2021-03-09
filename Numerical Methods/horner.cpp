#include "headers.h"
#include <iostream>
using namespace std;

double Horner(int n, double w[], double p) {
	double y = w[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		y = y * p + w[i];
	}
	return y;
}

//n - ilosc elemetnow w tablicy
//w - tablica wartoœci przed x
//x - wartosc punktu

void HornerFromMain() {
	cout << "\nPodaj wielkosc wielomianu\n";
	int n = 0;
	cin >> n;
	double* w = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Podaj wartoœæ przy x^" << i << "\n";
		cin >> w[i];
	}
	cout << "Dla jakiego x policzyc?";
	int x = 0;
	cin >> x;
	cout << "Wynik to: " << Horner(n, w, x) << "\n";
}