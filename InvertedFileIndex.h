#ifndef INVERTEDFILEINDEX_H_INC
#define INVERTEDFILEINDEX_H_INC

#include <iostream>
#include <map>

class InvertedFileIndex
{
    public:

    InvertedFileIndex()
    :
    inv_index{}
    {
    }
    //the multimap container which shall be our inverted index
    std::multimap<std::string, int> inv_index;

    //takes an input stream (which is presumed to contain strings and no
    //punctuation) and processes it as to create an inverted index
    void create_index(std::istream &istr);
    //given an output stream, write the inverted file index to it
    std::ostream & output_index(std::ostream &output_to);
};


#endif
