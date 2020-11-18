#include <iostream>
#include <string>

using namespace std;

#define SEMVER_x 0
#define SEMVER_y 0
#define SEMVER_z 1

void usage()
{

}

void version()
{
    // Use this if you want to add detail on SEMVER
    // Using this cuz we cant leave an empty #define
    // Yes, I know, that's ugly
    string SEMVER_addendum("");

    cout << "libspu v" << SEMVER_x << "." << SEMVER_y << "." << SEMVER_z;
    if(SEMVER_addendum.length() != 0)
    {
        cout << SEMVER_addendum;
    }
    cout << " (using SEMVER)" << endl;
    cout << "Compiled on " << __DATE__ << endl;
    return 0;
}


int main(int argc, char const *argv[])
{
    if((argc >= 1) && (string(argv[1]).compare(string("-v")) == 0))
    {
        version()
        return 0;
    }
    return 0;
}