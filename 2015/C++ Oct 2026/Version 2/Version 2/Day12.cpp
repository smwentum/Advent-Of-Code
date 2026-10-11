#include "Day12.h"

#include<algorithm>
#include<fstream>
#include<iostream>
#include<string>
#include<ranges>
#include<unordered_map>
#include<vector>


using std::string; 
using std::vector; 
using std::cin;
using std::cout; 
using std::endl;

void Day12Part1()
{
	vector <string> lines{}; 
	GetLinesFromFile("Day12a.txt",lines);
	vector<vector<string>> splitlines{};
	int i = 0; 
	std::unordered_map<char,int> map{};

	map['a'] = 0;
	map['b'] = 0;
	map['c'] = 0; 
	map['d'] = 0;

	for (auto line : lines)
	{

		cout << line << endl;
		
		splitlines.push_back(std::views::split(line, ' ') | std::ranges::to<vector<string>>());
		i++;
	}

	int lineCount{ 0 };

	while (lineCount < splitlines.size() && lineCount >= 0)
	{
		if (splitlines[lineCount][0] == "cpy")
		{
			string valueCoppied{ splitlines[lineCount][1] };
			char key{ splitlines[lineCount][2][0] };
			if (!std::any_of(valueCoppied.begin(), valueCoppied.end(),
				[](unsigned char c) {
					return std::isalpha(c);
				}))
			{
				map[key] = std::stoi(valueCoppied);
			}
			else
			{
				map[key] = map[splitlines[lineCount][1][0]];
			}
			lineCount++;
		}
		else if (splitlines[lineCount][0] == "inc")
		{
			map[splitlines[lineCount][1][0]]++;
			lineCount++;
		}
		else if (splitlines[lineCount][0] == "dec")
		{
			map[splitlines[lineCount][1][0]]--;
			lineCount++;
		}
		else if (splitlines[lineCount][0] == "jnz")
		{
			string valueCoppied{ splitlines[lineCount][1] };
			if (!std::any_of(valueCoppied.begin(), valueCoppied.end(),
				[](unsigned char c) {
					return std::isalpha(c);
				}))
			{
				if (std::stoi(valueCoppied) == 0)
				{
					lineCount++;
				}
				else
				{
					lineCount += stoi(splitlines[lineCount][2]);
				}
			}
			else
			{
				if (map[valueCoppied[0]] != 0)
				{
					lineCount += stoi(splitlines[lineCount][2]);
				}
				else
				{
					lineCount++;
				}
			}
		}
	}

	cout << "Day 12 part 1: " << map['a'] << endl;

	//vector<vector<string>> splitlines = std::views::split(lines, ' ') | std::ranges::to<vector<vector<string>>>();

}
void Day12Part2()
{

}

void GetLinesFromFile(const string& filename, vector<string>& lines)
{
	std::fstream file(filename); 

	if (!file.is_open())
	{
		cout << "Error opening the file"; 
	}
	string line; 
	while (std::getline(file, line))
	{
		lines.push_back(line);
	}
}
