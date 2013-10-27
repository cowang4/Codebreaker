#pragma once
#include "LetterCount.h"
#include "Guess.h"

class CFreq
{
public:
	CFreq(void);
	~CFreq(void);

	class freq_pair: public std::pair<char,int>
	{
	public:
		freq_pair(char _f, int _s) : std::pair<char,int>(_f,_s) {}

		bool operator<  (const freq_pair &rhs) const { return this->second < rhs.second; }
		bool operator>  (const freq_pair &rhs) const { return this->second > rhs.second; }
	};
	
	static std::list<CFreq::freq_pair> compute_freq( list<CGuess> &words );
};

template<class _Elem,
	class _Traits> inline
	std::basic_ostream<_Elem, _Traits>& operator<<(
		std::basic_ostream<_Elem, _Traits>& _Ostr,
		const CFreq::freq_pair &fp)
	{	// insert a string
		_Ostr << fp.first << " occurs " << fp.second;
		return _Ostr;
	};

	template<class _Elem,
	class _Traits> inline
	std::basic_ostream<_Elem, _Traits>& operator<<(
		std::basic_ostream<_Elem, _Traits>& _Ostr,
		const std::list<CFreq::freq_pair> &list)
	{
		for (std::list<CFreq::freq_pair>::const_iterator it=list.begin(); it!=list.end(); it++)
		{
			const CFreq::freq_pair &p = (*it);
			_Ostr << p << endl;
		}
		return _Ostr;
	};