#include <iostream>
#include <cmath>
#include <string>

//#include <fstream> // para imprimir datos para graficas

#include <iomanip> // para imprimir datos cientificos ??

//#include <functional> // para usar std::function<double(double)>;

#include <vector>

//#include <algorithm>
//#include <numeric>



//implementation===================================================================================================================================


void print_matrix(const std::vector<double> & data, int m, int n) // barre la matris y hace print
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}


std::vector<double> function_Rx(double theta) { // entra angulo theta
    std::vector<double> Rx(9); // 3x3 = 9 elementos
    Rx[0] = 1.0;           Rx[1] = 0.0;               Rx[2] = 0.0;
    Rx[3] = 0.0;           Rx[4] = std::cos(theta);   Rx[5] = -(std::sin(theta));
    Rx[6] = 0.0;           Rx[7] = std::sin(theta);   Rx[8] = std::cos(theta);
    return Rx;  
}

std::vector<double> function_Ry(double theta) { // entra angulo theta
    std::vector<double> Ry(9); // 3x3 = 9 elementos
    Ry[0] = std::cos(theta);   Ry[1] = 0.0;   Ry[2] = std::sin(theta);
    Ry[3] = 0.0;               Ry[4] = 1.0;   Ry[5] = 0.0;
    Ry[6] = -(std::sin(theta));Ry[7] = 0.0;   Ry[8] = std::cos(theta);
    return Ry;
}

std::vector<double> function_Rz(double theta) { // entra angulo theta
    std::vector<double> Rz(9); // 3x3 = 9 elementos
    Rz[0] = std::cos(theta);   Rz[1] = -(std::sin(theta));   Rz[2] = 0.0;
    Rz[3] = std::sin(theta);   Rz[4] = std::cos(theta);      Rz[5] = 0.0;
    Rz[6] = 0.0;               Rz[7] = 0.0;                  Rz[8] = 1.0;
    return Rz;
}

std::vector<double> multiply_matrix_vector(const std::vector<double>& R, const std::vector<double>& v)
{
    std::vector<double> vresult(3, 0.0);

    for (int ii = 0; ii < 3; ++ii) {
        vresult[ii] = (R[ii * 3 + 0] * v[0]) + (R[ii * 3 + 1] * v[1]) + (R[ii * 3 + 2] * v[2]);
    }

    return vresult;
}


//main======================================================================================================================================


int main(int argc, char **argv)
{
    if (argc != 7 )
    {
       std::cerr << " error. Los argumentos deben ser : vx vy vz thetax thetay thetaz \n";
       return 1;
    }
    
    const double vx = std::stod(argv[1]);
    const double vy = std::stod(argv[2]);
    const double vz = std::stod(argv[3]);

    const double thetax = std::stod(argv[4]);
    const double thetay = std::stod(argv[5]);
    const double thetaz = std::stod(argv[6]);

  std::vector<double> v { vx, vy, vz}; // 

    std::cout << "vector input:" << " \n";

    print_matrix(v, 1, 3);

    std::vector<double> R_x = function_Rx(thetax);
    std::vector<double> R_y = function_Ry(thetay);
    std::vector<double> R_z = function_Rz(thetaz);

    std::vector<double>  totalResult = multiply_matrix_vector( R_z ,multiply_matrix_vector( R_y ,multiply_matrix_vector(R_x, v)));

    print_matrix(totalResult, 3, 1);

  return 0;
}
