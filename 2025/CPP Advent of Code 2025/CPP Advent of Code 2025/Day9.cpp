#include "Day9.h"

using namespace std;

void Day9PartOne()
{
	getPoints();
}

vector<tuple<int, int>> getPoints()
{
	vector<tuple<int, int>> points; 
	ifstream file("Day9a.txt");
	string line; 
	while (getline(file, line))
	{
		int a{ 0 };
		int b{0};
		stringstream ss(line);
		string line1; 
		if (getline(ss,line1,','))
		{
			a = stoi(line1);
	
		}
		if (getline(ss, line1, ','))
		{
			b = stoi(line1);

		}
		cout << a << endl;
		cout << b << endl;
	}
	return points; 
}