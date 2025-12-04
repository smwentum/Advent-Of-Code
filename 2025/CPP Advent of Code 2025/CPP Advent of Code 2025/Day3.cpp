#include "Day3.h"

using namespace std; 

void Day3PartOne()
{
	vector<string> batteryBanks = getDay3PartOneInput();
	int total = 0;
	for (auto batterybank : batteryBanks)
	{
		total += getBestTwoBatteriesFromBank(batterybank); 
	}
	cout << "Day 3 part 1: " << total << endl; 
}

//i am going to guess a leetcode code trick of i think montonic stack (i think i am using the wrong term)
int getBestTwoBatteriesFromBank(string bb)
{
	//start from the end 
	char bigestSecondDigit = bb[bb.length() - 1];
	int bestAnswer = 0; 
	for (int i = bb.length() - 2; i >= 0; i--)
	{
		string myGuess = { bb[i],bigestSecondDigit };
		bestAnswer = max(bestAnswer, stoi(myGuess));
		bigestSecondDigit = max(bb[i], bigestSecondDigit);
	}
	return bestAnswer;
}


vector<string> getDay3PartOneInput()
{
	vector<string> lines; 

	ifstream file("Day3.txt");
	string line; 
	while (getline(file, line))
	{
		lines.push_back(line);
	}

	return lines; 
}