#pragma once

using fptr = double(double); // puntero a funcion
double forward_diff(double x, double h, fptr f);
double central_diff(double x, double h, fptr f);
