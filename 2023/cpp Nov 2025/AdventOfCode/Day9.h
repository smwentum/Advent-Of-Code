#pragma once

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>


void Day9PartOne();
void Day9PartTwo();
std::vector<std::string> getDay9Input(); 
long long getDay9PartOneVal(std::string line);
long long getDay9PartTwoVal(std::string line);
std::vector<long long> convertLineToVector(std::string line);