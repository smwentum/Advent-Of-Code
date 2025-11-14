#include "CamelHand.h"
#include "CamelCard.h"

using namespace std; 

CamelHand::CamelHand(string hand, long long bid)
{
	this->hand = hand; 
	this->bid = bid; 
	
	
	for (char h : hand)
	{
		cards.push_back(CamelCard(h));
	}
	sort(cards.begin(),cards.end());
	this->handType = GetHandType(cards);
	cout << "Hand: " << this->hand
		<< " " << GetHandTypeName(this->handType) << endl; 
}

string CamelHand::GetHandTypeName(HandType ht)
{
	switch (ht)
	{
		case HandType::FiveOfAKind:
			return "Five of a kind";
		case HandType::FourOfAKind:
			return "Four of a kind";
		case HandType::FullHouse:
			return "Full house";
		case HandType::ThreeOfKind:
			return "Three of a kind";
		case HandType::TwoPair:
			return "Two pair";
		case HandType::OnePair:
			return "One pair";
		case HandType::HighCard:
			return "High card";
		
	}
	return "Unknown";
}

//TODO: should i just leave hand as hand or maybe make it an hand of cards

HandType CamelHand::GetHandType(vector<CamelCard> cards)
{
	if (isFiveOfAKind(cards))
	{
		return HandType::FiveOfAKind;
	}
	if (isFourOfAKind(vector<CamelCard>(cards.begin() + 1, cards.end())) ||
		isFourOfAKind(vector<CamelCard>(cards.begin(), cards.end() - 1)))
	{
		return HandType::FourOfAKind;
	}
	if (isThreeOfAKind(vector<CamelCard>(cards.begin(), cards.end() - 2))
		&& isPair(vector<CamelCard>(cards.begin() + 2, cards.end())) )
	{
		return HandType::FullHouse;
	}

	if (isThreeOfAKind(vector<CamelCard>(cards.begin()+2, cards.end()))
		&& isPair(vector<CamelCard>(cards.begin(), cards.end()-3)))
	{
		return HandType::FullHouse;
	}

	if (isThreeOfAKind(cards))
	{
		return HandType::ThreeOfKind;
	}
	if (isTwoPair(cards))
	{
		return HandType::TwoPair;
	}
	if (isPair(cards))
	{
		return HandType::OnePair;
	}


	

	return HandType::HighCard;
}

bool CamelHand::isFiveOfAKind(vector<CamelCard> cards) 
{
	for (int i = 0; i < cards.size()-1; i++)
	{
		if (cards[i] != cards[i + 1])
		{
			return false; 
		}
	}

	return cards.size() == 5;
		
}

bool CamelHand::isFourOfAKind(vector<CamelCard> cards) 
{
	for (int i = 0; i < cards.size() - 1; i++)
	{
		if (cards[i] != cards[i + 1])
		{
			return false;
		}
	}

	return cards.size() == 4;
}

bool CamelHand::isThreeOfAKind(vector<CamelCard> cards)
{
	
	for (int i = 0; i < cards.size() - 2; i++)
	{
		if (cards[i] == cards[i + 1] 
			&& cards[i] == cards[i + 2])
		{
			return true;
		}
	}

	return false; 
}

//This assumes the cards are sorted 
bool CamelHand::isPair(vector<CamelCard> cards)
{

	for (int i = 0; i < cards.size()-1; i++)
	{
		if (cards[i] == cards[i + 1])
		{
			return true; 
		}
	}
	return false; 
}


bool CamelHand::isTwoPair(vector<CamelCard> cards)
{

	for (int i = 0; i < cards.size() - 1; i++)
	{
		if (cards[i] == cards[i + 1])
		{
			vector<CamelCard> restOfHand; 
			for (int j = i + 2; j < cards.size(); j++)
			{
				restOfHand.push_back(cards[j]);
			}
			return isPair(restOfHand);
		}
	}
	return false;
}

bool CamelHand::operator<(const CamelHand& other) const
{
	if (this->handType != other.handType)
	{
		return this->handType <  other.handType;
	}

	vector<CamelCard> cards1{};
	vector<CamelCard> cards2{};
	for (char h : this->hand)
	{
		cards1.push_back(CamelCard(h));
	}
	for (char h : other.hand)
	{
		cards2.push_back(CamelCard(h));
	}

	for (int i = 0; i < cards1.size(); i++)
	{
		if (cards1[i] == cards2[i])
		{
			continue;
		}
		return cards1[i] < cards2[i];
	}
}

long long CamelHand::getBid()
{
	return bid;
}

bool CamelHand::operator()(const CamelHand& a, const CamelHand& b) const {
	return a < b; // Sort in descending order
}