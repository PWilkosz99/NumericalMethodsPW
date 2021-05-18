#include "headers.h"

using namespace std;

class Polynomial {

public:
	func* f;
	vector <double> poly;

	Polynomial(vector<double> poly) {
		this->poly = poly;
	}

	Polynomial(func* f, vector<double> poly)
	{
		this->poly = poly;
		this->f = f;
	}

	double value(double x) {
		double sum = 0;
		for (int i = 0; i < poly.size(); i++)
		{
			sum += poly[i] * pow(x, i);
		}
		return sum;
	}
};

vector<double> PolyMultiplicationByNumeral(vector<double> Poly1, double nmr) {
	for (int i = 0; i < Poly1.size(); i++)
	{
		Poly1[i] *= nmr;
	}
	return Poly1;
}

double DotProduct(double s, pair<double, double> g, Polynomial poly1, Polynomial poly2) {
	double a;
	double sum = 0;
	for (double b = g.first + s; b <= g.second; b += s)//Trapezoidal Method
	{
		double a = b - s;
		sum += ((poly1.value(a) * poly2.value(a) + poly1.value(b) * poly2.value(b)) / 2) * (b - a);//p=1
	}
	return sum;
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
	if (Poly1.size() < Poly2.size())
	{
		for (int i = 0; i < Poly1.size(); i++)
		{
			Poly1[i] -= Poly2[i];
		}
		for (int i = Poly1.size(); i < Poly2.size(); i++)
		{
			Poly1.push_back(-Poly2[i]);
		}
	}
	else
	{
		for (int i = 0; i < Poly2.size(); i++)
		{
			Poly1[i] -= Poly2[i];
		}
	}
	return Poly1;
}

vector<double> FillByZero(int n) {
	vector<double> Poly(n);
	for (int i = 0; i < n; i++)
	{
		Poly[i] = 0.0;
	}
	return Poly;
}

vector<vector<double>> Round(vector<vector<double>> B) {//for nicer result
	for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
			if (B[i][j] < 0.025 && B[i][j] > -0.025)
			{
				B[i][j] = 0;
			}
		}
	}
	return B;
}

vector<double> VectOper(vector<double> Vec) {
	Vec.push_back(0);
	for (int i = Vec.size() - 1; i > 0; i--)
	{
		Vec[i] = Vec[i - 1];
	}
	Vec[0] = 0;
	return Vec;
}

vector<vector<double>> GramSchmidt(pair<double, double> g, func* FuncTab, int n) {
	double resGJ;
	vector<double> gj;
	vector<vector<double>> BS(n);
	vector<vector<double>> BO(n);
	for (int i = 0; i < n; i++) {
		BS[i] = FillByZero(n);
		BS[i][i] = 1;
	}
	BO[0] = BS[0];
	for (int i = 2; i <= n; i++) {
		vector<double> sum = FillByZero(i);
		for (int j = 1; j <= i - 1; j++) {
			if (j > gj.size()) {
				resGJ = DotProduct(0.001, g, Polynomial(FuncTab, BO[j - 1]), Polynomial(FuncTab, BO[j - 1]));
				gj.push_back(resGJ);
			}
			else
			{
				resGJ = gj[j - 1];
			}
			sum = PolySum(PolyMultiplicationByNumeral(BO[j - 1], (DotProduct(0.0001, g, Polynomial(FuncTab, BS[i - 1]), Polynomial(FuncTab, BO[j - 1])) / resGJ)), sum);
		}
		BO[i - 1] = PolySub(BS[i - 1], sum);
	}
	return Round(BO);
}

vector<vector<double>> ThreePartRule(pair<double, double> g, int n) {
	vector<double> pk1, pk2;
	vector<vector<double>> BO;
	double tmp;
	BO.push_back({ 1 });

	for (int i = 1; i <= n; i++)
	{
		pk1.clear();
		pk2.clear();

		pk1 = BO[i - 1];
		if (i > 1)
		{
			pk2 = BO[i - 2];
		}
		else
		{
			pk2 = { 0 };
		}

		tmp = -1 * (DotProduct(0.0001, g, Polynomial(VectOper(pk1)), Polynomial(pk1)) / DotProduct(0.0001, g, Polynomial(pk1), Polynomial(pk1)));
		vector<double> pol = PolySum(VectOper(pk1), PolyMultiplicationByNumeral(pk1, tmp));

		if (i > 1) {
			tmp = -1 * DotProduct(0.0001, g, Polynomial(pk1), Polynomial(pk1)) / DotProduct(0.0001, g, Polynomial(pk2), Polynomial(pk2));
			BO.push_back(PolySum(pol, PolyMultiplicationByNumeral(pk2, tmp)));
		}
		else {
			BO.push_back(pol);
		}
	}
	return Round(BO);
}


void ScalarTest(double h, pair<double, double> g, vector<vector<double>> baza, func* ftab) {
	double res;
	cout.precision(5);
	cout << fixed << "\n";
	for (int i = 0; i < baza.size() - 1; i++)
	{
		for (int j = i + 1; j < baza.size(); j++)
		{
			res = DotProduct(h, g, Polynomial(ftab, baza[i]), Polynomial(ftab, baza[j]));
			cout << "Polynomial " << i + 1 << " \u22C5" << " Polynomial" << j + 1 << " = " << res << "\n";//DOT
		}
	}
}

void PrintBase(vector<vector<double>> base) {
	for (int i = 0; i < base.size(); i++)
	{
		for (int j = 0; j < base[i].size(); j++)
		{
			cout << base[i][j] << "\t";
		}
		cout << "\n";
	}
}


void runable() {
	
}