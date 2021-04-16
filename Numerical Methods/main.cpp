#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>


using namespace std;

vector<double> loadPoints(ifstream& plik) {
	vector<double> points;
	int n;
	plik >> n;
	//cout << n;
	double tmp;
	double* A = new double[n];
	for (int i = 0; i < n; ++i) {
		plik >> tmp;;
		points.push_back(tmp);
	}
	return points;
}


int main() {
	//Menu();

	ifstream file1("data\\points1.txt");
	vector<double> A = loadPoints(file1);
	file1.close();

	//cout << TrapezoidalRule(A, f1);

	ifstream file2("data\\points2.txt");
	vector<double> B = loadPoints(file2);
	file2.close();

	cout << TrapezoidalRule(B, f1);

}
