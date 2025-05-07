#include <iostream>
#include <cmath>

// declaracion
void Pi_aprox( int n_deseada);

int main(void)
{
    int n_deseada = 0;
   
     
    std::cout << "Aproximemos pi, escribe el numero de iteraciones para aproximar pi de forma numerica, recuerda puedes elegir entre 1 y 20\n";
    std::cin >> n_deseada;
    std::cout << "Ecribiste: " << n_deseada << "\n";
    std::cout.setf(std::ios::fixed);
    std::cout.precision(16);
    Pi_aprox( n_deseada); 
    
   

    
}
    

// Implementanding
void Pi_aprox( int n_deseada)
{
    double pi_aprox = 0.0;
     const int MIN = 1;
     const int MAX = 20;



    // iteración individual, aca crece la idea es que n pase por varios valores hasta la n deseada, y pi aprox guarde cada valor y luego lo sume, ojito, n es menor en el for por que apenas iguale el deseado, se para el for
    
    do while (n_deseada >= MIN and n_deseada <= MAX) // intento 32000 de que la validación no salga mal 
   { 

   
    for (int n = 0; n < n_deseada; n++)
    { 
    
     

     
     
    


        double termino = (1.0 / pow(16, n)) * ((4.0 / ((8 * n) + 1)) - (2.0 / ((8 * n) + 4)) - (1.0 / ((8 * n) + 5)) - (1.0 / ((8 * n) + 6)));
        pi_aprox += termino;

        
    }

    std::cout << "tu aproximacion de pi con " << n_deseada<< " terminos para n es:" << pi_aprox<< "\n";
}
while 
}
