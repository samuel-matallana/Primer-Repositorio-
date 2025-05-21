#include <iostream>
#include "integration.h"
// declaration 
double f (double x);

double trapezoid(double inf, double sup, double steps, fptr f);

long sum= 0
long dx = ((sup -inf)/steps)
for( int n = 1; n <= steps-1  ; ++n) {
     x += inf + n*dx
    sum += f (x) 
    }
}