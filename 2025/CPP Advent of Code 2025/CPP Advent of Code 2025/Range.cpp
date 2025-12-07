#include "Range.h"


Range::Range(long long start, long long stop)
{
	this->start=start; 
	this->stop=stop; 
}

bool Range::isInRange(long long value) const
{
	return value >= start && value <= stop; 
}