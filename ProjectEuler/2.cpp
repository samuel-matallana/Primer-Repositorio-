#include <iostream>
#include <cmath>

int main(int argc, char **argv){


    long limit = std::stol(argv[1]);
    long sum = 0; 
    long a = 1; 
    long b = 2; 
    long c = 0; 

    while (a <= limit)  {
        if (a % 2 == 0) {
            sum += a;
        }
        c = a + b;
        a = b;
        b = c;
    } 
std::cout << sum << "\n";
return 0;
}

