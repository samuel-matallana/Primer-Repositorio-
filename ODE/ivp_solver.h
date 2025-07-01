#pragma once

#include <valarray>

template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer) {
    system_t dsdt(s.size());
    for(double t = tinit; t <= tend; t += dt) {
        fderiv(s, dsdt, t);
        s = s + dt * dsdt;
        writer(s, t);
    }
}

template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer) {
    system_t k1(s.size()), k2(s.size()), y1(s.size());
    for(double t = tinit; t <= tend; t += dt) {
        fderiv(s, k1, t);
        y1 = s + dt * k1;
        fderiv(y1, k2, t + dt);
        s = s + (dt / 2.0) * (k1 + k2);
        writer(s, t);
    }
}
