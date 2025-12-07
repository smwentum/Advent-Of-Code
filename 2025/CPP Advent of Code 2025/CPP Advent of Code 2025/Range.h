#pragma once
class Range
{
	public: 
		Range(long long start, long long stop);
		bool isInRange(long long value) const;
	private: 
		long long start; 
		long long stop; 

};

