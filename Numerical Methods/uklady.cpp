#include "headers.h"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

//dane: wyrzucic ostatni wiersz

double* ElimGauss(double** A, double* b, unsigned int n) {
	try
	{
		double* x = new double[n];
		for (int i = 0; i < n; i++)
		{
			//cout << A[i][i] << ", ";
			if (A[i][i] == 0)
			{
				throw "0 na przek¹tnej\nNie mozna obliczyæ z podstawowego algorytmu Gaussa";
			}
		}

		for (int k = 0; k < n - 1; k++)
		{
			for (int i = k + 1; i < n; i++)
			{
				A[i][k] = A[i][k] / A[k][k];
				for (int j = k + 1; j < n + 1; j++)
				{
					if (j == n)
					{
						b[i] = b[i] - (A[i][k] * b[k]);
					}
					else
					{
						A[i][j] = A[i][j] - (A[i][k] * A[k][j]);
					}

				}
				A[i][k] = 0;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			x[i] = b[i];
			for (int j = i + 1; j < n; j++)
			{
				if (j == n)
				{
					x[i] = x[i] - (b[i] * x[j]);
				}
				else
				{
					x[i] = x[i] - (A[i][j] * x[j]);
				}
			}
			x[i] = x[i] / A[i][i];
		}
		return x;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
	return NULL;
}

void ElimGaussFromMain() {
	int n;
	cout << "Podaj rozmiar macierzy:\n";
	cin >> n;
	double** a = new double* [n];
	double* b = new double[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << "\nPodaj element [" << i << "][" << j << "] :";
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\nPodaj element b[" << i << "]";
		cin >> b[i];
	}

	double* x = ElimGauss(a, b, n);

	for (int i = 0; i < n; i++)
	{
		cout << x[i] << "\n";
	}
}

double* ElimGaussCrout(double** A, double* b, unsigned int n) {
	double piv, maxx, tmp, c, S;
	int* W = new int[n];
	double* x = new double[n];

	for (int i = 0; i < n; ++i)
	{
		W[i] = i;
	}

	try {
		for (int i = 0, j, k; i < (n - 1); ++i) {
			maxx = fabs(A[i][W[i]]);
			k = i;

			for (j = i + 1; j < n; ++j)
			{
				piv = fabs(A[i][W[j]]);

				if (piv > maxx)
				{
					maxx = piv;
					k = j;
				}
			}
			if (maxx == 0)
			{
				delete[] W;
				throw"Nieoznaczony uk³ad równañ";
			}
			if (i != k)
			{
				tmp = W[i];
				W[i] = W[k];
				W[k] = tmp;
			}

			piv = A[i][W[i]];

			for (j = i + 1; j < n; ++j)
			{
				c = A[j][W[i]] / piv;

				for (k = i; k < n; ++k)
				{
					A[j][W[k]] -= c * A[i][W[k]];
				}

				b[j] -= c * b[i];
			}
		}

		x[W[n - 1]] = b[n - 1] / A[n - 1][W[n - 1]];

		for (int i = n - 2, j; i >= 0; --i)
		{
			S = 0;
			for (j = n - 1; j > i; --j)
			{
				S += A[i][W[j]] * x[W[j]];
			}
			x[W[i]] = (b[i] - S) / A[i][W[i]];
		}
		return x;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
	return NULL;
}

void ElimGaussTest() {
	double** a = new double* [5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = new double[5];
	}
	a[0][0] = 0.00; a[0][1] = -3.0; a[0][2] = 4.00; a[0][3] = 6.80; a[0][4] = 9.00;
	a[1][0] = -3.00; a[1][1] = 2.0; a[1][2] = 4.60; a[1][3] = 6.30; a[1][4] = -10.00;
	a[2][0] = 2.00; a[2][1] = -1.0; a[2][2] = 2.80; a[2][3] = -8.40; a[2][4] = -5.00;
	a[3][0] = -6.00; a[3][1] = 2.0; a[3][2] = 7.00; a[3][3] = -0.50; a[3][4] = -0.90;
	a[4][0] = 5.00; a[4][1] = -2.0; a[4][2] = -0.50; a[4][3] = 12.00; a[4][4] = -4.00;

	double* b = new double[5];
	b[0] = 66.64; b[1] = -36.26; b[2] = -4.32; b[3] = 16.60; b[4] = -12.9;

	double* w = ElimGauss(a, b, 5);

	if (w != NULL) {
		for (int i = 0; i < 5; i++)
		{
			cout << w[i] << "\n";
		}
	}
}

void ElimGaussCroutFromMain() {
	int n;
	cout << "Podaj rozmiar macierzy:\n";
	cin >> n;
	double** a = new double* [n];
	double* b = new double[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << "\nPodaj element [" << i << "][" << j << "] :";
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\nPodaj element b[" << i << "]";
		cin >> b[i];
	}

	double* x = ElimGaussCrout(a, b, n);

	for (int i = 0; i < n; i++)
	{
		cout << x[i] << "\n";
	}
}

void ElimGaussCroutTest() {
	double** a = new double* [5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = new double[5];
	}
	a[0][0] = 0.00; a[0][1] = -3.0; a[0][2] = 4.00; a[0][3] = 6.80; a[0][4] = 9.00;
	a[1][0] = -3.00; a[1][1] = 2.0; a[1][2] = 4.60; a[1][3] = 6.30; a[1][4] = -10.00;
	a[2][0] = 2.00; a[2][1] = -1.0; a[2][2] = 2.80; a[2][3] = -8.40; a[2][4] = -5.00;
	a[3][0] = -6.00; a[3][1] = 2.0; a[3][2] = 7.00; a[3][3] = -0.50; a[3][4] = -0.90;
	a[4][0] = 5.00; a[4][1] = -2.0; a[4][2] = -0.50; a[4][3] = 12.00; a[4][4] = -4.00;

	double* b = new double[5];
	b[0] = 66.64; b[1] = -36.26; b[2] = -4.32; b[3] = 16.60; b[4] = -12.9;

	double* w = ElimGaussCrout(a, b, 5);
	if (w != NULL) {
		for (int i = 0; i < 5; i++)
		{
			cout << w[i] << "\n";
		}
	}
}

double** LUdecomposition(double** A, int n) {
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i <= j)
			{
				for (int k = 0; k <= i - 1; k++)
				{
					A[i][j] -= A[i][k] * A[k][j];
				}
			}
			else
			{
				for (int k = 0; k <= j - 1; k++)
				{
					A[i][j] -= A[i][k] * A[k][j];
				}
				A[i][j] /= A[j][j];
			}
		}
	}
	return A;
}

