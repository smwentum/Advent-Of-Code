#include "Day7.h"
#include "CamelHand.h"
using namespace std;

void Day7PartOne()
{
	//read in the input
	vector<string> lines = GetInput(); 
	vector<CamelHand> hands{};
	for (auto line : lines)
	{
		//cout << line << endl;
		int indexof = line.find_first_of(' ');
		string hand = line.substr(0, indexof ); 
		long long score = stoll(line.substr(indexof + 1));
		//cout << "hand: " << hand << " score: " << score << endl;
		//		cout << "\n";
		hands.push_back(CamelHand(hand, score,false));
	

	}

	sort(hands.begin(), hands.end());

	

	long long total = 0;
	for (int i = 1; i <= hands.size();i++)
	{
		total += i * hands[i-1].getBid();
	}


	cout << "Day 7 part 1: " << total << endl;
}

void Day7PartTwo()
{
	vector<string> lines = GetInput();
	vector<CamelHand> hands{};
	for (auto line : lines)
	{
		//cout << line << endl;
		int indexof = line.find_first_of(' ');
		string hand = line.substr(0, indexof);
		long long score = stoll(line.substr(indexof + 1));
		//cout << "hand: " << hand << " score: " << score << endl;
		//		cout << "\n";
		hands.push_back(CamelHand(hand, score,true));
	}

	sort(hands.begin(), hands.end());



	long long total = 0;
	for (int i = 1; i <= hands.size(); i++)
	{
		total += i * hands[i - 1].getBid();
	}


	cout << "Day 7 part 2: " << total << endl;
}

vector<string> GetInput()
{
	vector<string> lines{};
	ifstream file("day7a.txt");
	string line;

	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}