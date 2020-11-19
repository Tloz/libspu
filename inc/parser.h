#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

namespace libspu
{
    vector<string> str_explode(string const & s, char delim);
    vector<vector<string>> getTokensFromFile(string fileName, char delimiter = ';');
}

#endif