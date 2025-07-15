#pragma once

// ivp_solver.h
#include <iostream>
#include <valarray>
#include <functional>


// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());
    system_t dsdt_1(s.size());


    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);
        fderiv( s+ dt*dsdt, dsdt_1, t+dt )
        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = dsdt + (dt/2)(dsdt*dsdt1)// Euler
         
        double heun1 = s*dt + t  
        double heun = s (dt/2)*(heun1+s)
        // write new state
        writer(s, t,  heun);
      }
} 
