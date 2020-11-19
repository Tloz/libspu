#include "../inc/parser.h"

vector<string> libspu::str_explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }
    return result;
}

vector<vector<string>> libspu::getTokensFromFile(string fileName, char delimiter)
{
    /* declaring what we'll need :
     * string line -> the line beeing parsed
     * ifstream myfile -> the file that name has been given as parameter
     * vector <vector <string> > tokens -> the return value
     * 
     * Putting all line into tokens
     */
    string line;
    ifstream myfile(fileName);
    vector< vector<string> > tokens;
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            // If line is blank or start with # (comment)
            // then we don't parse it
            if((line.length() == 0) || (line.at(0) == '#'))
                continue;
            else
            {
                vector <string> tmptokens = str_explode(line, delimiter);
                tokens.push_back(tmptokens);
            }
        }
    }
    else
    {
        cout << "Unable to open file " << fileName << endl;
        throw exception();
    }
    return tokens;
}