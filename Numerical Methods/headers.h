#pragma once
#include <istream>
#include <iostream>
#include <fstream>
#include <vector>




void Menu();
std::vector<double> loadPoints(std::ifstream& plik);

double Horner(int n, double w[], double p);
double Horner(int n, std::vector<double> w, double p);
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

typedef double(*func)(double);
double f4(double x);
double f5(double x);
double TrapezoidalRule(std::vector<double> points, func f);
double TrapezoidalRule(std::vector<double> points, std::vector<double> coefficients);
double TrapezoidalRule(double n, double a, double b, std::vector<double> coefficients);
double TrapezoidalRuleNC(double n, double a, double b, std::vector<double> coefficients);
double SimpsonRule(double n, double a, double b, func f);
double TrapezoidalRuleNC(double n, double a, double b, func f);

double GaussLegendre(int n, double a, double b, func f);

std::vector<std::vector<double>> GramSchmidt(std::pair<double, double> g, func* FuncTab, int n);
std::vector<std::vector<double>> ThreePartRule(std::pair<double, double> g, int n);
void ScalarTest(double h, std::pair<double, double> g, std::vector<std::vector<double>> baza, func* ftab);
void PrintBase(std::vector<std::vector<double>> base);

double fx(double x);
double* Approximation(std::vector<func> f, func function);
double* ApproximationCustomBase(std::vector<std::vector<double>> base, func function);

void PrintZeros(std::vector<double> zrs);
double DerivativeByDefinition(func f, double x, double h);
double NewtonRaphsonSingle(func f, func df, double x);
double NewtonRaphsonSingleWithDerivative(func f, double x);
std::vector<double> NewtonRaphson(func f, func df, double x);
std::vector<double> NewtonRaphsonWithDerivative(func f, double x);
double SecantMethod(func f, double x1, double x2);
double RegulaFalsi(func f, double x1, double x2);
double BisectionMethod(func f, double x1, double x2);

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double df1(double x);
double df2(double x);
double df3(double x);
double df4(double x);

typedef double(*funcTherm)(double, double, double);
double ThermalConductivityEQ(double alpha, double beta, double T);
double EulerMethod(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta);
double HeunMethod(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta);
double ModifiedEulerMethod(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta);
double RungeKutta4(int n, double xs, double xf, double ys, funcTherm f, double alpha, double beta);