#include "headers.h"

using namespace std;

vector<double> PolyMultiplication(vector<double> Poly1, vector<double> Poly2) {
	vector<double> Poly3;
	Poly3.resize(Poly1.size() + Poly2.size() - 1, 0);

	for (int i = 0; i != Poly1.size(); i++) {
		for (int j = 0; j != Poly2.size(); j++) {
			Poly3[i + j] += Poly1[i] * Poly2[j];
		}
	}
}

// 1 + x + x^2 + x^3
double DotProduct(vector<double> fx, vector<double> gx) {

	double res = TrapezoidalRuleNC(10000, -1, 1, PolyMultiplication(fx, gx));

	return res;
}


