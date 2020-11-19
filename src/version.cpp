#include "../inc/version.h"

// Use this if you want to add detail on SEMVER
// Using this cuz we cant leave an empty #define
// Yes, I know, that's ugly
string SPU_SEMVER_addendum("");

int libspu::version_x()
{
    return SPU_SEMVER_x;
}

int libspu::version_y()
{
    return SPU_SEMVER_x;
}

int libspu::version_z()
{
    return SPU_SEMVER_x;
}

string libspu::version_a()
{
    return SPU_SEMVER_addendum;
}

string libspu::version()
{
    string v("");
    v += to_string(SPU_SEMVER_x) + "." + to_string(SPU_SEMVER_y) + "." + to_string(SPU_SEMVER_z);
    if(SPU_SEMVER_addendum.length() != 0)
        v += SPU_SEMVER_addendum;
    return v;
}

string libspu::compiledate()
{
    return string(__DATE__);
}

void libspu::version_info()
{
    cout << "libspu version ";
    cout << libspu::version();
    cout << " (using SEMVER)" << endl;
    cout << "Compiled on " << libspu::compiledate() << endl;
}