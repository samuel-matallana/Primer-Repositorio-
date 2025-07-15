#include <iostream>
#include <valarray>
#include <cmath>
#include "ivp_solver.h"



typedef std::valarray<double> state_t; // alias for state type

void initial_conditions(state_t & y);
void print(const state_t & y, double time);
void fderiv(const state_t & y, state_t & dydt, double t);

int main(int argc, char **argv)
     const double  ti = std::stoi(argv[3]);
{    const double  w = std::stoi(argv[4]);
     const double A = 0.5
    int N = 1;
    state_t y(N);
    initial_conditions(y);

    // // lambda for derivatives
    // auto fderiv = [R](const state_t & y, state_t & dydt, double t){
    //     dydt[0] = R*y[0]*(1-y[0]);
    // };

    //integrate_euler(fderiv, y, 0.0, 10.0, 0.05, print);
    integrate_heun(fderiv, y, 0.0, 10.0, 0.05, print);
    return 0;
}

void initial_conditions(state_t & y)
{
  y[0] = 0.5;
}

void print(const state_t & y, double time)
{
  std::cout << time << "\t" << y[0] << std::endl;
}

void fderiv(const w,  const state_t & y, state_t & dydt, double t)
{
    dydt[0] = -w*A*sd::sin(w*t)
}