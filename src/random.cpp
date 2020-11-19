#include "../inc/random.h"

// #include <iostream>
// #include <iomanip>
// #include <sstream>


int libspu::random_Int(int min, int max)
{
    return min + rand() % max;
}

float libspu::random_Float()
{
    return rand();
}

float libspu::random_Float(float min, float max)
{
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
