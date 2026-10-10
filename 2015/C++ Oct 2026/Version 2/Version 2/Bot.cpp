#include "Bot.h"


#include <algorithm>
#include <tuple>
#include <vector>



Bot::Bot(int id, int low, int high)
{
	this->id = id;
	this->low = low; 
	this->high = high; 


}

int Bot::getId()
{
	return this->id;
}
int Bot::getChip()
{
	return this->val[1];
}

void Bot::AddValue(int v)
{
	this->val.push_back(v);
	if (this->val.size() > 1)
	{
		std::sort(val.begin(), val.end());
	}
	
}



bool Bot::CanGiveAway()
{
	return this->val.size() == 2;
}

void Bot::GiveAway()
{
	this->val.clear();
}

bool Bot::CanRecieve()
{
	return this->val.size() < 2;
}

std::tuple<int,int> Bot::GetHigh()
{
	if (CanGiveAway())
	{
		return std::tuple<int,int>(this->high, this->val[1]);
	}
}

std::tuple<int, int> Bot::GetLow()
{
	if (CanGiveAway())
	{
		return std::tuple<int, int>(this->low, this->val[0]);
	}
}