#include <iostream>
#include <string>

using namespace std;

#define SEMVER_x 0
#define SEMVER_y 0
#define SEMVER_z 1


int main(int argc, char const *argv[])
{
    string SEMVER_addendum("");

    if((argc >= 1) && (string(argv[1]).compare(string("-v")) == 0))
    {
        cout << "libspu v" << SEMVER_x << "." << SEMVER_y << "." << SEMVER_z;
        if(SEMVER_addendum.length() != 0)
        {
            cout << SEMVER_addendum;
        }
        cout << endl << "(using SEMVER)" << endl;
        cout << "Compiled on " << __DATE__ << endl;
        // quit after printing
        return 0;
    }
    return 0;
}