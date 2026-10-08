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


const int ROWS{ 6 }; //6
const int COLS{ 50 }; //50
const char OFF{ '.' };
const char ON{ '#' };


void Day8Part1()
{


	vector<vector<char>>  littleScreen(ROWS, vector<char>(COLS, OFF));

	//printScreen(littleScreen);


	vector<string> linesFromFile{}; 

	getLinesFromFile("day8.txt", &linesFromFile);

	//refactor this into a different function 
	for(auto line: linesFromFile)
	{
		//cout << line << endl << endl; 

		auto parts = std::views::split(line, ' ') | std::ranges::to<vector<string>>();

		//string command = parts[0];
		//cout << command << endl;

		if (parts[0] == "rect")
		{
			int fillCols = stoi(parts[1].substr(0, parts[1].find('x')));
			int fillrows = stoi(parts[1].substr(parts[1].find('x') + 1));
			//cout << "rows " << fillrows << " cols: " << fillCols << endl;

			rect(fillrows, fillCols, &littleScreen);
			//printScreen(littleScreen);
		}
		else if (parts[1] == "row")
		{
			int rotateBy = stoi(parts[4]); 
			int rotateRow1 = stoi(parts[2].substr(parts[2].find("=") + 1));
			rotateRow(&littleScreen, rotateRow1, rotateBy); 
			//printScreen(littleScreen);
		}

		else if (parts[1] == "column")
		{
			int rotateBy = stoi(parts[4]);
			int rotateRow1 = stoi(parts[2].substr(parts[2].find("=") + 1));
			rotateCol(&littleScreen, rotateRow1, rotateBy);
			//printScreen(littleScreen);
		}

		

	}
	cout << "Day 8 part 1: " << getCountOfOnPixles(littleScreen) << endl;
	

}
void Day8Part2()
{
	
}

void rect(int rows, int cols, vector<vector<char>>* screen)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(*screen)[i][j] = ON;
		}
	}
}

void rotateRow(vector<vector<char>>* screen, int row, int rotateBy)
{
	vector<char> rowFromMatrix = (*screen)[row];
	/*for (int i = 0; i < rotateBy % ROWS; i++)
	{
		
	}*/

	//refactor this at some point
	for (int i = 0; i < rotateBy; i++)
	{
		vector<char> computedVector{};
		computedVector.push_back(rowFromMatrix[rowFromMatrix.size() - 1]); 
		for (int i = 0; i < rowFromMatrix.size() - 1; i++)
		{
			computedVector.push_back(rowFromMatrix[i]);
		}

		rowFromMatrix = computedVector; 
	}
	
	(*screen)[row] = rowFromMatrix;
}

void rotateCol(vector<vector<char>>* screen, int col, int rotateBy)
{
	vector<char> colFromMatrix{}; 

	for (int i = 0; i < ROWS; i++)
	{
		colFromMatrix.push_back((*screen) [i][col]);
	}

	for (int i = 0; i < rotateBy; i++)
	{
		vector<char> computedVector{};
		computedVector.push_back(colFromMatrix[colFromMatrix.size() - 1]);
		for (int i = 0; i < colFromMatrix.size() - 1; i++)
		{
			computedVector.push_back(colFromMatrix[i]);
		}

		colFromMatrix = computedVector;
	}

	for (int i = 0; i < ROWS; i++)
	{
		(*screen)[i][col] = colFromMatrix[i];
	}
	
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


int getCountOfOnPixles(const vector<vector<char>>& littleScreen)
{
	int count{ 0 };

	for (int i = 0; i < littleScreen.size(); i++)
	{
		for (int j = 0; j < littleScreen[0].size(); j++)
		{
			if (littleScreen[i][j] == ON)
			{
				count++;
			}
		}
	}

	return count; 
}
