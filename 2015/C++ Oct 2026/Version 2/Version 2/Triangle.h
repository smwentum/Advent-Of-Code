#pragma once
class Triangle
{

	private: 
		unsigned int side1; 
		unsigned int side2; 
		unsigned int side3; 

	public:
		//constructor
		Triangle(unsigned int side1, unsigned int side2, unsigned int side3);

		//member functions
		bool isTriangle() const; 


		bool isTrianglePt2() const;



};

