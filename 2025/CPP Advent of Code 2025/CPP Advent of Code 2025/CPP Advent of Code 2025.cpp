// CPP Advent of Code 2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"

using namespace std; 

int main()
{
	cout << "Day 1" << endl; 
	Day1PartOne();
	Day1PartTwo();
	cout << "Day 2" << endl; 
	//DayTwoPartOne(); 
	cout << "i have day 2, but it slow, just for now i am going to leave it commented out" << endl; 
	//DayTwoPartTwo();
	cout << "Day 3" << endl;
	Day3PartOne(); 
	cout << "Day 2" << endl; 
	//DayTwoPartOne(); 
	//DayTwoPartTwo();


	cout << "Day 4" << endl; 
	day4PartOne();
	day4PartTwo();
}
