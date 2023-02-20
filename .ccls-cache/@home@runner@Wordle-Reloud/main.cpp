/* main.cpp
   Wordle Reload is a game that allows you to guess either a 3 letter word or 5 letter word.
   You have a set amount of time to guess a word.  At the conlusion of game play
   you will be provided stats on your overall game play.

   Author:Ayush Panda
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
//Display welcome message, introducing the user to the program and
//describing the instructions for the game
void gameDisplayInstructions() {
   cout << "Program 3: Wordle Reload \n"
        << "CS 141, Spring 2022, UIC \n"
        << " \n"
        << "The objective of this game is to guess the randomly selected \n"
        << "word within a given number of attempts. You can select either \n"
        << "a three or five word board. \n"
        << "At the conlusion of the game, stats will be displayed.  \n"
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
}//end gameDisplayInstructions()


//binary search function
int binarySearch (string searchWord, vector <string> wordleWords, int numAttempts) {
   int low, mid, high;
   int searchResult = -1;
   int guessNumber = 1;
  low = 0;
   high = wordleWords.size() - 1;
  cout << "Nice work! You guessed the correct word"<< endl;
  cout << "  - You completed the board in: 0 seconds." << endl;
  cout << "  - It took you " << guessNumber << "/" << numAttempts
       <<" attempts." << endl;
  
   while (low <= high) {
     mid = (low + high) / 2;
     searchResult = searchWord.compare(wordleWords[mid]);
     cout << searchResult;
     if (searchResult == 0) {
       return mid;
     }
     else if (searchResult < 0) {
       high = mid - 1;
     }
     else { 
       low = mid + 1;
       }
    }
  return -1;
}

//creates vectors of either 3 letter of 5 letter words
void readIntoDict (vector <string> & wordleWords3, vector <string> & wordleWords5, char fileName[]) {
   ifstream inStream;
   inStream.open(fileName);
   assert (inStream.fail() == false);
   wordleWords3.clear();
   wordleWords5.clear();
   string newWord;
   while (inStream >> newWord) {
      if (newWord.size() > 3) {
         wordleWords5.push_back(newWord);
      }
      else {
         wordleWords3.push_back(newWord);
      }
   }
   inStream.close();
} // end of readIntoDict()

int main() {
   int menuChoice;
   string userInput;
   vector <string> dictionary;
   vector <string> correctSpellings;
   vector <string> incorrectSpellings;
   vector <string> wordleWords3;
   vector <string> wordleWords5;

  int numAttempts = 0;
  // time_t startTime = time(NULL); 
  // int elaspedSeconds = 0;
  // elaspedSeconds = difftime (time (NULL), startTime);
   
   //Read in words from the dictionary and commonly misspelled words files into vectors.
   //readWordsIntoDictionary(dictionary, "dictionary.txt");
   //readCommonMisspelledWords(incorrectSpellings, correctSpellings, "wordlewords.txt");
   readIntoDict(wordleWords3, wordleWords5, "wordlewords.txt"); 
   
   //Display game instructions
   gameDisplayInstructions();
   
   //For random number generation seed the random number generator to 1, so that results
   //are predictable.  To make results different every time instead you would
   //srand( time( NULL));
  //Don't do this if you want your code to match test cases!

  
   //Keep looping until user selects the option to exit
   while (true) {
      cout << endl;
      cout << "Select a menu option:" << endl;
      cout << "   1. To play Wordle Reload 3 letter play" << endl;
      cout << "   2. To play Wordle Reload 5 letter play" << endl;
      cout << "   3. Exit the program" << endl;
      
      cout << endl;
      cin >> menuChoice;
      
      if (menuChoice == 3) {
        cout <<"Overall Stats: "<< endl;
        cout << "- You guessed: " << "0" << endl;
        cout << "- Your longest streak is: " << "0" <<endl;
        cout << "- Average word completion time: " << "0" <<endl;

         cout << "Exiting program";
         break;
      }
      
      if (menuChoice == 1) {
        numAttempts = 4;
        int random = rand() % wordleWords3.size();
         cout << "Your choice -->" << endl;
         cout << "To get started, enter your first 3 letter word." << endl;
         cout << "You have 4 attempts to guess the random word." << endl;
         cout << "The timer will start after your first word entry." << endl;
         cout << "Try to guess the word within 20 seconds." << endl << endl;
         cout << "Please enter word -->" << endl << endl;
         cin >> userInput;
        
         for (int i = 0; i < userInput.size(); i++) {
            char temp;
            temp = userInput[i];
            userInput[i] = toupper(temp);
         }
         for (int j = 0; j < userInput.size(); j++) {
            cout << "  [ " << userInput[j] << " ]  ";
         }
         cout << endl;
         binarySearch(userInput, wordleWords3, numAttempts);  
         continue;
      }

     if (menuChoice == 2) {
        numAttempts = 6;
         cout << "Your choice -->" << endl;
         cout << "To get started, enter your first 5 letter word." << endl;
         cout << "You have 6 attempts to guess the random word." << endl;
         cout << "The timer will start after your first word entry." << endl;
         cout << "Try to guess the word within 40 seconds." << endl << endl;
         cout << "Please enter word -->" << endl << endl;
         cin >> userInput;
         for (int i = 0; i < userInput.size(); i++) {
            char temp;
            temp = userInput[i];
            userInput[i] = toupper(temp);
         }
         for (int j = 0; j < userInput.size(); j++) {
            cout << "  [ " << userInput[j] << " ]  ";
         }
         cout << endl;
         // if (binarySearch(userInput, wordleWords5, numAttempts) != -1) {
         //  cout << "Nice work! You guessed the correct word"<< endl;
         //  cout << "  - You completed the board in: 0 seconds." << endl;  
         // }
         // else {
         //   continue;
         // }

      }

     
      break;
   }

	return 0;
}//End of Main