#pragma once
class CLetterCount : public std::map<char, int>
{
public:
	CLetterCount(void);
	~CLetterCount(void);
	void insert(char c);
};

