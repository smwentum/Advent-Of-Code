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
	largestId *= 3;
	vector<long long> fakeIds; 
	for (long long  i = 1; i < 10; i++)
	{
		fakeIds.push_back(i);
	}
	long long curr = 1;
	

	long long count = 0;
	set<long long> s; 
	for (auto productIdRange : productIdRanges)
	{
		for (long long start = productIdRange.getStart(); start < productIdRange.getEnd(); start++)
		{
			if (isFakeNumber(start))
			{
				s.insert(start);
			}
		}

		
	}
	
	
	cout << "Day 2 part 1: " << accumulate(s.begin(), s.end(), 0LL) << endl;


	
}

bool isFakeNumber(long long start)
{
	string s1 = to_string(start);
	if (s1.length() % 2 != 0)
	{
		return false; 
	}
	for (int i = 0; i < s1.length() / 2; i++)
	{
		if (s1[i] != s1[i + s1.length() / 2])
		{
			return false; 
		}
	}
	return true; 
}

vector<ProductId> GetDayTwoInput()
{
	ifstream file("Day2.txt");
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
