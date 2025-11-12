#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>



void Day6PartOne();
void Day6PartTwo();
std::vector<std::string> getThelines();
std::vector<int> getNumbersFromLinePt6(std::string line);
long long getNumbersFromLineDay6Part2(std::string line);
long long getNumberOfWaysToWin(long long time, long long distance);
long long getDay6Part1Answer(long long time, long long timeHeld);