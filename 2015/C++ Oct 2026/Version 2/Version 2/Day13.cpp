#include "Day13.h"

#include<bit>
#include<fstream>
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
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

	//now that the map is created get 

	long long answer{ 0 };

	cout << "Day 13 part 1" << answer  << endl; 

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
	
}

void printMaze(const vector<string>& maze)
{
	for (auto m : maze)
	{
		cout << m << endl;
	}
}

long long BFS(const vector<string>& maze)
{
	std::unordered_map<std::tuple<int, int>, int> vistedPoints{};

	std::tuple<int, int> startPoint(1, 1);
	std::tuple<int, int> sentinle(-1, -1); 
	std::tuple<int, int> endPoint(31, 39);

	std::queue<std::tuple<int,int>> queue{}; 

	queue.push(startPoint);
	queue.push(sentinle);
	long long distance{0};

	while (queue.size() > 0)
	{
		std::tuple<int, int> currentPoint = queue.front();
		queue.pop();

		if (!vistedPoints.contains(currentPoint))
		{
			if (currentPoint == sentinle)
			{
				if (queue.size() == 0)
				{
					break;
				}
				else
				{
					distance++;
					queue.push(sentinle); 
				}
			}
			else
			{
				vistedPoints[currentPoint] = distance;

				if (currentPoint == endPoint)
				{
					return distance;
				}

				int row{ std::get<0>(currentPoint) };
				int col{ std::get<1>(currentPoint) };

				//add the neighbors
				if (row > 0 && maze[row-1][col] == '.')
				{
					queue.push(std::tuple<int, int>(std::get<0>(currentPoint) -1, std::get<1>(currentPoint)));
				}

				if (col > 0 && maze[row][col-1] == '.')
				{
					queue.push(std::tuple<int, int>(std::get<0>(currentPoint), std::get<1>(currentPoint)-1 ));
				}
				if (maze[row + 1][col] == '.')
				{
					queue.push(std::tuple<int, int>(row + 1, col));
				}
				if (maze[row][col + 1] == '.')
				{
					queue.push(std::tuple<int, int>(row, col + 1));
				}
				

			}
		}
	}

	return distance; 


}
