#pragma once

#include<algorithm>


class Range
{
	public: 
		Range(long long start, long long stop);
		bool isInRange(long long value) const;
		static bool DoesRangesOverLap(Range r1, Range r2);
		static Range GetUnionOfTwoRanges(Range r1, Range r2);
		long long GetLengthOfRange();
	private: 
		long long start; 
		long long stop; 

};

