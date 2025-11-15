#pragma once


class CamelCard
{

		
	
	public:
		CamelCard(char letter);
		
		char letter;
		int strength;

		int getStrength() const;

		bool operator==(const CamelCard& other) const;
		bool operator<(const CamelCard& other) const;

};

