#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <array>

constexpr double PI = 3.14159265358979323846;
constexpr double EPSILON = 1e-10;

using Matrix3x3 = std::array<std::array<double, 3>, 3>;
using Vector3 = std::array<double, 3>;

// Funciones optimizadas con constexpr donde sea posible
constexpr Matrix3x3 rotationMatrixX(double theta) noexcept {
    return {{
        {1.0, 0.0, 0.0},
        {0.0, std::cos(theta), -std::sin(theta)},
        {0.0, std::sin(theta), std::cos(theta)}
    }};
}

constexpr Matrix3x3 rotationMatrixY(double theta) noexcept {
    return {{
        {std::cos(theta), 0.0, std::sin(theta)},
        {0.0, 1.0, 0.0},
        {-std::sin(theta), 0.0, std::cos(theta)}
    }};
}

constexpr Matrix3x3 rotationMatrixZ(double theta) noexcept {
    return {{
        {std::cos(theta), -std::sin(theta), 0.0},
        {std::sin(theta), std::cos(theta), 0.0},
        {0.0, 0.0, 1.0}
    }};
}

constexpr Vector3 applyMatrix(const Vector3& v, const Matrix3x3& m) noexcept {
    return {
        m[0][0]*v[0] + m[0][1]*v[1] + m[0][2]*v[2],
        m[1][0]*v[0] + m[1][1]*v[1] + m[1][2]*v[2],
        m[2][0]*v[0] + m[2][1]*v[1] + m[2][2]*v[2]
    };
}

// Función de formato optimizada
std::string formatComponent(double val) {
    if (std::abs(val) < EPSILON) return "@";
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6);
    
    // Manejo de valores cercanos a 1 o -1
    if (std::abs(val - 1.0) < EPSILON) return "1";
    if (std::abs(val + 1.0) < EPSILON) return "-1";
    
    // Valores científicos pequeños
    if (std::abs(val) < 1e-5) {
        oss << std::scientific << val;
        std::string s = oss.str();
        auto e_pos = s.find('e');
        if (e_pos != std::string::npos) {
            s.erase(s.find_last_not_of('0') + 1, e_pos);
            if (s.back() == '.') s.pop_back();
        }
        return s;
    }
    
    // Valores decimales normales
    oss << val;
    std::string s = oss.str();
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    if (s.back() == '.') s.pop_back();
    return s;
}

void printVector(const Vector3& v) {
    std::string x_str = formatComponent(v[0]);
    std::string y_str = formatComponent(v[1]);
    std::string z_str = formatComponent(v[2]);
    
    std::cout << x_str << " " << y_str;
    if (z_str != "@") std::cout << " " << z_str;
    std::cout << "\n";
}

double parseInput(const char* arg) {
    if (std::string(arg) == "@") return 0.0;
    return std::stod(arg);
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        std::cerr << "Uso: " << argv[0] << " vx vy vz thetax thetay thetaz\n";
        std::cerr << "Use '@' para valores cero\n";
        return 1;
    }

    try {
        Vector3 v{
            parseInput(argv[1]),
            parseInput(argv[2]),
            parseInput(argv[3])
        };
        
        // Aplicar rotaciones en orden Z-Y-X (más eficiente que crear matrices temporales)
        double angles[3] = {
            parseInput(argv[6]),  // Z
            parseInput(argv[5]),  // Y
            parseInput(argv[4])   // X
        };
        
        // Optimización: calcular directamente la matriz compuesta
        const auto rotZ = rotationMatrixZ(angles[0]);
        const auto rotYZ = rotationMatrixY(angles[1]);
        const auto rotXYZ = rotationMatrixX(angles[2]);
        
        // Multiplicación de matrices optimizada
        Matrix3x3 composite;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                composite[i][j] = rotXYZ[i][0]*rotYZ[0][j] + 
                                 rotXYZ[i][1]*rotYZ[1][j] + 
                                 rotXYZ[i][2]*rotYZ[2][j];
            }
        }
        
        Matrix3x3 finalMatrix;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                finalMatrix[i][j] = composite[i][0]*rotZ[0][j] + 
                                   composite[i][1]*rotZ[1][j] + 
                                   composite[i][2]*rotZ[2][j];
            }
        }
        
        Vector3 result = applyMatrix(v, finalMatrix);
        printVector(result);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    
    return 0;
}
