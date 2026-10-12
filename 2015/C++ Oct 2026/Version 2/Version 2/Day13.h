#pragma once

#include<string>
#include<vector>

void Day13Part1();
void Day13Part2(); 
void createMaze(std::vector<std::string>& maze);
void printMaze(const std::vector<std::string>& maze);
long long BFS();
bool isOpen(unsigned int x, unsigned int y);