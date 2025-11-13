#include "CamelHand.h"

using namespace std; 

CamelHand::CamelHand(string hand, long long bid)
{
	this->hand = hand; 
	this->bid = bid; 
	this->handType = getHandType();
}

//TODO: should i just leave hand as hand or maybe make it an hand of cards

HandType GetHandType()
{

}