#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Day2.h"

void Day2PartTwo()
{
	std::ifstream inFile;
	inFile.open("Day2.txt");
	std::stringstream strStream;
	strStream << inFile.rdbuf();
	std::string line;
	int sum = 0; 
	while (std::getline(strStream, line))
	{
		std::vector<int> nums = splitStringIntoVectorOfints(line);
		std::sort(nums.begin(), nums.end());
		for(int i = nums.size() - 1; i >0 ;i--)
		{
			for(int j = i-1;j >= 0 ;j--)
			{
				if (nums[i] > nums[j] && nums[i] % nums[j] == 0)
				{
					sum += nums[i] / nums[j];
				}

			}
		}
	}
	std::cout << sum << std::endl;

}


std::vector<int> splitStringIntoVectorOfints(const std::string& str)
{
	std::vector<int> numbers; 

	std::stringstream ss(str);
	int number; 
	while (ss >> number)
	{
		numbers.push_back(number);
	}

	return numbers;
}
