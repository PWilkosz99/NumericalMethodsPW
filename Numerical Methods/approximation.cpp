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
double DotProduct(vector<double> fx, vector<double> gx) {

	double res = TrapezoidalRuleNC(10000, -1, 1, PolyMultiplication(fx, gx));

	return res;
}

vector<vector<double>> GramSchmidt(vector<vector<double>> fi) {
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
			div = (DotProduct(fi[i-1], gi[i-1]) / DotProduct(gi[i-1], gi[i-1]));
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

vector<vector<double>> ThreeFormula(vector<vector<double>> fi) {
	double c, d;
	int a = 1;

	vector<vector<double>> baza;
	vector<double> tmp;
	tmp.push_back(1.0);
	auto bazap = PolyMultiplicationByNumeral(baza[0], a);
	//baza n+1
	auto b1 = -DotProduct(bazap, baza[1]) / DotProduct(baza[1], baza[1]);
	auto baza2 = 1.0;
	for (int i = 0; 3 < fi.size(); i++)
	{
		//bazap = razyx(baza[:, i - 1])
		auto i1 = DotProduct(bazap, baza[i-1]);
		auto i2 = DotProduct(baza[i - 1], baza[i-1]);
		auto i3 = DotProduct(baza[i - 2], baza[i - 2]);
		c = i1 / i2;
		d = i2 / i3;
		for (int j = 1; j < fi.size(); j++)
		{
			baza[i] = PolySub(bazap,(PolySub(PolyMultiplicationByNumeral(baza[i - 1], c),PolyMultiplicationByNumeral(baza[i - 2], d))));
		}
	}
	return baza;
}


