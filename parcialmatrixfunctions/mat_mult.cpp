#include <iostream>
#include <vector>
#include <string>

void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);

void trace(const std::vector<double> & data, int m, int n);
void fill_hil(std::vector<double> & data, int m, int n);
void print_hil(const std::vector<double> & data, int m, int n);
void mat_mul( std::vector<double> & adata, std::vector<double> & bdata,std::vector<double> & cdata, int m, int n, int o, int p);
void power(std::vector<double> & adata, std::vector<double> & bdata, std::vector<double> & cdata, int m, int n, int o, int p, int power);
bool indempotent(std::vector<double> & adata, std::vector<double> & bdata, std::vector<double> & cdata, int m, int n, int o, int p, int power, std::vector<double> & I_n);
void Ident(std::vector<double> & I_n, int m, int p);



int main(int argc, char **argv){
  // Valores por defecto
   int M = 0;
   int N = 0;
   int O = 0;
   int P = 0;

  // Solo asignamos si el argumento existe
  if (argc > 1) M = std::stoi(argv[1]);
  if (argc > 2) N = std::stoi(argv[2]);
  if (argc > 3) O = std::stoi(argv[3]);
  if (argc > 4) P = std::stoi(argv[4]);

 

  std::vector<double> array2d(M*N, 0.0);
  std::vector<double> barray2d(O*P, 0.0);
  std::vector<double> carray2d(M*P, 0.0);
  std::vector<double> I_n(M*P, 0.0);
 
  fill_matrix(array2d, M, N);
  fill_matrix(barray2d, O, P);
  print_matrix(array2d, M, N);
  print_matrix(barray2d, O, P);

  power(array2d, barray2d,carray2d, M, N, O, P , 3);
  print_matrix(carray2d, M, P);
  
  
  
  


  
  

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
      dataout[jj*m+ii ]= datain[ii*n + jj]; // A_(i, j) = i*n + j = id
    }
  } 
}
void trace(const std::vector<double> & data, int m, int n) {
  double traza = 0;

  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      if (ii==jj){
        traza += data[ii*n+jj];
      }
    }
  } 
  std::cout << "La traza es : " << traza << "\n";
}
void fill_hil(std::vector<double> & data, int m, int n){
  {
  for (double ii = 0; ii < m; ++ii) {
    for (double jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = 1/(ii+jj+1); // A_(i, j) = i*n + j = id
    }
  }
 
} 
}
void print_hil(const std::vector<double> & data, int m, int n)
{ std::cout << "La matrix de hilbert de tamaño " << m << "x"<< n << " es: \n";
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
        
        
      std::cout << data[ii*n + jj] << "   ";
    }
    std::cout << "\n";
    std::cout << "\n";
  }
  std::cout << "\n";
}
void mat_mul( std::vector<double> & adata, std::vector<double> & bdata, std::vector<double> & cdata, int m, int n, int o, int p){
 if(n!= o){
    std::cerr << "La multiplicación de matrices no esta definida para las matrices que estas solicitando";
    return;}
 for (int ii = 0; ii < m; ii++) {
    for (int jj = 0; jj < p; jj++) {
      for (int k = 0; k < n; k++){
      cdata[ii*p + jj] += adata[ii*n+k]*bdata[k*p+jj]; 
    }}
  }   
}
void power(std::vector<double> & adata, std::vector<double> & bdata, std::vector<double> & cdata, int m, int n, int o, int p, int power){
  if(m != n ){std::cerr << "la multiplicación de potencias solo esta definida para matrices cuadradas \n"; return;}
  for(int l=1; l < power; l++){
     std::fill(cdata.begin(), cdata.end(), 0.0);

 mat_mul (adata, bdata, cdata, m, n, o, p);
 for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      
      adata[ii*n+jj]= cdata[ii*n + jj];
      
    }
  } 
 
 }
}

void Ident(std::vector<double> & In, int m ,int p){
  for( int i = 0; i< m; i++){
  for( int j = 0; j< p; j++){
    if (i==j){ 
      In[i*p+j] = 1.0;
      }
  }

}}

bool indempotent(std::vector<double> & adata, std::vector<double> & bdata, std::vector<double> & cdata, int m, int n, int o, int p, int power, std::vector<double> & I_n){
power(adata, bdata, cdata, m, n, o, p, power);

for( int i = 0; i< m; i++){
  for( int j = 0; j< p; j++){ 
cdata[i*p+j]-=1;}}
int sum = 0;
for( int i = 0; i< m; i++){
  for( int j = 0; j< p; j++){ 
sum += cdata[i*p+j];
return sum
}}


