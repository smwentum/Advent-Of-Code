
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
				//cout << currentVal << endl;
				sum += currentVal;
				col += start;
			}

		}
	}

	cout << "Day 3 Part 1 answer: " << sum <<endl; 
	//figure out which ones count
	//return answer

}


int PartOneReturnNumberIfValid(const vector<string>& lines, int row, int start, int stop)
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



void Day3PartTwo()
{
	//get the input
	vector<string> lines = getLinesFromFile();
	//get the numbers
	long long sum = 0;
	//for part two i am going to do the reverse and find the stars a find two different numbers around it
	for (size_t row = 0; row < lines.size(); row++)
	{
		for (size_t col = 0; col < lines[0].length(); col++)
		{
			//lines = getLinesFromFile();
			if (lines[row][col] =='*')
			{
			
				long long currentVal{ returnProductIfAroundStar(lines, row,col)};
				//cout << currentVal << endl;
				sum += currentVal;
				
			}

		}
	}

	cout << "Day 3 Part 2 answer: " << sum << endl;
	//figure out which ones count
	//return answer

}

long long returnProductIfAroundStar(vector<string>& lines,  int row, int col)
{
	vector<int> dx{ -1,-1,-1,0,0,1,1,1 };
	vector<int> dy{ -1,0,1,-1,1,-1,0,1 };

	long long a{ 0 };
	long long b{ 0 };
	vector<long long> nums; 
	for (int i = 0; i < dx.size(); i++)
	{
		
		if (isValidPoint(row + dx[i], col + dy[i], lines.size(), lines[0].size()))
		{
			if (isdigit(lines[row + dx[i]][col + dy[i]]))
			{
				//keep going left until you stop having digits
				int left = col + dy[i];

				while (isValidPoint(row + dx[i] ,left, lines.size(), lines[0].size())
					&& isdigit(lines[row + dx[i]][left] ) )
				{
					left--; 
				}
				//if (left > 0)
				//{
					left++;
				//}

				//keep going right until you stop having digits
				int right = 0;
				while (isValidPoint(row + dx[i] ,left + right, lines.size(), lines[0].size())
					&& isdigit(lines[row + dx[i]][left +right] ))
				{
					right++;
				}
				//right--;
				/*if (right > 1)
				{
					right--;
				}*/
				//get full digit string from[left,right]
				
				//cout << "start: " << col + dy[i] - left << endl;
				//cout << "length: " << abs(right - left )+1 << endl;
				//cout << "val: " << lines[row + dx[i]].substr(col + dy[i] - left, abs(right - left )+1) << endl;
				
				//right = min(1, right);
				
				if (right > 0)
				{
					nums.push_back(stoll(lines[row + dx[i]].substr(left, right)));
				}

				/*if (a == 0)
				{
					a = stoll(lines[row + dx[i]].substr(col + dy[i] - left, abs(right - left )+1));
				}
				else
				{
					b = stoll(lines[row + dx[i]].substr(col + dy[i] - left, abs(right - left )+1));
					
				}*/

				for (int j = 0; j < right; j++)
				{
					lines[row + dx[i]][left + j] = '.';

				}
				//mark [left, right] as all stars
			}

		}
	}
	if (nums.size() == 2)
	{
		return nums[0] * nums[1];
	}
	return 0;
}




#pragma region generic stuff

bool isValidPoint(int row, int col, int  maxRows, int  maxCols)
{
	return !(row < 0 || row >= maxRows || col < 0 || col >= maxCols);
}


bool nextToSymbol(const vector<string>& lines, int row, int col)
{
	vector<int> dx{ -1,-1,-1,0,0,1,1,1 };
	vector<int> dy{ -1,0,1,-1,1,-1,0,1 };

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
	ifstream file("Day3.txt");
	string str;
	while (std::getline(file, str))
	{
		lines.push_back(str);
	}

	return lines;
}
#pragma endregion
