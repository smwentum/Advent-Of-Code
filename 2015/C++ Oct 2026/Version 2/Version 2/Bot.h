#pragma once

#include<string>
#include<tuple>
#include<vector>


class Bot
{

	public:

		Bot(int id, std::tuple<std::string, int> low, std::tuple<std::string,int> high);
		void AddValue(int val);
		void GiveAway();
		int getId();
		bool CanGiveAway();
		bool CanRecieve(); 
		int getChip();
		int getChipCount();
		std::tuple<std::string, int, int> GetHigh();
		std::tuple<std::string, int, int> GetLow();


	private:
		int id; 
		std::tuple<std::string, int> high;
		std::tuple<std::string, int> low;
		std::vector<int> val{};
};

