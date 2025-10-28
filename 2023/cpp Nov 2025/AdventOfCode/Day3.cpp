
#include "Day3.h"

using namespace std;

void Day3PartOne()
{
	//get the input
	vector<string> lines = getLinesFromFile();
	for (string line : lines)
	{
		cout << line << endl;
	}
	//get the numbers
	//figure out which ones count
	//return answer

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