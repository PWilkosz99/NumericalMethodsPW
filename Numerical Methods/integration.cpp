#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include "headers.h"

using namespace std;

typedef double(*func)(double);

double f4(double x) {
	return x * x * pow(sin(x), 3);
}

double f5(double x) {
	return exp(x * x) * (x - 1);
}

double TrapezoidalRule(vector<double> points, func f) {
	double result = 0.0;
	double dx;
	for (size_t i = 1; i < points.size() - 1; i++)
	{
		dx = points[i] - points[i - 1];
		result += (dx / 2.0) * f(points[i - 1]) + (dx / 2.0) * f(points[i]);
	}
	return result;
}

//ZAD1
double TrapezoidalRule(vector<double> points, vector<double> coefficients) {
	double result = 0.0;
	double dx;
	int n = coefficients.size();
	for (size_t i = 1; i < points.size() - 1; i++)
	{
		dx = points[i] - points[i - 1];
		result += (dx / 2.0) * Horner(n, coefficients, points[i - 1]) + (dx / 2.0) * Horner(n, coefficients, points[i]);
	}
	return result;
}

double TrapezoidalRule(double n, double a, double b, vector<double> coefficients) {
	double result = 0.0;
	double pos = 0.0;
	double dx = (b - a) / n;
	int nj = coefficients.size();
	for (size_t i = 0; i < n; i++)
	{
		result += (dx / 2.0) * Horner(nj, coefficients, pos) + (dx / 2.0) * Horner(nj, coefficients, pos+dx);
		pos += dx;
	}
	return result;
}

//ZAD2B
double SimpsonRule(double n, double a, double b, func f) {
	double x;
	double s1 = 0.0;
	double s2 = 0.0;

	double dx = (b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		x = a + i * dx;
		s2 += f(x - dx / 2);
		if (i < n)
		{
			s1 += f(x);
		}
	}
	return dx / 6 * (f(a) + f(b) + 2 * s1 + 4 * s2);
}

//double SimpsonRule(double n, double a, double b, func f) {
//	double x;
//	double s1 = 0.0;
//	double s2 = 0.0;
//
//	double dx = (b - a) / n;
//	for (int i = 1; i <= n; i++)
//	{
//		x = a + i * dx;
//		s2 += f(x - dx / 2);
//		if (i < n)
//		{
//			s1 += f(x);
//		}
//	}
//	return dx / 6 * (f(a) + f(b) + 2 * s1 + 4 * s2);
//	}

//ZAD2A
double TrapezoidalRuleNC(double n, double a, double b, func f) {
	double res = 0.0;
	double x1;
	double x2;
	double dx = (b - a) / n;
	for (int i = 0; i < n; i++)
	{
		x1 = a + i * dx;
		x2 = a + (i + 1.0) * dx;

		res += 0.5 * (x2 - x1) * (f(x1) + f(x2));
	}
	return res;
}

//ZAD2A
double TrapezoidalRuleNC(double n, double a, double b, vector<double> coefficients) {
	double res = 0.0;
	double x1;
	double x2;
	double dx = (b - a) / n;
	int nj = coefficients.size()-1;
	for (int i = 0; i < n; i++)
	{
		x1 = a + i * dx;
		x2 = a + (i + 1.0) * dx;

		res += 0.5 * (x2 - x1) * (Horner(nj, coefficients, x1) + Horner(nj, coefficients, x2));
	}
	return res;
}

//LAB7
double GaussLegendre(int n, double x1, double x2, func f) {
	if (x1 > x2)
	{
		double tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	try {
		n++;//ze wzgledu na nomenklature z prezentacji
		if (n <= 5) {
			double* A = new double[n];
			double* X = new double[n];

			ifstream file;

			switch (n) {
			case 2://ilosc wezlow
				file.open("data\\abscissae2.txt");
				break;
			case 3:
				file.open("data\\abscissae3.txt");
				break;
			case 4:
				file.open("data\\abscissae4.txt");
				break;
			case 5:
				file.open("data\\abscissae5.txt");
				break;
			}

			for (int i = 0; i < n; i++)
			{
				file >> X[i];
				file >> A[i];
			}

			file.close();

			double a = (x2 - x1) * 0.5;
			double b = (x2 + x1) * 0.5;
			double S = 0;
			double t;

			for (int i = 0; i < n; ++i) {
				t = b + a * X[i];
				S += A[i] * f(t);
			}
			return a * S;
		}
		else
		{
			throw "Funkcja dzia³a dla mniejszego od 5";
		}
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
}