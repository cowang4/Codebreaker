#include <map>
#include <string>
#include <iostream>

class Freq {
public:
  Freq();
  //work functions
  static void count_letter_freq(const std::string &word);
  //print functions
  static void print_cyphertext_counts_and_percentages();
  //accessors
  static double get_percentage(char c);
  static int get_count(char c);
private:
  //private acessors
  static double get_percentage(std::map<char,int>::iterator it);
  static int get_count(std::map<char,int>::iterator it);
  //member vars
  static std::map<char, double> english_percentages;
  static std::map<char, int> cyphertext_counts;
  static unsigned int total_count;
};

static std::map<char, double> english_percentages;
unsigned int Freq::total_count = 0;
std::map<char,int> Freq::cyphertext_counts;

Freq::Freq() {
  english_percentages['a']=8.2;
  english_percentages['b']=1.5;
  english_percentages['c']=2.8;
  english_percentages['d']=4.2;
  english_percentages['e']=12.7;
  english_percentages['f']=2.2;
  english_percentages['g']=2.0;
  english_percentages['h']=6.1;
  english_percentages['i']=7.0;
  english_percentages['j']=0.1;
  english_percentages['k']=0.8;
  english_percentages['l']=4.0;
  english_percentages['m']=2.4;
  english_percentages['n']=6.7;
  english_percentages['o']=7.5;
  english_percentages['p']=1.9;
  english_percentages['q']=0.1;
  english_percentages['r']=6.0;
  english_percentages['s']=6.3;
  english_percentages['t']=9.0;
  english_percentages['u']=2.8;
  english_percentages['v']=1.0;
  english_percentages['w']=2.4;
  english_percentages['x']=0.1;
  english_percentages['y']=2.0;
  english_percentages['z']=0.1;
}

void Freq::count_letter_freq(const std::string &word) {
  for (unsigned int i = 0; i < word.size(); ++i) {
    char c = tolower(word[i]);
    if (!isalpha(c)) {
      std::cerr << "ERROR: input char not a letter.\n";
      continue;
    }
    total_count += 1;
    std::pair<std::map<char,int>::iterator,bool> pair = cyphertext_counts.insert(std::pair<char,int>(c,1));
    if (pair.second == false) {
      pair.first->second += 1;
    }
  }
}

void Freq::print_cyphertext_counts_and_percentages() {
  std::cout << "Total char count (excluding spaces): " << total_count << "\n";
  for (std::map<char,int>::iterator it = cyphertext_counts.begin(); it != cyphertext_counts.end(); ++it) {
    std::cout << "char:\t" << it->first << "\t" << get_count(it) << "\t" << get_percentage(it) << "%\n";
  }
}

double Freq::get_percentage(char c) {
  int count = get_count(c);
  if (count == 0) return 0.0;
  return 100*((double)count / (double)total_count);
}

double Freq::get_percentage(std::map<char,int>::iterator it) {
  int count = get_count(it);
  if (count == 0) return 0.0;
  return 100*((double)count / (double)total_count);
}

int Freq::get_count(char c) {
  std::map<char,int>::iterator it = cyphertext_counts.find(c);
  if (it == cyphertext_counts.end()) return 0;
  return it->second;
}

int Freq::get_count(std::map<char,int>::iterator it) {
  if (it == cyphertext_counts.end()) return 0;
  return it->second;
}
