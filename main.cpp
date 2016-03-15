#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "freq.h"
#include "guess.h"

using namespace std;

void print_text(const vector<string> &text) {
  for (unsigned int i = 0; i < text.size(); ++i) {
    cout << text[i] << " ";
  }
  cout << "\n";
}

int main(int argc, char* argv[]) {
  /*int value = system("fgrep -ix 'poop' /usr/share/dict/words");
  if (value == 0)
    printf("Poop is a word\n");*/

  Freq freq;
  vector<string> cypher_text;

  cout << "Input cyphertext, break with \"quit\":\n";
  while (true) {
    string word;
    cin >> word;
    if (word == "quit") break;
    freq.count_letter_freq(word);
    cypher_text.push_back(word);
  }
  freq.print_cyphertext_counts_and_percentages();

  Grade grader;
  cout << "cypher text grade: " << grader.percent_words(cypher_text);

  //find I and A
  set<char> one_letter_words;
  for (unsigned int i = 0; i < cypher_text.size(); ++ i) {
    if (cypher_text[i].size() == 1)
      one_letter_words.insert(cypher_text[i][0]);
  }
  assert(one_letter_words.size() == 2);
  char one = *one_letter_words.begin();
  char two = *one_letter_words.end();
  //TODO: get cleaned words, lowercase no punctuation
  double perc1 = Freq::get_percentage(one);
  double perc2 = Freq::get_percentage(two);
  Guess AI;
  vector<string> guess_text = cypher_text;
  if (perc1 > perc2) {
    AI.transform_letter(one, 'A', guess_text);
    AI.transform_letter(two, 'I', guess_text);
  }
  else {
    AI.transform_letter(one, 'I', guess_text);
    AI.transform_letter(two, 'A', guess_text);
  }

  print_text(guess_text);

  return 0;
}
