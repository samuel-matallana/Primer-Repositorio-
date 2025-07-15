#include "matrix_utils.h"

int main (){
    int N = 2;
    std::vector<double> A(N*N, 0.0);
    std::vector<double> B(N*N, 0.0);

    //Matriz identidad
    for (int i=0; i<N; i++){
        A[i*(N+1)]= 1;
    }
    for (int i=0; i<N; i++){
        B[i*(N+1)]= 1;
    }

    std::cout << check_inverse(N, A, B, 0.0001) << "\n";

    //Matriz identidad ligeramente cambiada, pero sigue diciendo que son iguales
    for (int i=0; i<N; i++){
        B[i*(N+1)]= 0.99997;
    }
    std::cout << check_inverse(N, A, B, 0.0001) << "\n";

    //Matriz identidad ligeramente cambiada, pero dice que no son inversas
    for (int i=0; i<N; i++){
        B[i*(N+1)]= 0.997;
    }
    std::cout << check_inverse(N, A, B, 0.0001) << "\n";


    return 0;
}