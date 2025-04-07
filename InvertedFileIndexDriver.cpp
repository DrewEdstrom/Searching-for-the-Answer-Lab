#include <iostream>
#include <sstream>
#include <fstream>
#include "TextProcessing.h"
#include "InvertedFileIndex.h"

using namespace std;

int main()
{
    InvertedFileIndex index;
    ifstream read_file;
    ofstream write_file;
    stringstream processed_text{""};
    string read_dir;
    string write_dir;

    cout << "\n\nWelcome to the inverted file index creation program!"
            << "\n\nPlease enter the directory of the file you would like "
            << "to create an inverted file index from.\n\n";

    //take in directory for read file
    getline(cin, read_dir);
    read_file.open(read_dir);

    //if we can't open that file, prompt and try again
    while(!read_file)
    {
        cout << "\n\nCan't open file! Please enter the read directory again.";
        getline(cin, read_dir);
        read_file.open(read_dir);
    }

    cout << "\n\nFile opened successfully. "
            << "Now enter the directory you would like to write to.\n\n";
    
    //take in directory for the file to be written to
    getline(cin, write_dir);
    write_file.open(write_dir);

    //if we can't open that file, prompt and try again
    while(!write_file)
    {
        cout << "\n\nCan't open file! Please enter the write directory again.";
        getline(cin, write_dir);
        write_file.open(write_dir);
    }

    cout << "\n\nFile opened successfully. ";

    //removes all of the punctuation from the text provided
    remove_punctuations(read_file, processed_text);
    //then the cleaned up text is what is used to create the inverted file
    //index
    index.create_index(processed_text);
    //and then finally the inverted file index is written to a file
    index.output_index(write_file);

    //close the files since we're done with them
    read_file.close();
    write_file.close();

    cout << "\n\nSuccessfully wrote to output file.\n\n";

    return 0;
}
