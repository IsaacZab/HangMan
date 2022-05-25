#include "Game.h"

Game::Game(std::string word) {
  this->word = word;
  correctGuesses = 0;
}
std::vector<int> *Game::makeGuess(char guess) {
  std::vector<int> *retVector = NULL;
  for (int i = 0; i < word.length(); i++) {
    if (word.at(i) == guess) {
      if (retVector == NULL) {
        retVector = new std::vector<int>();
      }
      retVector->push_back(i);
      correctGuesses += 1;
    }
  }
  return retVector;
}

bool Game::isComplete() { 
  return correctGuesses == word.length(); 
}
