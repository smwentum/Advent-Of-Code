#include "Day8.h"

using namespace std; 

void Day8PartOne()
{
	long long answer{ 0 };
	vector<string> lines = GetDay8Input();

	for (auto line : lines)
	{
		cout << line << endl; 
	}

	cout << "Day 8 part one: " << answer << endl; 

}


vector<string> GetDay8Input()
{
	vector<string> lines{};

	ifstream file("Day8a.txt");
	string line; 

	while (getline(file, line))
	{
		if (line.size() > 0 && isalpha(line[0]))
		{
			lines.push_back(line);
		}
	}


	return lines;
}