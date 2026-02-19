#include "Day8.h"
#include "Point.h"

using namespace std; 

void Day8PartOne()
{
	//i want to use union find to do this
	//first step is to get the input;
	std::vector<Point> junctionBoxes;
	GetDay8Input(junctionBoxes);

	
}

void GetDay8Input(std::vector<Point>& junctionBoxes)
{

	ifstream file("Day8a.txt");
	string line;
	while (getline(file, line))
	{
		auto coords = split(line, ',');

		junctionBoxes.push_back(Point(stoi(coords[0]), stoi(coords[1]), stoi(coords[2])));
	}
	
}

std::vector<std::string> split(const std::string& s, char delim)
{
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}
