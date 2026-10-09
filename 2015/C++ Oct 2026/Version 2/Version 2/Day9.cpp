#include "Day9.h"

#include<algorithm>

#include<iostream>
#include<fstream>
#include<string>

using std::string;
using std::cout;
using std::endl; 
using std::cin; 


void Day9Part1()
{
	string fileName{ "Day9.txt" };
	string line = getFileLine(fileName);

	// cout << line << endl;
	int count = 0; 
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '(' )
		{
			size_t rightBrace = line.find(')', i + 1);

			if (rightBrace != std::string::npos)
			{
				string marker = line.substr(i, rightBrace - i + 1);
				//cout << marker << endl;
				int length{ std::stoi(marker.substr(1, marker.find('x') - 1)) };
				//cout << "length " << marker.substr(1, marker.find('x') - 1) << endl;
				//cout << marker.find('x') + 1 << endl; 
				//cout << marker.find(')') << endl;
				//cout << marker.find(')') - marker.find('x') + 1 -  << endl;
				//cout << marker.find(')') - (marker.find('x') + 1) << endl;
				int repeatAmount{ std::stoi(marker.substr(marker.find('x') + 1 , marker.find(')') - (marker.find('x') + 1))) };
				count += length * repeatAmount; 
				i += marker.size() + length-1;
				//cout << i; 

			} 
				//cout << "repeat amount: " << marker.substr(marker.find('x')+1 , marker.find(')') - (marker.find('x') + 1) ) << endl;

			
			
		}
		else
		{
			count++; 
		}
	}
	cout << "Day 9 part 1 ("<<fileName <<"): " << count << endl; 

}
void Day9Part2()
{

}

string getFileLine(string fileName)
{
	std::ifstream file(fileName);

	string line{}; 

	if (std::getline(file, line))
	{

	}

	return line; 

}

