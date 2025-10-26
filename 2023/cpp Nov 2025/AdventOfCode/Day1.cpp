#include "Day1.h"


using namespace std;
//std::vector<std::string> GetFileLines(); 

void DayOnePartOne()
{
	// Implementation for Day 1 Part One	


	//read the input file

	std::vector<std::string> lines = GetFileLines();

	int sum {0};
	for (string line : lines)
	{
		//pull out the first and last digit
		int first = GetFirstDigit(line);
		int last = GetLastDigit(line);
		int num = first * 10 + last;
		sum += num;
	}
	cout << "Day one Part 1: " << sum << endl;
		

	//get the sum of the digits that match

}

int GetFirstDigit(string s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			return (int)(s[i] - '0');
		}
	}
}

int GetLastDigit(string s)
{
	for (int i = s.length()-1; i >= 0; --i)
	{
		if (std::isdigit(s[i]))
		{
			return (int)(s[i] - '0');
		}
	}

}

std::vector<std::string> GetFileLines()
{
	std::ifstream file("day1.txt");
	std::string str;
	std::vector<std::string> lst{};
	while (std::getline(file, str))
	{
		//std::cout << str << std::endl;
		lst.push_back(str);
	}
 
	return lst;
}


