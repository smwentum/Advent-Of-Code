#include "Day5.h"
#include "Range.h"


using namespace std; 

void day5PartOne()
{
	vector<Range> ranges; 
	vector<long long> ingrediennts; 
	GetInput(ranges, ingrediennts);
	int cnt{0};
	for (auto ingreient : ingrediennts)
	{
		if (any_of(ranges.begin(), ranges.end(), [ingreient](const Range& range) {
			return range.isInRange(ingreient);
			}))
		{
			cnt++;
		}
	}
	cout << "Day 5 part One: " << cnt << endl;
}


//i am going to do something weird for this one
void GetInput(vector<Range>& ranges, vector<long long>& ingrediennts)
{
	ifstream file("Day5.txt");
	bool isRange = true; 
	string line; 
	while (getline(file, line))
	{
		if (line.size() == 0)
		{
			isRange = false; 
			continue; 
		}
		if (isRange)
		{
			long long a, b; 
			a = stoll(line.substr(0, line.find('-')));
			b = stoll(line.substr(line.find('-') + 1));
			//cout << a << b << endl;
			ranges.push_back(Range(a, b));
		}
		else
		{
			ingrediennts.push_back(stoll(line));
		}
	}
}

