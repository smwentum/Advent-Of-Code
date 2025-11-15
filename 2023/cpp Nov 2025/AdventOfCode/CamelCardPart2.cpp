#include "CamelCardPart2.h"

CamelCardPart2::CamelCardPart2(char letter)
{
	this->letter = letter;
	this->strength = getStrengthPart2();
}

bool CamelCardPart2::operator==(const CamelCardPart2& other) const
{
	return letter == other.letter;
}

bool CamelCardPart2::operator<(const CamelCardPart2& other) const
{
	return getStrengthPart2() < other.getStrengthPart2();
}

int CamelCardPart2::getStrengthPart2() const
{
	switch (this->letter)
	{
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'T':
		return 10;
	case 'J':
		return -1;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'A':
		return 14;
	}
	return 0;
}