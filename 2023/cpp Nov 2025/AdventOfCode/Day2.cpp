#include "Day2.h"

using namespace std; 

void Day2PartOne()
{
	//parse the file
	vector<string> lines = GetLinesFromFile();
	int sum{ 0 };
	for (auto line : lines)
	{
		sum += Part1ReturnIfValid(line);
	}

	//use a dict to hold colors 
	//test if its possible
	//if possible add game number
	//print result
	cout << "Day 2 Part 1: " << sum << endl; 
}

vector<string> GetLinesFromFile()
{
	ifstream file("Day2.txt");
	string str; 
	vector<string> lst{};

	while (std::getline(file, str))
	{
	
		lst.push_back(str);
	}

	return lst;
}

int Part1ReturnIfValid(string line)
{
	stringstream ss(line);

	string dummy;
	int gameId{ 0 };
	ss >> dummy;
	ss >> gameId;
	//cout << "Game Id: " << gameId<< endl;
	ss >> dummy;
	string gameString;
	std::map<string, int> dices;
	while (getline(ss, gameString, ';'))
	{
		//std::remove(gameString.begin(), gameString.end(), ' ');
		//cout << gameString << endl;
		
		stringstream ss2(gameString);
		string currentDraw;
		while (getline(ss2, currentDraw, ','))
		{
			stringstream ss3(currentDraw);
			int numOfDice{ 0 };
			string dicecolor{ "" };
			ss3 >> numOfDice;
			ss3 >> dicecolor;
			if (dicecolor[dicecolor.length() - 1] == ',')
			{
				dicecolor = dicecolor.substr(0, dicecolor.length() - 1);
			}
			//cout << "From me: " << numOfDice << " " << dicecolor << endl; 
			if (dices.find(dicecolor) == dices.end())
			{
				dices[dicecolor] = 0;
			}
			dices[dicecolor] = std::max(dices[dicecolor], numOfDice);
		}

	}

	if (dices["red"] > 12 || dices["green"] > 13 || dices["blue"] > 14)
	{
		gameId = 0;
	}
	
	return gameId; 

}

