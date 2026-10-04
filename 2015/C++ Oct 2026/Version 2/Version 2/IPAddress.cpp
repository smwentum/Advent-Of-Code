

#include "IPAddress.h"

#include<algorithm>
#include<fstream>
#include<iostream>
#include<string>
#include<string_view>
#include<ranges>
#include<set>
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

bool IPAddress::IsSSL()
{
	//get list of abas from supertext
	std::set<string> aba{};
	
	for (int j = 0; j < SupernetSequences.size(); j++)
	{
		line = SupernetSequences[j];

		for (int i = 0; i < line.length() - 2; i++)
		{
			if (line[i] == line[i + 2] && line[i] != line[i + 1])
			{
				aba.insert(line.substr(i, 3));
			}
		}
	}

	for (int j = 0; j < HyperTextSequences.size(); j++)
	{
		line = HyperTextSequences[j];

		for (int i = 0; i < line.length() - 2; i++)
		{
			if (line[i] == line[i + 2] && line[i] != line[i + 1])
			{
				string s1{};
				s1 += line[i + 1];
				s1 += line[i];
				s1 += line[i + 1];
				if (aba.contains(s1))
				{
					return true;
				}
			}
		}
	}

	return false; 

}