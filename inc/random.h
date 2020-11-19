#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>

using namespace std;

// 
// TODO: throw exception when min > max
// 

namespace libspu
{
    int random_int(int min = 0 , int max = RAND_MAX);
    float random_float();
    float random_float(float min, float max);
}


#endif // RANDOM_H