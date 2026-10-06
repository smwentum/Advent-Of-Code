#include "Day8.h"

#include<algorithm>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>


using std::string;
using std::vector; 
using std::cout;
using std::endl;


const int ROWS{ 6 };
const int COLS{ 50 };

void Day8Part1()
{


	vector<vector<char>>  littleScreen(ROWS, vector<char>(COLS, 'o'));

	printScreen(littleScreen);


	vector<string> linesFromFile{}; 

	getLinesFromFile("day8a.txt", &linesFromFile);
	

}
void Day8Part2()
{
	
}

void printScreen(const vector<vector<char>>& littleScreen)
{
	cout << endl; 

	for (int i = 0; i < littleScreen.size(); i++)
	{
		for (int j = 0; j < littleScreen[0].size(); j++)
		{
			cout << littleScreen[i][j];
		}
		cout << endl;
	}

	cout << endl;

	cout << endl;
	cout << endl; 
}

void getLinesFromFile(string fileName, vector<string>* lines)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		cout << "can't open file" << endl; 
	}

	string line; 
	while (std::getline(file, line))
	{
		lines->push_back(line);
	}

}