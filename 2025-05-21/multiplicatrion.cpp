#include <iostream>
#include <vector>
#include <string>

void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);

void multiplicacion_matrices(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
     const std::vector<double> & B, std::vector<double> & R);            
void Multiplication_transpose(int n_col_A, int n_row_A, const std::vector<double> & A, std::vector<double> & R);

int main(int argc, char **argv)
{
  const int M = std::stoi(argv[1]);
  const int N = std::stoi(argv[2]);

  std::vector<double> array2d(M*N, 0.0);

  fill_matrix(array2d, M, N);
  print_matrix(array2d, M, N);

  std::vector<double> R(M*M, 0.0);

  Multiplication_transpose(M,N,array2d, R);
    print_matrix(R,M,M);
  return 0;
}

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

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      dataout[jj*m + ii] = datain[ii*n + jj];
    }
  }
}


void multiplicacion_matrices(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
     const std::vector<double> & B, std::vector<double> & R){
    if (n_col_A != n_row_B){
        std::cerr << "Tamaños equivocados al multiplicar matrices";
        std::cout << "Error al multiplicar las matrices";
    }
    R.resize(n_row_A * n_col_B);
    for (int ii = 0; ii < n_row_A; ii++){
        for (int jj = 0; jj < n_col_B; jj++){
            double sum = 0.0;
            for (int k = 0; k < n_col_A; k++){
                sum += A[n_col_A*ii + k]*B[n_col_B*k +jj];
            }
            R[n_col_B*ii + jj] = sum;
        }
    }
    return;
}

void Multiplication_transpose(int n_col_A, int n_row_A, const std::vector<double> & A, std::vector<double> & R){
    std::vector<double> T (n_col_A* n_row_A,0.0);
    transpose_matrix(A ,n_col_A, n_row_A , T);
    multiplicacion_matrices(n_row_A, n_col_A, A, n_col_A, n_row_A, T, R);
    return;
}