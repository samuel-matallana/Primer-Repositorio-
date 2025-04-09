#include <iostream>
#include <string> 

int main() {
    std::string nombre;
    
    std::cout << "Samuel Matallana";
    std::getline(std::cin, nombre);
    
    std::cout << "Hola, " << nombre << "!";
    
    return 0;
}
