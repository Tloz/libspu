#include "../inc/version.h"
#include <iostream>

using namespace std;
using namespace libspu;


int main()
{
    version_info();
    string remote = getRemoteVersionString("");

    cout << "Remote: " << remote << endl;
    cout << "Local : " << version() << endl;
    int code = compareVersions(decomposeSemverString(remote), decomposeSemverString(version()));

    cout << readableVersionState(code) << endl;

    return 0;
}