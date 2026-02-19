#pragma once

#include <math.h>

class Point
{
	public: 
		Point(long long x, long long y, long long z,long long id);
		static double getDistance(Point p1, Point p2);
		long long getId();
		long long getX(); 
	private:
		long long x; 
		long long y; 
		long long z; 
		long long id;
};

