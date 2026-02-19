#include "Point.h"

using namespace std; 

Point::Point(long long x, long long y, long long z,long long id)
{
	this->x = x;
	this->y = y; 
	this->z = z;
	this->id = id;
}

double Point::getDistance(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2)
		+ pow(p1.y - p2.y, 2)
		+ pow(p1.z - p2.z, 2));
}

long long Point::getId()
{
	return this->id;
}

long long Point::getX()
{
	return this->x; 
}