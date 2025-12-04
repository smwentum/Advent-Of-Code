#include "Day2.h"


using namespace std; 

void DayTwoPartOne()
{
	vector<ProductId> productIdRanges = GetDayTwoInput();
	
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

void DayTwoPartTwo()
{
	vector<ProductId> productIdRanges = GetDayTwoInput();

	long long count = 0;
	set<long long> s;
	for (auto productIdRange : productIdRanges)
	{
		for (long long start = productIdRange.getStart(); start <= productIdRange.getEnd(); start++)
		{
			if (isFakeNumberPart2(start))
			{
				s.insert(start);
			}
		}


	}


	cout << "Day 2 part 2: " << accumulate(s.begin(), s.end(), 0LL) << endl;
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

bool isFakeNumberPart2(long long start)
{

	string s1 = to_string(start);
	for (int i = 1; i < s1.length(); i++)
	{
		if (s1.length() % i == 0)
		{
			if ( isFakeNumberPart2helper(s1, i))
			{
				return true; 
			}
		}
	
	}
	return false;
}

bool isFakeNumberPart2helper(string s, int length)
{
	for (int i = 0; i < s.length() - length; i+=length)
	{
		if (s.substr(0, length) != s.substr(i + length, length))
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
