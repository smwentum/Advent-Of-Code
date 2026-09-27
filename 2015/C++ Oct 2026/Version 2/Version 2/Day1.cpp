#include "Day1.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ranges>
#include <string_view>
#include <vector>



void Day1Part1()
{
	std::vector<std::string> directions = GetFile("Day1a.txt");
	for (std::string direction : directions)
	{
		std::cout << direction <<std::endl;
	}
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
	std::cout << line << std::endl;


	//auto sp


	//for (const auto token : std::views::split(line, ","))
	//{
	//	directions.push_back(std::string{ std::string_view(token) });
	//}*/

	return directions;

}