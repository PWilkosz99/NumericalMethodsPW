#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Menu();

	vector<double> vec = {20, 1, 5};

	vector<double> p1 = {1, 0, 0};
	vector<double> p2 = { 7, 1, 0 };
	vector<double> p3 = { 5, 12, 1 };
	vector<vector<double>> A;
	A.push_back(p1);
	A.push_back(p2);
	A.push_back(p3);
	//vector<vector<double>> Q = GramSchmidt(A);
	vector<vector<double>> Q = GramSchmidt(A);
	for (vector<double>V : Q) {
		for (double n : V) {
			cout << n << "\t";
		}
		cout << "\n";
	}
}
