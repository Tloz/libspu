#include <iostream>

#include "../inc/version.h"

using namespace std;

// Use this if you want to add detail on SEMVER
// Using this cuz we cant leave an empty #define
// Yes, I know, that's ugly
string SPU_SEMVER_addendum(SPU_SEMVER_DEFADDENDUM);

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

std::string libspu::info()
{
    return SPU_INFO;
}

std::string libspu::license()
{
    return SPU_LICENSE;
}

std::string libspu::license_info()
{
    return SPU_LICENSE_INFO;
}


std::string libspu::getRemoteVersionString(std::string API_target)
{
    // TODO: proper fetchnig of version string
    cout << endl << endl << "/!\\ WARNING: This is emulated, no connection made /!\\" << endl << endl;
    // cout << "Calling " + SPU_SEMVER_API_TARGET + "..." << endl;
    return "0.1.0";
    // return "0.2.0-alpha";
    // return "1.0.0";
    // return "2.3.5";
    // return "3.0.1-rc";
}

int libspu::compareVersions(std::string remote, std::string local)
{
    // TODO: split remote into numbers
    unsigned int remote_major;
    unsigned int remote_minor;
    unsigned int remote_patch;
    std::string remote_metadata;
    unsigned int local_major = SPU_SEMVER_x;
    unsigned int local_minor = SPU_SEMVER_y;
    unsigned int local_patch = SPU_SEMVER_z;
    std::string local_metadata = SPU_SEMVER_addendum;

    // TODO:assign values to above variable by cutting parameters properly

    if(remote_major > local_major)
        return 4; // There is a new major version
    if(remote_minor > local_minor)
        return 3; // There is a new minor version
    if(remote_patch > local_patch)
        return 2; // There is a new patch
    if(remote_metadata != local_metadata) // WARNING, non properway to compare strings !!!!
        return 1; // There is an other build
    return 0; // remote and local versions are the same or local version is ahead of repo
}

std::string libspu::readableVersionState(int code)
{
    switch(code)
    {
        case 0:
        return "Remote and local version are the same (or you are ahead of dev branch, lucky you)";
        break;

        case 1:
        return "There is a new build";
        break;

        case 2:
        return "There is a new patch";
        break;

        case 3:
        return "There is a new minor version";
        break;

        case 4:
        return "There is a new major version";
        break;

        default:
        return "Unknown code obtained";
        break;
    }
}