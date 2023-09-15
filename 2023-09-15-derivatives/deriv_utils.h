#pragma once
#include <cmath>

using fptr = double(double); // puntero a funcion
double forward_diff(double x, double h, fptr f);
double central_diff(double x, double h, fptr f);
double richardson_forward(double x, double h, fptr f, int order);
double richardson_central(double x, double h, fptr f, int order);
