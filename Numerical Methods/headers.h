#pragma once
#include <istream>

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