#include <iostream>
#include <math.h>

using namespace std;

typedef double(*func)(double);

double f1(double x) {
    return x * x * sin(x) * sin(x) * sin(x);
}

double f2(double x) {
    return exp(x * x) * (x - 1);
}

double TrapezoidalRule(double x, func f) {
    return f(x);
}