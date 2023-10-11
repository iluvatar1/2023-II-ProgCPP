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
