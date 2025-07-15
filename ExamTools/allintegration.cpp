#include <iostream>
#include <fstream>
#include <cmath>
#include <functional>

//Declaration
using fptr = std::function<double(double)>;

double trapezoid(double a, double b, int N, fptr f);
double simpson(double, double b, int N, fptr f);

using algptr = std::function<double(double, double, int, fptr)>;

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha);

double gauss2(double a, double b, fptr f);

double gauss3(double a, double b, fptr f);

double gaussN(double a, double b, fptr f, int n);

//function
double f(double x);

int main(void){
    double exact_result = 2.0/3.0;


    // open file for writing
    std::ofstream file("integration_all.txt");
    file.precision(15);
    file.setf(std::ios::scientific);

    for (int N = 2; N <= 10; N++){
    double trapezoid_result = trapezoid(-2.0, 2.0, N, f);
    double simpson_result = simpson(-2.0, 2.0, N, f);
    double richardson_trapezoid_result = richardson(-2.0, 2.0, N, f, trapezoid, 2);
    double richardson_simpson_result = richardson(-2.0, 2.0, N, f, simpson, 4);
    double error_trapezoid = std::abs(1.0 - trapezoid_result/exact_result);
    double error_simpson = std::abs(1.0 - simpson_result/exact_result);
    double error_richardson_trapezoid = std::abs(1.0 - richardson_trapezoid_result/exact_result);
    double error_richardson_simpson = std::abs(1.0 - richardson_simpson_result/exact_result);
    double gauss_quadratureN = gaussN(-2.0, 2.0, f,7);
    double error_gaussN = std::abs(1.0 - gauss_quadratureN/exact_result);
    double gauss_quadrature3 = gauss3(-2.0, 2.0, f);
    double error_gauss3 = std::abs(1.0 - gauss_quadrature3/exact_result);
    file << N << " "
            << trapezoid_result << " "
            << error_trapezoid << " "
            << richardson_trapezoid_result << " "
            << error_richardson_trapezoid << " "
            << simpson_result << " "
            << error_simpson << " "
            << richardson_simpson_result << " "
            << error_richardson_simpson << " "
            << gauss_quadratureN << " "
            << error_gaussN << " "
            << gauss_quadrature3 << " "
            << error_gaussN <<
            std::endl;
    }
    file.close();
    return 0;
}

double f( double x){
    return 7*x*x*x - 8*x*x + 3*x + 3;
}

double trapezoid(double a, double b, int N, fptr f){
    double deltax = (b - a)/N;
    double sum = 0.0;

    for (int k = 1; k <= N-1; k++){
        double x_k = a + k * deltax;
        sum = sum + f(x_k);
    }
    double result = deltax * (0.5 * f(a) + sum + 0.5 * f(b));
    return result;
}

double simpson(double a, double b, int N, fptr f){
    if (N % 2 != 0){
        N ++;
    }

    double deltax = (b - a)/N;
    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int k = 1; k <= N * 0.5; k++){
        double x_2k1 = a + (2 * k - 1) * deltax;
        sum1 = sum1 + f(x_2k1);
    }

    for (int k = 1; k <= N * 0.5 - 1; k++){
        double x_2k = a + 2 * k * deltax;
        sum2 = sum2 + f(x_2k);
    }
    double result = deltax * (1.0/3.0) * (f(a) + 4 * sum1 + 2 * sum2 + f(b));
    return result;
}

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha){
    double aux = std::pow(2.0, alpha);
    double R1 = alg(a, b, N, f);
    double R2 = alg(a, b, N * 2, f);
    double result = (aux * R2 - R1) / (aux - 1.0);
    return result;
}

double gauss2(double a, double b, fptr f){
    //define point coordinates
    double x0 = -1.0/std::sqrt(3.0);
    double x1 = +1.0/std::sqrt(3.0);

    //define weights
    double w0 = 1.0;
    double w1 = 1.0;

    //capture integral
    double result = (b - a)/2.0 * (w0 * f(((b - a) * x0)/2.0 + (a + b)/2.0) + w1 * f(((b - a) * x1)/2.0 + (a + b)/2.0));
    return result;
}

double gauss3(double a, double b, fptr f){
    // aux
    double aux1 = (b - a)/2.0;
    double aux2 = (b + a)/2.0;

    //define point coordinates
    std::vector<double> x(3);
    x[0] = -std::sqrt(3.0/5.0);
    x[1] = 0.0;
    x[2] = +std::sqrt(3.0/5.0);

    //define weights
    std::vector<double> w(3);
    w[0] = 5.0/9.0;
    w[1] = 8.0/9.0;
    w[2] = 5.0/9.0;

    //capture integral
    double result = 0.0;
    for(int k = 0; k < 3; ++k){
        result = result + w[k] * f(aux1 * x[k] + aux2);
    }
    return aux1 * result;
}

double gaussN(double a, double b, fptr f, int n) {
    std::vector<double> x, w;

    if (n == 2) {
        x = { -0.5773502691896257, 0.5773502691896257 };
        w = { 1.0, 1.0 };

    } else if (n == 3) {
        x = { -0.7745966692414834, 0.0, 0.7745966692414834 };
        w = { 0.5555555555555556, 0.8888888888888888, 0.5555555555555556 };

    } else if (n == 4) {
        x = {
            -0.8611363115940526,
            -0.3399810435848563,
             0.3399810435848563,
             0.8611363115940526
        };
        w = {
            0.3478548451374538,
            0.6521451548625461,
            0.6521451548625461,
            0.3478548451374538
        };

    } else if (n == 5) {
        x = {
            -0.9061798459386640,
            -0.5384693101056831,
             0.0,
             0.5384693101056831,
             0.9061798459386640
        };
        w = {
            0.2369268850561891,
            0.4786286704993665,
            0.5688888888888889,
            0.4786286704993665,
            0.2369268850561891
        };

    } else if (n == 6) {
        x = {
            -0.9324695142031521,
            -0.6612093864662645,
            -0.2386191860831969,
             0.2386191860831969,
             0.6612093864662645,
             0.9324695142031521
        };
        w = {
            0.1713244923791704,
            0.3607615730481386,
            0.4679139345726910,
            0.4679139345726910,
            0.3607615730481386,
            0.1713244923791704
        };

    } else if (n == 7) {
        x = {
            -0.9491079123427585,
            -0.7415311855993945,
            -0.4058451513773972,
             0.0,
             0.4058451513773972,
             0.7415311855993945,
             0.9491079123427585
        };
        w = {
            0.1294849661688697,
            0.2797053914892766,
            0.3818300505051189,
            0.4179591836734694,
            0.3818300505051189,
            0.2797053914892766,
            0.1294849661688697
        };

    } else {
        throw std::invalid_argument("gaussN solo admite n = 2 a 7");
    }

    // Cambio de variable de [-1, 1] a [a, b]
    double aux1 = (b - a) / 2.0;
    double aux2 = (b + a) / 2.0;

    double result = 0.0;
    for (int k = 0; k < n; ++k) {
        result += w[k] * f(aux1 * x[k] + aux2);
    }

    return aux1 * result;
}