#ifndef day3_h
#define day3_h

#include <iostream>
#include <string>

void partOne(std::string fileName);
std::vector<std::vector<std::string>> getDirections(std::string fileName);

std::set<std::tuple<int, int>> getAllPoints(std::vector<std::string> directions);

#endif