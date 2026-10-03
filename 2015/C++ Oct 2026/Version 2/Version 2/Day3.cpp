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
		std::cout << side_lengths[0] << " " << side_lengths[1] << " " << side_lengths[2] << std::endl;
		triangles.push_back(Triangle(side_lengths[0], side_lengths[1], side_lengths[2]));
		
	}

	return triangles;

}


