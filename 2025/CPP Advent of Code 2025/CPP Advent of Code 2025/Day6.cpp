#include "Day6.h"

using namespace std; 

void Day6PartOne()
{
	vector<vector<long long>> nums; 
	vector<string> ops;
	getInput(nums,ops);
	long long total{0};
	long long valOfLine;
	bool justAdd;
	for (int i = 0; i < ops.size(); i++)
	{
		valOfLine = 0;
		justAdd = ops[i] != "*";
		vector<long long> l;
		for (int j = 0; j < nums.size(); j++)
		{
			l.push_back(nums[j][i]);
		}
		if (justAdd)
		{
			valOfLine = accumulate(l.begin(), l.end(), 0ll, [](long long val, const long long curr)
				{
					return val + curr;
				});
		}
		else
		{
			valOfLine = accumulate(l.begin(), l.end(), 1ll, [](long long val, const long long curr)
				{
					return val * curr;
				});
		}
		total += valOfLine; 
		
	}
	cout << "Day 6 part one" << total << endl; 
}

void getInput(vector<vector<long long>>& nums, vector<string>& ops)
{
	ifstream file("Day6a.txt"); 

	string line; 

	while (getline(file, line))
	{
		line.erase(line.begin(), std::find_if(line.begin(), line.end(), 
			[](unsigned char ch) { 
				return !isspace(ch); 
			}));
		if (isdigit(line[0]))
		{
			stringstream ss(line);
			nums.push_back(vector<long long>());
			long long num;
			while (ss >> num)
			{
				nums[nums.size() - 1].push_back(num);
			}
		}
		else
		{
			stringstream ss(line);
			string op;
			while (ss >> op)
			{
				ops.push_back(op); 
			}
		}
	}
}
