#include "StdAfx.h"
#include "LetterCount.h"


CLetterCount::CLetterCount(void)
{
}


CLetterCount::~CLetterCount(void)
{
}

void CLetterCount::insert(char c)
{
	//searches list of letters, if found, adds 1 to its count, otherwise adds to end of list 
	CLetterCount::iterator it;
	it = this->find(c);
	
	if (it != end() )
	{
		(*it).second = (*it).second + 1; 
	}
	else
	{
		(*this)[c] = 1;
	}

}
