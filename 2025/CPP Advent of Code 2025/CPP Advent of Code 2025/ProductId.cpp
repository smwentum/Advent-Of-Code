#include "ProductId.h"


ProductId::ProductId(long long start, long long end)
{
	this->start = start; 
	this->end = end; 
}


bool ProductId::isInRange(long long num)
{
	return start <= num && num <= end; 
}

long long ProductId::getEnd()
{
	return end; 
}