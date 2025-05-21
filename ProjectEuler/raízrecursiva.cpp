#include <iostream>
#include <string>

// Función para contar cuántas fracciones tienen numerador con más dígitos
int count_longer_numerators(int expansions) {
    int count = 0;

    // p y q representan el numerador y denominador de la expansión anterior
    long long p = 1;
    long long q = 1;

    // Usamos un bucle for normal hasta el número deseado de expansiones
    for (int i = 1; i <= expansions; ++i) {
        // Nueva expansión: fórmula recursiva
        long long next_p = p + 2 * q;
        long long next_q = p + q;

        // Convertimos a string para comparar la cantidad de dígitos
        int digits_num = std::to_string(next_p).length();
        int digits_den = std::to_string(next_q).length();

        if (digits_num > digits_den) {
            count++;
        }

        // Actualizamos para la siguiente iteración
        p = next_p;
        q = next_q;
    }

    return count;
}

int main() {
    int n;

    // Pedir al usuario el número de expansiones
    std::cout << "Ingrese el número de expansiones a calcular: ";
    std::cin >> n;

    // Calcular e imprimir el resultado
    int result = count_longer_numerators(n);
    std::cout << "En las primeras " << n << " expansiones, "
              << result << " fracciones tienen más dígitos en el numerador que en el denominador.\n";

    return 0;
}