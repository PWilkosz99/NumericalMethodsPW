#pragma once
#include <istream>

void Menu();

double Horner(int n, double w[], double p);
void HornerFromMain();
void HornerTest();

double HornerUOG(int n, double b[], double x[], double p);
void HornerUOGFromMain();
void HornerUOGTest();

double CalculateLi(int n, int i, double x[], double p);

double LagrangeInterpolation(int n, double x[], double y[], double p);
void LagrangeInterpolationFromMain();
void LagrangeInteprolationTest();

double* CalculateBK(int n, double x[], double y[]);
void CalculateBKFromMain();
void CalculateBKTest();

double* BKToNaturalForm(int n, double b[], double x[]);
void BKToNaturalFormTest();
void BkToNaturalFormFromMain();

double* ElimGauss(double** A, double* b, unsigned int n);
void ElimGaussFromMain();
void ElimGaussTest();
double* ElimGaussCrout(double** A, double* b, unsigned int n);
void ElimGaussCroutFromMain();
void ElimGaussCroutTest();

double** LUdecomposition(double** A, int n);
void PrintMatrices(double** A, int n);
void PrintVec(double* X, int n, char s);
void PrintB(double* X, int n);
void PrintX(double* X, int n);
double* CalculateX(double** A, double* B, int n);
void LUFromMain();
void LUdecompositionTest();


///tmp
typedef double(*func)(double);
double f1(double x);
double f2(double x);
double TrapezoidalRule(double x, func f);