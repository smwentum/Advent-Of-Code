#pragma once


class CamelCard
{
	private:
		char letter;
		int strength;
	
	public:
		CamelCard(char letter);
		
		int getStrength() const;

		bool operator==(const CamelCard& other) const;
		bool operator<(const CamelCard& other) const;

};

