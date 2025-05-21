#include <iostream>
#include <string>


int main (void){
    double x = {-9.98}, y{1.0};
    for (int ii = 1; ii <= 10;++ii){
        for (int jj = 1; jj <= 10 ; ++jj)
        {(jj <= 10 -ii) ? std::cout << " " : std::cout << "*";}
        std::cout << "\n";
    }
    std::cout << x << "\n";
    return 0;
    
}