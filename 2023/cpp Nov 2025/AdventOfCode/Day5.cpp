#include "Day5.h"

using namespace std;

void Day5PartOne()
{
	vector<string> lines = getInput(); 
	for (auto line : lines)
	{
		cout << line << endl;
	}

}


vector<string> getInput()
{
	ifstream file("Day5a.txt");
	string line; 
	vector<string> lines{};

	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}
