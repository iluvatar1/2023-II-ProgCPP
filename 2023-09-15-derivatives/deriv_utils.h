#pragma once
#include <cmath>

using fptr = double(double); // puntero a funcion
using algptr = double(double, double, fptr);
double forward_diff(double x, double h, fptr f);
double central_diff(double x, double h, fptr f);
double richardson(double x, double h, fptr f, int order, algptr alg);
