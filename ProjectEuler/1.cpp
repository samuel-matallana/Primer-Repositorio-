#include <iostream>
#include <cmath>

int main(int argc, char **argv){


    long limit = std::stol(argv[1]);
    long sum = 0; 
    long ii = 0; 
 for (ii=0; ii < limit; ii++)  {
        if (ii % 3 == 0 or ii % 5 == 0){
            sum += ii;
            }
 } 
std::cout << sum << "\n";
return 0;
}

