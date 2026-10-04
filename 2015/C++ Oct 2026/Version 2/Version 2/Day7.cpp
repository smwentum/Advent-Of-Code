#include "Day7.h"
#include "IPAddress.h"

#include<algorithm>
#include <fstream>
#include <iostream>
#include<string>
#include<vector>
#include<ranges>


using std::vector;
using std::cout;
using std::endl;
using std::string;

void Day7Part1()
{
	vector<IPAddress> lines = getLinesFromFile("Day7.txt");
	cout << "Day 7 part 1: " << std::count_if(lines.begin(), lines.end(), [](auto&& l) {
		return l.IsTLS();
		}) << endl;


}
void Day7Part2()
{
	vector<IPAddress> lines = getLinesFromFile("Day7.txt");
	cout << "Day 7 part 2: " << std::count_if(lines.begin(), lines.end(), [](auto&& l) {
		return l.IsSSL();
		}) << endl;
}

vector<IPAddress> getLinesFromFile(string fileName)
{
	vector<IPAddress> lines{};

	std::ifstream file(fileName);

	string line{};
	while (std::getline(file, line))
	{
		lines.push_back(IPAddress(line));
	}

	return lines;
}
