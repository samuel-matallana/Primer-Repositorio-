#include <iostream>
#include <vector>
#include <cmath>
#include <string>

// Función para calcular la derivada
std::vector<double> derivadas(const std::vector<double>& coeficientes) {
    std::vector<double> derivada;
    int potencia = 0;

    for (auto coeficiente : coeficientes) {
        if (potencia > 0) {
            derivada.push_back(coeficiente * potencia);
        }
        ++potencia;
    }

    return derivada;
}

// Función para imprimir un vector
void imprimirVector(const std::vector<double>& vec) {
    for (auto val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main(void) {
    std::vector<double> data = {3.0, 7.0, 2.5};
    std::vector<double> newdata = derivadas(data);

    std::cout << "Derivada: ";
    imprimirVector(newdata);

    return 0;
}
