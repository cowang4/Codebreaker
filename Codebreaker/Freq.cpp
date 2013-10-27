#include "StdAfx.h"
#include "Freq.h"
#include "Guess.h"

CFreq::CFreq(void)
{
}


CFreq::~CFreq(void)
{
}

std::list<CFreq::freq_pair> CFreq::compute_freq( list<CGuess> &words )//returns sorted list of most commonly used letters
{
	CLetterCount lc;
	string currentWord;
	list<CGuess>::iterator it;

	//iterates through words of raw cypher and preformes action below
	for (it=words.begin(); it!=words.end(); it++)
	{
		//iterates through a word saving each letter to CLetterCount object... more info later
		currentWord = (*it).origword;
		for (unsigned int i = 0; i < currentWord.length(); i++ )
		{
			char curchar;
			curchar = currentWord[i];
			lc.insert (curchar);
		}
	}
	
	//a frequency pair is a pair of values a char and an int
	std::list<freq_pair> freq;
	CLetterCount::iterator lcit;

	//iterates through letter count (custom map of char letter, int count)
	for (lcit=lc.begin(); lcit!=lc.end(); lcit++)
	{
		//adds the frequncy pair to the end of a list called 'freq', with the correct values from the map of course
		freq.push_back(freq_pair((*lcit).first,(*lcit).second) );
	}

	//probably sorts the list by the most frequently appearing letter
	freq.sort( greater<freq_pair>( ) );

	/*
	Used map of LetterCounts to search by char letter (maps are <key, value>).
	Now using list of frequency pairs because can sort by count (value basiclly)
	*/

	return freq;
}
