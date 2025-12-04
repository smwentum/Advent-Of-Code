#pragma once
class ProductId
{
	public: 
		ProductId(long long start, long long end);
		bool isInRange(long long num); 
		long long getEnd(); 
		long long getStart(); 
	private: 
		long long start; 
		long long end; 
};

