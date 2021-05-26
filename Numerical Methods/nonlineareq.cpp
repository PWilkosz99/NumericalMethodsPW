#include "headers.h"

double f1(double x) {
	return pow(x, 3) + pow(x, 2) - (3 * x);
}

double df1(double x) {
	return 3 * pow(x, 2) + 2 * x - 3;
}

double f2(double x) {
	return pow(x, 2) - 2;
}

double df2(double x) {
	return 2 * x;
}

double f3(double x) {
	return sin(pow(x, 2)) - pow(x, 2);
}

double df3(double x) {
	return 2 * x * (cos(pow(x, 2)) - 1);
}

double f4(double x) {
	return sin(pow(x, 2)) - pow(x, 2) + 0.5;
}

double df4(double x) {
	return 2 * x * (cos(pow(x, 2)) - 1);
}