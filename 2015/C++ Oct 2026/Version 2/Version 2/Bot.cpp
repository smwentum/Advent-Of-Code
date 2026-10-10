#include "Bot.h"


#include <algorithm>
#include<string>
#include <tuple>
#include <vector>

using std::string;


Bot::Bot(int id, std::tuple<std::string, int> low, std::tuple<std::string, int> high)
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
	return this->val[0];
}
int Bot::getChipCount()
{
	return this->val.size();
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

std::tuple<std::string, int, int> Bot::GetHigh()
{
	if (CanGiveAway())
	{
		return std::tuple<std::string,int,int>(std::get<0>(this->high), std::get<1>(this->high), this->val[1]);
	}
}

std::tuple<std::string, int, int> Bot::GetLow()
{
	if (CanGiveAway())
	{
		return std::tuple<std::string,int, int>(std::get<0>(this->low), std::get<1>(this->low), this->val[0]);
	}
}