#include "Day8.h"

#include<algorithm>
#include<fstream>
#include<iostream>
#include<vector>


using std::vector; 
using std::cout;
using std::endl;


void Day8Part1()
{
	const int ROWS{ 6 };
	const int COLS{ 50 };

	vector<vector<char>>  littleScreen(ROWS, vector<char>(COLS, 'o'));

	printScreen(littleScreen);


	

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