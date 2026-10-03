#include "RoomName.h"


#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>


RoomName::RoomName(std::string roomName)
{
	this->roomName = roomName;
	//i would need the string
	this->setValues();
}

void RoomName::setValues()
{
	for (int i = 0; i < 26; i++)
	{
		charMap[(char)('a' + i)] = 0;
	}

	auto parts = std::views::split(this->roomName, '-')
		| std::ranges::to<std::vector<std::string>>();
	

	for (auto part : parts| std::views::take(parts.size()-1))
	{
		for (auto c : part)
		{
			if (std::isalpha(c))
			{
				charMap[c]++;
			}
		}
		
	}

	//convert to a vector 

	auto pairs = charMap | std::ranges::to<std::vector>();
	int n = 5;
	std::vector<std::pair<char, int>> top_n(n);

	//this would get the top n
	std::ranges::partial_sort_copy(charMap, top_n,
		[](const auto& a,
			const auto& b) {
				return a.second > b.second; 
		});

	//this will set ties
	std::ranges::sort(top_n, [](const auto& a, const auto& b)
		{
			return std::tie(a.second, b.first) > std::tie(b.second, a.first);
		});

	auto topKeys = top_n | std::views::keys;

	this->stringCheckSum = std::string(topKeys.begin(), topKeys.end());

	std::cout << parts[parts.size() - 1] << std::endl; 

	size_t index = parts[parts.size() - 1].find("[");
	if (index != std::string::npos)
	{
		std::string sectoridString = parts[parts.size() - 1].substr(0, index );
		this->sectorId = std::stoi(sectoridString);
		this->checksum = parts[parts.size() - 1].substr(index + 1, 5);
	}



}

bool RoomName::DoesMatch() const
{
	return stringCheckSum == checksum;
}