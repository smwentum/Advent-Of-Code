#include "Day3.h"
#include "Triangle.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>



//set of steps 

void DayThreePartOne()
{
	std::vector<Triangle> triangles = GetTrianglesFromFile("Day3.txt");

	std::cout <<"Day 3 part 1: " << std::ranges::count_if(triangles, std::identity(), &Triangle::isTriangle) << std::endl;
}



void DayThreePartTwo()
{
	std::vector<Triangle> triangles = GetTrianglesFromFilePart2("day3.txt");

	std::cout << "Day 3 part 2: " << std::ranges::count_if(triangles, std::identity(), &Triangle::isTriangle) << std::endl;
}


std::vector<Triangle> GetTrianglesFromFile(std::string fileName)
{
	std::ifstream fstream(fileName); 

	std::vector<Triangle> triangles; 
	if (!fstream.is_open())
	{
		std::cerr << "Cannot open file" << std::endl;
	}

	std::string line; 


	while (std::getline(fstream, line))
	{
	

		auto side_lengths = std::views::split(line, ' ') 
			| std::views::filter([](auto&& r)
				{
					return !r.empty();
				})
			| std::views::transform([](auto&& r)
				{
					unsigned int value = 0; 
					std::from_chars(r.data(), r.data() + r.size(), value);
					return value;
				})
			| std::ranges::to<std::vector<unsigned int>>();
		

		triangles.push_back(Triangle(side_lengths[0], side_lengths[1], side_lengths[2]));
		
	}

	return triangles;

}



std::vector<Triangle> GetTrianglesFromFilePart2(std::string fileName)
{
	std::ifstream fstream(fileName);

	std::vector<Triangle> triangles;
	if (!fstream.is_open())
	{
		std::cerr << "Cannot open file" << std::endl;
	}

	std::string line;
	std::vector<std::vector<int>> sideLengths (1908,std::vector<int>(3,0)) ; 

	int i = 0;
	while (std::getline(fstream, line))
	{


		auto side_lengths = std::views::split(line, ' ')
			| std::views::filter([](auto&& r)
				{
					return !r.empty();
				})
			| std::views::transform([](auto&& r)
				{
					unsigned int value = 0;
					std::from_chars(r.data(), r.data() + r.size(), value);
					return value;
				})
			| std::ranges::to<std::vector<unsigned int>>();


		sideLengths[i][0] = side_lengths[0];
		sideLengths[i][1] = side_lengths[1];
		sideLengths[i][2] = side_lengths[2];
		
		i++;
		

	}
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < sideLengths.size(); i+=3)
		{
			triangles.push_back(Triangle(sideLengths[i][j], sideLengths[i + 1][j], sideLengths[i + 2][j]));
		}
	}

	return triangles;

}
