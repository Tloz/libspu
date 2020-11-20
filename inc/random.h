#ifndef RANDOM_H
#define RANDOM_H

//
//        /!\ DISCLAIMER /!\
//
//  Before use, please note that none
//  of these functions are suitable
//  for SECURITY purposes. DO NOT use
//  them to generate passwords
//  or, you know, ssh keys of ANY KIND
//
//                 You've been warned.
//

#include <cstdlib>
#include <string>

// #define CHAR_MIN 1
// #define CHAR_MAJ 2
// #define CHAR_NUMBERS 4
// #define CHAR_SPECIAL 8

using namespace std;

namespace libspu
{
    //returns a random int between min and max
    int random_int(int min = 0 , int max = RAND_MAX);

    //returns a random float
    float random_float();

    //returns a random float between min and max
    float random_float(float min, float max);

    // returns a random string of length char picked from set
    string random_string(int length = 10);
}

#endif // RANDOM_H