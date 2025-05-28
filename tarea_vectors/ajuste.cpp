#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_datos.txt" << std::endl;
        return 1;
    }

    std::string fname = argv[1];
    std::ifstream fin(fname);
    if (!fin) {
        std::cerr << "No se pudo abrir el archivo " << fname << std::endl;
        return 1;
    }

    std::vector<double> xdata, ydata;
    double x, y;

    while (fin >> x >> y) {
        xdata.push_back(x);
        ydata.push_back(y);
    }
    fin.close();

    int N = xdata.size();
    double Ex = 0, Ey = 0, Exx = 0, Exy = 0, Eyy = 0;
    for (int i = 0; i < N; ++i) {
        Ex += xdata[i];
        Ey += ydata[i];
        Exx += xdata[i] * xdata[i];
        Exy += xdata[i] * ydata[i];
        Eyy += ydata[i] * ydata[i];
    }
    Ex /= N;
    Ey /= N;
    Exx /= N;
    Exy /= N;
    Eyy /= N;

    double m = (Exy - Ex * Ey) / (Exx - Ex * Ex);
    double b = (Exx * Ey - Ex * Exy) / (Exx - Ex * Ex);

    double s2 = (Eyy - Ey * Ey - m * m * (Exx - Ex * Ex)) * N / (N - 2);
    double dm = std::sqrt(s2 / (N * (Exx - Ex * Ex)));
    double db = std::sqrt(dm * dm * Exx);

    std::cout << "Pendiente m = " << m << " ± " << dm << std::endl;
    std::cout << "Ordenada b = " << b << " ± " << db << std::endl;

    double h = m * 1.602176634e-19;
    std::cout << "h estimada = " << h << " J·s" << std::endl;

    // Escribir archivo para Gnuplot
    std::ofstream fout("ajuste.dat");
    for (int i = 0; i < N; ++i) {
        fout << xdata[i] << " " << ydata[i] << " " << m * xdata[i] + b << std::endl;
    }
    fout.close();

    return 0;
}