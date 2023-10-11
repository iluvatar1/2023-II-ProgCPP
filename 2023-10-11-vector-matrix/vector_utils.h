#pragma once
#include <vector>
#include <cmath>

double pnorm(const std::vector<double> & data, int p);
int argmax(const std::vector<double> & data);
void deriv_poly(const std::vector<double> & pcoeff,
		std::vector<double> & dcoeff);
double eval_poly(const std::vector<double> & pcoeff, double x);
double eval_poly_deriv(const std::vector<double> & pcoeff, double x);
