#include "Day8.h"

#include<algorithm>
#include<fstream>
#include<iostream>
#include<ranges>
#include<string>
#include <string_view>
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

	//printScreen(littleScreen);


	vector<string> linesFromFile{}; 

	getLinesFromFile("day8a.txt", &linesFromFile);

	for(auto line: linesFromFile)
	{
		cout << line << endl << endl; 

		auto parts = std::views::split(line, ' ') | std::ranges::to<vector<string>>();

		string command = parts[0];
		cout << command << endl;

		if (command == "rect")
		{
			int fillCols = stoi(parts[1].substr(0, parts[1].find('x')));
			int fillrows = stoi(parts[1].substr(parts[1].find('x') + 1));
			//cout << "rows " << fillrows << " cols: " << fillCols << endl;


		}

	}
	

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