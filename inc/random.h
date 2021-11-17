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
        // returns a random int between min and max
        int random_int(int min = 0 , int max = RAND_MAX);

        // returns a random float
        float random_float();

        // returns a random float between min and max
        float random_float(float min, float max);

        // returns a random string of length alnum char
        std::string random_string(int length = 10);

        // return a random value between 1 and dice_max_value
        int dice(int dice_max_value);

        // tells if the throw is sucessfull (random value must be lower or equal to threshold)
        bool throw_under(int threshold, int dice_max_value = 100);

        // tells if the throw is sucessfull (random value must be greater or equal to threshold)
        bool throw_over(int threshold, int dice_max_value = 20);
}

#endif // RANDOM_H /*************** END OF FILE - random.h ****************/

