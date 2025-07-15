#include <iostream>
#include <functional>

int main() {
    auto crear_multiplicador = [](int factor) {
        return [factor](int x) {
            return x * factor;
        };
    };

    auto por5 = crear_multiplicador(5);
    std::cout << "5 × 4 = " << por5(4) << std::endl;

    return 0;
}
