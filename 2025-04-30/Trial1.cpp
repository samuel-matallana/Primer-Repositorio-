
#include <cmath>
#include <iostream>

bool is_prime(long long int n);
long long int sum_primes_lt(long long int n);

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "La suma de los numeros primos menores o iguales a "<< num <<" es "<<sum_primes_lt(num) << "\n";
    return 0;
}

/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/

bool is_prime(long long int n){

    if(n<=1){ 
        return false; 
    } else if (n%2==0 && n!=2){
        return false;
    }
    
    for(long long int ii=3;ii<=sqrt(n);ii+=2){
        if( n%ii==0 ){
            return false;
        } 
    }

    return true;
}

long long int sum_primes_lt(long long int n){
    long long int sum {0};
    for (long long int ii = 1; ii<=n; ii++){
        if (is_prime(ii)){
            sum+=ii;
        }
    }
    return sum;
}