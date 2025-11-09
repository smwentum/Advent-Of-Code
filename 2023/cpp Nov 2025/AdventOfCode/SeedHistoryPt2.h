#pragma once
class SeedHistoryPt2
{
	private: 
		long long start; 
		long long length; 
	public:
		SeedHistoryPt2(long long start, long long length);
		long long getStart() const noexcept { return start; }
		long long getLength() const noexcept { return length; }

		// Setters
		void setStart(long long s) noexcept { start = s; }
		void setLength(long long l) noexcept { length = l; }
};

