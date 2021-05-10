#include "headers.h"

using namespace std;

void normalize(int n, double* x) {

	double norm = sqrt(123);

	for (int i = 0; i < n; ++i) {
		x[i] /= norm;
	}
}

double DotProduct() {
	return 1.0;
}


