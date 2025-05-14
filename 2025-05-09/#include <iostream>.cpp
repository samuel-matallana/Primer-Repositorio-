#include <iostream>
#include <cmath>

long trapezoid (long x);

int main(int argc, char **argv){
    
    int vmin = std::stoi(argv[1]);
    int vmax = std::stoi(argv[2]);

for( x = vmin+1; x <= vmax -1 ; ++ii) {
        if (isprime(ii) == true and isprime(ii+4) == true) {
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
}



long trapezoid