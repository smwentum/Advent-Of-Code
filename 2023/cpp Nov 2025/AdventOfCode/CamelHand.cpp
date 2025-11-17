#include "CamelHand.h"
#include "CamelCard.h"

using namespace std; 


CamelHand::CamelHand(string hand, long long bid, bool usePart2Deck)
{
	this->hand = hand; 
	this->bid = bid; 
	
	
	for (char h : hand)
	{
		
		cards.push_back(CamelCard(h));
		
	}
	sort(cards.begin(), cards.end());
	if (!usePart2Deck)
	{

		this->handType = GetHandType(cards);
	}
	else
	{
		HandType HandTypeOldWay = GetHandType(cards); 
		HandType HandTypeNewWay = GetHandTypePart2(cards);
		this->handType = max(HandTypeOldWay,HandTypeNewWay);
	}
	
	if (any_of(hand.begin(), hand.end(), [](char c) { return c == 'J'; }))
	{
		/*cout << "Hand: " << this->hand
			<< " " << GetHandTypeName(this->handType) << endl;*/
	}
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
	if (isFourOfAKind(vector<CamelCard>(cards.begin(), cards.end())))
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


HandType CamelHand::GetHandTypePart2(vector<CamelCard> cards)
{
	//took this from the last time i answered this i am going to strip out the jacks and see what happens
	erase_if(cards, [](CamelCard c) { return c.letter == 'J'; });
	sort(cards.begin(), cards.end());
	if (cards.size() == 0 || cards.size() == 1)
	{
		return HandType::FiveOfAKind;
	}
	if (cards.size() == 2)
	{
		if (isPair(cards))
		{
			return HandType::FiveOfAKind;
		}
		else
		{
			return HandType::FourOfAKind;
		}
	}
	if (cards.size() == 3)
	{
		if (all_of(cards.begin() + 1, cards.end(), [&](const CamelCard& c) {
			return c.letter == cards[0].letter;
			}))
		{
			return HandType::FiveOfAKind;
		}
		if (isThreeOfAKind(cards))
		{
			return HandType::FullHouse;
		}
		if (isPair(cards))
		{
			return HandType::FourOfAKind;
		}
		return HandType::ThreeOfKind;
	}
	if (cards.size() == 4)
	{
		if (all_of(cards.begin() + 1, cards.end(), [&](const CamelCard& c) {
			return c.letter == cards[0].letter;
			}))
		{
			return HandType::FiveOfAKind;
		}
		if (isTwoPair(cards))
		{
			return HandType::FullHouse;
		}
		if (isThreeOfAKind(cards))
		{
			return HandType::FourOfAKind;
		}
		
		if (isPair(cards))
		{
			return HandType::ThreeOfKind;
		}


		return HandType::OnePair;

	}



	

	return HandType::HighCard;
}



bool CamelHand::isFiveOfAKind(vector<CamelCard> cards) 
{
	for (int i = 0; i < cards.size()-1; i++)
	{
		if (cards[i].letter != cards[i + 1].letter)
		{
			return false; 
		}
	}

	return cards.size() == 5;
		
}



bool CamelHand::isFourOfAKind(vector<CamelCard> cards) 
{
	bool isFirstFourCardsAFourOfAKind = true; 
	for (int i = 0; i < cards.size() - 2; i++)
	{
		if (cards[0].letter != cards[i + 1].letter)
		{
			isFirstFourCardsAFourOfAKind = false;
			break; 
		}
	}
	if (isFirstFourCardsAFourOfAKind)
	{
		return true; 
	}
	bool isLastfourCardsAforOfAKind = true; 
	for (int i = 1; i < cards.size()-1 ; i++)
	{
		if (cards[1].letter != cards[i + 1].letter)
		{
			return false;
		}
	}
	return true; 



}

bool CamelHand::isThreeOfAKind(vector<CamelCard> cards)
{
	
	if (cards.size() < 3)
	{
		return false;
	}

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
	if (cards.size() < 2)
	{
		return false;
	}

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
	if (cards.size() < 4)
	{
		return false;
	}

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