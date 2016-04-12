#ifndef GRADE_H
#define GRADE_H

#include <set>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include "freq.h"

using namespace std;

class Grade {
public:
  Grade();
  //grading functions
  static bool is_word(std::string s);
  static double percent_words(std::vector<std::string> guess_text);
  static string clean_word(string s);
  static vector<string> clean_text(vector<string> &text);
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
  cout << "Dictionary size: " << english_words.size() << endl;
}

string Grade::clean_word(string s) {
  while (!isalpha(s[s.size()-1])) {
    s = s.substr(0,s.size()-1);
  }
  while (!isalpha(s[0])) {
    s = s.substr(1);
  }
  while (!isalpha(s[s.size()-1])) {
    s = s.substr(0,s.size()-1);
  }
  for (string::size_type j = 0; j < s.size(); ++j) {
    if (isalpha(s[j]))
      s[j] = tolower(s[j]);
  }
  return s;
}
bool Grade::is_word(std::string s) {
  std::set<std::string>::iterator it;

  s = clean_word(s);

  it = english_words.find(s);
  if (it != english_words.end()) return true;
  s[0] = toupper(s[0]);
  it = english_words.find(s);
  if (it != english_words.end()) return true;
  
  return false;
}

vector<string> Grade::clean_text(vector<string> &text) {
  vector<string> cleaned;
  for (unsigned int i = 0; i < text.size(); ++i) {
    cleaned.push_back(clean_word(text[i]));
  }
  return cleaned;
}

double Grade::percent_words(std::vector<std::string> guess_text) {
  int correct = 0;
  int total = 0;
  for (unsigned int i = 0; i < guess_text.size(); ++i) {
    if (is_word(guess_text[i])) ++correct;
    else std::cout << guess_text[i] << "\n";
    ++total;
  }
  return (double)correct*100.0 / (double)total;
}

bool Grade::is_valid(string word) {
  for (unsigned int i = 0; i < english_words.size(); ++i) {
    for (int j = 0; j < word.size(); ++j) {
      if (isupper(word[i]) 
        bool poop = true;
    }
  }
}

#endif //GRADE_H
