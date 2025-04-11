#include <iostream>
#include <random>


// declaration
void play(int min_val, int max_val);


int main(void) {
    play(1, 100);
    play(2,22);

    return 0;
}
// Implmentamos 
void play(int success, int min_val, int max_val)
{
    const int NUM = success;
    int guessed_number = NUM/2;

    const int MIN = min_val;
    const int MAX = max_val;



    while(guessed_number != NUM) {
        std::cout << "Adivina un numero entre  " << MIN << "  y " << MAX << ":\n";
        std::cin >> guessed_number;
        std::cout << "Ecribiste: " << guessed_number << "\n";

        // validacion del rango 
        if (guessed_number < MIN or MAX < guessed_number) {
            std::cout << "Pero era entre 1 y 100 >:( \n";
            continue; 
        }

        if (guessed_number == NUM) {
            std::cout << "Adivinaste!!!!\n";
            //break;
        } else if (guessed_number > NUM){
            std::cout << "Te pasaste, pero puedes volver a intentar\n";
        } else { // es menor
            std::cout << "Te falta, pero puedes volver a intentar\n";
        }
    }

} 