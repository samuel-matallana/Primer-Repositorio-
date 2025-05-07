
#include <cmath>
#include <iostream>

bool is_prime(long long int n);
long int sum_fibonacci_odd(long int num);

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "La suma de los terminos de fibonacci impares menores o iguales a "<< num <<" es " << sum_fibonacci_odd(num) << "\n";
    return 0;
}

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

long int sum_fibonacci_odd(long int num){ 
    long int ahead{1};
    long int behind{1};
    long int aux{0};
    long int sum{0};
    while (ahead<=num)
    {
        if (ahead%2!=0){
            sum+=ahead;
        }
        aux=behind;
        behind=ahead;
        ahead+=aux;
    }
    return sum;
    
}
/*Nota:
unos de los casos de prueba del encabezado 1 y 2, dan lugar a valores que salen del rango de los long así que los dejé como long long
*/
