#include "Day10.h"
#include "Bot.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue> 
#include <string>
#include <tuple>
#include <ranges>
#include <unordered_map>

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
	std::unordered_map<int, vector<int>> output{};
	vector<Bot> bots{};
	for (auto line : lines)
	{
		//cout << line << endl; 
		auto parts = std::ranges::split_view(line, ' ') | std::ranges::to<vector<string>>();

		
		if (parts[0] == "bot")
		{
			int name = std::stoi(parts[1]);
			std::tuple<string, int> low{ parts[5], std::stoi(parts[6]) };
			std::tuple<string, int>  high { parts[10], std::stoi(parts[11]) };
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
				std::tuple<string, int, int> high = b->GetHigh(); 
				std::tuple<string, int, int> low = b->GetLow(); 
				
				if (std::get<2>(low) == 17 && std::get<2>(high) == 61)
				{
					cout  << "Day 10 part 1: " <<  b->getId() << endl;
					break;
				}
				if (std::get<0>(high) == "bot")
				{
					bots[std::get<1>(high)].AddValue(std::get<2>(high));
				}
				else if (std::get<0>(high) == "output")
				{
					int high1 = std::get<1>(high);
					if (!output.contains(high1))
					{
						output[high1] = vector<int>{};
					}
					output[high1].push_back(std::get<2>(high));
				}

				if (std::get<0>(low) == "bot")
				{
					bots[std::get<1>(low)].AddValue(std::get<2>(low));
				}
				else if (std::get<0>(low) == "output")
				{
					int low1 = std::get<1>(low);
					if (!output.contains(low1))
					{
						output[low1] = vector<int>{};
					}
					output[low1].push_back(std::get<2>(low));
				}

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
	vector<string> lines{};
	getLines("Day10.txt", lines);
	int maxNumberOfBots{ 0 };
	std::unordered_map<int, vector<int>> output{};
	vector<Bot> bots{};
	for (auto line : lines)
	{
		//cout << line << endl; 
		auto parts = std::ranges::split_view(line, ' ') | std::ranges::to<vector<string>>();


		if (parts[0] == "bot")
		{
			int name = std::stoi(parts[1]);
			std::tuple<string, int> low{ parts[5], std::stoi(parts[6]) };
			std::tuple<string, int>  high{ parts[10], std::stoi(parts[11]) };
			bots.push_back(Bot(name, low, high));
		}
	}

	std::sort(bots.begin(), bots.end(), [](Bot& b1, Bot& b2) { return b1.getId() < b2.getId(); });

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
			auto b = std::ranges::find_if(bots, [](Bot& b) {
				return b.CanGiveAway();
				});

			if (b != bots.end())
			{
				std::tuple<string, int, int> high = b->GetHigh();
				std::tuple<string, int, int> low = b->GetLow();

				if (std::get<0>(high) == "bot")
				{
					bots[std::get<1>(high)].AddValue(std::get<2>(high));
				}
				else if (std::get<0>(high) == "output")
				{
					int high1 = std::get<1>(high);
					if (!output.contains(high1))
					{
						output[high1] = vector<int>{};
					}
					output[high1].push_back(std::get<2>(high));
				}

				if (std::get<0>(low) == "bot")
				{
					bots[std::get<1>(low)].AddValue(std::get<2>(low));
				}
				else if (std::get<0>(low) == "output")
				{
					int low1 = std::get<1>(low);
					if (!output.contains(low1))
					{
						output[low1] = vector<int>{};
					}
					output[low1].push_back(std::get<2>(low));
				}

				b->GiveAway();


			}

		}
		else
		{
			break;
		}
	}

	cout <<"Day 10 part 2: "  << output[0][0] * output[1][0] * output[2][0] << endl;
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


