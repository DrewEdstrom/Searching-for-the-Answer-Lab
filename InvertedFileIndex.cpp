#include <iostream>
#include <map>
#include "InvertedFileIndex.h"

using namespace std;

//takes an input stream (which is presumed to contain strings and no
//punctuation) and processes it as to create an inverted index
void InvertedFileIndex::create_index(istream &istr)
{
    //represents a word taken from the input stream
    string word;
    //the current position of the word relative to the rest of the text
    //(begins at 0)
    int pos{0};

    //process each world in the input stream
    while(istr >> word)
    {
        //add to the inverted index so long as it is not any of these
        //common words (this isn't by any means a comprehensive list)
        if(word != "a" && word != "and" && word != "the" 
            && word != "to" && word != "for" && word != "they"
            && word != "in" && word != "i" && word != "he" 
            && word != "she" && word != "an" && word != "it" 
            && word != "me" && word != "of" && word != "is" 
            && word != "my" && word != "we")
        {
            inv_index.insert({word, pos});
        }

        //increment pos to reflect we're at the next position in the text
            pos++;
    }
}

//given an output stream, write the inverted file index to it
ostream & InvertedFileIndex::output_index(ostream &output_to)
{
    //the iterator we'll be using to iterate through inv_index
    auto it{inv_index.begin()};

    output_to << "{\n";

    //until we get to the end of the inverted file index, write the words
    //and where they occur
    while(it != inv_index.end())
    {
        //how many instances of a key are present in the multimap
        int instances = static_cast<int>(inv_index.count(it->first));

        //writes where the first occurance of a word in the text is
        output_to << "\"" << it->first << "\": [";

        //if there are other instances, we'll write where those occur too
        for(int i = 0; i < instances - 1; i++)
        {
            output_to << it->second << ", ";
            it++;
        }

        //if we're at the end of the inverted file index, no commas are
        //needed for additional entries
        if(it == prev(inv_index.end()))
        {
            output_to << it->second << "]\n";
        }
        //otherwise put a comma
        else
        {
            output_to << it->second << "],\n";
        }

        //iterate to the next position in the inverted file index
        it++;

    }

    return output_to << "}\n";
}
