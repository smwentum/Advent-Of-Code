#pragma once

#include<algorithm>
#include <string>
#include <vector>
#include <iostream>

#include "HandType.h"
#include "CamelCard.h"

class CamelHand
{
	public:
		CamelHand(std::string hand, long long bid);
		long long getBid();
		bool operator<(const CamelHand& other) const;
		bool operator()(const CamelHand& a, const CamelHand& b) const;
	private:
		std::string hand; 
		long long bid;
		HandType handType; 
		std::string GetHandTypeName(HandType ht);
		std::vector<CamelCard> cards;
		HandType GetHandType(std::vector<CamelCard> cards) ;
		bool isFiveOfAKind(std::vector<CamelCard> cards) ;
		bool isFourOfAKind(std::vector<CamelCard> cards) ;
		bool isThreeOfAKind(std::vector<CamelCard> cards);
		bool isPair(std::vector<CamelCard> cards);
		bool isTwoPair(std::vector<CamelCard> cards);
		
		
			
		
};

