#include <iostream>
#include <cmath>
#include <string>



int main(void){

    
    unsigned long long  sum= 0;
    

    for( unsigned long long ii=1; ii == 1000;  ++ii) {
         sum += static_cast<unsigned long long>(pow(ii, ii));
    std::cout << sum << "\n";}
    

    return 0;
}