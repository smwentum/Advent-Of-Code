#include "Day2.h"


using namespace std; 

void DayTwoPartOne()
{
	vector<ProductId> productIdRanges = GetDayTwoInput();
	long long largestId = 0; 
	for(auto productIdrange: productIdRanges)
	{
		largestId = max(largestId, productIdrange.getEnd());
	}
	//cout << largestId << endl; 
	vector<long long> fakeIds; 
	for (long long  i = 0; i < 10; i++)
	{
		fakeIds.push_back(i);
	}
	long long curr = 1;
	while (stoll(to_string(curr) + to_string(curr)) <= largestId+1)
	{
		fakeIds.push_back(stoll(to_string(curr) + to_string(curr)));
		curr += 1; 
	}

	sort(fakeIds.begin(), fakeIds.end());
	long long count = 0;
	for (auto productIdRange : productIdRanges)
	{
		for (auto fakeId : fakeIds)
		{
			if (productIdRange.isInRange(fakeId))
			{
				count+=fakeId; 
			}
			else if (productIdRange.getEnd() < fakeId)
			{
				break;
			}
		}
	}

	cout << "Day 2 part 1: " << count << endl;


	
}

vector<ProductId> GetDayTwoInput()
{
	ifstream file("Day2a.txt");
	string line; 
	vector<ProductId> productIds; 
	while (getline(file, line))
	{
		stringstream ss(line);
		string line2; 
		while (getline(ss, line2, ','))
		{
			int end = line2.find('-');
			long long a = stoll(line2.substr(0,end));
			long long b = stoll(line2.substr(end + 1));
			//cout << "a: " << a << " b: " << b << endl;
			productIds.push_back(ProductId(a, b));

		}
	}
	return productIds;
}
