#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Menu();

	vector<double> vec = {20, 1, 5};

	vector<double> p1 = {20, 1, 5};
	vector<double> p2 = {20, 1, 5, 5 , 2, 6,};

	cout << DotProduct(p1, p2);
}
