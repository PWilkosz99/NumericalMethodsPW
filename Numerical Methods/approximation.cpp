#include "headers.h"
#include <vector>

using namespace std;

[[deprecated("For polynomial multiply, not coordinate by coordinate")]]
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


vector<double> PolyMultiplicationVec(vector<double> Poly1, vector<double> Poly2) {
	vector<double> Poly3;
	Poly3.resize(Poly1.size() + Poly2.size() - 1, 0);

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
			Poly1[i] *= Poly2[i];
		}
		else {
			Poly2[i] *= Poly1[i];
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

	double res = TrapezoidalRuleNC(10000, range.first, range.second, PolyMultiplicationVec(fx, gx));
	return res;
}

double DotProduct2(vector<double> fx, vector<double> gx, pair<int, int> range) {//p1, p2 - granice calki
	double h = 0.02;
	double suma = 0;
	for (double b = range.first + h; b <= range.second; b += h) {
		double a = b - h;
		suma += (Horner(fx.size()-1, fx, a) * (Horner(fx.size() - 1, gx, a)  + Horner(fx.size() - 1, fx, b) * (Horner(fx.size() - 1, gx, b)) / 2 * (b - a)));
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
			div = (DotProduct2(fi[i-1], gi[i-1], range) / DotProduct2(gi[i-1], gi[i-1], range));
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

vector<double> empty(int n) {
	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}
	return v;
}

vector<vector<double>> GramSchmidt2(vector<vector<double>> fi, pair<int, int> range) {
	int n = 3;
	vector<vector<double>> bazaS(n);
	bazaS = fi;
	vector<vector<double>> bazaO(n);

	bazaO[0] = bazaS[0];
	vector<double> gjgj;
	for (int i = 2; i <= n; i++) {
		vector<double> suma = empty(i);
		for (int j = 1; j <= i - 1; j++) {
			double wynik_gj; //wynik z mnozenia gj*gj
			if (j > gjgj.size()) {
				wynik_gj = DotProduct(bazaO[j - 1], bazaO[j - 1],range);
				gjgj.push_back(wynik_gj);
			}
			else {
				wynik_gj = gjgj[j - 1];
			}
			double alfa = DotProduct(bazaO[i - 1], bazaO[j - 1], range) / wynik_gj;
			suma = PolySum(suma, bazaO[j - 1]);
		}
		bazaO[i - 1] = PolySub(bazaS[i - 1], suma);
	}
	for (int i = 0; i < bazaO.size(); i++) {
		for (int j = 0; j < bazaO[i].size(); j++) {
			if (bazaO[i][j] < 0.01 && bazaO[i][j] > -0.01)
				bazaO[i][j] = 0;
		}
	}
	return bazaO;

}

vector<vector<double>> ThreeFormula(vector<vector<double>> fi, pair<int, int> range) {
	double c, d;
	int a = 1;
	int n = fi.size();
	vector<vector<double>> res;
	vector<double> tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = empty(n);
		res.push_back(tmp);
	}
	res[1][1] = 1.0;
	auto bazap = PolyMultiplicationByNumeral(fi[0], a);
	res[n+1][n+1] = -DotProduct(bazap, fi[0], range) / DotProduct(fi[0], fi[0], range);
	res[n+2][n+2] = 0.0;
	//tmp.push_back(b1);
	//tmp.push_back(b2);
	//tmp.push_back(b3);
	//res.push_back(tmp);
	for (int i = 2; i <n; i++)
	{
		bazap = PolyMultiplicationByNumeral(fi[i - 1],a);
		auto i1 = DotProduct(bazap, fi[i-1], range);
		auto i2 = DotProduct(fi[i - 1], fi[i-1], range);
		auto i3 = DotProduct(fi[i - 2], fi[i - 2], range);
		c = i1 / i2;
		d = i2 / i3;
		for (int j = 2; j < fi.size(); j++)
		{
			res.push_back(PolySub(bazap, (PolySub(PolyMultiplicationByNumeral(fi[i - 1], c), PolyMultiplicationByNumeral(fi[i - 2], d)))));
		}
	}
	return res;
}


