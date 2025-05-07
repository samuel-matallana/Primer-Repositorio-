#include <iostream>
using namespace std;

// Función para encontrar el mayor factor primo
long long mayorFactorPrimo(long long n) {
    long long mayor = -1;

    // Elimina los factores de 2
    while (n % 2 == 0) {
        mayor = 2;
        n /= 2;
    }

    // Revisa los factores impares desde 3 en adelante
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            mayor = i;
            n /= i;
        }
    }

    // Si lo que queda de n es un número primo mayor que 2
    if (n > 2) {
        mayor = n;
    }

    return mayor;
}

int main() {
    long long numero;

    cout << "Ingresa un número entero positivo: ";
    cin >> numero;

    if (numero <= 1) {
        cout << "Debe ingresar un número mayor que 1." << endl;
    } else {
        long long resultado = mayorFactorPrimo(numero);
        cout << "El mayor factor primo de " << numero << " es: " << resultado << endl;
    }

    return 0;
}