#include "Range.h"

using namespace std;

Range::Range(long long start, long long stop)
{
	this->start=start; 
	this->stop=stop; 
}

bool Range::isInRange(long long value) const
{
	return value >= start && value <= stop; 
}

bool Range::DoesRangesOverLap(Range r1, Range r2)
{
	return max(r1.start, r2.start) <= min(r1.stop, r2.stop);
}

Range Range::GetUnionOfTwoRanges(Range r1, Range r2)
{
	return Range(min(r1.start, r2.start), max(r1.stop, r2.stop));
}

long long Range::GetLengthOfRange()
{
	return stop - start + 1;
}