#include "Day16.h"

#include<algorithm>
#include<iostream>

#include<string>


using std::string;
using std::cin; 
using std::cout; 
using std::endl;

void Day16Part1()
{
	//test case 
	string startString{ "10000" };
	int length{ 20 };

	while (startString.size() < length)
	{
		startString += GetTail(startString);
		
	}
	cout << startString;

	
}
void Day16Part2()
{
	
}


std::string GetTail(const std::string &s)
{
	string s1{ s };


	std::reverse(s1.begin(), s1.end()); 
	
	string ans{""};

	for (char c1 : s1)
	{
		if (c1 == '0')
		{
			ans += '1';
		}
		else
		{
			ans += '0';
		}
	}

	return ans; 
}