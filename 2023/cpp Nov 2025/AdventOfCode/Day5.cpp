#include "Day5.h"
#include "SeedMapper.h"

// TODO: refactor getting seeds to separte function 



using namespace std;

void Day5PartOne()
{
	vector<string> lines = getInput(); 
	/*for (auto line : lines)
	{
		cout << line << endl;
	}*/

	//part one get the seeds
	vector<long long> seeds{}; 
	vector<vector<SeedMapper>> seedMaps{};
	int start{ -1 };
	for (size_t i = 0; i < lines.size(); i++)
	{
		if (i == 0)
		{
			size_t start = lines[i].find(':');
			string seedLine =  lines[i].substr(start+2);
			istringstream iss(seedLine);
			long long seed;
			while (iss >> seed)
			{
				seeds.push_back(seed);
			}

		}
		else
		{
			if (isalpha(lines[i][0]))
			{
				++start;
				seedMaps.push_back(vector<SeedMapper>{});

			}
			if (isdigit(lines[i][0]))
			{
				//i am just going to add it to the current vector
				istringstream iss(lines[i]);
				long long source, dest, length; 
				iss >> source >> dest >> length;
				cout << source << " " << dest << " " << length << endl;
				seedMaps[start].push_back(SeedMapper(source, dest, length));
			}
		}
	}


}


vector<string> getInput()
{
	ifstream file("Day5a.txt");
	string line; 
	vector<string> lines{};

	while (getline(file, line))
	{
		lines.push_back(line);
	}
	return lines;
}
