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
	//string startString{ "10000" };
	//int length{ 20 };

	string startString{ "00111101111101000" };
	int length{ 272 };

	while (startString.size() < length)
	{
		startString +="0"+ GetTail(startString);

	}
	//cout << startString << endl;

	startString = startString.substr(0, length);

	//cout << startString << endl;


	while (startString.length() > 0 && startString.length() % 2 == 0)
	{
		startString = createCheckSum(startString);
		//cout << startString << endl;
	}
	cout << "Day 16 part 1: " << startString << endl; 
}
void Day16Part2()
{
	
}


std::string createCheckSum(const std::string& s)
{
	string ans{ "" }; 

	for (int i = 0; i < s.length() - 1; i += 2)
	{
		if (s[i] == s[i + 1])
		{
			ans += "1";
		}
		else
		{
			ans += "0";
		}
	}

	return ans; 
}

std::string GetTail(const std::string &s)
{
	string s1{ s };


	string ans{ "" };
	std::reverse(s1.begin(), s1.end()); 
	
	

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