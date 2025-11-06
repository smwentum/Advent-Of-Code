#include "Day4.h"

using namespace std;

void Day4PartOne()
{

	vector<string> lines = dayFourGetLinesFromFile();
	long long sum = 0;
	for (string line : lines)
	{
		//cout << line << endl;
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
	set<long long> v1{};
	vector<long long> v2{}; 
	for (const auto& token_range : secondPart | std::views::split('|'))
	{
		string word(token_range.begin(), token_range.end());
		//cout << word << endl;
		if (v1.size() == 0)
		{
			for (const auto& token_range11 : word | std::views::split(' '))
			{
				string word1(token_range11.begin(), token_range11.end());
				long long num; 
				if (isdigit(word1[0]))
				{

					v1.insert(stoll(word1));
				}
				
			}
			
		}
		else
		{
			for (const auto& token_range1 : word | std::views::split(' '))
			{
				string word1(token_range1.begin(), token_range1.end());
				long long num;
				//cin >> num;
				if (isdigit(word1[0]))
				{
					num = stoll(word1);
					if (v1.contains(num))
					{
						ans += 1;
					}
				}
			}

		}
	}
	if (ans < 1)
	{
		return 0;
	}
	return pow(2,ans-1); 
}


vector<string> dayFourGetLinesFromFile()
{
	ifstream file("Day4.txt");
	string str;
	vector<string> lines{};
	while (getline(file, str))
	{
		lines.push_back(str);
	}
	return lines;
}
