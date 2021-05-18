#include "headers.h"
#include <vector>

using namespace std;

class Polynomial {

public:
	func* f;
	vector <double> poly;

	Polynomial(func* f, vector<double> poly)
	{
		this->poly = poly;
		this->f = f;
	}

	double value(double x)
	{
		double sum = 0;
		for (int i = 0; i < poly.size(); i++)
		{
			sum += poly[i] * f[i](x);
		}
		return sum;
	}
};

double x0(double x) { return 1; }
double x1(double x) { return x; }
double x2(double x) { return pow(x, 2); }
double x3(double x) { return pow(x, 3); }
double x4(double x) { return pow(x, 4); }
double x5(double x) { return pow(x, 5); }
double x6(double x) { return pow(x, 6); }
double x7(double x) { return pow(x, 7); }
double x8(double x) { return pow(x, 8); }
double x9(double x) { return pow(x, 9); }

vector<double> PolyMultiplicationByNumeral(vector<double> Poly1, double nmr) {
	for (int i = 0; i < Poly1.size(); i++)
	{
		Poly1[i] *= nmr;
	}
	return Poly1;
}

double DotProduct(double s, pair<double,double> g, Polynomial poly1, Polynomial poly2) {
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

vector<vector<double>> GramSchmidt(pair<double,double> g, func* FuncTab, int n) {
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
	for (int i = 0; i < BO.size(); i++) 
	{
		for (int j = 0; j < BO[i].size(); j++) 
		{
			if (BO[i][j] < 0.01 && BO[i][j] > -0.01) 
			{
				BO[i][j] = 0;
			}
		}
	}
	return BO;
}


void testBazy(double h, pair<double, double> g, vector<vector<double>> baza, double (*ftab[])(double)) {
	cout << "Baza ortogonalna" << endl;
	for (int i = 0; i < baza.size(); i++) {
		for (int j = 0; j < baza[i].size(); j++) {
			cout << baza[i][j] << " ";


		}
		cout << endl;
	}
	for (int i = 0; i < baza.size() - 1; i++) {
		for (int j = i + 1; j < baza.size(); j++) {
			double iloczyn = DotProduct(h, g, Polynomial(ftab, baza[i]), Polynomial(ftab, baza[j]));
			cout << "Iloczyn dla wielomianow " << i + 1 << " i " << j + 1 << " = " << iloczyn << endl;
		}
	}
}


void runable() {
	func baza[5];
	baza[0] = x0;
	baza[1] = x1;
	baza[2] = x2;
	baza[3] = x3;
	baza[4] = x4;

	vector<vector<double>> bazav = GramSchmidt(make_pair(-1,1), baza, 5);
	testBazy(0.01, make_pair(-1, 1), bazav, baza);
}