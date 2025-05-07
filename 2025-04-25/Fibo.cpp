#include <iostream>
#include <string> 

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "No se te olvide que después de compilar el programa debes poner el número límite de la serie :) \n";
        return 1;
    }

    unsigned long long n = std::stoull(argv[1]);

    unsigned long long a = 1, b = 2;
    unsigned long long suma = 0;

    while (a <= n)
    {
        if (a % 2 == 1)
        {
            suma += a;
        }

        // Generar el siguiente término de Fibonacci, piensa en los escaloncitos
        unsigned long long c = a + b;
        a = b;
        b = c;
    }

    std::cout << "Suma de números impares de Fibonacci <= " << n << " es: " << suma << "\n";
    return 0;
}
