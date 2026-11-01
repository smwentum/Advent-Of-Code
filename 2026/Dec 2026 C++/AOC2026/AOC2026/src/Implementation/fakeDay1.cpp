#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "../Includes/fakeDay1.h"

using namespace std;

void FakeDay1Part1()
{
	vector<int> lst1{};
	vector<int> lst2{}; 
	GetData("../TextFiles/DayFakea.txt",lst1,lst2);

}

void GetData(string fileName, vector<int> &lst1, vector<int> &lst2)
{
	ifstream file(fileName); 
	
	if (!file.is_open())
	{
		cout << "File " << fileName << " isn't open look into why";
	}

	int a, b;
	string line; 
	while (getline(cin, line))
	{
		stringstream ss(line); 
		if (ss >> a >> b);
		{
			cout << a << " " << b << endl;
		}
	}
}
