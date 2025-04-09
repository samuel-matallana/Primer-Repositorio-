#include <iostream>
#include <string> 

int main(void) {
    std::string nombre;
    
    std::cout << "¿ Cómo te llamas ?";
    std::getline(std::cin, nombre);
    
    std::cout << "Hola, " << nombre << "!" << "," << "¿cómo estás?" << std::endl;
    
    return 0;
}
