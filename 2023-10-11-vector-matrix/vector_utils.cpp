#include "vector_utils.h"

double pnorm(const std::vector<double> & data, int p)
{
  double suma = 0.0;
  // accumulate
  for (auto val : data) {
    suma += std::pow(val, p);
  }
  return std::pow(suma, 1.0/p);
}

int argmax(const std::vector<double> & data)
{
  /*
    O(n)
  declarar una var que guarde el maximo = data[0]
  declarar otra que guarde el indice = 0
  > , >=
  recorrer el vector
    si el valor actual es mayor que el maximo actual
      se cambia el maximo y el argmax

  retornar argmax
  */
  double valmax = data[0];
  int posmax = 0;
  for (int ii = 0; ii < std::size(data); ii++) {
    if (data[ii] > valmax) {
      valmax = data[ii];
      posmax = ii;
    }
  }
  return posmax;
}

void deriv_poly(const std::vector<double> & pcoeff,
		std::vector<double> & dcoeff)
{
  for (int ii = 1; ii < pcoeff.size(); ii++) {
    dcoeff[ii-1] = (ii)*pcoeff[ii];
  }
}

double eval_poly(const std::vector<double> & pcoeff, double x)
{
  double suma = 0.0;
  for(int ii = 0; ii < pcoeff.size(); ii++) {
    suma += pcoeff[ii]*std::pow(x, ii);
  }
  return suma;
}

double eval_poly_deriv(const std::vector<double> & pcoeff, double x)
{
  std::vector<double> dcoeff(pcoeff.size() - 1);
  deriv_poly(pcoeff, dcoeff);
  return eval_poly(dcoeff, x);
}


