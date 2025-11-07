#pragma once


class SeedMapper
{
	public:
		SeedMapper(long long source, long long dest, long length);

		bool isInSet(long long seed);
		long long getNewValue(long long seed);
	private:
		long long source;
		long long dest;
		long long length;
};