void PrintMatrices(double** A, int n)
{
	cout << "Macierz L:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (j < i)
			{
				printf("%10.3lf", A[i][j]);
			}
			else if (j == i)
			{
				printf("%10.3lf", 1.0);
			}
			else
			{
				printf("%10.3lf", 0.0);
			}
		printf("\n");
	}

	cout << "Macierz U:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i - 1) {
				printf("%10.3f", A[i][j]);
			}
			else {
				printf("%10.3f", 0.0);
			}

		}
		printf("\n");
	}
}

void PrintVec(double* X, int n, char s) {
	cout << "Wektor " << s << ":\n";
	for (int i = 0; i < n; i++)
	{
		printf("%c%d: %10.3f", s, i, X[i]);
		printf("\n");
	}
}

void PrintB(double* X, int n) {
	PrintVec(X, n, 'B');
}

void PrintX(double* X, int n) {
	PrintVec(X, n, 'X');
}

void PrintMatrix(double** A, int n) {
	cout << "Macierz A:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%10.3lf", A[i][j]);
		printf("\n");
	}
}

double* CalculateX(double** A, double* B, int n) {
	double* XY = new double[n];
	try {
		for (int i = 0; i < n; i++)
		{
			XY[i] = B[i];
			for (int j = 0; j < i; j++)
			{
				XY[i] -= A[i][j] * XY[j]; //obliczam Y
			}
			//cout << XY[i] <<"\n";
		}

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < n; j++)
			{
				XY[i] -= A[i][j] * XY[j];
			}
			if (A[i][i] == 0) {
				throw "Singular matrix - cannot be calculated";
			}
			XY[i] /= A[i][i];
		}
		return XY;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
}

double** loadMatrix(ifstream& plik) {
	int n;
	plik >> n;

	double** A = new double* [n];

	for (int i = 0, j; i < n; ++i) {
		double* col = new double[n];

		for (j = 0; j < n; ++j) {
			plik >> col[j];
		}
		A[i] = col;
	}
	return A;
}

double* loadVector(ifstream& plik) {
	int n;
	plik >> n;

	double* v = new double[n];
	for (int i = 0; i < n; i++) {
		plik >> v[i];
	}
	return v;
}

void LUFromMain() {
	int n = 0;
	cout<<"Podaj rozmiar macierzy:\n";
	cin >> n;
	double** A = new double* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
	double* B = new double[n];
	double* X = new double[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Wprowadz wartoœæ A[%d][%d] elementu: ", i, j);
			cin >> A[i][j];
			//scanf_s("%f", &A[i][j]);
		}
	}
	printf("\nWprowadz wartosci wektora B: \n");
	for (int i = 0; i < n; i++)
	{
		printf("B[%d]", i);
		//scanf_s("%f", &B[i]);
		cin >> B[i];
	}

	PrintMatrix(A, 3);
	PrintB(B, 3);

	A = LUdecomposition(A, 3);
	PrintMatrices(A, 3);
	X = CalculateX(A, B, n);
	PrintX(X, n);
}

void LUdecompositionTest() {

	int n = 3;
	double** A = new double* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
	double* B = new double[n];
	double* X = new double[n];

	//Macierz 1 - przyk³ad z prezentacji
	ifstream plik("data\\matrix1.txt");
	A = loadMatrix(plik);
	PrintMatrix(A, 3);

	B = loadVector(plik);
	PrintB(B, 3);

	A = LUdecomposition(A, 3);
	PrintMatrices(A, 3);

	X = CalculateX(A, B, n);
	//PrintX(X, n);
	plik.close();
	//Dla macierzy tej uzyskanie X nie jest mo¿liwe poniewaz macierz jest osobliwa(det=0)

	cout << "\n\n\Rownanie 2:\n";


	//Macierz 2
	ifstream plik2("data\\matrix2.txt");
	A = loadMatrix(plik2);
	PrintMatrix(A, 3);

	B = loadVector(plik2);
	PrintB(B, 3);

	A = LUdecomposition(A, 3);
	PrintMatrices(A, 3);

	X = CalculateX(A, B, n);
	PrintX(X, n);
	plik2.close();

	cout << "\n\n\Rownanie 3:\n";


	//Macierz 3
	ifstream plik3("data\\matrix3.txt");
	A = loadMatrix(plik3);
	PrintMatrix(A, 3);

	B = loadVector(plik3);
	PrintB(B, 3);

	A = LUdecomposition(A, 3);
	PrintMatrices(A, 3);

	X = CalculateX(A, B, n);
	PrintX(X, n);
	plik3.close();
}
