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
	if (Poly1.size() < Poly2.size()) {
		for (int i = 0; i < Poly1.size(); i++)
		{
			Poly1[i] -= Poly2[i];
		}
		for (int i = Poly1.size(); i < Poly2.size(); i++)
		{
			Poly1.push_back(-Poly2[i]);
		}
	}
	else {
		for (int i = 0; i < Poly2.size(); i++)
		{
			Poly1[i] -= Poly2[i];
		}
	}
	return Poly1;
}

// 1 + x + x^2 + x^3
double DotProduct(vector<double> fx, vector<double> gx, pair<int, int> range) {

	double res = TrapezoidalRuleNC(10000, range.first, range.second, PolyMultiplication(fx, gx));

	return res;
}

double iloczynSkalarny(vector<double> w1, vector<double> w2) { //p1, p2 - granice calki
	double h = 0.002;
	double p1 = -1;
	double p2 = 1;

	double suma = 0;
	for (double b = p1 + h; b <= p2; b += h) {
		double a = b - h;
		suma += (w1[a] * w2[a]+ w1[b] * w2[b] / 2 * (b - a));
	}
	return suma;
}

vector<vector<double>> GramSchmidt(vector<vector<double>> fi, pair<int, int> range) {
	double div;
	vector<double> sumvec;
	vector<vector<double>> gi;
	bool opr = false;
	//gi.resize(fi.size());
	for (int i = 0; i < fi.size(); i++)
	{
		if (i == 0) {
			gi.push_back(fi[i]);
			continue;
		}
		for (int j = 0; j < i; j++)
		{
			opr = true;
			div = (DotProduct(fi[i-1], gi[i-1], range) / DotProduct(gi[i-1], gi[i-1], range));
			sumvec = PolySum(PolyMultiplicationByNumeral(gi[j], div), sumvec);
		}
		if (opr) {
			gi.push_back(PolySub(fi[i], sumvec));
			sumvec.clear();
			opr = false;
		}
	}
	return gi;
}

vector<vector<double>> ThreeFormula(vector<vector<double>> fi, pair<int, int> range) {
	double c, d;
	int a = 1;
	int n = fi.size();
	vector<vector<double>> baza;
	vector<double> tmp;
	double b1 = 1.0;
	auto bazap = PolyMultiplicationByNumeral(fi[0], a);
	double b2 = -DotProduct(bazap, fi[0], range) / DotProduct(fi[0], fi[0], range);
	double b3 = 1.0;
	tmp.push_back(b1);
	tmp.push_back(b2);
	tmp.push_back(b3);
	baza.push_back(tmp);
	for (int i = 3; i <n+1; i++)
	{
		bazap = PolyMultiplicationByNumeral(fi[i - 1],a);
		auto i1 = DotProduct(bazap, fi[i-1], range);
		auto i2 = DotProduct(fi[i - 1], fi[i-1], range);
		auto i3 = DotProduct(fi[i - 2], fi[i - 2], range);
		c = i1 / i2;
		d = i2 / i3;
		for (int j = 1; j < fi.size(); j++)
		{
			baza.push_back(PolySub(bazap,(PolySub(PolyMultiplicationByNumeral(fi[i - 1], c),PolyMultiplicationByNumeral(fi[i - 2], d)))));
		}
	}
	return baza;
}


