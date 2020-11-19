#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>


using namespace std;

namespace libspu
{
    int random_Int(int min = 0 , int max = RAND_MAX);
    float random_Float();
    float random_Float(float min, float max);
}


#endif // RANDOM_H