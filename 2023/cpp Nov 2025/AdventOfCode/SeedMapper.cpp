#include "SeedMapper.h"



SeedMapper::SeedMapper(long long source, long long dest, long length)
{
	this->source = source;
	this->dest = dest;
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
