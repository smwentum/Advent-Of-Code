#pragma once

#include<string>
#include<map>


using std::string;

class Day8Node
{
	public:

		//contructors
		Day8Node();
		Day8Node(std::string name, std::string left, std::string right);
		//vars
		string name; 
		string left; 
		string right;
		//getters 
		string getLeft();
		string getRight(); 
	//private: 
		 

};

