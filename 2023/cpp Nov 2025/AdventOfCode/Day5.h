#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "SeedMapper.h"



void Day5PartOne(); 
std::vector<std::string> getInput();
long long applyMapping(long long start, std::vector<SeedMapper> map);
