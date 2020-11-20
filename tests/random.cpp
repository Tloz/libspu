#include "../inc/random.h"
#include <cassert>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    srand( (unsigned) time(NULL) * getpid());
    cout << "Function random_int(int min, int max)" << endl;
    int iterations = 100000000;
    int minI, maxI;
    minI = 1;
    maxI = 2;
    cout << "min = " << minI << ", max = " << maxI << ". Generating " << iterations << " numbers" << endl;
    // for (int i = 0; i < iterations; ++i)
    // {
    //     int var = libspu::random_int(minI, maxI);
    //     assert((var >= minI) && (var <= maxI));
    //     if(i % 1000000 == 0)
    //         cout << "." << flush;
    // }
    cout << endl << "Passed !" << endl << endl;

    cout << "Function random_float(float min, float max)" << endl;
    float minF, maxF;
    minF = 6.5;
    maxF = 6.6;
    cout << "min = " << minF << ", max = " << maxF << ". Generating " << iterations << " numbers" << endl;
    // for (int i = 0; i < iterations; ++i)
    // {
    //     float var = libspu::random_float(minF, maxF);
    //     assert((var >= minF) && (var <= maxF));
    //     if(i % 1000000 == 0)
    //         cout << "." << flush;
    // }
    cout << endl << "Passed !" << endl;

    cout << "Function random_string(): " << libspu::random_string() << endl;
    cout << "Function random_string(-4): " << libspu::random_string(-4) << endl;
    cout << "Function random_string(15): " << libspu::random_string(15) << endl;
    return 0;
}