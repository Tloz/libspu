#include <iostream>
#include <vector>
#include <exception>

#include "../inc/matrix2d.h"


int main()
{
    size_t m;
    size_t n;

    std::cin >> m >> n;

    // floats initialized to 0.0
    libspu::Matrix2D<float> fltMatrix(m, n);
    // std::cout << fltMatrix << std::endl;
    // doubles initialized to 0.0
    // Matrix2D<double> dblMatrix(m, n);
    // std::cout << dblMatrix << std::endl;
    // // bools initialized to true
    // Matrix2D<bool>  boolMatrix(m, n, true);
    // std::cout << boolMatrix << std::endl;
    // // ints initialized to 42
    // Matrix2D<int> intMatrix(m, n, 42);
    // std::cout << intMatrix << std::endl;
}