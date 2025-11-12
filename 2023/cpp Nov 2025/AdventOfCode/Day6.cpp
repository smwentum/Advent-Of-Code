#include "Day6.h"

using namespace std; 

void Day6PartOne()
{
	//get the data 
	vector<string> lines = getThelines(); 
	
	vector<int> times{ getNumbersFromLinePt6(lines[0]) };
	vector<int> distances{ getNumbersFromLinePt6(lines[1]) };

	for (auto time : times)
	{
		cout << time << endl; 
	}

	for (auto distance : distances)
	{
		cout << distance << endl; 
	}
	

	

}

vector<int> getNumbersFromLinePt6(string line)
{
	vector<int> numbers{};
	line = line.substr(line.find_first_of(':')+1);
	line = line.substr(line.find_first_not_of(' '));
	cout << line << endl; 
	stringstream ss(line);
	string numberString;
	

	while (getline(ss, numberString, ' '))
	{
		//cout << numberString << endl;
		if (isdigit(numberString[0]))
		{
			numbers.push_back(stoi(numberString));
		}
	}
	return numbers;
}




vector<string> getThelines()
{
	vector<string> lines{};

	//get lines 
	ifstream file("Day6a.txt");
	string line{};
	while (getline(file, line))
	{
		//cout << line << endl;
		lines.push_back(line);
	}


	return lines;
}