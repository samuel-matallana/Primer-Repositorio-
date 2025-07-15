#include <iostream>

int main() {
    auto suma = [](int a, int b, int c, int d) {
        return a + b+c+d;
    };

    std::cout << "Suma: " << suma(3, 4,25,50) << std::endl;
    return 0;
}

