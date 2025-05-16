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
double gauss3(double inf, double sup, fptr f)
{
    // aux
    double aux1 = (sup-inf)/2;
    double aux2 = (sup+inf)/2;

    // define point coordinates
    std::vector<double> x(3);
    x[0] = -std::sqrt(3.0/5.0);
    x[1] = 0;
    x[2] = +std::sqrt(3.0/5.0);
    
    //define weigths
    std::vector<double> w;
    w.resize(3);
    w[0] = 5.0/9.0;
    w[1] = 8.0/9.0;
    w[2] = 5.0/9.0;
    
    // compute integral
    double result = 0.0;
    for(int k = 0; k < 3; ++k){
        result = result + w[k]*f(aux1*x[k] + aux2);
    }
    return aux1*result;
}

double gauss5(double inf, double sup, fptr f){
    // aux
    double aux1 = (sup - inf)/2.0;
    double aux2 = (sup + inf)/2.0;

    //define point coordinates
    std::vector<double> x(5);
    x[0] = -1.0/3.0*std::sqrt(5+2*std::sqrt(10.0/7.0));
    x[1] = -1.0/3.0*std::sqrt(5-2*std::sqrt(10.0/7.0));
    x[2] = 0.0;
    x[3] = +1.0/3.0*std::sqrt(5-2*std::sqrt(10.0/7.0));
    x[4] = +1.0/3.0*std::sqrt(5+2*std::sqrt(10.0/7.0));

    //define weights
    std::vector<double> w(5);
    w[0] = (322.0-13.0*std::sqrt(70.0))/900.0;
    w[1] = (322.0+13.0*std::sqrt(70.0))/900.0;
    w[2] = 128.0/225.0;
    w[3] = (322.0+13.0*std::sqrt(70.0))/900.0;
    w[4] = (322.0-13.0*std::sqrt(70.0))/900.0;

    //capture integral
    double result = 0.0;
    for(int k = 0; k < 5; ++k){
        result = result + w[k] * f(aux1 * x[k] + aux2);
    }
    return aux1 * result;
}

double gauss7 (double inf, double sup, fptr f){
    // aux
    double aux1 = (sup - inf)/2.0;
    double aux2 = (sup + inf)/2.0;

    //define point coordinates
    std::vector<double> x(7);
    x[0] = -0.949107912342759;
    x[1] = -0.741531185599394;
    x[2] = -0.405845151377397;
    x[3] = 0.0;
    x[4] = 0.405845151377397;
    x[5] = 0.741531185599394;
    x[6] = 0.949107912342759;

    //define weights
    std::vector<double> w(7);
    w[0] = 0.129484966168870;
    w[1] = 0.279705391489277;
    w[2] = 0.381830050505119;
    w[3] = 0.417959183673469;
    w[4] = 0.381830050505119;
    w[5] = 0.279705391489277;
    w[6] = 0.129484966168870;

    //capture integral
    double result = 0.0;
    for(int k = 0; k < 7; ++k){
        result = result + w[k] * f(aux1 * x[k] + aux2);
    }
    return aux1 * result;
}