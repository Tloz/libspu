#include "random_function.h"

using namespace std;

int main()
{
    srand( (unsigned) time(NULL) * getpid());
    
    test_random_int();

    test_random_float();

    test_random_string();

    test_dice();

    // cout << "Function random_float(float min, float max)" << endl;
    // float minF, maxF;
    // minF = 6.5;
    // maxF = 6.6;
    // cout << "min = " << minF << ", max = " << maxF << ". Generating " << iterations << " numbers" << endl;
    // for (int i = 0; i < iterations; ++i)
    // {
    //     float var = libspu::random_float(minF, maxF);
    //     assert((var >= minF) && (var <= maxF));
    //     if(i % 1000000 == 0)
    //         cout << "." << flush;
    // }
    // cout << endl << "Passed !" << endl;

    // cout << "Function random_string(): " << libspu::random_string() << endl;
    // cout << "Function random_string(4): " << libspu::random_string(4) << endl;
    // cout << "Function random_string(15): " << libspu::random_string(15) << endl << endl;

    return 0;
}