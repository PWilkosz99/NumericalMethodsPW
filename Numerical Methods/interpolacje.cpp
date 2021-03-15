#include "headers.h"
#include <iostream>

using namespace std;

double CalculateLi(int n, int i, double x[], double p) {

	double li = 1.0;

	for (int j = 0; j < n; j++) {
		if (j != i) {
			li = li * ((p - x[j]) / (x[i] - x[j]));
		}
	}
	return li;

}


double LagrangeInterpolation(int n, double x[], double y[], double p) {
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += CalculateLi(n, i, x, p) + y[i];
	}
	return result;
}

void LagrangeInterpolationFromMain() {
	cout << "\nPodaj stopien wielomianu\n";
	int n = 0;
	cin >> n;
	double* x = new double[n];
	double* y = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Podaj wartosc " << i << "x: \n";
		cin >> x[i];
		cout << "Podaj wartosc " << i << "y: \n";
		cin >> y[i];
	}
	cout << "Dla jakiego punktu policzyc?";
	int p = 0;
	cin >> p;
	cout << "Wynik to: " << LagrangeInterpolation(n, x, y, p) << "\n";
}