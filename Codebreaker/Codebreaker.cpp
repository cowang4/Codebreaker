// Codebreaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Freq.h"
#include "Grader.h"
#include "Guess.h"

std::list<CFreq::freq_pair> decoder (istream *stm, int char_to_try,char *letters);
std::list<CFreq::freq_pair> decoder (list<string> cypher, int char_to_try, char* letters);

string one_letter_words[] = { "a", "i" };
string common_two_letter_words[] = { "of", "to", "in", "it", "is", "he", "by", "or", "as", "at", "an", "so" };
string common_three_letter_words[] = { "the", "and", "for", "are", "but", "all", "not" };
string common_four_letter_words[] = { "that", "with", "from", "have", "this", "they" };

int _tmain(int argc, _TCHAR* argv[])
{
	static char rantop8[] = {'t','a','e','i','n','o','s','r'};
	static char common_letters[] = { 'e', 't', 'a', 'o', 'n', 'i', 's', 'r', 'h', 'l', 'd', 'c', 'u', 'p', 'f', 'm', 'w', 'y', 'b', 'g', 'v', 'k', 'q', 'x', 'j', 'z' };
	std::list<CFreq::freq_pair> modelist;
	istream *stm;
	list<CFreq::freq_pair>::iterator it;
	string filename;

	if (argc <= 1)
	{
		cout<< "Please type in cyphertext\n\n";
		stm = &cin;
	}
	else
	{
		filename = argv[1];
		stm = new fstream (filename, ios::in);
	}
	
	// Try our first guess using the most common letters in English
	modelist = decoder(stm,8, common_letters);
	cout << modelist << endl;

	//try our seccond guess with random top eight most commonly used letters
	modelist = decoder(stm,8, rantop8);
	cout << modelist << endl;
	return 0;
}

std::list<CFreq::freq_pair> decoder (istream *stm, int char_to_try, char* letters)//called by main with a filestream
{
	std::list<CFreq::freq_pair> modelist;
	string word; 
	list<string> cypher;
	do
	{
		//reads the words from the file to a list of words
		*stm >> word;
		cypher.push_back (word);
	}
	while ( stm->eof() != 1);//cancel the do after no more words in istream (file)	
	modelist = decoder (cypher, char_to_try, letters);
	return modelist;

}
std::list<CFreq::freq_pair> decoder (list<string> cypher, int char_to_try, char* letters)//gets called by decoder above that filters out words
{
	std::list<CFreq::freq_pair> modelist;

	// Starting to add an if statement to check if the cyper list is empty.  Got interrupted //maybe fixed this, needs testing
	if (cypher.size() >1)
		return modelist;

	modelist = CFreq::compute_freq (cypher);//calculates most used letters in cypher, and arranges them from greatest to least used
	std::list<CFreq::freq_pair>::iterator mlit = modelist.begin();
	list<CGuess> guess;//list of guesses

	CFreq::freq_pair cur_freq_letter = (*mlit);
	mlit++;

	//starts guessing the answers to the cypher, word by word
	for( list<string>::iterator it = cypher.begin(); it != cypher.end(); it++ )
	{
		string word = (*it);

		string first_guess = CGuess::substitute( word, cur_freq_letter.first, letters[0] );
		guess.push_back( CGuess( word, first_guess ));
	}


	for (int i = 1; i < char_to_try; i++)
	{
		cur_freq_letter = *mlit;	// first time through loop, copy 2nd modelist item and 
		mlit++;						// point to 3rd

	
		for( list<CGuess>::iterator it = guess.begin(); it != guess.end(); it++ )
		{
			it->substitute (cur_freq_letter.first ,letters [i]);
			
		}
	}

	cout << guess << endl;

	return modelist;
}