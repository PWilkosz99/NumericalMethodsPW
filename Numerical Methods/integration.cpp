#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

typedef double(*func)(double);



double f1(double x) {
    return 0.4 * pow(x,4) + 5.0 * pow(x,3) + -6.0 * pow(x,2) + -2.0 * x + 55;
}

double f2(double x) {
    return exp(x * x) * (x - 1);
}

double f3(double x) {
	return x;
}

double TrapezoidalRule(vector<double> points, func f) {
	double result = 0.0;
	double dx;
	for (size_t i = 1; i < points.size() - 1; i++)
	{
		dx = points[i] - points[i - 1];
		result += (dx / 2.0) * f(points[i - 1]) + (dx / 2.0) * f(points[i - 1]);
	}
	return result;
}

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