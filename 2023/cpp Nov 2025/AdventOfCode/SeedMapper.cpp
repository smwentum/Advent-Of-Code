#include "SeedMapper.h"

using namespace std;

SeedMapper::SeedMapper(long long source, long long dest, long length)
{
	this->source = dest;
	this->dest = source;
	this->length = length;
}

bool SeedMapper::isInSet(long long seed) const
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

bool SeedMapper::seedRangeIsInMapperRange(SeedHistoryPt2 seed)
{
	long long start1 = source;
	long long end1 = source + length;
	long long start2 = seed.getStart();
	long long end2 = seed.getLength() + seed.getStart();

	return start1 <= start2 && end2 <= end1; 
}

bool SeedMapper::rangesIntersectALittle(SeedHistoryPt2 seed)
{
	long long start1 = source;
	long long end1 = source + length;
	long long start2 = seed.getStart();
	long long end2 = seed.getLength() + seed.getStart();

	return start1 <= end2 && start2 <= end1; 
}

//took this from copilot 
vector<SeedHistoryPt2> SeedMapper::getNewValues(SeedHistoryPt2 seed)
{
	std::vector<SeedHistoryPt2> ans{};
	long long s1 = source;
	long long e1 = source + length;
	long long s2 = seed.getStart();
	long long e2 = seed.getStart() + seed.getLength();

	// Left piece: portion of [s2,e2) that lies before s1
	if (s2 < s1) {
		long long leftStart = s2;
		long long leftEnd = std::min(e2-1, s1);
		long long leftLen = leftEnd - leftStart;
		if (leftLen > 0) {
			ans.push_back(SeedHistoryPt2(leftStart, leftLen));
		}
	}

	// Right piece: portion of [s2,e2) that lies after e1
	if (e2 > e1) {
		long long rightStart = std::max(s2+1, e1);
		long long rightEnd = e2;
		long long rightLen = rightEnd - rightStart;
		if (rightLen > 0) {
			ans.push_back(SeedHistoryPt2(rightStart, rightLen));
		}
	}

	long long interStart = std::max(s1, s2);
	long long interEnd = std::min(e1, e2);


	long long interLen = interEnd - interStart;
	long long mappedStart = dest + (interStart - source);
	if (interLen > 0)
	{
		ans.push_back(SeedHistoryPt2(interStart, interLen));
	}
	return ans; 
}
