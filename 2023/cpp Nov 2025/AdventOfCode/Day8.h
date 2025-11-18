#pragma once



#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <numeric>
#include <vector>
#include <map>

#include "Day8Node.h"

void Day8PartOne();
void Day8PartTwo();
long long Day8PartTwoHelper(std::string current,
						const std::string directions,
						std::map<std::string, Day8Node> graph);
std::vector<std::string> GetDay8Input();

