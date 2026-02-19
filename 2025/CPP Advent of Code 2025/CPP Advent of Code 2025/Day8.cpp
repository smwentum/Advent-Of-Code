#include "Day8.h"
#include "Point.h"
#include "UnionFind.h"


using namespace std; 

struct CompareOnLastElement {
	bool operator()(const std::tuple<int, int, double>& a, const std::tuple<int, int, double>& b)
	{
		return std::get<2>(a) > std::get<2>(b);
	}

};

void Day8PartOne()
{
	//i want to use union find to do this
	//first step is to get the input;
	std::vector<Point> junctionBoxes;
	GetDay8Input(junctionBoxes);

	//next is to do a union find
	UnionFind uFind(junctionBoxes.size());

	//i need a min heap
	std::priority_queue<std::tuple<int, int, double>, 
		std::vector<std::tuple<int,int, double>>, 
		CompareOnLastElement> minHeap;

	for (int i = 0; i < junctionBoxes.size(); i++)
	{
		for (int j = i + 1; j < junctionBoxes.size(); j++)
		{
			minHeap.push(std::tuple<int,int,double>(junctionBoxes[i].getId(),
													junctionBoxes[j].getId(),
													Point::getDistance(junctionBoxes[i], junctionBoxes[j])));
		}
	}

	int numberOfBoxesToJoin = 9;

	while (minHeap.size() > 0 && numberOfBoxesToJoin > 0)
	{
		tuple<int, int, double> x = minHeap.top();
		minHeap.pop();
		if (uFind.find(std::get<0>(x)) != uFind.find(std::get<1>(x)))
		{
			numberOfBoxesToJoin--;
			uFind.unite(std::get<0>(x), std::get<1>(x));
		}
		else
		{
			auto t = "";
		}
	}

	for (int i = 0; i < junctionBoxes.size(); i++)
	{
		uFind.find(i);
	}
	cout << "Day 8 Part 1: " << uFind.getLargestThreeSizes(); 
	
}

void GetDay8Input(std::vector<Point>& junctionBoxes)
{

	ifstream file("Day8a.txt");
	string line;
	int i = 0;
	while (getline(file, line))
	{
		auto coords = split(line, ',');
		
		junctionBoxes.push_back(Point(stoi(coords[0]), stoi(coords[1]), stoi(coords[2]),i));
		i++;
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
