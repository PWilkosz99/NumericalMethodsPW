#include "headers.h"
//#define SHOWSTEPS

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

double ModifiedEulerMethod(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta)
{
	double res = ys;
	double y0 = ys;
	double h = (xf - xs) / n;
	for (int i = 0; i < n; i++)
	{
		res += h * (f(alpha, beta, y0 + 0.5 * h * f(alpha, beta, y0)));
		y0 = res;
#ifdef SHOWSTEPS
		cout << "[" << i << "] " << res << "\n";
#endif
	}
	return res;
}

double RungeKutta4(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta)
{
	double res = ys;
	double h = (xf - xs) / n;
	double k1, k2, k3, k4;
	for (int i = 0; i < n; i++)
	{
		k1 = f(alpha, beta, res);
		k2 = f(alpha, beta, res + 0.5 * h * k1);
		k3 = f(alpha, beta, res + 0.5 * h * k2);
		k4 = f(alpha, beta, res + h * k3);

		res = res + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
#ifdef SHOWSTEPS
		cout << "[" << i << "] " << res << "\n";
#endif
	}
	return res;
}

void runable()
{
	cout << EulerMethod(10, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
	cout << HeunMethod(10, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
	cout << ModifiedEulerMethod(10, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
	cout << RungeKutta4(10, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
}