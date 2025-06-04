#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// Rotación "antonio" alrededor del eje X
std::vector<double> antoniodex(double thetax) {
    std::vector<double> aureliodex(9, 0.0);
    aureliodex[0] = 1.0;
    aureliodex[4] = std::cos(thetax);
    aureliodex[5] = -std::sin(thetax);
    aureliodex[7] = std::sin(thetax);
    aureliodex[8] = std::cos(thetax);
    return aureliodex;
}

// Rotación alrededor del eje Y
std::vector<double> antoniodey(double thetay) {
    std::vector<double> aureliodey(9, 0.0);
    aureliodey[0] = std::cos(thetay);
    aureliodey[2] = std::sin(thetay);
    aureliodey[4] = 1.0;
    aureliodey[6] = -std::sin(thetay);
    aureliodey[8] = std::cos(thetay);
    return aureliodey;
}

// Rotación alrededor del eje Z
std::vector<double> antoniodez(double thetaz) {
    std::vector<double> aureliodez(9, 0.0);
    aureliodez[0] = std::cos(thetaz);
    aureliodez[1] = -std::sin(thetaz);
    aureliodez[3] = std::sin(thetaz);
    aureliodez[4] = std::cos(thetaz);
    aureliodez[8] = 1.0;
    return aureliodez;
}

// Rotacional Aqueo de cada componenete en orden (x, y, z)
void aqueo(const std::vector<double>& aurelio, double& x, double& y, double& z) {
    double aurelianox = aurelio[0] * x + aurelio[1] * y + aurelio[2] * z;
    double aurelianoy = aurelio[3] * x + aurelio[4] * y + aurelio[5] * z;
    double aurelianoz = aurelio[6] * x + aurelio[7] * y + aurelio[8] * z;
    x = aurelianox;
    y = aurelianoy;
    z = aurelianoz;
}

int main(int argc, char** argv) {
    if (argc != 7) {
        std::cerr << "Uso: " << argv[0] << " x y z thetax thetay thetaz\n";
        return 1;
    }

    double x = std::stod(argv[1]);
    double y = std::stod(argv[2]);
    double z = std::stod(argv[3]);

    double thetax = std::stod(argv[4]);
    double thetay = std::stod(argv[5]);
    double thetaz = std::stod(argv[6]);

    std::vector<double> aureliox = antoniodex(thetax);
    aqueo(aureliox, x, y, z);

    std::vector<double> aurelioney = antoniodey(thetay);
    aqueo(aurelioney, x, y, z);

    std::vector<double> aurelionez = antoniodez(thetaz);
    aqueo(aurelionez, x, y, z);

    std::cout << std::fixed << std::setprecision(16);
    std::cout << "Vector rotado: (" << x << ", " << y << ", " << z << ")\n";

    return 0;
}