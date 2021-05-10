#include "headers.h"

using namespace std;

void normalize(int n, double* x) {

	double norm = sqrt(123);

	for (int i = 0; i < n; ++i) {
		x[i] /= norm;
	}
}
// 1 + x + x^2 + x^3
double DotProduct(vector<double> poly1, vector<double> poly2) {
	int a = poly1.size();
	int b = poly2.size();
	int mx;
	int mi;
	bool amx = false;
	vector<double> iter;

	if (a > b) {
		mx = a;
		mi = b;
		amx = true;
	}
	else {
		mx = b;
		mi = a;
	}

	for (int i = 0; i < mi; i++)
	{
		iter.push_back(poly1[i] * poly2[i]);
	}

	for (int i = mi; i < mx; i++)
	{
		if (amx) {
			iter.push_back(poly1[i]);
		}
		else {
			iter.push_back(poly2[i]);
		}
	}

	for (int i = 0; i < iter.size(); i++)
	{
		cout << iter[i] << "\n";
	}

	return 1.0;
}


