#include <iostream>
#include "integration.h"
// declaration 

double trapezoid(double inf, double sup, int steps, fptr f){
double x = inf;
double sum= 0.0;
double dx = ((sup -inf)/steps);

for( int n = 1; n <= steps-1  ; ++n) {
    double xi = inf + (n* dx);
    sum += f (xi) ;
    }
    double result {dx*(0.5 * f(inf) + sum + 0.5* f (sup))};
    return result; 
}

// Método de Simpson
double simpson(double inf, double sup, int steps, fptr f) {
    if (steps % 2 != 0) {
        std::cerr << "Simpson requiere número par de pasos. steps=" << steps << "\n";
        return 0.0;
    }

    double dx = (sup - inf) / steps;
    double sum1 = 0.0, sum2 = 0.0;

    for (int k = 1; k <= steps / 2; ++k) {
        double x = inf + (2 * k - 1) * dx;
        sum1 += f(x);
    }

    for (int k = 1; k <= (steps / 2) - 1; ++k) {
        double x = inf + 2 * k * dx;
        sum2 += f(x);
    }

    double result = dx / 3.0 * (f(inf) + 4.0 * sum1 + 2.0 * sum2 + f(sup));
    return result;
}

// Extrapolación de Richardson
double richardson_t(double inf, double sup, int steps, fptr f, algptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);
    double val1 = alg(inf, sup, steps, f);
    double val2 = alg(inf, sup, steps * 2, f);
    return (aux * val2 - val1) / (aux - 1.0);
}


double gauss2 (double inf, double sup, fptr f){
    double x0 = -1/ std::sqrt(3.0); 
    double x1 = 1/ std::sqrt(3.0) ;
    double w0 = 1.0;
    double w1 = 1.0;
    double a = (sup-inf)/2;
    double b = (sup+inf)/2;
    double result = a * (w0*f(a*x0+b) + w1*f(a*x1+b));
    return result; 
}
double gauss3 (double inf, double sup, fptr f){
    double x0 = -1* std::sqrt(3.0/5.0); 
    double x1 =  std::sqrt(3.0/5.0) ;
    double x2 = 0;
    double w0 = 5.0/9.0;
    double w1 = 5.0/9.0;
    double w2 = 8.0/9.0;
    double a = (sup-inf)/2;
    double b = (sup+inf)/2;
    double result = a * (w0*f(a*x0+b) + w1*f(a*x1+b) + w2*f(a*x2+b));
    return result; 
}


