#include "headers.h"
#define SHOWSTEPS

using namespace std;

typedef double(*funcTherm)(double, double, double);

double ThermalConductivityEQ(double alpha, double beta, double T)
{
	return alpha * (pow(T, 4) - beta);
}

double EulerMethod(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta)
{
	double res = ys;
	double h = (xf - xs) / n;
	for (int i = 0; i < n; i++)
	{
		res += h * f(alpha, beta, res);
#ifdef SHOWSTEPS
		cout << "[" << i << "] " << res << "\n";
#endif

	}
	return res;
}

double HeunMethod(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta)
{
	double res = ys;
	double y0 = ys;
	double h = (xf - xs) / n;
	for (int i = 0; i < n; i++)
	{
		res += 0.5 * h * (f(alpha, beta, y0) + f(alpha, beta, y0 + h * f(alpha, beta, y0)));
		y0 = res;
#ifdef SHOWSTEPS
		cout << "[" << i << "] " << res << "\n";
#endif
	}
	return res;
}

void runable()
{
	cout << EulerMethod(10, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0);
	cout << HeunMethod(10, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0);
}