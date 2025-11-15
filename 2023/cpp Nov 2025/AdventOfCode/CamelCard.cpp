#include "CamelCard.h"


CamelCard::CamelCard(char letter)
{
	this->letter = letter;
	this->strength = getStrength();
}

bool CamelCard::operator==(const CamelCard& other) const
{
	return letter == other.letter;
}

bool CamelCard::operator<(const CamelCard& other) const
{
	return getStrength() < other.getStrength();
}

int CamelCard::getStrength() const
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
			return 11; 
		case 'Q':
			return 12; 
		case 'K':
			return 13;
		case 'A':
			return 14;
	}
	return 0;
}


