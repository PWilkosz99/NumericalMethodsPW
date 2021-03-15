#include "headers.h"

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