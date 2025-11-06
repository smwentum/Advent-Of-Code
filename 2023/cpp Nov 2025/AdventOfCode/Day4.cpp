#include "Day4.h"

using namespace std;

void Day4PartOne()
{

	vector<string> lines = dayFourGetLinesFromFile();
	long long sum = 0;
	for (string line : lines)
	{
		cout << line << endl;
		sum += getCountOfWinningNumbers(line);
	}

	cout << "Day 4 part 1: " <<sum << endl; 

	
}

long long getCountOfWinningNumbers(string line)
{
	//just want the two list of numbers
	//remove card part of input
	
	string secondPart =removeFirstPart(line);
	
	//cout << secondPart << endl;

	long long ans = getDay4PartOneAnswerFromLine(secondPart);
	
	
	return ans; 
}

string removeFirstPart(string line)
{
	string ans = "";
	for (const auto& token_range : line | std::views::split(':'))
	{
		string word(token_range.begin(), token_range.end());
		ans = word;
	}

	return ans;
}

long long getDay4PartOneAnswerFromLine(string secondPart)
{
	long long ans =  0;
	vector<int> v1{};
	vector<int> v2{}; 
	for (const auto& token_range : secondPart | std::views::split('|'))
	{
		string word(token_range.begin(), token_range.end());
		cout << word << endl;
		
	}
	return ans; 
}


vector<string> dayFourGetLinesFromFile()
{
	ifstream file("Day4a.txt");
	string str;
	vector<string> lines{};
	while (getline(file, str))
	{
		lines.push_back(str);
	}
	return lines;
}
