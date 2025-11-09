#include "SeedMapper.h"



SeedMapper::SeedMapper(long long source, long long dest, long length)
{
	this->source = dest;
	this->dest = source;
	this->length = length;
}

bool SeedMapper::isInSet(long long seed)
{
	return seed >= source and seed <= source + length;

}
long long SeedMapper::getNewValue(long long seed)
{
	if (isInSet(seed))
	{
		return seed - source + dest;
	}
	return seed;
}

bool SeedMapper::isDisjoint(SeedHistoryPt2 seed)
{
	long long start1 = source;
	long long end1 = source + length;
	long long start2 = seed.getStart(); 
	long long end2 = seed.getLength() + seed.getStart(); 

	//i just need to make sure these intervals don't overlap
	return start1 > end2 || start2 > end1; 



}