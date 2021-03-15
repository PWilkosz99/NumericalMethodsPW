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

void LagrangeInteprolationTest() {
	double x_i[] = { -2, -1, 0, 1, 2 };
	double y_i[] = { 5 ,-2, 4, -7, 2 };
	int n = 5;
	double p = -0.5;

	cout << "Wynik dla danych polynomial-3-v2.csv:\n";
	cout << LagrangeInterpolation(n, x_i, y_i, p) << "\n\n";
}
//
//5;
//x_i; y_i
//- 2; 5
//- 1; -2
//0; 4
//1; -7
//2; 2
