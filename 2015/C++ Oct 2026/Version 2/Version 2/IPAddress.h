#pragma once

#include<string>
#include<vector>




class IPAddress
{
	private:

		std::vector<std::string> SupernetSequences; 
		std::vector<std::string> HyperTextSequences;
		

	public:
		IPAddress(std::string line);
		bool IsTLS();
		bool IsSSL();

		std::string line;
};

