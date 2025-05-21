#include <iostream>
#include <fstream>
#include <cmath>
#include "integration.h"

double f(double x) {
        return 7*x*x*x -8*x*x + 3*x + 3;

}

double relative_error(double exact, double approx) {
    return std::abs(1.0 - approx / exact);
}

int main(void) {
    const double a = -2.0, b = 2.0;
    const double exact_result = -92.0/3.0;

    std::ofstream file("errores.txt");
    file << "# N h fe ce rfe rce\n";

     for (int N : {100
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