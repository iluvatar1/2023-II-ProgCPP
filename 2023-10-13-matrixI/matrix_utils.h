#pragma once
#include <iostream>
#include <vector>
#include <random>

void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed);
void matmul(const std::vector<double> & A,
	    int Am, int An,
	    const std::vector<double> & B,
	    int Bm, int Bn,
	    std::vector<double> & C);
void power(const std::vector<double> & A, int m, int p,
	   std::vector<double> & C);
