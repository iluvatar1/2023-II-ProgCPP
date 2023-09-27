#pragma once

using fptr = double(double);

double trapezoid(double a, double b, int n, fptr fun);
