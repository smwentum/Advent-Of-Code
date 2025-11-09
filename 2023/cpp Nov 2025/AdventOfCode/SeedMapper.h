#pragma once

#include <vector>

#include "SeedHistoryPt2.h"

class SeedMapper
{
	public:
		SeedMapper(long long source, long long dest, long length);

		bool isInSet(long long seed) const;
		long long getNewValue(long long seed);
		bool isDisjoint(SeedHistoryPt2 seed);
		bool seedRangeIsInMapperRange(SeedHistoryPt2 seed);
		bool rangesIntersectALittle(SeedHistoryPt2 seed);
		std::vector<SeedHistoryPt2> getNewValues(SeedHistoryPt2 seed);
	private:
		long long source;
		long long dest;
		long long length;
};