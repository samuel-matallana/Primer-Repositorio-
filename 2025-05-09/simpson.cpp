#include <iostream>
#include "integration.h"
// declaration 

double simpson(double inf, double sup, int steps, fptr f){
double x = inf;
double suma= 0.0;
double sumb= 0.0;
int step = steps;
double b = 0.0;
double dx = ((sup -inf)/steps);

if( step % 2 == 0) {
for( int n = 1; n <= steps  ; ++n) {
        x +=dx;
        if (n % 2 == 0 )
    { suma += f(x);}
    else 
{sumb += f(x);}



    double result {(dx/3)*( f(inf) + 4*suma + 2*sumb+ f(sup))};
    return result; 
}}}