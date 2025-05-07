#include "prime_utils.h"

int main(int argc, char **argv){
    long long vmax = std::stoll(argv[1]);
    long long primefactor = 1;

    if (isprime(vmax)) {
        std::cout << vmax << "\n"; // el número es primo → es su mayor factor primo
    } else {
        for (long long ii = vmax / 2; ii >= 2; ii--) {
            if (vmax % ii == 0 && isprime(ii)) {
                primefactor = ii;
                std::cout << primefactor << "\n"; // mayor factor primo encontrado
                break;
            }
        }
    }

    return 0;
}

    
