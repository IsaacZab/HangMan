#include "Dictionary.h"
Dictionary::Dictionary(){}
void Dictionary::load(std::string filePath) {
  std::string STRING;
  std::ifstream infile; 
  infile.open(filePath);
  while (!infile.eof()) {
    getline(infile, STRING);
    wordList.push_back(STRING);
  }
  infile.close();
}

std::string Dictionary::getWord() {
  int index;
  srand(time(NULL));
  index = rand() % wordList.size();

  return wordList[index];
}
