#include "Day4.h"

using namespace std;

void day4PartOne()
{
	vector<string> lines = GetLines(); 
	cout << "Day Four Part One: " << neighborCheck(lines) << endl; 
		

}

int neighborCheck(const vector<string>& lines)
{
	int cnt = 0;
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 0; j < lines[i].size(); j++)
		{
			if (lines[i][j] == '@' && !isGoodPoint(lines,i,j))
			{
				cnt++; 
			}
		}
	}
	return cnt;
}


bool isGoodPoint(const vector<string>& lines,int row, int col)
{
	int cnt = 0;
	vector<int> xOffset{ -1,0,1 }; 
	vector<int> yOffset{ -1,0,1 };

	for (int i = 0; i < xOffset.size(); i++)
	{
		for (int j = 0; j < yOffset.size(); j++)
		{
			if (xOffset[i] == 0 && yOffset[j] == 0)
			{
				continue;
			}

			if (isValidPoint(lines, row, col, xOffset[i], yOffset[j]) && lines[row+xOffset[i]][col+yOffset[j]] == '@')
			{
				cnt++; 
			}
		}
	}
	
	
	return cnt  > 3 ;
}
bool isValidPoint(const vector<string>& lines, int row, int col, int x, int y)
{
	return row + x >= 0 && col + y >= 0 && row + x < lines.size() && col + y < lines[row].size(); 
}








vector<string> GetLines()
{
	vector<string> lines; 

	ifstream file("Day4.txt");
	string line; 

	while (getline(file, line))
	{
		lines.push_back(line);
	}


	return lines; 
} 


