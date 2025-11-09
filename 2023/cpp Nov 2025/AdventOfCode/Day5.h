#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "SeedMapper.h"




void Day5PartOne(); 
void Day5PartTwo();
std::vector<std::string> getInput();
long long applyMapping(long long start, std::vector<SeedMapper> map);
