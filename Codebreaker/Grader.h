#pragma once
#include "Guess.h"

class CGrader
{
public:
	CGrader(void);
	~CGrader(void);

	bool is_valid_one_letter_words( list<CGuess> guess );
	int grade( list<CGuess> guess );
};

