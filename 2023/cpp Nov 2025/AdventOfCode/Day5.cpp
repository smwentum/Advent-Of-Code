#include "Day5.h"
#include "SeedHistory.h"
#include "SeedMapper.h"






using namespace std;

void Day5PartOne()
{
	vector<string> lines = getInput(); 
	/*for (auto line : lines)
	{
		cout << line << endl;
	}*/

	//part one get the seeds
	vector<SeedHistory> seeds{}; 
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
				seeds.push_back(SeedHistory(seed));
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

	//now figure out where the seeds go
	
	for (int i =0 ;i < seeds.size();i++)
	{
		seeds[i].setSoil(applyMapping(seeds[i].getSeed(), seedMaps[0]));
		seeds[i].setFertilizer(applyMapping(seeds[i].getSoil(), seedMaps[1]));
		seeds[i].setWater(applyMapping(seeds[i].getFertilizer(), seedMaps[2]));
		seeds[i].setLight(applyMapping(seeds[i].getWater(), seedMaps[3]));
		seeds[i].setTemperature(applyMapping(seeds[i].getLight(), seedMaps[4]));
		seeds[i].setHumidity(applyMapping(seeds[i].getTemperature(), seedMaps[5]));
		seeds[i].setLocation(applyMapping(seeds[i].getHumidity(), seedMaps[6]));
		//ans += seedhistory.getLocation();
	}
	auto ans = std::min_element(seeds.begin(), seeds.end(), [](const SeedHistory& a, const SeedHistory& b) {return  a.getLocation()< b.getLocation(); });

	cout << "Day 5 part 1 answer: " << ans->getLocation() << endl; 

}

long long applyMapping(long long start, vector<SeedMapper> map)
{

	const auto it = std::find_if(map.begin(), map.end(), [start](SeedMapper m1) { return m1.isInSet(start); });

	if (it != map.end())
	{
		return it->getNewValue(start);
	}


	//if (std::any_of(map.begin(), map.end(), [start](SeedMapper m1) { return m1.isInSet(start); } ))
	//{
	//	SeedMapper sm = std::find_first_of(map.begin(), map.end(), [start](SeedMapper m1) { return m1.isInSet(start); })
	//}
	return start; 
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
