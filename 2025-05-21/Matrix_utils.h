#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>


void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);

void multiplicacion_matrices(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
     const std::vector<double> & B, std::vector<double> & R);            
void Multiplication_transpose(int n_col_A, int n_row_A, const std::vector<double> & A, std::vector<double> & R);

bool Check_inverse(int n,const std::vector<double> & A, const std::vector<double> & B, double presicion);