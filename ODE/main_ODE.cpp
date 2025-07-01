#include <iostream>
#include <valarray>
#include <cmath>
#include <functional>
#include <fstream>

typedef std::valarray<double> state_t;

void print(const state_t & y, double time, const char *fname)
{
    std::ofstream file(fname, std::ios::app);
    file << y[0] << " " << y[1] << std::endl; // posición y velocidad
    file.close();
}

template <class deriv_t, class system_t, class printer_t>
void solve_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    system_t dsdt(s.size());

    for(double t = tinit; t <= tend; t += dt) {
        fderiv(s, dsdt, t);
        s = s + dt * dsdt;
        writer(s, t, "output-euler.txt");
    }
}

template <class deriv_t, class system_t, class printer_t>
void solve_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    system_t k1(s.size()), k2(s.size()), y1(s.size());

    for(double t = tinit; t <= tend; t += dt) {
        fderiv(s, k1, t);
        y1 = s + dt * k1;
        fderiv(y1, k2, t + dt);
        s = s + (dt / 2.0) * (k1 + k2);
        writer(s, t, "output-heun.txt");
    }
}

int main(int argc, char **argv)
{
    if(argc != 5) {
        std::cerr << "Uso: " << argv[0] << " dt t0 tf w\n";
        return 1;
    }

    const double dt = std::stod(argv[1]);
    const double t0 = std::stod(argv[2]);
    const double tf = std::stod(argv[3]);
    const double w  = std::stod(argv[4]);

    state_t y(2); // y[0] = posición, y[1] = velocidad
    double y0 = 1.0, v0 = 0.0;

    y[0] = y0; y[1] = v0;

    // Derivadas para oscilador armónico
    auto fderiv = [w](const state_t & y, state_t & dydt, double t) {
        dydt[0] = y[1];
        dydt[1] = -w * w * y[0];
    };

    // Limpiar archivos previos
    std::ofstream("output-euler.txt").close();
    std::ofstream("output-heun.txt").close();

    // Resolver con Euler
    solve_euler(fderiv, y, t0, tf, dt, print);

    // Reset de condiciones iniciales
    y[0] = y0; y[1] = v0;

    // Resolver con Heun
    solve_heun(fderiv, y, t0, tf, dt, print);

    std::cout << "Simulaciones completas. Datos en output-euler.txt y output-heun.txt\n";
    return 0;
}
