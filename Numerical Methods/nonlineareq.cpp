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

void runable() {
	PrintZeros(NewtonRaphson(f1, df1, -10));
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