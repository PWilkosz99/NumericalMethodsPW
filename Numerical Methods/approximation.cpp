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
	return Poly3;
}

vector<double> PolyMultiplicationByNumeral(vector<double> Poly1, int nmr) {
	for (int i = 0; i < Poly1.size(); i++)
	{
		Poly1[i] *= nmr;
	}
	return Poly1;
}

vector<double> PolySum(vector<double> Poly1, vector<double>Poly2) {
	bool mxa = false;
	int mx = 0;
	int mi = 0;
	if (Poly1.size() > Poly2.size()) {
		mxa = true;
		mx = Poly1.size();
		mi = Poly2.size();
	}
	else
	{
		mx = Poly2.size();
		mi = Poly1.size();
	}

	for (int i = 0; i < mi; i++)
	{
		if (mxa) {
			Poly1[i] += Poly2[i];
		}
		else {
			Poly2[i] += Poly1[i];
		}
	}

	if (mxa) {
		return Poly1;
	}
	else
	{
		return Poly2;
	}
}

vector<double> PolySub(vector<double> Poly1, vector<double>Poly2) {
	bool mxa = false;
	int mx = 0;
	int mi = 0;
	if (Poly1.size() > Poly2.size()) {
		mxa = true;
		mx = Poly1.size();
		mi = Poly2.size();
	}
	else
	{
		mx = Poly2.size();
		mi = Poly1.size();
	}

	for (int i = 0; i < mi; i++)
	{
		if (mxa) {
			Poly1[i] -= Poly2[i];
		}
		else {
			Poly2[i] -= Poly1[i];
		}
	}

	if (mxa) {
		return Poly1;
	}
	else
	{
		return Poly2;
	}
}

// 1 + x + x^2 + x^3
double DotProduct(vector<double> fx, vector<double> gx) {

	double res = TrapezoidalRuleNC(10000, -1, 1, PolyMultiplication(fx, gx));

	return res;
}

vector<vector<double>> GramSchmidt(vector<vector<double>> fi) {
	//int i = fi.size();
	int k = 0;
	double sum;
	vector<double> sumvec;
	double div;
	vector<vector<double>> gi;
	for (int i = 0; i < fi.size(); i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			vector<double> tmp;
			//tmp.push_back();
			div = (DotProduct(fi[i], gi[i]) / DotProduct(gi[i], gi[i]));
			sumvec = PolySum(PolyMultiplicationByNumeral(gi[j], div), sumvec);
		}
	}
	return gi;//tmp
}


