#include "Day10.h"
#include "Bot.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue> 
#include <string>
#include <tuple>
#include <ranges>

#include <vector>

using std::string; 
using std::vector; 
using std::cin; 
using std::cout; 
using std::endl;


void Day10Part1()
{

	vector<string> lines{};
	getLines("Day10.txt", lines);
	int maxNumberOfBots{ 0 };

	//for (auto line : lines)
	//{
	//	//cout << line << endl; 
	//	auto parts = std::ranges::split_view(line, ' ') | std::ranges::to<vector<string>>();
	//	

	//	if (parts[0] == "value")
	//	{
	//		maxNumberOfBots = std::max(maxNumberOfBots, std::stoi(parts[5]));
	//	}
	//	if (parts[0] == "bots")
	//	{
	//		maxNumberOfBots = std::max(maxNumberOfBots, std::stoi(parts[1]));
	//		maxNumberOfBots = std::max(maxNumberOfBots, std::stoi(parts[6]));
	//		maxNumberOfBots = std::max(maxNumberOfBots, std::stoi(parts[11]));
	//	}
	//}

	//cout << maxNumberOfBots << endl;
	
	vector<Bot> bots{};
	//create the bots 
	for (auto line : lines)
	{
		//cout << line << endl; 
		auto parts = std::ranges::split_view(line, ' ') | std::ranges::to<vector<string>>();

		
		if (parts[0] == "bot")
		{
			int name = std::stoi(parts[1]);
			int low = std::stoi(parts[6]);
			int high = std::stoi(parts[11]);
			bots.push_back(Bot(name, low, high));
		}
	}

	std::sort(bots.begin(), bots.end(), [](Bot& b1, Bot&b2) { return b1.getId() < b2.getId(); });

	for (auto line : lines)
	{
		//cout << line << endl; 
		auto parts = std::ranges::split_view(line, ' ') | std::ranges::to<vector<string>>();
		if (parts[0] == "value")
		{
			int id = std::stoi(parts[5]);
			int val = std::stoi(parts[1]);
			bots[id].AddValue(val);

		}
	}

	while (true)
	{
		if (std::ranges::any_of(bots, [](Bot b) {
			return b.CanGiveAway();
			}))
		{
			auto b = std::ranges::find_if(bots, [](  Bot& b) {
				return b.CanGiveAway();
				});

			if (b != bots.end())
			{
				std::tuple<int, int> high = b->GetHigh(); 
				std::tuple<int, int> low = b->GetLow(); 
				//cout << "Name :" << b->getId() << endl;
				//cout << "High " << std::get<0>(high) << " " << std::get<1>(high) << endl;
				//cout << "Low " << std::get<0>(low) << " " << std::get<1>(low) << endl;
				if (std::get<1>(low) == 17 && std::get<1>(high) == 61)
				{
					cout  << "Day 10 part 1: " <<  b->getId() << endl;
				}
				bots[std::get<0>(high) ].AddValue(std::get<1>(high));
				bots[std::get<0>(low)].AddValue(std::get<1>(low));
				b->GiveAway();

				
			}

		}
		else
		{
			break; 
		}
	}

}
void Day10Part2()
{

}

void getLines(string fileName, vector<string>& lines)
{
	std::fstream file(fileName); 

	string line; 
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
}


