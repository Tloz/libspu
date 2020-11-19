#include "../inc/random.h"

int libspu::random_int(int min, int max)
{
    return min + rand() % (max - min);
}

float libspu::random_float()
{
    return rand();
}

float libspu::random_float(float min, float max)
{
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}
