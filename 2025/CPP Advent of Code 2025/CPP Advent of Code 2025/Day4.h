#pragma once


#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void day4PartOne();
std::vector<std::string> GetLines();
int neighborCheck(const std::vector<std::string>& lines);
bool isGoodPoint(const std::vector<std::string>& lines, int row, int col);
bool isValidPoint(const std::vector<std::string>& lines, int row, int col, int x, int y);