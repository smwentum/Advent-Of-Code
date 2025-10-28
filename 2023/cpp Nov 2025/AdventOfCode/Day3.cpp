
#include "Day3.h"

using namespace std;

void Day3PartOne()
{
	//get the input
	vector<string> lines = getLinesFromFile();
	//get the numbers
	for (string line : lines)
	{
		stringstream ss1(line);
		string parsedInput;
		while (getline(ss1, parsedInput, '.'))
		{
			if (all_of(parsedInput.begin(), parsedInput.end(), 
						[](unsigned char c) {
					return isdigit(c);
				}) && parsedInput.size() > 0)
			{
				cout << parsedInput << endl;
			}
		}
	}
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