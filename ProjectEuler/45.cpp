#include <iostream>
#include <cmath>

// Verifica si un número es pentagonal
bool esPentagonal(long long x) {
    double n = (1 + std::sqrt(24 * x + 1)) / 6.0;
    return n == static_cast<long long>(n);
}

int main() {
    long long n = 144; // comenzamos en el siguiente a H143 = 40755

    while (true) {
        long long hex = n * (2 * n - 1);
        if (esPentagonal(hex)) {
            std::cout << "El siguiente número triangular que también es pentagonal y hexagonal es: " << hex << std::endl;
            break;
        }
        ++n;
    }

    return 0;
}


