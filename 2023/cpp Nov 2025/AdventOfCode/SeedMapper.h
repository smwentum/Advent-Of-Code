#pragma once

#include "SeedHistoryPt2.h"

class SeedMapper
{
	public:
		SeedMapper(long long source, long long dest, long length);

		bool isInSet(long long seed);
		long long getNewValue(long long seed);
		bool isDisjoint(SeedHistoryPt2 seed);
	private:
		long long source;
		long long dest;
		long long length;
};