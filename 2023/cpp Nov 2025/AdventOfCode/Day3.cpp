
#include "Day3.h"

using namespace std;

void Day3PartOne()
{
	//get the input
	vector<string> lines = getLinesFromFile();
	//get the numbers
	long long sum = 0; 
	for (size_t row = 0; row < lines.size(); row++)
	{
		for (size_t col = 0; col < lines[0].length(); col++)
		{
			if (isdigit(lines[row][col]))
			{
				int start = 0;
				while (col + start < lines[0].length() && isdigit(lines[row][col+start]))
				{
					++start; 
				}
				
				int currentVal{ PartOneReturnNumberIfValid(lines, row, col, start) };
				cout << currentVal << endl;
				sum += currentVal;
				col += start;
			}

		}
	}

	cout << "Day 3 Part 1 answer: " << sum <<endl; 
	//figure out which ones count
	//return answer

}

int PartOneReturnNumberIfValid(const vector<string>& lines,int row, int start, int stop)
{
	//part one get the number
	int num = stoi(lines[row].substr(start, stop));
	for (int i = 0; i < stop; i++)
	{
		if (nextToSymbol(lines, row, start + i))
		{
			return num;
		}
	}
	return 0;
}

bool nextToSymbol(const vector<string>& lines, int row, int col)
{
	vector<int> dx{-1,-1,-1,0,0,1,1,1};
	vector<int> dy{ -1,0,1,-1,1,-1,0,1};

	for (int i = 0; i < dx.size(); i++)
	{
		if (row + dx[i] >= 0 && row + dx[i] < lines.size() &&
			col + dy[i] >= 0 && col + dy[i] < lines[0].size()
			)
		{
			char c = lines[row + dx[i]][col + dy[i]];
			if (c != '.' && !isalnum(c) && c != '\n')
			{
				return true; 
			}
		}
	}
	return false;
}


vector<string> getLinesFromFile()
{
	vector<string> lines{};
	ifstream file("Day3a.txt");
	string str; 
	while (std::getline(file, str))
	{
		lines.push_back(str);
	}

	return lines;
}