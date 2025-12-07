#pragma once

#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<iostream>
#include<numeric>


#include "Range.h"

void day5PartOne(); 
void day5PartTwo();
void GetInputPartOne(std::vector<Range>& ranges, std::vector<long long>& ingrediennts);
void GetInputPartTwo(std::vector<Range>& ranges);
bool findTwoRangesToCombine(std::vector<Range>& ranges);