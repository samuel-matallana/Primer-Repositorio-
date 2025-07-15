#include <iostream>
#include <ostream>
#include<cmath>
int duplicar(int x) {
    return x*2
;}

void incrementar (int& y) {y++;}
int main (int argc, char**argv)
{
    int a = 5;
    int b = duplicar(a);
    incrementar (b);

int arr[5] ;
arr[0] = 1;
arr[1] = 1;
arr[2] = 1;
arr[3] = 1;
arr[4] = 1;
arr[5] = 1 ;
 
std::cout<< a <<"\n";
std::cout<< b <<"\n";
std::cout << sizeof(arr)/sizeof(arr[0])<< "\n";
    return 0;

}