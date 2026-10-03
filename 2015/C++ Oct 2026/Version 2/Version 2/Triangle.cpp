#include "Triangle.h"


Triangle::Triangle(unsigned int unsigned side1, unsigned int side2, unsigned int side3)
{
	this->side1 = side1;
	this->side2 = side2; 
	this->side3 = side3; 
}

bool Triangle::isTriangle() const
{
	if (side1 >= side2 + side3
		|| side2 >= side1 + side3
		|| side3 >= side1 + side2)
	{
		return false;
	}
		return true; 
}