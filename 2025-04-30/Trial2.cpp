
#include <cmath>
#include <iostream>

bool is_prime(long long int n);
long long int great_prime_factor(long long int num);

int main(int argc, char **argv){
    long long int num = std::stoll(argv[1]);
    std::cout << "El factor primo mas grande de "<< num <<" es " << great_prime_factor(num) << "\n";
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

long long int great_prime_factor(long long int num){
    long long int result {0};
    long long int ii {2};

    if (is_prime(num)){ 
        return num; 
    }

    while (ii*ii<=num){
        result=num/ii;
        if ( num%ii!=0 ){
            ii++;
            continue;
        } else if(is_prime(result)){
            break;
        }
        num=result;
    }

    return result;
}
