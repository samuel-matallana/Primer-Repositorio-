#include <iostream>
int main (void) {
   const int NUM = 10;
    int guessed_number;
   
    for (;;) {
        std::cout << " Adivina un núnmero entre 1 y 100: \n";
        std::cin >> guessed_number;

        if (guessed_number == NUM) {
            std::cout << "Adivinaste!!!\n";
            break;
          } else if(guessed_number > NUM) {
            std::cout << "Te pasaste, pero puedes tratar de nuevo\n"; 
         } else { 
            std::cout << "Te falta, pero puedes tratar de nuevo\n";
         } 
    }

    return 0;
 }