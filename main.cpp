#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "freq.h"

using namespace std;

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

  return 0;
}
