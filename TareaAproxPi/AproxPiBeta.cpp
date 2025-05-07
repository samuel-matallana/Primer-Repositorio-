#include <iostream>
#include <cmath>        // Para pow()
#include <iomanip>      // Para setprecision()

// Declaración de función
void aproximar_pi(int iteraciones);

int main() {
    int n_deseada = 0;
    const int MIN = 1;
    const int MAX = 20;

    std::cout << "Aproximemos π con la fórmula de Bailey–Borwein–Plouffe (BBP)\n";
    
    // Solicitar número de iteraciones al usuario
    do {
        std::cout << "Ingresa el número de iteraciones (" << MIN << " a " << MAX << "): ";
        std::cin >> n_deseada;

        if (n_deseada < MIN || n_deseada > MAX) {
            std::cout << "Por favor ingresa un número entre 1 y 20.\n";
        }
    } while (n_deseada < MIN || n_deseada > MAX);

    // Llamar a la función que calcula pi
    aproximar_pi(n_deseada);

    return 0;
}

// Función que implementa la fórmula BBP
void aproximar_pi(int iteraciones) {
    double pi_aprox = 0.0;

    for (int n = 0; n < iteraciones; ++n) {
        double termino = (1.0 / pow(16, n)) * (
            (4.0 / (8 * n + 1)) -
            (2.0 / (8 * n + 4)) -
            (1.0 / (8 * n + 5)) -
            (1.0 / (8 * n + 6))
        );

        pi_aprox += termino;
    }

    // Mostrar resultado con precisión
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "La aproximación de pi con " << iteraciones << " iteraciones es: " << pi_aprox << "\n";
}