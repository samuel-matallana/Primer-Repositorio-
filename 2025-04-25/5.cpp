#include <iostream>
#include <numeric> // Para std::gcd

// Función para calcular el mínimo común múltiplo
long long lcm(long long a, long long b) {
    return a / std::gcd(a, b) * b;
}

int main() {
    long long result = 1;
    for (int i = 2; i <= 20; ++i) {
        result = lcm(result, i);
    }
    std::cout << "El menor número divisible por todos los números del 1 al 20 es: " << result << std::endl;
    return 0;
}
