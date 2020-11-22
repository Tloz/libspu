#ifndef VERSION_H
#define VERSION_H

/***************************************************************************
*             Version info for SimpleProjectUtilities
*
*   File    : version.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : November 22, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libspu
*   Purpose : Header for version info.
*             Part of the SimpleProjectUtilities library
*
***************************************************************************/


/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/
#include <string>

#define SPU_SEMVER_x 0
#define SPU_SEMVER_y 2
#define SPU_SEMVER_z 2

/**************************************************************************\
*                               PROTOTYPES                                 *
\**************************************************************************/

namespace libspu
{
    int version_x();
    int version_y();
    int version_z();
    std::string version_a();
    std::string version();
    std::string compiledate();
    void version_info();
}

#endif // VERSION_H /************** END OF FILE - version.h ***************/

