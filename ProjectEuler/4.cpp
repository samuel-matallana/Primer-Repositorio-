#include <iostream>
#include <cmath>

int main(int argc, char **argv){


    long limit = std::stol(argv[1]);
    long sum = 0; 
    long a = 121; 
    long b = 0; 
    long ii = 0; 
    long pal = 0;

    for (ii =1; ii <= 999000; ii++  )  {
       if ( ii % 11 == 0){pal = ii ;};
         b = pal / 121;

    } 
std::cout << pal << " " << a << " " << b <<"\n";
return 0;
}
