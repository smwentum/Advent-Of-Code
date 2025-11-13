#include "Day6.h"

using namespace std;

void DaySixPartOne()
{
	//read in the input
	vector<string> lines = GetInput(); 

	for (auto line : lines)
	{
		cout << line << endl;
	}

}

vector<string> GetInput()
{
	vector<string> lines{};
	ifstream file("day7a.txt");
	string line;

	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}