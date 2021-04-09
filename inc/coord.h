#ifndef COORD_H
#define COORD_H

/***************************************************************************
*             Coord module for SimpleProjectUtilities
*
*   File    : coord.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : January 06, 2021
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libspu
*   Purpose : Header for managing cartesian and polar coordinates.
*             Part of the SimpleProjectUtilities library
*
***************************************************************************/

/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/

#include <cmath>
#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif

/**************************************************************************\
*                               PROTOTYPES                                 *
\**************************************************************************/


namespace libspu
{
    class Coord
    {
    private:
        float m_a;
        float m_b;
        // float m_c; // implement 3D
        bool m_polar; // true means polar system, false means cartesian
    public:
        Coord();
        Coord(float a, float b, bool polar = false);
        // Coord(float a, float b, float c, bool polar = false); // implement 3D
        ~Coord();

        void fromCartesian(float x, float y);
        void fromPolar(float r, float angle);
        bool cartesian();
        bool polar();
        void convertToCartesian();
        void convertToPolar();
        float x();
        float y();
        float r();
        float angle();
        float theta();
        // float z(); // implement 3D
        // float phi(); // implement 3D
        
    };
    
}

#endif // COORD_H /*************** END OF FILE - parser.h ****************/