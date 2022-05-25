#include "Dictionary.h"
#include "Game.h"
#include <iostream>
using namespace std;

void startScreen() {
  std::cout << R"(
  _    _                   __  __                        
 | |  | |                 |  \/  |             _     _   
 | |__| | __ _ _ __   __ _| \  / | __ _ _ __ _| |_ _| |_     +---+
 |  __  |/ _` | '_ \ / _` | |\/| |/ _` | '_ \_   _|_   _|    |   |
 | |  | | (_| | | | | (_| | |  | | (_| | | | ||_|   |_|      O   |
 |_|  |_|\__,_|_| |_|\__, |_|  |_|\__,_|_| |_|              /|\  |
                      __/ |                                 / \  |
                     |___/                                       |
                        By:Isaac Z.                       ========= 
                                                  
    Try to guess the word letter by letter. 
    
    Correct letters will be filled in. 
    
    You will have 6 lives, each incorrect guess will lose a life.
    

           Press enter to start....
  
                                                            
                                    )"
            << endl;
}

int main() {

  Dictionary dic; // creating dictionary

  dic.load("words.txt"); // loading words.txt

  std::string word = dic.getWord();

  Game game(word); // creating game with random word

  startScreen();

  
  

  

  return 0;
}
