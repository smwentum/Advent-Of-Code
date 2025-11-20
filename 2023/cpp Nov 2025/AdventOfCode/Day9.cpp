#include "Day9.h"


using namespace std;

void Day9PartOne()
{
	vector<string> lines = getDay9Input(); 
	long long answer{ 0 }; 
	for (auto line : lines)
	{
		//cout << line << endl; 
		answer += getDay9PartOneVal(line); 
	}

	cout << "Day 9 part 1 answer: " << answer << endl; 
}

long long getDay9PartOneVal(string line)
{
	vector<vector<long long>> rows;
	vector<long long> curr = convertLineToVector(line); 
	while (!all_of(curr.begin(), curr.end(),
		[](long long i) {return i == 0; }))
	{
		rows.push_back(curr);
		vector<long long> curr1{};
		for (int i = 0; i < curr.size() - 1; i++)
		{
			curr1.push_back(curr[i + 1] - curr[i ]);
		}
		curr = curr1; 
	}
	rows.push_back(curr);
	long long sum{ 0 };
	for (auto row : rows)
	{
		sum += row[row.size() - 1];
	}
	return sum;
	
}
vector<long long> convertLineToVector(string line) 
{
	vector<long long> ans{}; 

	stringstream ss(line);
	string s1;
	long long a;
	while(ss >> a)
	{
		ans.push_back(a);
	}

	return ans; 
}

vector<string> getDay9Input()
{

	vector<string> lines{};
	ifstream file("Day9.txt"); 
	string line;
	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}