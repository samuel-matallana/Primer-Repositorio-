#include <iostream>
#include <cmath>
#include <string>


// declaration

int largest_prime_factor (int m);

//impllementanding

int main (void){
    std::cout << largest_prime_factor(9)<< std::endl;
    std::cout << largest_prime_factor(97)<< std::endl;
    std::cout << largest_prime_factor(100)<< std::endl;
    std::cout << largest_prime_factor(12345)<< std::endl;
    std::cout << largest_prime_factor(1000099)<< std::endl;
    std::cout << largest_prime_factor(5412345)<< std::endl;
return 0;
}


int largest_prime_factor (int m) {
    int factor =2;
    int largest = 2; 

    
    while (m > 1) {
        if (m % factor == 0) {
            largest = factor;
            while (m % factor == 0) {
                m /= factor;
            }
        }
        factor++;
    }

    return largest;}