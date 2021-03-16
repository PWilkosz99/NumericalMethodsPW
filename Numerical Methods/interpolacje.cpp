#include "headers.h"
#include <iostream>

using namespace std;

// [LAB 1|2 ZAD 3]


double CalculateLi(int n, int i, double x[], double p) {

	double li = 1.0;

	for (int j = 0; j < n; j++) {
		if (j == i) {
			continue;
		}
		li = li * ((p - x[j]) / (x[i] - x[j]));
	}
	return li;

}

// [LAB 1|2 ZAD 4]
double LagrangeInterpolation(int n, double x[], double y[], double p) {
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += CalculateLi(n, i, x, p) * y[i];
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
	double p = 0;
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

double* CalculateBK(int n, double x[], double y[]) {

	double** M = new double* [n]; //macierz 3d
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[i + 1];
		M[i][0] = y[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			M[i][j] = (M[i][j - 1] - M[i - 1][j - 1]) / (x[i] - x[i - j]);
		}
	}

	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = M[i][i]; //przekatna macierzy
	}

	return b;
}

//bk - ilorazy roznicowe
void CalculateBKFromMain() {
	int n;
	cout << "Podaj ilosc punktów: ";
	cin >> n;
	double* x = new double[n];
	double* y = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "Podaj wartosc " << i << "x: \n";
		cin >> x[i];
		cout << "Podaj wartosc " << i << "y: \n";
		cin >> y[i];
	}
	double* bk = new double[n];
	bk = CalculateBK(n, x, y);

	for (int i = 0; i < n; i++)
	{
		cout << bk[i] << "\n";
	}
}


void CalculateBKTest() {

	cout << "Wynik dla danych polynomial-4-v2.csv:\n";
	//1
	double x_i1[] = { -1, -0.8, -0.4, -0.2, -0.1, 0, 0.4, 0.5, 0.8, 1};
	double y_i1[] = { 0.1, 0.2, 5.3, 4.4, 2.5, 0.6, 3.7, 5.8, 4.9, 12};
	int n1 = 10;
	double* bk1 = new double[n1];
	bk1 = CalculateBK(n1, x_i1, y_i1);
	cout << "Dane 1:\n";
	for (int i = 0; i <n1; i++)
	{
		cout<<bk1[i]<<"\n";
	}

	//2
	cout << "\n\n";
	double x_i2[] = { -1, -0.4, -0.2, -0.1, 0.4, 1};
	double y_i2[] = { -.1, 5.3, 4.4, 2.5, 3.7, 12};
	int n2 = 6;
	double* bk2 = new double[n2];
	bk2 = CalculateBK(n2, x_i2, y_i2);
	cout << "Dane 2:\n";
	for (int i = 0; i < n2; i++)
	{
		cout << bk2[i] << "\n";
	}
	cout << "\n\n";

	//Dane 3 s¹ takie same jak 1

	//4
	double x_i4[] = { -1, -0.4, 0.5, 0.8};
	double y_i4[] = { 0.1, 3.7, 5.8, 4.9};
	int n4 = 4;
	double* bk4 = new double[n4];
	bk4 = CalculateBK(n4, x_i4, y_i4);
	cout << "Dane 4:\n";
	for (int i = 0; i < n4; i++)
	{
		cout << bk4[i] << "\n";
	}
	cout << "\n\n";
}