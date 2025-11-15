#pragma once


class CamelCard
{

		
	
	public:
		CamelCard(char letter);
		
		char letter;
		int strength;

		int getStrength() const;

		//static int getStrengthPart2(char letter);

		bool operator==(const CamelCard& other) const;
		bool operator<(const CamelCard& other) const;

};

