#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "HandType.h"

class CamelHand
{
	public:
		CamelHand(std::string hand, long long bid);
	private:
		string hand; 
		long long bid;
		HandType handType; 

		HandType GetHandType();
};

