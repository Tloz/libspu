#ifndef PARSER_H
#define PARSER_H

/***************************************************************************
*             Parser module for SimpleProjectUtilities
*
*   File    : parser.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : November 22, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libspu
*   Purpose : Header for parsing functions.
*             Part of the SimpleProjectUtilities library
*
***************************************************************************/

/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/

#include <string>
#include <vector>

/**************************************************************************\
*                               PROTOTYPES                                 *
\**************************************************************************/

namespace libspu
{
    std::vector<std::string> str_explode(std::string const & s, char delim);
    std::vector<std::vector<std::string>> getTokensFromFile(std::string fileName, char delimiter = ';');
}

#endif // PARSER_H /*************** END OF FILE - parser.h ****************/

