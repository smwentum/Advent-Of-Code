#include "Day1.h"

using namespace std; 


void  Day1PartOne()
{
	vector<string> lines = Day1ReadFile();
	long long start = 50;
	int count = 0; 
	for (auto line : lines)
	{
		long long num = stoll(line.substr(1));
		if (line[0] == 'L')
		{
			start = (start - num) ;
		}
		else if (line[0] == 'R')
		{
			start = (start + num);
		}
		while (start < 0)
		{
			start += 100;
		}
		if (start % 100 == 0)
		{
			count++; 
		}
		

		start %= 100;
		
	}
	cout << "Day 1 part 1: " << count << endl;
}


void  Day1PartTwo()
{
	vector<string> lines = Day1ReadFile();
	long long start = 50;
	int count = 0;
	for (auto line : lines)
	{
		long long num = stoll(line.substr(1));
		if (line[0] == 'L')
		{
			start = (start - num);
		}
		else if (line[0] == 'R')
		{
			start = (start + num);
		}
		
		if (start <=0  || start >= 100)
		{
			count++;
		}
		while (start < 0)
		{
			start += 100;
		}

		start %= 100;

	}
	cout << "Day 1 part 1: " << count << endl;
}



vector<string> Day1ReadFile()
{
	vector<string> lst{}; 

	ifstream file("day1.txt");
	string line; 
	while (std::getline(file, line))
	{
		lst.push_back(line);
	}

	return lst;
}