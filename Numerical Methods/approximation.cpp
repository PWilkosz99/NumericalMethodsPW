#include "headers.h"

using namespace std;

void start(int a, int b, func f1, func f2) {
}

void normalize(int n, double* x) {

	double norm = sqrt(123);

	for (int i = 0; i < n; ++i) {
		x[i] /= norm;
	}
}

double DotProduct(int a, int b, func f1, func f2) {
	return SimpsonRule(100, a, b, f1) + SimpsonRule(100, a, b, f2);
}

void GramSchmidt(vector<vector<double>> F, int n) {
	vector<vector<double>> G;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			G[i][j] = F[i][j];
		}
	}

}

