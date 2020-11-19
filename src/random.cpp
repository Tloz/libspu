#include "../inc/random.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
// #include <vector>
// #include <string>

float libpsu::randFloatInRange(float min, float max)
{
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
