# include <iostream>
# include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{

    const double n = std::stoi(argv[1]);
    const double r1 = std::stoi(argv[2]);
    const double r2 = std::stoi(argv[3]);
    const double d = std::stoi(argv[4]);

    Eigen::Matrix2d a; 
    Eigen::Matrix2d b; 
    Eigen::Matrix2d c;
    Eigen::Matrix2d A; 
    
 
   //std::cout.precision(16);
   //std::cout.setf(std::ios::scientific);
   a << 1, ((n-1)/r2),  0, 1;
   b << 1, 0 ,   d/n ,1 ;
   c << 1, -((n-1)/ r1),  0, 1;


  A = a * b * c;


    double valor = -1*  A (0, 1); 
    double det = A.determinant();
   


   std::cout << "Here is the matrix a:\n" << a << std::endl;
   std::cout << "Here is the matrix b:\n" << b << std::endl;
   std::cout << "Here is the matrix c:\n" << c << std::endl;
  
   std::cout << "The value of 1/f:\n" << valor << std::endl;
   std::cout << "The value of the Matriz determinant is :\n" << det << std::endl;


   return 0;
}
// 

//By William Oquendo

//© Copyright 2025. 