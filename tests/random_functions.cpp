#include "random_function.h"
using namespace std;

void test_random_int()
{
    int iterations = 10000;
    int valMin = 3;
    int valMax = 20;
    bool minReached = false;
    bool maxReached = false;
    cout << "Testing random_int(" << valMin << ", " << valMax << "):" << endl;
    cout << "Generating " << iterations << " numbers between " << valMin << " and " << valMax << endl;

    for (int i = 0; i < iterations; ++i)
    {
        int var = libspu::random_int(valMin, valMax);
        if(var == valMax)
            maxReached = true;
        else if(var == valMin)
            minReached = true;
        assert((var >= valMin) && (var <= valMax));
        // code below prints a dot every 1000000 number
        // if(i % 1000000 == 0)
        //     cout << "." << flush;
    }
    cout << "All assertions passed !" << endl;
    cout << "Minimum (" << valMin << ") ";
    if(minReached)
    {
        cout << "reached !";
    }
    else
    {
        cout << "not reached...";
    }
    cout << endl;

    cout << "Maximum (" << valMax << ") ";
    if(maxReached)
    {
        cout << "reached !";
    }
    else
    {
        cout << "not reached...";
    }
    cout << endl << endl;
}

void test_random_float()
{
    cout << "Function random_float(float min, float max)" << endl;
    int iterations = 100000;
    float minF, maxF;

    minF = 1.25;
    maxF = 31415.169;
    cout << "min = " << minF << ", max = " << maxF << ". Generating " << iterations << " numbers" << endl;
    for (int i = 0; i < iterations; ++i)
    {
        float var = libspu::random_float(minF, maxF);
        cout << "iteration " << i << " : " << var << endl;
        assert((var >= minF) && (var <= maxF));
        if(i % 1000000 == 0)
            cout << "." << flush;
    }
    
    
    minF = 6.5;
    maxF = 6.6;
    
    cout << "min = " << minF << ", max = " << maxF << ". Generating " << iterations << " numbers" << endl;
    for (int i = 0; i < iterations; ++i)
    {
        float var = libspu::random_float(minF, maxF);
        cout << "iteration " << i << " : " << var << endl;
        assert((var >= minF) && (var <= maxF));
        if(i % 1000000 == 0)
            cout << "." << flush;
    }
    cout << endl << "Passed !" << endl;
}

void test_random_string()
{

}

void test_dice()
{

}