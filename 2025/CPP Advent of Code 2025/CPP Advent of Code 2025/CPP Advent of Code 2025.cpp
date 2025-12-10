// CPP Advent of Code 2025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"


using namespace std; 

int main()
{
	cout << "Day 1" << endl; 
	Day1PartOne();
	Day1PartTwo();
	cout << "Day 2" << endl; 
	cout << "i have day 2, but it slow, just for now i am going to leave it commented out" << endl;
	//DayTwoPartOne(); 
	//DayTwoPartTwo();
	cout << "Day 3" << endl;
	Day3PartOne(); 
	//Day3PartTwo();
	//DayTwoPartTwo();

	cout << "Day 4" << endl; 
	day4PartOne();
	day4PartTwo();

	cout << "Day 5" << endl; 
	day5PartOne();
	day5PartTwo();

	cout << "Day 6" << endl; 
	Day6PartOne(); 
	Day6Part2();
	
	cout << "Day 7" << endl; 
	Day7PartOne();
	
}
