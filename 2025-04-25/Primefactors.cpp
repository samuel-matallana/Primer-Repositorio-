#include "prime_utils.h"


// declaration

void test(void);

int main(int argc, char **argv){

    // ./a.out -> argc = 1, argv = ["./a.out"]
    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]
    // ./a.out 10 0.55 -> argc = 3, argv = ["./a.out", "10", "0.55"]
    // ./a.out 300 400 -> argc = 3, argv = ["./a.out", "300", "400"]

    
    int vmax = std::stoi(argv[1]);

    for(int ii = 2; ii <= vmax; ++ii) {
        if (isprime(ii) == true and vmax % isprime(ii) == 0) {
            std::cout << "( " << ii << " ) ";
        }
    }
    std::cout << "\n";

    return 0;
}


