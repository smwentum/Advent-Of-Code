#include "Day8.h"
#include "Day8Node.h"

using namespace std; 

void Day8PartOne()
{
	long long answer{ 0 };
	vector<string> lines = GetDay8Input();

	string directions = lines[0];
	set<string> uniqueNodes{}; 
	map<string,Day8Node> graph{};
	for (int i = 1; i < lines.size(); i++)
	{
		string s1 = lines[i].substr(0, 3);
		string s2 = lines[i].substr(lines[i].find_first_of('(')+1, 3);
		string s3 = lines[i].substr(lines[i].find_first_of(',') + 2, 3);
		//cout << s1 << endl; 
		//cout << s2 << endl; 
		//cout << s3 << endl;
		uniqueNodes.emplace(s1);
		uniqueNodes.emplace(s2);
		uniqueNodes.emplace(s3);
		graph[s1] =  Day8Node(s1, s2, s3);
	}

	string current = "AAA"; 
	while (current != "ZZZ")
	{
		if (directions[answer % directions.size()] == 'L')
		{
			current = graph[current].getLeft(); 
		}
		else
		{
			current = graph[current].getRight(); 
		}
		
		answer++; 
	}

	cout << "Day 8 part one: " << answer << endl; 

}


long long Day8PartTwoHelper(string current,
							const string directions, 
							map<string, Day8Node> graph)
{
	long long answer{ 0 };
	


	


	while (!current.ends_with("Z"))
	{
		if (directions[answer % directions.size()] == 'L')
		{
			current = graph[current].getLeft();
		}
		else
		{
			current = graph[current].getRight();
		}

		answer++;
	}
	return answer; 

}

void Day8PartTwo()
{

	long long answer{ 0 };
	vector<string> lines = GetDay8Input();

	string directions = lines[0];
	set<string> uniqueNodes{};
	map<string, Day8Node> graph{};
	for (int i = 1; i < lines.size(); i++)
	{
		string s1 = lines[i].substr(0, 3);
		string s2 = lines[i].substr(lines[i].find_first_of('(') + 1, 3);
		string s3 = lines[i].substr(lines[i].find_first_of(',') + 2, 3);
		//cout << s1 << endl; 
		//cout << s2 << endl; 
		//cout << s3 << endl;
		uniqueNodes.emplace(s1);
		uniqueNodes.emplace(s2);
		uniqueNodes.emplace(s3);
		graph[s1] = Day8Node(s1, s2, s3);
	}

	answer = 1;
	for (string s : uniqueNodes)
	{
		if (s.ends_with("A"))
		{
			auto x = Day8PartTwoHelper(s,directions,graph);
			answer = lcm(answer, x);
		}
	}


	cout << "Day 8 part two: " << answer << endl;


}


vector<string> GetDay8Input()
{
	vector<string> lines{};

	ifstream file("Day8.txt");
	string line; 

	while (getline(file, line))
	{
		if (line.size() > 0 && isalnum(line[0]))
		{
			lines.push_back(line);
		}
	}


	return lines;
}