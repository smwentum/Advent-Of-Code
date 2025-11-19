#include "Day9.h"


using namespace std;

void Day9PartOne()
{
	vector<string> lines = getDay9Input(); 
	long long answer{ 0 }; 
	for (auto line : lines)
	{
		cout << line << endl; 
		answer += getDay9PartOneVal(line); 
	}

	cout << "Day 9 part 1 answer: " << answer << endl; 
}

long long getDay9PartOneVal(string line)
{
	vector<vector<long long>> rows;
	
}
vector<long long> convertLineToVector(string line) {}

vector<string> getDay9Input()
{

	vector<string> lines{};
	ifstream file("Day9a.txt"); 
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}