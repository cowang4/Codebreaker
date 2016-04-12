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
  cout << "cypher text grade: " << grader.percent_words(cypher_text) << endl;

  vector<string> clean_text = grader.clean_text(cypher_text);
  
  print_text(clean_text);

  return 0;
}
