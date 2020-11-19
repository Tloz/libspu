#include <iostream>
#include <string>
#include "inc/base64.h"

using namespace std;

#define SPU_SEMVER_x 0
#define SPU_SEMVER_y 0
#define SPU_SEMVER_z 1

namespace libpsu
{
    void version()
    {
        // Use this if you want to add detail on SEMVER
        // Using this cuz we cant leave an empty #define
        // Yes, I know, that's ugly
        string SPU_SEMVER_addendum("");

        cout << "libspu v" << SPU_SEMVER_x << "." << SPU_SEMVER_y << "." << SPU_SEMVER_z;
        if(SPU_SEMVER_addendum.length() != 0)
        {
            cout << SPU_SEMVER_addendum;
        }
        cout << " (using SEMVER)" << endl;
        cout << "Compiled on " << __DATE__ << endl;
    }
}


int main(int argc, char const *argv[])
{
    // cout << "Base64: " << libspu::base64::encode(string("You will never catch me haha !")) << endl;
    if((argc > 1) && (string(argv[1]).compare(string("-v")) == 0))
    {
        libpsu::version();
        return 0;
    }
    return 0;
}