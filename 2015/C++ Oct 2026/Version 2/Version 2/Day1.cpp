#include "Day1.h"

#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <ranges>
#include <string_view>
#include <vector>



void Day1Part1()
{
	std::vector<std::string> directions = GetFile("Day1.txt");
	int currentDirection = 0;
	int x = { 0 };
	int  y = { 0 };
	for (const std::string& direction : directions)
	{
		int s = std::stoi(direction.substr(1));

		if (direction[0] == 'L')
		{
			currentDirection--;
		}
		else if (direction[0] == 'R')
		{
			currentDirection++;
		}

		if (currentDirection > 3)
		{
			currentDirection %= 4;
		}
		else if (currentDirection < 0)
		{
			while (currentDirection < 0)
			{
				currentDirection += 4;
			}
		}
	
		switch (currentDirection)
		{
			case 0:
				y += s;
				break;
			case 1: 
				x += s;
				break; 
			case 2: 
				y -= s;
				break; 
			case 3: 
				x -= s; 
				break; 
				

		}
		
	}
	std::cout<< "Day 1 part 1: " << abs(x) + abs(y) << std::endl;
	


}

std::vector<std::string> GetFile(std::string fileName)
{
	std::vector<std::string> directions{};

	std::string line{}, direction{};

	std::ifstream iFile(fileName);

	if (!iFile.is_open())
	{
		std::cerr << "cant open file" << std::endl;
	}


	while (std::getline(iFile, direction))
	{
		line += direction;
		//std::cout << line << std::endl;
	}
	//std::cout << line << std::endl;

	std::string delmiter = ",";
	

	for (std::string_view token : std::views::split(line, delmiter)
		| std::views::transform([](auto&& x) {return trimAndConvert(x); } ))
	{
		directions.emplace_back(token);
	}



	return directions;

}

