#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 5, 3, 9, 2};

    std::sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
