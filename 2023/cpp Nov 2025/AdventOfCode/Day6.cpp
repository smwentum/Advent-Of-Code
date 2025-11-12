#include "Day6.h"

using namespace std; 

void Day6PartOne()
{
	//get the data 
	vector<string> lines = getThelines(); 
	
	vector<int> times{ getNumbersFromLinePt6(lines[0]) };
	vector<int> distances{ getNumbersFromLinePt6(lines[1]) };
	long long product = 1;

	

	for (int i = 0; i < times.size(); i++)
	{
		long long ans = getNumberOfWaysToWin(times[i], distances[i]);
		if (ans > 1ll)
		{
			product *= ans;
		}
	}
	
	cout << "Day 6 part 1: " << product << endl; 
	

}


void Day6PartTwo()
{
	//get the data 
	vector<string> lines = getThelines();

	long long  times{ getNumbersFromLineDay6Part2(lines[0])};
	long long distances{ getNumbersFromLineDay6Part2(lines[1]) };
	long long product = 1;



	long long ans = getNumberOfWaysToWin(times, distances);


	cout << "Day 6 part 2: " << ans << endl;


}

long long getNumberOfWaysToWin(long long time, long long distance)
{
	long long left{0};
	long long right{0};
	long long a{ getDay6Part1Answer(time,0) };
	long long b{ getDay6Part1Answer(time,0) };


	for (int i = 1; i < time; i++)
	{
		a = b; 
		b = getDay6Part1Answer(time, i);
		if (b > distance && a <= distance)
		{
			left = i; 
		}
		if (a > distance && b <= distance)
		{
			right = i; 
			break;
		}
	}

	if (right < left)
	{
		return 0ll; 
	}

	return right - left ;
}
long long getDay6Part1Answer(long long time, long long timeHeld)
{
	if (timeHeld < time)
	{
		return timeHeld* (time - timeHeld);
	}
	return 0ll;
}

vector<int> getNumbersFromLinePt6(string line)
{
	vector<int> numbers{};
	line = line.substr(line.find_first_of(':')+1);
	line = line.substr(line.find_first_not_of(' '));
	//cout << line << endl; 
	stringstream ss(line);
	string numberString;
	

	while (getline(ss, numberString, ' '))
	{
		//cout << numberString << endl;
		if (isdigit(numberString[0]))
		{
			numbers.push_back(stoi(numberString));
		}
	}
	return numbers;
}

long long getNumbersFromLineDay6Part2(string line)
{
    // substring after ':'
    auto colonPos = line.find_first_of(':');
    if (colonPos != string::npos)
    {
        line = line.substr(colonPos + 1);
    }

    // trim leading whitespace (spaces, tabs, CR, LF)
    size_t first = line.find_first_not_of(" \t\r\n");
    if (first != string::npos)
    {
        line = line.substr(first);
    }
    else
    {
        line.clear();
    }

    // remove all non-digit characters (use unsigned char with isdigit)
    line.erase(std::remove_if(line.begin(), line.end(), [](unsigned char c) {
        return !std::isdigit(c);
    }), line.end());

    if (line.empty())
        return 0ll;

    return std::stoll(line);
}




vector<string> getThelines()
{
	vector<string> lines{};

	//get lines 
	ifstream file("Day6.txt");
	string line{};
	while (getline(file, line))
	{
		//cout << line << endl;
		lines.push_back(line);
	}


	return lines;
}