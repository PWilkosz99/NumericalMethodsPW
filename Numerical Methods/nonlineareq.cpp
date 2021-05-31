#include "headers.h"

using namespace std;

double f1(double x) {
	return pow(x, 3) + pow(x, 2) - (3 * x) - 3;
}

double df1(double x) {
	return 3 * pow(x, 2) + (2 * x) - 3;
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

#define EPSILON 0.000001
#define EPSILONTEST 0.1
#define MAXITER 1000000


bool CheckIfThisResultExist(double res, vector<double> ResultList) {
	for (auto a : ResultList) {
		if (a > res) {
			if ((a-res)< EPSILONTEST) {
				return true;
			}
		}
		else {
			if ((res-a) < EPSILONTEST) {
				return true;
			}
		}
	}
	return false;
}

void PrintZeros(vector<double> zrs) {
	int i = 0;
	for (auto n : zrs) {
		cout << "x[" << i << "] = " << n << "\n";
		i++;
	}
}

double NewtonRaphsonSingle(func f, func df, double x)
{
	double h = f(x) / df(x);
	while (abs(h) >= EPSILON)
	{
		h = f(x) / df(x);
		x = x - h;
	}
	return x;
}

vector<double> NewtonRaphson(func f, func df, double x)
{
	double EXT = 0.1;
	int EXTtimes = 0;

	vector<double> res;
	int iter = 0;
	double h = f(x) / df(x);
	while (iter < MAXITER)
	{
		h = f(x) / df(x);
		x = x - h;

		if (abs(h) <= EPSILON) {
			if (!CheckIfThisResultExist(x, res)) {
				res.push_back(x);
				EXTtimes = 0;
			}
			else {
				x += EXT * EXTtimes;
				EXTtimes++;
			}
		}
		iter++;
	}
	return res;
}

double SecantMethod(func f, double x1, double x2)
{
	double xm;
	double fk;
	double x0;
	if (f(x1) * f(x2) < 0) {
		do {
			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
			fk = f(x1) * f(x0);

			x1 = x2;
			x2 = x0;

			if (fk == 0)
			{
				break;
			}
			else 
			{
				xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
			}
		} while (fabs(xm - x0) >= EPSILON);
		return x0;
	}
	else 
	{
		cout << "Brak rozwiazan dla przedzialu" << "[" << x1 << "]" << "\n";
		throw "Brak rozwiazan";
	}
}

void runable() {
	//PrintZeros(NewtonRaphson(f1, df1, -10));
	cout<<SecantMethod(f1, -100, 120);
}

//1
//- 1.73205
//- 1
//1.73205
//2
//-1.41421
//1.41421
//3
//0.000133735
//4
//-1.22364
//1.22364