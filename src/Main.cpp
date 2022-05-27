#include "Dictionary.h"
#include "Game.h"
#include <iostream>
#include <string>
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
void gameOver() {

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
                      
                    Thanks for playing! 
                            
                  Press Enter to play again.. 
    )";
}

void drawMan(int numGuesses) {
  switch (numGuesses) {

  case 0:
    std::cout << R"( 
                +---+
                |   |
                    |
                    |
                    |
                    |
              =========)";
    break;
  case 1:
    std::cout << R"( 
                   
                +---+
                |   |
                O   |
                    |
                    |
                    |
              ========= )";
    break;
  case 2:
    std::cout << R"( 
                +---+
                |   |
                O   |
                |   |
                    |
                    |
              =========)";
    break;
  case 3:
    std::cout << R"( 
                +---+
                |   |
                O   |
               /|   |
                    |
                    |
              =========)";
    break;
  case 4:
    std::cout << R"( 
                +---+
                |   |
                O   |
               /|\  |
                    |
                    |
              =========)";
    break;
  case 5:
    std::cout << R"( 
                +---+
                |   |
                O   |
               /|\  |
               /    |
                    |
              =========)";
    break;
  case 6:
    std::cout << R"( 
                +---+
                |   |
                O   |
               /|\  |
               / \  |
                    |
              =========)";
    break;
  default:
    break;
  }
}

int main() {

  int wrongGuesses = 0;

  std::string progress = "";

  Dictionary dic; // creating dictionary

  dic.load("words.txt"); // loading words.txt

  std::string word = dic.getWord();

  Game game(word); // creating game with random word

  for (int i = 0; i < word.length(); i++) {
    progress.append("_ ");
  }

  startScreen();

  std::cin.ignore();

  while (!game.isComplete() && wrongGuesses < 6) {
    char guessedLetter;

    std::vector<int> *correctLetters;

    drawMan(wrongGuesses);
    std::cout <<std::endl<< progress << std::endl;
    std::cout << "Enter Guess.. ";
    std::cin >> guessedLetter;
    correctLetters = game.makeGuess(guessedLetter);
    if (correctLetters == NULL) {
      wrongGuesses++;
    } 
    else {
      std::string temp (1,guessedLetter);
      for(int i = 0; i < correctLetters->size();i++) {
        progress.replace(correctLetters-> at(i) * 2,1,temp);
      }
    } 
  }
   std::cout <<std::endl<<"The word was: "<< word << std::endl;
  if(game.isComplete()){
    std::cout<<"Congrats you win!"<< std::endl;
  } else{
    std::cout<<"Better luck next time"<< std::endl;
  
  }
  gameOver();
  return 0;
}
