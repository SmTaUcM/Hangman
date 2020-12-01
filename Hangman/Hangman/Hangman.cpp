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
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>
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
}//------------------------------------------------------------------------------------------------


string gen_Guess_Str(string guess_Word)
{
    string guess_Str;
    for (int i = 0; i < guess_Word.size(); i++)
    {
        guess_Str += "*";
    }
    return guess_Str;
}


void play_Hangman()
{
    // Read in the words from the text file and select one at random.
    list<string> word_List = read_text_file();
    /*// Display the contents of the list.
    for (string v : word_List)
    {
        cout << v << "\n";
    }*/

    // initialise local variables.
    int guesses = 7;
    char guess_char = 0;
    string guess_str;
    bool playing = true;

    // Generate a randum number.
    srand(time(nullptr));  // Seed the random number generator.
    int random_Int = rand() % word_List.size(); // Generate the random number.

    // Retrieve the randomly selected word from the list.
    list<string>::iterator it = word_List.begin(); // Create iterator pointing to first element
    advance(it, random_Int); // Advance the iterator by 'random_Int' positions.

    // Ouput the randomly chosen word.
    const string word = *it;
    cout << "Word to guess = " << word << endl;
    guess_str = gen_Guess_Str(word);
    //cout << "Word to guess = " << guess_str << endl;

    // Main game loop.
    while (playing == true)
    {
        // Prompt the user with the state of the word to guess.
        cout << "You have " << guesses << " guess(es) left." << endl;
        cout << "The word to guess is: " << guess_str << endl;

        // Prompt the user for input, ensuring that only a single alphabetic character is used.
        while (not isalpha(guess_char))
        {
            cout << "Please enter your next guess: ";
            cin >> guess_char;
            //cout << "Entered: " << guess_char << endl;

            // Test to see if the character entered is in the word to guess.
            if (word.find(guess_char) != string::npos)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }

        playing = false;
    }

    // Iterate though the word to guess.
    for (int index = 0; index < word.size(); index++)
    {
        //cout << word[index] << " ";
    }
}//------------------------------------------------------------------------------------------------


int main()
{
    play_Hangman();
    return 0;
}//------------------------------------------------------------------------------------------------
