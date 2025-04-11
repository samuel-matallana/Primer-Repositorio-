#include <iostream>
int main (void) {
   const int NUM = 10;
    unsigned int guessed_number = NUM+1;
   
    while (guessed_number!= NUM  ) {
        std::cout << " Adivina un núnmero entre 1 y 100: \n";
        std::cin >> guessed_number;
        std:: cout << "Escribiste: " << guessed_number << "\n" ;
        //Validación del rango 
        if ( 1 >= guessed_number or guessed_number >= 100 ){
         std:: cout << "Era entre 1 y 100 >:( \n" ;
         continue;
         }

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