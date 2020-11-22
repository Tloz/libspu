#include "../inc/random.h"

using namespace std;

int libspu::random_int(int min, int max)
{
    if(min > max)
        throw exception();
    return min + rand() % (max - min);
}

float libspu::random_float()
{
    return rand();
}

float libspu::random_float(float min, float max)
{
    if(min > max)
        throw exception();
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

string libspu::random_string(int length)
{
    /* TODO:
     * Do this in a way where you don't allocate memory
     * compute ascii code instead
     */

    if(length <= 0)
        throw exception();

    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    for (int i = 0; i < length; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
}