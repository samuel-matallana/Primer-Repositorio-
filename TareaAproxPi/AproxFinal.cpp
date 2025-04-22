#include <iostream>
#include <cmath>

// declaracion
void Pi_aprox( int n_deseada);

int main(void)
{
    int n_deseada = 21;
   
     
    std::cout << "Aproximación de pi usando métodos númericos\n";
    
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::scientific);
    std::cout.precision(16);
    Pi_aprox( n_deseada); 
    
   return 0;

    
}
    

// Implementanding
void Pi_aprox( int n_deseada)
{
    double pi_aprox = 3.1333333333333333;
    


    // iteración individual, aca crece la idea es que n pase por varios valores hasta la n deseada, y pi aprox guarde cada valor y luego lo sume, ojito, n es menor 
    //en el for por que apenas iguale el deseado, se para el for
    

    for (int n = 1; n < n_deseada; n++)
    { 
     
        double termino = (1.0 / pow(16, n)) * ((4.0 / ((8 * n) + 1)) - (2.0 / ((8 * n) + 4)) - (1.0 / ((8 * n) + 5)) - (1.0 / ((8 * n) + 6)));
        pi_aprox += termino;
        double error_porcentual = fabs(1-(pi_aprox/M_PI));

         

        std::cout << "El valor de Pi aproximado con una sumatoria con n= " << n << " elementos es: " << pi_aprox  << " su error relativo con respecto al valor proporcionado por M_PI es de " << std::scientific << error_porcentual << " % \n";
    } 
    

    
     


   

    
}

  