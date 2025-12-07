#include "Day3.h"

using namespace std; 


static std::map<std::tuple<std::string, int>, std::string> dict;

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


long long getBestTwelveBatteriesFromBank(string bb)
{
	//after doing some research i am going to try to do the problem with recursion
	return stoll(getBestNBattriesFromBank(bb, 12));
	
	
}

string getBestNBattriesFromBank(string bank, int num)
{
	auto t = tuple<string, int>(bank, num);
	if (num == 0)
	{
		return "";
	}
	if (dict.contains(t))
	{
		return dict[t];
	}
	if (bank.length() == num)
	{
		//there aren't any choices so i just go with that
		dict[t] = bank; 
	}
	else if (bank.length() > num)
	{
		string s = "";
		s = myMax(bank[0] + getBestNBattriesFromBank(bank.substr(1), num - 1), getBestNBattriesFromBank(bank.substr(1), num));
		dict[t] = s; 
	}
	else
	{
		cout << "something is wrong" << endl; 
	}
	return dict[t];
}

string myMax(string s1, string s2)
{
	if (stoll(s1) >= stoll(s2))
	{
		return s1; 
	}
	return s2; 
}


void Day3PartTwo()
{
	vector<string> batteryBanks = getDay3PartOneInput();
	long long total = 0;
	for (auto batterybank : batteryBanks)
	{
		total += getBestTwelveBatteriesFromBank(batterybank);
	}
	cout << "Day 3 part 2: " << total << endl;
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