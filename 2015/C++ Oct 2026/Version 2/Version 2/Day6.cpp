#include "Day6.h"

#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>


void Day6Part1()
{
	std::vector<std::string> lines = getLines("day6.txt");
	std::cout << "Day 6 part 1: ";
	for (int col = 0; col < lines[0].size(); col++)
	{
		std::map<char, int> map{}; 
		
		for (int row = 0; row < lines.size(); row++)
		{
			if (map.contains(lines[row][col]))
			{
				map[lines[row][col]]++; 
			}
			else
			{
				map[lines[row][col]] = 1; 
			}
		}

		//i should have a co

		auto maxVal = std::max_element(map.begin(), map.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
			});

		std::cout << maxVal->first;
	}
	std::cout << std::endl;
}
void Day6Part2()
{
	std::vector<std::string> lines = getLines("day6.txt");
	std::cout << "Day 6 part 1: ";
	for (int col = 0; col < lines[0].size(); col++)
	{
		std::map<char, int> map{};

		for (int row = 0; row < lines.size(); row++)
		{
			if (map.contains(lines[row][col]))
			{
				map[lines[row][col]]++;
			}
			else
			{
				map[lines[row][col]] = 1;
			}
		}

		//i should have a co

		auto maxVal = std::max_element(map.begin(), map.end(), [](const auto& p1, const auto& p2) {
			return p1.second > p2.second;
			});

		std::cout << maxVal->first;
	}
	std::cout << std::endl;
}


std::vector<std::string> getLines(std::string fileName)
{
	std::vector<std::string>lines{};
	
	std::ifstream file(fileName); 
	std::string line; 

	while (std::getline(file, line))
	{
		lines.push_back(line);
	}

	return lines;
}

