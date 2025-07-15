#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> multiplyMatrixVector(const vector<vector<double>>& M, const vector<double>& v) {
    vector<double> result(3, 0.0);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result[i] += M[i][j] * v[j];
    return result;
}

vector<vector<double>> rotationX(double theta) {
    return {
        {1, 0, 0},
        {0, cos(theta), -sin(theta)},
        {0, sin(theta), cos(theta)}
    };
}

vector<vector<double>> rotationY(double theta) {
    return {
        {cos(theta), 0, sin(theta)},
        {0, 1, 0},
        {-sin(theta), 0, cos(theta)}
    };
}

vector<vector<double>> rotationZ(double theta) {
    return {
        {cos(theta), -sin(theta), 0},
        {sin(theta), cos(theta), 0},
        {0, 0, 1}
    };
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        cerr << "Uso: ./a.out vx vy vz thetax thetay thetaz\n";
        return 1;
    }

    double vx = atof(argv[1]);
    double vy = atof(argv[2]);
    double vz = atof(argv[3]);
    double thetax = atof(argv[4]);
    double thetay = atof(argv[5]);
    double thetaz = atof(argv[6]);

    vector<double> v = {vx, vy, vz};

    vector<vector<double>> Rx = rotationX(thetax);
    vector<vector<double>> Ry = rotationY(thetay);
    vector<vector<double>> Rz = rotationZ(thetaz);

    v = multiplyMatrixVector(Rx, v);
    v = multiplyMatrixVector(Ry, v);
    v = multiplyMatrixVector(Rz, v);

    printf("%.6f %.6f %.6f\n", v[0], v[1], v[2]);

    return 0;
}
