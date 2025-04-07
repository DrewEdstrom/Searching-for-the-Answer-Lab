#ifndef TEXTPROCESSING_H_INC
#define TEXTPROCESSING_H_INC

#include <iostream>
#include <string>
#include <sstream>

std::stringstream & remove_punctuations(std::istream &istr, std::stringstream &sstr) 
{
    std::string word;
    //the "clean" word which has had punctuation removed
    std::string cw;

    while(istr >> word)
    {
        cw = "";

        for(char c: word)
        {
            if(!ispunct(c))
            {
                cw += static_cast<char>(tolower(c));
            }
        }

        sstr << cw << " ";
    }

    return sstr;
}
 
#endif
