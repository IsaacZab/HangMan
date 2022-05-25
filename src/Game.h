#include <string>
#include <vector>

class Game {
public:
  Game(std::string word);
  std::vector<int> *makeGuess(char guess);

  bool isComplete();

private:
  int correctGuesses;
  std::vector<char> guessedLetters;
  std::string word;
};
