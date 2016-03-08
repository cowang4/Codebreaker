// Codebreaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Freq.h"
#include "Grader.h"
#include "Guess.h"

std::list<CGuess> readStream(istream *stm);
void substitute(list<CGuess> &cypher, char oldLetter, char newLetter);
void substituteUsingFreqAnalysis(list<CGuess> cypher, std::list<CFreq::freq_pair> modelist, int char_to_try, char* letters);
list<CGuess> findNLetterWords(list<CGuess> cypher, int n);

string one_letter_words[] = { "a", "i" };
string common_two_letter_words[] = { "of", "to", "in", "it", "is", "he", "by", "or", "as", "at", "an", "so", "am", "ax", "me", "go", "be", "do", "ha", "he", "hi", "if", "my", "no", "oh", "on", "uh", "um", "up", "us", "we"};
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
	//reads cypher from stream (console or file)
	list<CGuess> cypherText = readStream(stm);

	modelist = CFreq::compute_freq (cypherText);//calculates most used letters in cypher, and arranges them from greatest to least used
	cout << modelist << endl;
	
	// Try our first guess using the most common letters in English
	substituteUsingFreqAnalysis(cypherText, modelist, 8, common_letters);

	//try our seccond guess with random top eight most commonly used letters
	substituteUsingFreqAnalysis(cypherText, modelist, 8, rantop8);

	return 0;
}

std::list<CGuess> readStream (istream *stm)
{
	string word; 
	list<CGuess> cypher;
	do
	{
		//reads the words from the file to a list of words
		*stm >> word;
		cypher.push_back(CGuess(word, word ));
	}
	while ( stm->eof() != 1);//cancel the do after no more words in istream (file)	

	return cypher;
}


void substitute(list<CGuess> &cypher, char oldLetter, char newLetter)
{
		for( list<CGuess>::iterator it = cypher.begin(); it != cypher.end(); it++ )//loops through words in a "guess" (list<CGuess>) and substitutes the old letters for new letter, new in Uppercase
		{
			it->substitute(oldLetter, newLetter);
			
		}
}

void substituteUsingOneLetterWords(list<CGuess> cleanCypher)
{
	//find 1 letter words
	list<CGuess> oneLetterWords = findNLetterWords(cleanCypher, 1);
	
	for (list<CGuess>::iterator i = oneLetterWords.begin(); i != oneLetterWords.end(); i++)
	{

	}
}

list<CGuess> findNLetterWords(list<CGuess> cypher, int n)
{
	list<CGuess> nLenghtwords;
	for (list<CGuess>::iterator i = cypher.begin(); i != cypher.end(); i++)//iterates through words
	{
		if ((*i).guessword.length() == n && (*i).guessword != nLenghtwords.find((*i).guessword))//stopped here, this doesnt work, need to write my own find
		{
			nLenghtwords.push_back(*i);
		}
	}
}

void substituteUsingFreqAnalysis (list<CGuess> cypher, std::list<CFreq::freq_pair> modelist, int char_to_try, char* letters)//gets called by decoder above that filters out words
{
	std::list<CFreq::freq_pair>::iterator mlit = modelist.begin();

	CFreq::freq_pair cur_freq_letter = (*mlit);

	for (int i = 0; i < char_to_try; i++)//for the charachters we want to try,
	{
		cur_freq_letter = *mlit;	
		mlit++;						

		substitute(cypher, cur_freq_letter.first, letters[i]);

	}

	cout << cypher << endl;

	return;
}