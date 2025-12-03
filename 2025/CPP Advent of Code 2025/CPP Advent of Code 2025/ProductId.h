#pragma once
class ProductId
{
	public: 
		ProductId(long long start, long long end);
		bool isInRange(long long num); 
		long long getEnd(); 
	private: 
		long long start; 
		long long end; 
};

