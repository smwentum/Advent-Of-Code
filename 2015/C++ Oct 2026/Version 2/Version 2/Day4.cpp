#include "Day4.h"
#include "RoomName.h"

#include <iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>


//steps: get the data

void Day4Part1()
{
	std::vector<RoomName> roomNames = getRoomNames("day4.txt");
	unsigned int total = std::accumulate(roomNames.begin(), roomNames.end(), 0,
		[](unsigned int total, RoomName rn) {

			if (rn.DoesMatch())
			{
				total += rn.getSectorId();
				//std::cout << rn.getSectorId() << std::endl;
			}


			return total;
		});

	std::cout << "Day 4 part 1: " << total << std::endl; 
}
void Day4Part2()
{

}

std::vector<RoomName> getRoomNames(std::string fileName)
{
	std::vector<RoomName> roomNames;

	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cout << "File wont open" << std::endl;
	}

	std::string roomName;
	while (std::getline(file, roomName))
	{
		roomNames.push_back(RoomName(roomName));
	}


	return roomNames;

	
}