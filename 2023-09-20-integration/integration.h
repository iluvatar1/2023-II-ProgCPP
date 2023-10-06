#pragma once

#include <vector>
#include <cmath>
#include <iostream>

using fptr = double(double);

double trapezoid(double a, double b, int n, fptr fun);

double gauss_5(double a, double b, fptr fun);
