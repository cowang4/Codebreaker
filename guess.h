#include <vector>
#include <string>

using namespace std;

class Guess {
public:
  Guess();
  void transform_alphabet(vector<string> &cypher_text);
  void transform_letter(char oldc, char newc, vector<string> &cypher_text);
private:
  char alphabet[26];
};

Guess::Guess() {
  for (int i = 0; i < 26; ++i) {
    alphabet[i] = static_cast<char>(i+97);
  }
}

void Guess::transform_alphabet(vector<string> &cypher_text) {
  for (unsigned int i = 0; i < cypher_text.size(); ++i) {
    for (unsigned int k = 0; k < cypher_text[i].size(); ++k) {
      cypher_text[i][k] = alphabet[static_cast<unsigned int>(cypher_text[i][k])];
    }
  }
}

void Guess::transform_letter(char oldc, char newc, vector<string> &cypher_text) {
  alphabet[static_cast<unsigned int>(oldc)-97] = newc;
  for (unsigned int i = 0; i < cypher_text.size(); ++i) {
    for (unsigned int k = 0; k < cypher_text[i].size(); ++k) {
      if (cypher_text[i][k] == oldc)
        cypher_text[i][k] = newc;
    }
  }
}
