#include "headers.h"
#include <iostream>

using namespace std;



/// <summary>
/// [LAB 1|2 ZAD 3]
/// </summary>
/// <param name="n"></param>
/// <param name="i"></param>
/// <param name="x"></param>
/// <param name="p"></param>
/// <returns></returns>
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

/// <summary>
/// [LAB 1|2 ZAD 4]
/// </summary>
/// <param name="n"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="p"></param>
/// <returns></returns>
double LagrangeInterpolation(int n, double x[], double y[], double p) {
	double result = 0.0;
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

/// <summary>
/// Testy dla danych z pliku csv
/// </summary>
void LagrangeInteprolationTest() {
	double x_i[] = { -2, -1, 0, 1, 2 };
	double y_i[] = { 5 ,-2, 4, -7, 2 };
	int n = 5;
	double p = -0.5;

	cout << "Wynik dla danych polynomial-3-v2.csv:\n";
	cout << LagrangeInterpolation(n, x_i, y_i, p) << "\n\n";
}

/// <summary>
/// Obliczanie ilorazów ró¿nicowych
/// </summary>
/// <param name="n">iloœæ parametrów</param>
/// <param name="x">xi</param>
/// <param name="y">yi</param>
/// <returns>Tablica paramerow b_k</returns>
double* CalculateBK(int n, double x[], double y[]) {

	double** M = new double* [n]; //macierz 3d
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[i + 1];//trojkatna
		M[i][0] = y[i];
	}

	for (int i = 1; i < n; i++) {//obieg po przekatniej
		for (int j = 1; j < i; j++) {
			M[i][j] = (M[i][j - 1] - M[i - 1][j - 1]) / (x[i] - x[i - j]);
		}
	}

	double* b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = M[i][i]; //przekatna macierzy
	}
	return b;
}

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


/// <summary>
/// Testy dla danych z pliku csv
/// </summary>
void CalculateBKTest() {

	cout << "Wynik dla danych polynomial-4-v2.csv:\n";
	//1
	double x_i1[] = { -1, -0.8, -0.4, -0.2, -0.1, 0, 0.4, 0.5, 0.8, 1 };
	double y_i1[] = { 0.1, 0.2, 5.3, 4.4, 2.5, 0.6, 3.7, 5.8, 4.9, 12 };
	int n1 = 10;
	double* bk1 = new double[n1];
	bk1 = CalculateBK(n1, x_i1, y_i1);
	cout << "Dane 1:\n";
	for (int i = 0; i < n1; i++)
	{
		cout << bk1[i] << "\n";
	}

	//2
	cout << "\n\n";
	double x_i2[] = { -1, -0.4, -0.2, -0.1, 0.4, 1 };
	double y_i2[] = { -.1, 5.3, 4.4, 2.5, 3.7, 12 };
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
	double x_i4[] = { -1, -0.4, 0.5, 0.8 };
	double y_i4[] = { 0.1, 3.7, 5.8, 4.9 };
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

/// <summary>
/// Zamiana wspó³cznynników postaci Newtnoa na postaæ naturaln¹
/// </summary>
/// <param name="n">Iloœæ parametrów</param>
/// <param name="b">Wspó³czynniki bk postaci Newtona</param>
/// <param name="x"></param>
/// <returns></returns>
double* BKToNaturalForm(int n, double b[], double x[]){
	double* nat = new double[n];
	nat[n - 1] = b[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		nat[i] = b[i];
		for (int j = i; j < n - 1; j++) {
			nat[j] -= x[j] * nat[j] + 1;
		}
	}
	return nat;
}


void BKToNaturalFormTest() {

	cout << "Wynik dla danych polynomial-4-v2.csv:\n";
	//1
	double x_i1[] = { -1, -0.8, -0.4, -0.2, -0.1, 0, 0.4, 0.5, 0.8, 1 };
	double y_i1[] = { 0.1, 0.2, 5.3, 4.4, 2.5, 0.6, 3.7, 5.8, 4.9, 12 };
	int n1 = 10;
	double* bk1 = new double[n1];
	bk1 = CalculateBK(n1, x_i1, y_i1);
	double* nat1 = new double[n1];
	nat1 = BKToNaturalForm(n1, bk1, x_i1);
	cout << "Dane 1:\n";
	for (int i = 0; i < n1; i++)
	{
		cout << nat1[i] << "\n";
	}

	//2
	cout << "\n\n";
	double x_i2[] = { -1, -0.4, -0.2, -0.1, 0.4, 1 };
	double y_i2[] = { -.1, 5.3, 4.4, 2.5, 3.7, 12 };
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
	double x_i4[] = { -1, -0.4, 0.5, 0.8 };
	double y_i4[] = { 0.1, 3.7, 5.8, 4.9 };
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


/*
polynomial - 3 - v2.csv - dane do wyznaczania wielomianu Lagrange'a, przyk³adowe wyniki: x = -0.500000    y = 2.820313
polynomial - 4 - v2.csv - dane do obliczania ilorazów ró¿nicowych - wspó³czynników b_k dla postaci Newtona, przyk³adowe wyniki : b = 0.100000 0.500000 20.416667 - 61.458333 37.202381 148.809524 - 240.575397 170.134649 - 15.538530 - 38.732206; x = 0.200000     y = -0.215715
Postaæ naturalna dla powy¿szego wiel.w postaci Newtona : a = 0.600000 - 16.098312 42.478886 123.756241 - 135.092299 - 252.016117 144.587708 189.040394 - 46.524295 - 38.732206
*/