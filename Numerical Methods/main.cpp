#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Definicje algorytmów znajduj¹ siê w pliku approximation.cpp

	//Algorytm Grama-Schmidta
	vector<double> p1 = { 1, 0, 0 };
	vector<double> p2 = { 1, 1, 0 };
	vector<double> p3 = { 1, 1, 1 };
	vector<vector<double>> A;
	A.push_back(p1);
	A.push_back(p2);
	A.push_back(p3);
	vector<vector<double>> Q = GramSchmidt(A, make_pair(-1, 1));
	for (vector<double>V : Q) {
		for (double n : V) {
			cout << n << "\t";
		}
		cout << "\n";
	}
	cout << "Wartoœci iloczynow skalarnych:\n";
	cout << iloczynSkalarny(Q[0], Q[1])<< "\n";
	cout << DotProduct(Q[1], Q[2], make_pair(-1, 1)) << "\n";
	cout << DotProduct(Q[0], Q[2], make_pair(-1, 1)) << "\n";

	cout << "\n\n";

	//Regu³a trójcz³onowa
	//Wektory liniowo zale¿ne
	p1 = { 1, 1, 2 };
	p2 = { 18, 9, 3 };
	p3 = { 6, 3, 1 };
	A.clear();
	A.push_back(p1);
	A.push_back(p2);
	A.push_back(p3);
	vector<vector<double>> Q2 = ThreeFormula(A, make_pair(-1, 1));
	for (vector<double>V : Q2) {
		for (double n : V) {
			cout << n << "\t";
		}
		cout << "\n";
	}

	cout << "Wartoœci iloczynow skalarnych:\n";
	cout << DotProduct(Q2[0], Q2[1], make_pair(1, -1)) << "\n";
	cout << DotProduct(Q2[1], Q2[2], make_pair(1, -1)) << "\n";
	cout << DotProduct(Q2[0], Q2[2], make_pair(1, -1)) << "\n";
}
