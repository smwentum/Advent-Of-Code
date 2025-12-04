#pragma once

#include<algorithm>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#include<set>
#include<vector>
#include<numeric>

#include "ProductId.h"

void DayTwoPartOne();
std::vector<ProductId> GetDayTwoInput();
bool isFakeNumber(long long start);
void DayTwoPartTwo();
bool isFakeNumberPart2helper(std::string s, int length);
bool isFakeNumberPart2(long long start);