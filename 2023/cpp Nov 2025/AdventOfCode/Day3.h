#pragma once

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>


void Day3PartOne();
std::vector<std::string> getLinesFromFile();
int PartOneReturnNumberIfValid(const std::vector<std::string>&lines, int row, int start, int stop);
bool nextToSymbol(const std::vector<std::string>& lines, int row, int col);
void Day3PartTwo();
int returnProductIfAroundStar(std::vector<std::string>& lines, int row, int col);
bool isValidPoint(int row, int col, int  maxRows, int  maxCols);