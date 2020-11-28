#include <iostream>
#include <vector>
#include <exception>

#include "../inc/matrix2d.h"


int main()
{
    size_t m;
    size_t n;

    std::cin >> m >> n;

    // ints initialized to 42
    libspu::Matrix2D<int> grid(m, n, 42);
    std::cout << grid << std::endl;
    grid(3, 3) = 6;
    std::cout << grid << std::endl;
}