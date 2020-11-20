#include <iostream>
#include <string>

#define SPU_SEMVER_x 0
#define SPU_SEMVER_y 2
#define SPU_SEMVER_z 0

using namespace std;

namespace libspu
{
    int version_x();
    int version_y();
    int version_z();
    string version_a();
    string version();
    string compiledate();
    void version_info();
}