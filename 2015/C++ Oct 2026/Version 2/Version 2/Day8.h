#pragma once

#include <vector>
#include <string>

void Day8Part1();
void Day8Part2();
void printScreen(const std::vector<std::vector<char>>& littleScreen);
void getLinesFromFile(std::string fileName, std::vector<std::string>* lines);
void rect(int rows, int cols, std::vector<std::vector<char>>* screen);