#pragma once
class CGuess
{
public:
	CGuess(void) : origword(""), guessword("") { }
	CGuess(string o, string g) { origword = o; guessword = g; }
	~CGuess(void);

	string origword;
	string guessword;
	void substitute( char oldletter, char newletter );
	static string substitute( string word, char oldletter, char newletter );
	static string substitute( string word, string old_subs, char oldletter, char newletter );
	static std::string to_string ();
};


template<class _Elem,
	class _Traits> inline
	std::basic_ostream<_Elem, _Traits>& operator<<(
		std::basic_ostream<_Elem, _Traits>& _Ostr,
		const CGuess _grgt)
	{	// insert a string
//		_Ostr << CGuess::to_string (origword.guessword);
		_Ostr << " " << _grgt.origword <<" = "<< _grgt.guessword;
		return _Ostr;
	}

template<class _Elem,
	class _Traits> inline
	std::basic_ostream<_Elem, _Traits>& operator<<(
		std::basic_ostream<_Elem, _Traits>& _Ostr,
		const std::list<CGuess> &list)
	{
		for (std::list<CGuess>::const_iterator it=list.begin(); it!=list.end(); it++)
		{
			_Ostr << *it << endl;
		}

		return _Ostr;
	};