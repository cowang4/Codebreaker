#include "StdAfx.h"
#include "Freq.h"

CFreq::CFreq(void)
{
}


CFreq::~CFreq(void)
{
}

std::list<CFreq::freq_pair> CFreq::compute_freq( list<string> &words )
{
	CLetterCount lc;
	string currentWord;
	list<string>::iterator it;

	//iterates through words of raw cypher and preformes action below
	for (it=words.begin(); it!=words.end(); it++)
	{
		//iterates through a word saving each letter to CLetterCount object... more info later
		currentWord = *it;
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

	//iterates through letter count (custom map)
	for (lcit=lc.begin(); lcit!=lc.end(); lcit++)
	{
		//adds the frequncy pair to the end of a list called 'freq', with the correct values from the map of course
		freq.push_back(freq_pair((*lcit).first,(*lcit).second) );
	}

	//probably sorts the list by the most frequently appearing letter
	freq.sort( greater<freq_pair>( ) );

	return freq;
}
