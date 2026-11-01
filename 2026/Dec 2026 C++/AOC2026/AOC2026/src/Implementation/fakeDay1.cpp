#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <sstream>
#include <vector>



#include "../Includes/fakeDay1.h"

using namespace std;

void FakeDay1Part1()
{
	vector<int> lst1{};
	vector<int> lst2{};
	string path{ DATA_PATH };
	path += "DayFake.txt";
	//cout << "Path: " << path << endl;
	GetData(path,lst1,lst2);
	cout << "Day Fake Part 1: " << DayOnePartOneAnswer(lst1, lst2);
}

void FakeDay1Part2()
{
	vector<int> lst1{};
	vector<int> lst2{};
	string path{ DATA_PATH };
	path += "DayFake.txt";
	//cout << "Path: " << path << endl;
	GetData(path, lst1, lst2);
	cout << "Day Fake Part 1: " << DayOnePartOneAnswer(lst1, lst2);
}

int DayOnePartOneAnswer(vector<int> &lst1, vector<int> &lst2)
{
	std::ranges::sort(lst1);
	std::ranges::sort(lst2);
	int totalDiff{ 0 };
	if (lst1.size() == lst2.size())
	{
		for (int i = 0; i < lst1.size(); i++)
		{
			totalDiff += abs(lst1[i] - lst2[i]);
		}
	}

	return totalDiff; 

}

int DayOnePartTwoAnswer(std::vector<int>& list1, std::vector<int>& list2)
{
	//turn list 2 into a dictionary

	map<int, int> map{}; 
	int answer{ 0 };
	for (auto l2 : list2)
	{
		if (!map.contains(l2))
		{
			map[l2] = 0;
		}
		map[l2]++;
	}

	for (auto l1 : list1)
	{
		if (map.contains(l1))
		{
			answer += map[l1] * l1;
		}
	}

	return answer;
	
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
	while (getline(file, line))
	{
		stringstream ss(line); 
		if (ss >> a >> b);
		{
			//cout << a << " " << b << endl;
			lst1.push_back(a);
			lst2.push_back(b);
		}
	}
}
