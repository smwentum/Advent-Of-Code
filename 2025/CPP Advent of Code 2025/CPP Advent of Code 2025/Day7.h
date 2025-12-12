#pragma once

#include<string>
#include<vector>
#include<algorithm>
#include <fstream>
#include<iostream>
#include<queue>
#include<tuple>
#include<set>
#include<map>

void Day7PartOne();
void Day7PartTwo();
void GetDay7PartOneInput(std::vector<std::string>& lines);
void printGrid(const std::vector<std::string>& lines);
long long getAnswer(std::tuple<int, int> t, std::vector<std::string>& lines);