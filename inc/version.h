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
***************************************************************************
*                   _________________________________________
*                  / Hi, I'm Marguerite, and I will guide    \
*                  | you through this file, catching your    |
*                  | attention on some important points.     |
*                  \ Keep your eyes open!                    /
*                   -----------------------------------------
*                          \   ^__^
*                           \  (oo)\_______
*                              (__)\       )\/\
*                                  ||----w |
*      /          \   /        \   ||     ||
* |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
***************************************************************************/

/**************************************************************************\
*                                  NOTE                                    *
****************************************************************************
*
*     /\      libspu - for SimpleProjectUtilities - gathers a bunch of
*    /__\     useful tools that you may use several times and don't want to
*   /\  /\    rewrite everytime you start a new project. Most likely you've 
*  /__\/__\   already done something like that yourself (and if not I encou-
*             age you to do so). So you're free to use this lib in any of
*  your work. No credit required. You don't need to tell me, pay me a coffee
*  or whatever. I want you to save time, not spend it on saying thank you.
*  Time is all we truly have, and it runs out so fast. You're also free not
*  to use this program. I don't need anyone to use it. I'm not planning to 
*  make money out of it, and neither should you, but, hey, if you want, 
*  I don't mind. Treat it like a gift from a distant relative: if you never
*  use it, it you send it to the junkyard, really, once more, I swear 
*  that I DON'T MIND. Therefore, this project is licensed under the terms 
*  of the Unlicence.
*
*             However, if you found some bugs, please report them by opening
*  an issue on the repository mentionned above. That would make you a great 
*  human beeing, and Marguerite the cow would be so happy if you do! 
*  Feature requests are welcome too! Just keep in mind I'm alone on this.
* 
*                       Thus being said, have fun coding !
*
\****************************************************************************

 .-.--------------------------------------------------------------------------.-.
((o))                             THE UNLICENSE                                  )
 \U/____________________________________________________________________________/
   |                                                                           |
   |  This is free and unencumbered software released into the public domain.  |
   |                                                                           |
   |  Anyone is free to copy, modify, publish, use, compile, sell, or          |
   |  distribute this software, either in source code form or as a compiled    |
   |  binary, for any purpose, commercial or non-commercial, and by any        |
   |  means.                                                                   |
   |                                                                           |
   |  In jurisdictions that recognize copyright laws, the author or authors    |
   |  of this software dedicate any and all copyright interest in the          |
   |  software to the public domain. We make this dedication for the benefit   |
   |  of the public at large and to the detriment of our heirs and             |
   |  successors. We intend this dedication to be an overt act of              |
   |  relinquishment in perpetuity of all present and future rights to this    |
   |  software under copyright law.                                            |
   |                                                                           |
   |  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          |
   |  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       |
   |  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   |
   |  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR        |
   |  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    |
   |  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    |
   |  OTHER DEALINGS IN THE SOFTWARE.                                          |
   |                                                                           |
   |  For more information, please refer to <https://unlicense.org>            |
   |                                                                           |
   |___________________________________________________________________________|
  /A\                                                                           \
 ((o))                                                                           )
  '-'---------------------------------------------------------------------------'


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

