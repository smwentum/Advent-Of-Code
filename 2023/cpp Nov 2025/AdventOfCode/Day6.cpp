#include "Day6.h"

using namespace std;

void DaySixPartOne()
{
	//read in the input
	vector<string> lines = GetInput(); 

	for (auto line : lines)
	{
		//cout << line << endl;
		int indexof = line.find_first_of(' ');
		string hand = line.substr(0, indexof - 1); 
		long long score = stoll(line.substr(indexof + 1));
		cout << "hand: " << hand << " score: " << score << endl;

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