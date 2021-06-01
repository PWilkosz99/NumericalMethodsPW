#include <iostream>
#include <locale.h>
#include <fstream>
#include "headers.h"
#include <vector>

using namespace std;

//Definicje funkcji znajdują się w pliku nonlinear.cpp

int main() {
	try
	{
		//Newton Raphson | ZAD 1a
		PrintZeros(NewtonRaphson(f1, df1, -10)); cout << endl;
		PrintZeros(NewtonRaphson(f2, df2, -10)); cout << endl;
		PrintZeros(NewtonRaphson(f3, df3, -10)); cout << endl;
		PrintZeros(NewtonRaphson(f4, df4, -10)); cout << endl;
		////Newtor Raphson z liczeniem pochodnej | ZAD 1b
		PrintZeros(NewtonRaphsonWithDerivative(f1, -10)); cout << endl;
		PrintZeros(NewtonRaphsonWithDerivative(f2, -10)); cout << endl;
		PrintZeros(NewtonRaphsonWithDerivative(f3, -10)); cout << endl;
		PrintZeros(NewtonRaphsonWithDerivative(f4, -10)); cout << endl << endl;
		//OPIS:
		// W funkcjach zgodnie z wytycznymi z zajęć nie używam dzielenia przez wielomian, 
		// powoduj to, że w celu uzyskania kilku mejsc zerowych muszę modyfikować zakres.
		// W funkcjach NewtonRaphson() oraz NewtonRaphsonWithDerivative() wyniki uzyskuję poprzez
		// uruchomienie algorytmu poprzez określoną liczbę iteracji, z jednoczesną modyfikacją zakresu obliczeń.
		// Z racji iż nie jest to optymalne rozwiązanie oraz z powodu, że dla metod siecznych, połowienia oraz fałszywej lini
		// skomplikowane jest znaleźenie stałej zależności wpływającej na zakres w oczekiwany sposób powodujący uzyskanie różnych pierwiastków
		// obliczenia dokonuję z ręcznym wprowadzeniu zakresu na podstawie wyznaczonych empirycznie wykresów.
		//PORÓWNANIE:
		// Obie z metod zwracają podobne wyniki(te same w przybliżeniu do 4 liczby poprzecinku),
		// ze wzgledu na dodatkowe wyliczanie pochodnej, a wiec dodatkowy podzial koszt obliczeniowy
		// dla metody z wyliczaniem pochodnej jest wyzszy co przeklada sie na niższą wydajność algorytmu

		//Metoda siecznych | ZAD 2

		cout << SecantMethod(f1, -10, 12) << "\t"; //f1 : -1.73205         
		cout << SecantMethod(f1, -10, 10) << "\t"; //f1 : -1
		cout << SecantMethod(f1, -10, 5) << "\n"; //f1 : 1.73205
		cout << SecantMethod(f2, -3, 0) << "\t"; //f2 : -1.41421
		cout << SecantMethod(f2, -1, 2) << "\n"; //f2 : 1.41421
		//cout << SecantMethod(f3, 0.1, -0.1) << "\n"; //f3 : Brak mozliwosci rozwiazania ta metoda: zadne f(x1)*f(x2) nie przyjmie wartosci ujemnych, nie spelnione warunki siecznych
		cout << SecantMethod(f4, -2, 0) << "\t"; //f4 : -1.22364
		cout << SecantMethod(f4, 0, 2) << "\n\n\n"; //f4 : 1.22364

		//Regula Falsi

		cout << RegulaFalsi(f1, -10, 12) << "\t"; //f1 : -1.73205         
		cout << RegulaFalsi(f1, -10, 10) << "\t"; //f1 : -1
		cout << RegulaFalsi(f1, -10, 5) << "\n"; //f1 : 1.73205
		cout << RegulaFalsi(f2, -3, 0) << "\t"; //f2 : -1.41421
		cout << RegulaFalsi(f2, -1, 2) << "\n"; //f2 : 1.41421
		//cout << RegulaFalsi(f3, -1, 3) << "\n"; //f3 : Brak mozliwosci rozwiazania ta metoda: zadne f(x1)*f(x2) nie przyjmie wartosci ujemnych lub zerowych, nie spelnione warunki siecznych
		cout << RegulaFalsi(f4, -2, 0) << "\t"; //f4 : -1.22364
		cout << RegulaFalsi(f4, 0, 2) << "\n\n\n"; //f4 : 1.22364

		//Metoda bisekcji

		cout << BisectionMethod(f1, -2, -1.5) << "\t"; //f1 : -1.73205         
		cout << BisectionMethod(f1, -1.5, 1) << "\t"; //f1 : -1
		cout << BisectionMethod(f1, -2, 2) << "\n"; //f1 : 1.73205
		cout << BisectionMethod(f2, -3, 0) << "\t"; //f2 : -1.41421
		cout << BisectionMethod(f2, -1, 2) << "\n"; //f2 : 1.41421
		//cout << BisectionMethod(f3, 0, 1) << "\n"; //f3 : Brak mozliwosci rozwiazania ta metoda: zadne f(x1)*f(x2) nie przyjmie wartosci ujemnych lub zerowych, nie spelnione warunki siecznych
		cout << BisectionMethod(f4, -2, 0) << "\t"; //f4 : -1.22364
		cout << BisectionMethod(f4, 0, 2) << "\n\n\n"; //f4 : 1.22364
	}
	catch (const exception& ex)
	{
		cerr << ex.what();
	}
	catch (const char* cex)
	{
		cerr << cex;
	}
}


//1
//- 1.73205
//- 1
//1.73205
//2
//-1.41421
//1.41421
//3
//0.000133735
//4
//-1.22364
//1.22364
