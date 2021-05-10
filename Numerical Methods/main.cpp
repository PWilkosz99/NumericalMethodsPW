#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

int main() {
	//Menu();

	vector<double> vec = {20, 1, 5};
	cout << TrapezoidalRuleNC(1000, 0, 5, vec);
}
