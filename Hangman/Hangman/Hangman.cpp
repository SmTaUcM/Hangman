//----------------------------------------------------------------------------------------------
// Name:        Hangman.cpp
// Purpose:     Hangman game - converted from JHub Coding Scheme Python module 3 assesment.
// Version:     v1.00
// Author:      S. Macintosh
//
// Created:     11/11/2020
// Copyright:   N/A
// Licence:     N/A
//------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
//                                           Imports.                                                
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
//                                         Main Program.                                             
//-------------------------------------------------------------------------------------------------
list<string> read_text_file()
{
    string line;
    list<string> word_List;
    ifstream data_file ("word_list.txt");

    if (data_file.is_open())
    {
        while (getline(data_file, line))
        {
            word_List.push_back(line);
        }
        data_file.close();
    }

    else
    {
        cout << "Error - Unable to open file.";
    }

    return word_List;
}
//-------------------------------------------------------------------------------------------------


void play_Hangman()
{
    list<string> word_List = read_text_file();

    // Display the contents of the list.
    for (string v : word_List)
    {
        cout << v << "\n";
    }


}
//-------------------------------------------------------------------------------------------------


int main()
{
    play_Hangman();
    return 0;
}
//-------------------------------------------------------------------------------------------------
