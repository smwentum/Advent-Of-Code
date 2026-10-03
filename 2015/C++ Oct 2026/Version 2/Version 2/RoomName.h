#pragma once

#include "map"
#include "string"

class RoomName
{
	private:
		unsigned int sectorId; 
		std::string checksum;
		std::string stringCheckSum;
		std::string roomName; 
		std::map<char, int> charMap;
		void setValues(); 
	public:
		RoomName(std::string roomName);
		bool DoesMatch() const; 
		

};

