#include "Day5.h"
#include "Range.h"


using namespace std; 

void day5PartOne()
{
	vector<Range> ranges; 
	vector<long long> ingrediennts; 
	GetInputPartOne(ranges, ingrediennts);
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

//my idea is just make sure the ranges are disjoint if not combine them
void day5PartTwo()
{
	vector<Range> ranges;
	GetInputPartTwo(ranges);
	long long cnt{ 0 };
	while (findTwoRangesToCombine(ranges))
	{

	}
	while (findTwoRangesToCombine(ranges))
	{

	}

	cnt = accumulate(ranges.begin(), ranges.end(), 0ll, [](long long val, Range& r1) {
		return val + r1.GetLengthOfRange();
		});


	//9314770827368 too low
	cout << "Day 5 part Two: " << cnt << endl;
}

bool findTwoRangesToCombine(vector<Range>& ranges)
{
	if (ranges.size() < 2)
	{
		return false; 
	}
	for(int i= 0; i < ranges.size();i++)
	{
		for (int j = i+1; j < ranges.size(); j++)
		{
			if (Range::DoesRangesOverLap(ranges[i], ranges[j]))
			{
				Range r1 = ranges[i];
				Range r2 = ranges[j];
				ranges.erase(ranges.begin() + j);
				ranges.erase(ranges.begin() + i);
				ranges.push_back(Range::GetUnionOfTwoRanges(r1,r2));

				return true; 
			}
		}
	}

	return false; 
}


//i am going to do something weird for this one
void GetInputPartOne(vector<Range>& ranges, vector<long long>& ingrediennts)
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


void GetInputPartTwo(vector<Range>& ranges)
{
	ifstream file("Day5.txt");
	bool isRange = true;
	string line;
	while (getline(file, line))
	{
		if (line.size() == 0)
		{
			break;
		}
		long long a, b;
		a = stoll(line.substr(0, line.find('-')));
		b = stoll(line.substr(line.find('-') + 1));
		//cout << a << b << endl;
		ranges.push_back(Range(a, b));
		
	}
}
