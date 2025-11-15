#pragma once
class CamelCardPart2
{
private:
	

public:
	CamelCardPart2(char letter);
	char letter;
	int strength;
	int getStrengthPart2() const;

	bool operator==(const CamelCardPart2& other) const;
	bool operator<(const CamelCardPart2& other) const;
};

