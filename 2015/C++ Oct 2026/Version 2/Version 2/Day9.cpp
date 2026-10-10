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
				int length{ std::stoi(marker.substr(1, marker.find('x') - 1)) };
				int repeatAmount{ std::stoi(marker.substr(marker.find('x') + 1 , marker.find(')') - (marker.find('x') + 1))) };
				count += length * repeatAmount; 
				i += marker.size() + length-1;

			} 
			
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
	string fileName{ "Day9.txt" };
	string line = getFileLine(fileName);

	// cout << line << endl;
	long long count = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '(')
		{
			size_t rightBrace = line.find(')', i + 1);


			if (rightBrace != std::string::npos)

			{

				string marker = line.substr(i, rightBrace - i + 1);
				long long length{ std::stoi(marker.substr(1, marker.find('x') - 1)) };


				string data{ line.substr(rightBrace + 1, length) };
				i += marker.size() + length - 1;
				if (!data.contains("("))
				{
					int repeatAmount{ std::stoi(marker.substr(marker.find('x') + 1 , marker.find(')') - (marker.find('x') + 1))) };
					count += length * repeatAmount;
					//i += marker.size() + length - 1;
				}
				else
				{
					int repeatAmount{ std::stoi(marker.substr(marker.find('x') + 1 , marker.find(')') - (marker.find('x') + 1))) };
					length = getLength(data);
					count += length * repeatAmount;
					//i += marker.size() 
				//cout << line.substr(rightBrace + 1, length) << endl; 
				}
			}

		}
		else
		{
			count++;
		}
	}
	cout << "Day 9 part 2 (" << fileName << "): " << count << endl;

}

long long getLength(string line )
{
	long long count{ 0 };
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '(')
		{
			size_t rightBrace = line.find(')', i + 1);


			if (rightBrace != std::string::npos)

			{

				string marker = line.substr(i, rightBrace - i + 1);
				long long length{ std::stoi(marker.substr(1, marker.find('x') - 1)) };


				string data{ line.substr(rightBrace + 1, length) };
				i += marker.size() + length - 1;
				if (!data.contains("("))
				{
					int repeatAmount{ std::stoi(marker.substr(marker.find('x') + 1 , marker.find(')') - (marker.find('x') + 1))) };
					count += length * repeatAmount;
					
					//break;
					//return count;
				}
				else
				{
					long long repeatAmount{ std::stoll(marker.substr(marker.find('x') + 1 , marker.find(')') - (marker.find('x') + 1))) };
					length = getLength(data);
					count += length * repeatAmount;
					//return count; 
					//i += marker.size() + length - 1;

				}

				//cout << line.substr(rightBrace + 1, length) << endl; 
			}
			
		}
		else
		{
			count++;
		}
	}
	return count; 
	
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

