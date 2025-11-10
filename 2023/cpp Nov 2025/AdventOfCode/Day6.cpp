#include "Day6.h"

using namespace std; 

void Day6PartOne()
{
	//get the data 
	vector<string> lines = getThelines(); 

}


vector<string> getThelines()
{
	vector<string> lines{};

	//get lines 
	ifstream file("Day6a.txt");
	string line{};
	while (getline(file, line))
	{
		cout << line << endl;
	}


	return lines;
}