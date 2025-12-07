#pragma once

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<tuple>



void Day3PartOne(); 
void Day3PartTwo();
std::vector<std::string> getDay3PartOneInput();
int getBestTwoBatteriesFromBank(std::string bb);
std::string myMax(std::string s1, std::string s2);
std::string getBestNBattriesFromBank(std::string bank, int num);
long long getBestTwelveBatteriesFromBank(std::string bb);