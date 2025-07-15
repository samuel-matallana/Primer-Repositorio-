#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>

// Tipos para claridad semántica
using Matrix3x3 = std::vector<std::vector<double>>;
using Vector3D = std::vector<double>;

// Crear matriz de rotación alrededor del eje X
Matrix3x3 createRotationMatrixX(double theta) {
double c = std::cos(theta);
double s = std::sin(theta);
return {
{1.0, 0.0, 0.0 },
{0.0, c , -s },
{0.0, s , c }
};
}

// Crear matriz de rotación alrededor del eje Y
Matrix3x3 createRotationMatrixY(double theta) {
double c = std::cos(theta);
double s = std::sin(theta);
return {
{ c , 0.0, s },
{0.0, 1.0, 0.0 },
{-s , 0.0, c }
};
}

// Crear matriz de rotación alrededor del eje Z
Matrix3x3 createRotationMatrixZ(double theta) {
double c = std::cos(theta);
double s = std::sin(theta);
return {
{ c , -s , 0.0 },
{ s , c , 0.0 },
{0.0, 0.0, 1.0 }
};
}

// Multiplicar una matriz 3x3 por un vector 3D
Vector3D multiply(const Matrix3x3& matrix, const Vector3D& vec) {
Vector3D result(3, 0.0);
for (int i = 0; i < 3; ++i) {
for (int j = 0; j < 3; ++j) {
result[i] += matrix[i][j] * vec[j];
}
}
return result;
}

// Aplicar rotaciones en orden: Rz(Ry(Rx(v)))
Vector3D applyRotations(const Vector3D& v, double thetaX, double thetaY, double thetaZ) {
auto Rx = createRotationMatrixX(thetaX);
auto Ry = createRotationMatrixY(thetaY);
auto Rz = createRotationMatrixZ(thetaZ);

Vector3D rotated = multiply(Rx, v);
rotated = multiply(Ry, rotated);
rotated = multiply(Rz, rotated);

return rotated;
}

int main(int argc, char* argv[]) {
if (argc != 7) {
std::cerr << "Uso: " << argv[0] << " vx vy vz thetax thetay thetaz\n";
return 1;
}

try {
// Leer parámetros de entrada
Vector3D originalVector = {
std::stod(argv[1]),
std::stod(argv[2]),
std::stod(argv[3])
};

double thetaX = std::stod(argv[4]);
double thetaY = std::stod(argv[5]);
double thetaZ = std::stod(argv[6]);

// Aplicar rotaciones
Vector3D result = applyRotations(originalVector, thetaX, thetaY, thetaZ);

// Imprimir resultado en notación científica con 10 decimales
std::cout << std::scientific << std::setprecision(10)
<< result[0] << " "
<< result[1] << " "
<< result[2] << "\n";

} catch (const std::invalid_argument&) {
std::cerr << "Error: Todos los argumentos deben ser números válidos.\n";
return 1;
} catch (const std::out_of_range&) {
std::cerr << "Error: Valor fuera de rango en uno de los argumentos.\n";
return 1;
}

return 0;
}
