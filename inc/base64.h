#ifndef BASE_64_H
#define BASE_64_H

// Original work from 
// https://github.com/tobiaslocker/base64

#include <algorithm>
#include <string>

namespace libspu
{
    std::string get_base64_chars();
    std::string to_base64(std::string const &data);
    std::string from_base64(std::string const &data);
}

#endif // BASE_64_H