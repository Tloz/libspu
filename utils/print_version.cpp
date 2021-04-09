#include "../inc/version.h"
#include <iostream>

using namespace std;

// This prints a string containing the current SEMVER
// This is used to put the version in the archive's name
// So please leave this untouched

int main()
{
    cout << libspu::version() << endl;
    return 0;
}