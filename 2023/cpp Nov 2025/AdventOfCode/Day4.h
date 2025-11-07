#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <sstream>
#include <set>
#include <ranges>
#include <vector>

void Day4PartOne();
void Day4PartTwo();
std::vector<std::string> dayFourGetLinesFromFile();
long long getCountOfWinningNumbers(std::string line);
std::string removeFirstPart(std::string line);
long long getDay4PartOneAnswerFromLine(std::string secondPart);
void getCountOfWinningNumbersPart2(std::string line, std::vector<long long>& cardCounts);
long long getDay4PartTwoAnswerFromLine(std::string secondPart);
int getCardId(const std::string line);