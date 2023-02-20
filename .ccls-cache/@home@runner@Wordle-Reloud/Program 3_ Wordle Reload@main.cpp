/* main.cpp
   Wordle Reload is a game that allows you to guess either a 3 letter word or 5 letter word.
   You have a set amount of time to guess a word.  At the conlusion of game play
   you will be provided stats on your overall game play.

   Author: Pritika Bhattacharya & Ayush Panda
   Date: 02/24/2022
   Class: CS 141, Spring 2022, UIC
   System: Windows using CLion
*/
#include <cassert>
#include <cctype>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void gameDisplayInstructions() {
   cout << "Program 3: Wordle Reload \n"
        << "CS 141, Spring 2022, UIC \n"
        << " \n"
        << "The objective of this game is to guess the randomly selected \n"
        << "word within a given number of attempts. You can select either \n"
        << "a three or five word board. \n"
        << "At the conclusion of the game, stats will be displayed.  \n"
        << "Indicators will be given if characters of the user entered \n"
        << "word are reflected in the guessed word. \n"
        << "  - If the character is in the correct position, the character \n"
        << "    will display as an uppercase value.\n"
        << "  - If the character is within the random word, the character \n"
        << "    will display as a lowercase value.\n"
        << "  - If you enter a character that is not in the word, an asterisk '*' \n"
        << "    will display."
        << " \n"
        << endl;
}//end displayWelcomeMessage()

void readIntoDict () {
  
}

int main() {
   // Read in words from the dictionary and commonly misspelled words files into vectors.


  gameDisplayInstruciton();
   //Display game instruction


   // For random number generation seed the random number generator to 1, so that results
   // are predictable.  To make results different every time instead you would
   // use srand( time( NULL));   Don't do this if you want your code to match test cases!
  
   // Keep looping until user selects the option to exit

	return 0;
}// End of Main