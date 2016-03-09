#ifndef GRADE_H
#define GRADE_H

#include <set>
#include <fstream>
#include <sstream>
#include "freq.h"

class Grade {
public:
  Grade();
  //grading functions
  static bool is_word(std::string s);
  static double percent_words(std::string guess_text);
private:
  static std::set<std::string> english_words;
};

std::set<std::string> Grade::english_words;

Grade::Grade() {
  std::ifstream dict("/usr/share/dict/american-english");
  std::string s;
  while (dict >> s) {
    english_words.insert(english_words.end(),s);
  }
}

bool Grade::is_word(std::string s) {
  std::set<std::string>::iterator it = english_words.find(s);
  if (it != english_words.end()) return true;
  return false;
}

double Grade::percent_words(std::string guess_text) {
  std::stringstream ss(guess_text);
  std::string word;
  int correct = 0;
  int total = 0;
  while (getline(ss,word,' ')) {
    if (is_word(word)) ++correct;
    ++total;
  }
  return (double)correct*100.0 / (double)total;
}


#endif //GRADE_H
