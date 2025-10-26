#pragma once

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include<string>
#include<vector>



std::vector<std::string> GetFileLines();
void DayOnePartOne();
void DayOnePartTwo();
std::vector<std::string> getAllPossibleNumbers();
int GetFirstDigit(std::string s);
int GetLastDigit(std::string s);
int GetLastDigitPart2(std::string s);
int GetFirstDigitPart2(std::string s);
int getValueFromWordString(std::string s);