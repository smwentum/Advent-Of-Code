#pragma once
#include<vector>
#include<string>
#include <string_view>

void Day1Part1();
void Day1Part2();
std::vector<std::string> GetFile(std::string fileName);

inline auto trimAndConvert(auto&& subrange)
{

	std::string_view sv(subrange.begin(), subrange.end());
	const auto start = sv.find_first_not_of(" \t\n\r");

	if (start == std::string_view::npos)
	{
		return std::string_view();
	}

	const auto end = sv.find_last_not_of(" \t\n\r");

	return sv.substr(start, end - start + 1);


}

