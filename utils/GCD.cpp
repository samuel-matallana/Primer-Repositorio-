#include "GCM.h"
#include "LCM.h"

long long gcd (long long a, long long  b);

int main(int argc, char **argv) {

    long a = std::stoi(argv[1]);
    long b = std::stoi(argv[2]);



    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    std::cout << a << "\n"; 

}