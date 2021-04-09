#ifndef RANDOM_H
#define RANDOM_H

/***************************************************************************
*             RNG module for SimpleProjectUtilities
*
*   File    : random.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : November 22, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libspu
*   Purpose : Header for generating random values functions.
*             Part of the SimpleProjectUtilities library
*
****************************************************************************
*                                                        _____________________________________
*                      /!\ DISCLAIMER /!\               / If you're just a tiny bit concerned \
*                                                       \ about security, please read this    /
*                Before use, please note that none       -------------------------------------
*                of these functions are suitable                \   ^__^
*                for SECURITY purposes. DO NOT use               \  (oo)\_______
*                them to generate passwords or worse,               (__)\       )\/\
*                you know, like ssh keys of ANY KIND                    ||----w |
*                                                                       ||     ||
*                               You've been warned.
*
\**************************************************************************/


/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/

#include <string>
#include <cstdlib> // For RAND_MAX

/**************************************************************************\
*                               PROTOTYPES                                 *
\**************************************************************************/

namespace libspu
{
    //returns a random int between min and max
    int random_int(int min = 0 , int max = RAND_MAX);

    //returns a random float
    float random_float();

    //returns a random float between min and max
    float random_float(float min, float max);

    // returns a random string of length alnum char
    std::string random_string(int length = 10);

    int dice(int max, int min = 2);
}

#endif // RANDOM_H /*************** END OF FILE - random.h ****************/

