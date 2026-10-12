#include "Day13.h"

#include<bit>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using std::string; 
using std::vector; 
using std::cin;
using std::cout;
using std::endl;

const int MazeX{ 40 };
const int MazeY{ 40 };

void Day13Part1()
{
	vector<string> maze{}; 

	createMaze(maze);
}


void Day13Part2()
{

}

void createMaze(vector<string> &maze)
{
	for (unsigned int i = 0; i< MazeX; i++)
	{
		maze.push_back("");
		for (unsigned int j = 0; j < MazeY; j++)
		{
			unsigned int val { i * i + 3 * i + 2 * i * j + j + j * j +1352};

			if (std::popcount(val) % 2 == 0)
			{
				maze[i] += ".";
			}
			else
			{
				maze[i] += "#";
			}

		}
	}
	for (auto m : maze)
	{
		cout << m << endl; 
	}
}

