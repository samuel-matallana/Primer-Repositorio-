#pragma once
#include <cmath>
#include <functional>
 
 using fptr = std::function < double(double)>;

double trapezoid(double inf, double sup, int steps, fptr f);
double simpson(double inf, double sup, int steps, fptr f);

using algptr = std::function<double(double, double, int, fptr)>;


double richardson_t(double inf, double sup, int steps, fptr f, algptr alg, int alpha);

double gauss2 (double inf, double sup, fptr f);
double gauss3 (double inf, double sup, fptr f);                             
