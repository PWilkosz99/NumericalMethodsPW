#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"

using namespace std;

//Definicje funkcji znajdują się w pliku differentialeq.cpp

int main() {
	cout << EulerMethod(1000, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
	cout << HeunMethod(1000, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
	cout << ModifiedEulerMethod(1000, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
	cout << RungeKutta4(1000, 0, 300, 1200, ThermalConductivityEQ, -1E-12, 0) << endl;
}
