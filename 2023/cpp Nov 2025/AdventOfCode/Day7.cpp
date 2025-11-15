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
	//Hand: T55J5 Three of a kind
	// Hand: Hand: JJA87 One pair
	//hands.push_back(CamelHand("JJA87", 14,true));
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

	sort(hands.begin(), hands.end(), 
		[](const CamelHand& a, const CamelHand& b) {
			if (a.handType != b.handType)
			{
				return a.handType < b.handType;
			}
			for (int i = 0; i < 5; i++)
			{
				if (a.hand[i] != b.hand[i])
				{
					return getStrengthPart2(a.hand[i]) < getStrengthPart2(b.hand[i]);
				}
			}
			return false; 
		});



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
	ifstream file("day7.txt");
	string line;

	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}

int getStrengthPart2(char letter)
{
	switch (letter)
	{
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'T':
		return 10;
	case 'J':
		return -1;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'A':
		return 14;
	}
	return 0;
}