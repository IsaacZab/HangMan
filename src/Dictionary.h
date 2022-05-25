#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <time.h>
#include <stdlib.h> 

class Dictionary {
public:
  Dictionary();
  void load(std::string filePath);

  std::string getWord();

private:
  std::vector<std::string> wordList;
};
