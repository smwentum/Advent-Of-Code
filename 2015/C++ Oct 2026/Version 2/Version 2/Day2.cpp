#include "Day2.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



void Day2Part1()
{
	std::vector<std::string> instructions = getInstructions("day2.txt");

	int row = 1; 
	int col = 1; 

	std::vector<std::vector<char>> map(3, std::vector<char>(3,0));

	map[0][0] = '1';
	map[0][1] = '2';
	map[0][2] = '3';
	map[1][0] = '4';
	map[1][1] = '5';
	map[1][2] = '6';
	map[2][0] = '7';
	map[2][1] = '8';
	map[2][2] = '9';


	std::cout << "Day 2 part 1: ";
	for (auto instruction : instructions)
	{
		//std::cout << instruction << std::endl; 
		//take each instruction and find the
		for (auto inst : instruction)
		{
			if (inst == 'U')
			{
				row =  std::max(0, row - 1);
			}
			else if (inst == 'D')
			{
				row = std::min(2, row + 1);
			}
			else if (inst == 'L')
			{
				col = std::max(0, col - 1);
			}
			else if (inst == 'R')
			{
				col = std::min(2, col + 1);
			}
			//std::cout << map[row][col] << std::endl ;
			
		}
		std::cout << map[row][col];// << std::endl << std::endl;
		
	}
	std::cout << std::endl; 
}



void Day2Part2()
{

}


std::vector<std::string> getInstructions(std::string fileName)
{
	std::vector<std::string> instructions{};

	std::ifstream fstream(fileName);

	if (!fstream.is_open())
	{
		std::cerr << "Cannot open file" << std::endl; 
	}

	std::string  direction; 
	while (std::getline(fstream, direction))
	{
		instructions.push_back(direction);
	}

	return instructions; 
}