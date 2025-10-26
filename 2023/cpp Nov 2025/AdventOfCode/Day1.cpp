#include "Day1.h"


using namespace std;
//std::vector<std::string> GetFileLines(); 


void DayOnePartOne()
{
	// Implementation for Day 1 Part One	


	//read the input file

	std::vector<std::string> lines = GetFileLines();

	int sum {0};
	for (string line : lines)
	{
		//pull out the first and last digit
		int first = GetFirstDigit(line);
		int last = GetLastDigit(line);
		int num = first * 10 + last;
		sum += num;
	}
	cout << "Day one Part 1: " << sum << endl;
		

	//get the sum of the digits that match

}

int GetFirstDigit(string s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			return (int)(s[i] - '0');
		}
	}
}


int GetLastDigit(string s)
{
	for (int i = s.length() - 1; i >= 0; --i)
	{
		if (std::isdigit(s[i]))
		{
			return (int)(s[i] - '0');
		}
	}

}

void DayOnePartTwo()
{
	std::vector<std::string> lines = GetFileLines();

	int sum{ 0 };
	for (string line : lines)
	{
		//pull out the first and last digit
		int first = GetFirstDigitPart2(line);
		int last = GetLastDigitPart2(line);
		int num = first * 10 + last;
		sum += num;
	}
	cout << "Day one Part 2: " << sum << endl;
}



int GetFirstDigitPart2(string s)
{
	vector<string> nums = getAllPossibleNumbers();


	int index = s.length()+1;
	int value = 11;

	for (string num : nums)
	{
		std::size_t found = s.find(num);
		if (found != std::string::npos)
		{
			if (index > found)
			{
				value= getValueFromWordString(num);
				index = found;
			}
		}
	}
	return value; 

}

int GetLastDigitPart2(string s)
{
	vector<string> nums = getAllPossibleNumbers();



	int index = -1;
	int value = 11;

	for (string num : nums)
	{
		std::size_t found = s.rfind(num);
		if (found != std::string::npos)
		{
			if (index < (int)found)
			{
				value = getValueFromWordString(num);
				index = found;
			}
		}
	}
	return value;

}

int getValueFromWordString(string s)
{
	if(s.length()  ==1 )
	{
		return s[0] - '0';
	}

	if (s == "one")
	{
		return 1;
	}
	if(s == "two")
	{
		return 2;
	}
	if (s == "three")
	{
		return 3;
	}
	if (s == "four")
	{
		return 4;
	}
	if (s == "five")
	{
		return 5;
	}
	if (s == "six")
	{
		return 6;
	}
	if (s == "seven")
	{
		return 7;
	}
	if (s == "eight")
	{
		return 8;
	}
	if (s == "nine")
	{
		return 9;
	}
}




vector<string> getAllPossibleNumbers()
{
	vector<string> nums{};

	nums.push_back("1");
	nums.push_back("one");
	nums.push_back("2");
	nums.push_back("two");
	nums.push_back("3");
	nums.push_back("three");
	nums.push_back("4");
	nums.push_back("four");
	nums.push_back("5");
	nums.push_back("five");
	nums.push_back("6");
	nums.push_back("six");
	nums.push_back("7");
	nums.push_back("seven");
	nums.push_back("8");
	nums.push_back("eight");
	nums.push_back("9");
	nums.push_back("nine");
	nums.push_back("0");

	return nums; 

}

vector<string> GetFileLines()
{
	std::ifstream file("day1.txt");
	std::string str;
	std::vector<std::string> lst{};
	while (std::getline(file, str))
	{
		//std::cout << str << std::endl;
		lst.push_back(str);
	}
 
	return lst;
}


