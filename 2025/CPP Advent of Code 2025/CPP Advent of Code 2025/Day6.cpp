#include "Day6.h"

using namespace std; 

void Day6PartOne()
{
	vector<vector<long long>> nums; 
	vector<string> ops;
	getDay6Part1Input(nums,ops);
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
	cout << "Day 6 part one: " << total << endl; 
}

void Day6Part2()
{
	vector<vector<long long>> nums;
	vector<string> ops;
	getDay6Part2Input(nums, ops);
	long long total{ 0 };
	long long valOfLine;
	bool justAdd;
	for (int i = 0; i < ops.size(); i++)
	{
		valOfLine = 0;
		justAdd = ops[i] != "*";
		vector<long long> l = nums[i];
		
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
	cout << "Day 6 part two: " << total << endl;

}

void getDay6Part1Input(vector<vector<long long>>& nums, vector<string>& ops)
{
	ifstream file("Day6.txt"); 

	string line; 
	string line1; 
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



void getDay6Part2Input(vector<vector<long long>>& nums, vector<string>& ops)
{
	ifstream file("Day6.txt");

	string line;
	string line1;
	vector<string> lines; 
	while (getline(file, line))
	{
		line1 = line; 
		line.erase(line.begin(), std::find_if(line.begin(), line.end(),
			[](unsigned char ch) {
				return !isspace(ch);
			}));
		if (isdigit(line[0]))
		{
			/*stringstream ss(line);
			nums.push_back(vector<long long>());
			long long num;
			while (ss >> num)
			{
				nums[nums.size() - 1].push_back(num);
			}*/
			lines.push_back(line1);
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
	//for (auto l : lines)
	//{
	//	cout << l << endl;
	//}
	nums.push_back(vector<long long>());
	for (int i = 0; i < lines[0].length(); i++)
	{
		string n1 = "";
		for (int j = 0; j < lines.size(); j++)
		{
			if (!isspace(lines[j][i]))
			{
				n1 += lines[j][i];
			}


		}
		//cout << n1 << endl; 
		if (n1.length() > 0)
		{
			nums[nums.size() - 1].push_back(stoll(n1));
		}
		else
		{
			nums.push_back(vector<long long>());
		}
	}
}