#include "Day7.h"

using namespace std; 

map<tuple<int, int>, long long> maps;

void Day7PartOne()
{
	vector<string> lines;
	GetDay7PartOneInput(lines);
	for (auto line : lines)
	{
		//cout << line << endl ; 
	}
	queue<tuple<int,int>> points; 
	set<tuple<int, int>> set; 

	for (int i = 0; i < lines[0].length(); i++)
	{
		if (lines[0][i] == 'S')
		{
			points.push(tuple<int, int>(0, i));
			break; 
		}
	}
	int rows = lines.size(); 
	int cnt = 0;
	while (points.size() > 0)
	{
		tuple<int, int> curr = points.front();
		points.pop();
		int currRow = get<0>(curr);
		int currCol = get<1>(curr);
		if (set.contains(curr))
		{
			continue;
		}
		set.insert(curr); 
		if (currRow >= rows - 1 || currCol < 0 || currCol >= lines[0].size())
		{
			continue;
		}
		if (lines[currRow + 1][currCol] != '^')
		{
			lines[currRow + 1][currCol] = '|';
			if (!set.contains(tuple<int, int>(currRow + 1, currCol)))
			{
				points.push(tuple<int, int>(currRow + 1, currCol));
				//cnt++;
			}
		}
		else
		{
			if (currCol > 0)
			{
			
				
				lines[currRow + 1][currCol - 1] = '|';
				if (!set.contains(tuple<int, int>(currRow + 1, currCol - 1)))
				{
					points.push(tuple<int, int>(currRow + 1, currCol - 1));
				}
			}
			if (currCol < lines[0].size() - 1)
			{
				
				lines[currRow + 1][currCol + 1] = '|';
				if (!set.contains(tuple<int, int>(currRow + 1, currCol+1)))
				{
					points.push(tuple<int, int>(currRow + 1, currCol + 1));
				}
				//cnt++;
			}
		}

	}
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines[0].size(); j++)
		{
			if (lines[i][j] == '^' && lines[i - 1][j] == '|')
			{
				cnt++; 
			}
		}
	}



	//printGrid(lines);
	cout << "Day 7 part One: " << cnt << endl; 
	

}



void Day7PartTwo() 
{
	vector<string> lines;
	GetDay7PartOneInput(lines);
	for (auto line : lines)
	{
		//cout << line << endl ; 
	}
	queue<tuple<int, int>> points;
	set<tuple<int, int>> set;
	tuple<int, int> curr; 
	long long cnt{0};
	for (int i = 0; i < lines[0].length(); i++)
	{
		if (lines[0][i] == 'S')
		{
			curr  =  tuple<int, int>(0, i);
			break;
		}
	}

	
	


	//printGrid(lines);
	cout << "Day 7 part two: " << getAnswer(curr,lines) << endl;
}

long long getAnswer(tuple<int, int> t, vector<string>& lines)
{

	if (maps.contains(t))
	{
		return maps[t]; 
	}
	int currRow = get<0>(t);
	int currCol = get<1>(t);
	if (currCol < 0|| currCol >= lines[0].size())
	{
		return 0; 
	}
	
	if (currRow >= lines.size() - 2)
	{
		maps[t] =  1;
	}
	else if (lines[currRow + 1][currCol] == '.')
	{
		maps[t] = getAnswer(tuple<int, int>(currRow + 1, currCol),lines);
	}
	else if (lines[currRow + 1][currCol] == '^')
	{
		maps[t] = getAnswer(tuple<int, int>(currRow + 1, currCol-1), lines) + 
			getAnswer(tuple<int, int>(currRow + 1, currCol  +1), lines);
	}
	return maps[t]; 
}



void printGrid(const vector<string>& lines) 
{
	cout << endl; 
	for (auto line : lines)
	{
		cout << line << endl ; 
	}
	cout << endl; 
}

void GetDay7PartOneInput(vector<string>& lines)
{
	ifstream file("Day7.txt");
	string line; 
	while (getline(file, line))
	{
		lines.push_back(line);
	}
}