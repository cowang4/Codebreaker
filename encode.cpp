#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
  //cout << "Input plaintext to be encoded:\n";
  string word;
  string plaintext = "";
  while (cin >> word) {
    if (word == "quit") break;
    for (unsigned int i = 0; i < word.size(); ++i) {
      if (isalpha(word[i]))
        plaintext += tolower(word[i]);
      else
        plaintext += word[i];
    }
    plaintext += " ";
  }
  srand(time(NULL));
  set<char> used;
  string cyphertext = plaintext;
  for (int i = 0; i < 26; ++i) {
    char oldchar = static_cast<char>(i+97);
    char newchar;
    do {
      newchar = static_cast<char>((rand() % 26) + 97);
    } while (used.count(newchar) == 1);
    for (unsigned int j = 0; j < plaintext.size(); ++j) {
      if (plaintext[j] == oldchar) {
        cyphertext[j] = newchar;
      }
    }
    used.insert(newchar);
  }
  cout << cyphertext;
}
