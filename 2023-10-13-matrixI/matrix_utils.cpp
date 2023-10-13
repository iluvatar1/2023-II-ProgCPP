#include "matrix_utils.h"

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

// A[ii, jj] = AT[jj, ii]
// ncols de AT, es el nrows de A
void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      dataout[jj*m + ii] = datain[ii*n + jj]; // Error here
    }
  }
}

void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed){
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(-1, 1);
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = dis(gen);
        }
    }

}

// AmxAn * BmxBn = AmxBn
void matmul(const std::vector<double> & A,
	    int Am, int An,
	    const std::vector<double> & B,
	    int Bm, int Bn,
	    std::vector<double> & C)
{
  // An == Bm
  //assert(An == Bm);
  for (int ii = 0; ii < Am; ii++) {
    for (int jj = 0; jj < Bn; jj++) {
      C[ii*Bn + jj] = 0.0;
      for (int kk = 0; kk < An; kk++) {
	C[ii*Bn + jj] += A[ii*An + kk]*B[kk*Bn + jj];
      }
    }
  }
}

void power(const std::vector<double> & A, int m, int p,
	   std::vector<double> & C)
{
  // verificar a p
  C = A;
  std::vector<double> tmp(A.size());
  for(int ip = 2; ip <= p; ip++) {
    tmp = C;
    matmul(A, m, m, tmp, m, m, C);
  }
}

