#include <iostream>
#include <sstream>

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
    {
        v += "-";
        v += SPU_SEMVER_DEFADDENDUM;
    }
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

string libspu::info()
{
    return SPU_INFO;
}

string libspu::license()
{
    return SPU_LICENSE;
}

string libspu::license_info()
{
    return SPU_LICENSE_INFO;
}


string libspu::getRemoteVersionString(string API_target)
{
    // TODO: proper fetchnig of version string
    cout << endl << "/!\\ WARNING: This is emulated, no connection made /!\\" << endl << endl;
    // cout << "Calling " + SPU_SEMVER_API_TARGET + "..." << endl;
    return "0.3.2-alpha";
}

vector<string> split(string strToSplit, char delimeter)
{
    int parts = 0;
    stringstream ss(strToSplit);
    string item;
    vector<string> splittedStrings;
    while (getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}

vector<string> libspu::decomposeSemverString(string semver)
{
    vector<string> tmp = split(semver, '-');
    vector<string> retval = split(tmp[0], '.');
    if(tmp.size() > 1)
    {
        retval.push_back(tmp[1]);
    }

    return retval;

}

int libspu::compareVersions(vector<string> remote, vector<string> local)
{
    string local_metadata("");
    unsigned int local_major = stoi(local[0]);
    unsigned int local_minor = stoi(local[1]);
    unsigned int local_patch = stoi(local[2]);
    if(local.size() > 3)
        local_metadata = local[3];

    string remote_metadata("");
    unsigned int remote_major = stoi(remote[0]);
    unsigned int remote_minor = stoi(remote[1]);
    unsigned int remote_patch = stoi(remote[2]);
    if(remote.size() > 3)
        remote_metadata = remote[3];


    if(remote_major > local_major)
        return 4; // There is a new major version
    if(remote_minor > local_minor)
        return 3; // There is a new minor version
    if(remote_patch > local_patch)
        return 2; // There is a new patch
    if(remote_metadata.compare(local_metadata) != 0)
        return 1; // There is an other build
    return 0; // remote and local versions are the same or local version is ahead of repo
}

string libspu::readableVersionState(int code)
{
    switch(code)
    {
        case 0:
        return "Remote and local version are the same (or you are ahead of dev branch, lucky you)";
        break;

        case 1:
        return "Remote build is different than yours";
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