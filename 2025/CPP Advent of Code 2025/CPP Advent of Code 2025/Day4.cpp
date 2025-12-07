#include "Day4.h"

using namespace std;

void day4PartOne()
{

	vector<string> lines = GetLines(); 
	
	using(auto line: lines)
	{
		cout << line << endl; 
	}

}


vector<string> GetLines()
{
	vector<string> lines; 

	ifstream file("Day4a.txt");
	string line; 

	while (getline(file, line))
	{
		lines.push_back(line);
	}


	return lines; 
} 


