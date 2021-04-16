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