#include <iostream>
#include <cmath>
#include <string>

bool isprime(long long n);

int main(void){

    // ./a.out -> argc = 1, argv = ["./a.out"]
    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]
    // ./a.out 10 0.55 -> argc = 3, argv = ["./a.out", "10", "0.55"]
    // ./a.out 300 400 -> argc = 3, argv = ["./a.out", "300", "400"]

    
    int vmax = 18;
    long sum = 0;
    long ii = 2;
    while (true) {
        if (isprime(ii) == true and vmax % ii == 0) {
            sum += ii;
            vmax /= ii;}
        else if (ii > vmax +2
        ){return sum;}ii++;
    
    
    std::cout << "la suma de los factores primos es: ( " << sum << " ) ";
    std::cout << "\n";} 

    return 0;}



// implementation
bool isprime(long long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    // suppose it is prime
    bool flag = true; 

    if (n == 2) {
        return true;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}