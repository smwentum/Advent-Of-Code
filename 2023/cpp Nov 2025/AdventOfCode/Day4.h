#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <set>
#include <ranges>
#include <vector>

void Day4PartOne();
std::vector<std::string> dayFourGetLinesFromFile();
long long getCountOfWinningNumbers(std::string line);
std::string removeFirstPart(std::string line);
long long getDay4PartOneAnswerFromLine(std::string secondPart);