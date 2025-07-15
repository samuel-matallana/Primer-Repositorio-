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

std::cout<< a <<"\n";
std::cout<< b <<"\n";
    return 0;

}