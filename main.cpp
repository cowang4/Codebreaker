#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "freq.h"

using namespace std;

int main(int argc, char* argv[]) {
  /*int value = system("fgrep -ix 'poop' /usr/share/dict/words");
  if (value == 0)
    printf("Poop is a word\n");*/

  Freq freq;

  cout << "Input cyphertext, break with \"quit\":\n";
  while (true) {
    string word;
    cin >> word;
    if (word == "quit") break;
    freq.count_letter_freq(word);
  }
  freq.print_cyphertext_counts_and_percentages();
}
