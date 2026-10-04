

#include "IPAddress.h"

#include<algorithm>
#include<fstream>
#include<iostream>
#include<string>
#include<string_view>
#include<ranges>
#include<vector>


using std::vector;
using std::cout;
using std::endl;
using std::string;

IPAddress::IPAddress(string line)
{
	this->line = line;
	//first thing i am going to do is remove the brackets and see if i can get this to work 
	std::ranges::replace(line, '[', ' ');
	std::ranges::replace(line, ']', ' ');
	auto parts = std::views::split(line,' ') | std::ranges::to<vector<string>>();

	for (int i = 0; i < parts.size(); i++)
	{
		if (i % 2 == 0)
		{
			this->SupernetSequences.push_back(parts[i]);
		}
		else
		{
			this->HyperTextSequences.push_back(parts[i]);
		}
	}
		
}

auto IsABBA = [](string s)
	{
		for (int i = 0; i < s.length() - 3; i++)
		{
			if (s[i] == s[i + 3]
				&& s[i + 1] == s[i + 2]
				&& s[i] != s[i + 2]
				)
			{
				return true;
			}
		}
		return false;
	};

bool IPAddress::IsTLS()
{
	return std::ranges::any_of(this->SupernetSequences, IsABBA)
		&& !std::ranges::any_of(this->HyperTextSequences, IsABBA);
}