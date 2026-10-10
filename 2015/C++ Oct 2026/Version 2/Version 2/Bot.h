#pragma once

#include<tuple>
#include<vector>

class Bot
{

	public:

		Bot(int id, int low, int high);
		void AddValue(int val);
		void GiveAway();
		int getId();
		bool CanGiveAway();
		bool CanRecieve(); 
		int getChip();
		int getChipCount();
		std::tuple<int, int> GetHigh();
		std::tuple<int, int> GetLow();


	private:
		int id; 
		int high; 
		int low; 
		std::vector<int> val{};
};

