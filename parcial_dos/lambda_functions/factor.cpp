#include <iostream>
#include <vector>

int main() {
    std::vector<int> entrada {1, 2, 3, 4, 5};
    int factor = 3;

    auto multiplicar = [factor, &entrada]() {
        std::vector<int> resultado (entrada.size());
        for (int x : entrada) {
            resultado[x]= factor*x;
        }
        return resultado;
    };

    std::vector<int> salida = multiplicar();

    std::cout << "Resultado: ";
    for (int x : salida) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
