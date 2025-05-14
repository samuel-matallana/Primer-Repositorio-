#include <iostream>
#include <cmath>
#include <functional>
#include <fstream>
 
 using fptr = std::function < double(double)>;

double trapezoid(double inf, double sup, int steps, fptr f);
double simpson(double inf, double sup, int steps, fptr f);

using algptr = std::function<double(double, double, int, fptr)>;


double richardson_t(double inf, double sup, int steps, fptr f, algptr alg, int alpha);

double f(double x) {
    return std::sin(std::exp(x));
}

double relative_error(double exact, double approx) {
    return std::abs(1.0 - approx / exact);
}

int main(void) {
    const double a = -5.0, b = 5.0;
    const double exact_result = 1.56898093601156;

    std::ofstream file("errores.txt");
    file << "# N h fe ce rfe rce\n";

     for (int N : {2, 4, 6, 8, 10, 26, 40, 56, 70, 86, 100, 250, 400, 550, 700, 850, 1000,
2500, 4000, 5500, 7000, 8500, 10000, 25000, 40000, 55000, 70000, 85000, 100000,
250000, 400000, 550000, 700000, 850000, 1000000, 1200000, 1400000, 1600000, 1800000, 2000000

}) {
        double h = (b - a) / N;

        double trap_result = trapezoid(a, b, N, f);
        double simp_result = simpson(a, b, N, f);
        double rich_trap_result = richardson_t(a, b, N, f, trapezoid, 2);
        double rich_simp_result = richardson_t(a, b, N, f, simpson, 4);

        double error_trap = relative_error(exact_result, trap_result);
        double error_simp = relative_error(exact_result, simp_result);
        double error_rich_trap = relative_error(exact_result, rich_trap_result);
        double error_rich_simp = relative_error(exact_result, rich_simp_result);

        file << N << " "
             << h << " "
             << error_trap << " "
             << error_simp << " "
             << error_rich_trap << " "
             << error_rich_simp << "\n";
    }

    file.close();
    std::cout << "Datos guardados en errores.txt\n";
    return 0;
} 



// implementación

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




