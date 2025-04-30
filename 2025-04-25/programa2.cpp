#include <iostream>
#include <string> //

// Declaration
unsigned long long max_prime(unsigned long long number);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "No se te olvide que despues de correr el programa  (g++) debes poner el numero a verificar :) \n";
        return 1;
    }

    unsigned long long n = std::stoull(argv[1]); // convierte argumento a número
    unsigned long long max_factor = max_prime(n);

    std::cout << "El mayor factor primo es: " << max_factor << " :)\n";
    return 0;
}

unsigned long long max_prime(unsigned long long number)
{
    unsigned long long max_factor = 1;
    unsigned long long i = 5;

    while (number % 2 == 0)
    {
        max_factor = 2;
        number /= 2;
    }

    while (number % 3 == 0)
    {
        max_factor = 3;
        number /= 3;
    }

    while (i * i <= number)
    {
        while (number % i == 0)
        {
            max_factor = i;
            number /= i;
        }
        while (number % (i + 2) == 0)
        {
            max_factor = i + 2;
            number /= (i + 2);
        }
        i += 6;
    }

    if (number > 1)
    {
        max_factor = number;
    }

    return max_factor;
}
