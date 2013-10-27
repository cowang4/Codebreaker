#include "StdAfx.h"
#include "Guess.h"

CGuess::~CGuess(void)
{
}

void CGuess::substitute( char oldletter, char newletter )
{
	string new_guess;
	new_guess = substitute( this->origword, this->guessword, oldletter, newletter );
	this->guessword = new_guess;
}

string CGuess::substitute( string word, char oldletter, char newletter )
{
	return substitute( word, "", oldletter, newletter );
}

string CGuess::substitute( string word, string old_subs, char oldletter, char newletter )
{
	string new_subs( word.length(), ' ');
	string temp_old_subs;
	if (word.length() == old_subs.length())
		temp_old_subs = old_subs;
	else 
	{
		temp_old_subs = old_subs + word.substr( old_subs.length(), word.length() - old_subs.length() ) ;
	}

	// Loop through each character of variable 'word'
	for(unsigned int i = 0; i < word.length(); i++ )
	{
		char current_char = word[i];
		char current_guess_char = temp_old_subs[i];

		// If the character in the word is different than the one in the same position of 
		// the current guess, copy the character from the current guess (since we've already
		// guessed what character it should be)
		// If the current character in the word is the one we want to substitute, do the substituion
		// with the new letter in UPPERCASE.
		// Otherwise, just copy the old letter over.
		if (current_char != current_guess_char)
			new_subs[i] = current_guess_char;
		else if (current_char == oldletter)
			new_subs[i] = _toupper(newletter);
		else
			new_subs[i] = current_char;
	}

	return new_subs;
}
