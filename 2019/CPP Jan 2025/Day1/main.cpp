#include <iostream>
#include <fstream>
#include <string>

void partOne(std::string fileName);
void partTwo(std::string fileName);
long getFuel(long fuel);

int main()
{
    std::string fileName = "../TextFiles/day1final.txt";
    partOne(fileName);
    partTwo(fileName);
}

void partOne(std::string fileName)
{

    std::ifstream file(fileName);
    std::string line;
    long sum{0};
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // std::cout << line << std::endl;
            sum += std::stol(line) / 3 - 2;
        }
    }

    std::cout << "Part one Day 1: " << sum << std::endl;
}

void partTwo(std::string fileName)
{

    std::ifstream file(fileName);
    std::string line;
    long sum{0};
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // std::cout << line << std::endl;
            sum += getFuel(std::stol(line));
        }
    }

    std::cout << "Part two Day 1: " << sum << std::endl;
}

long getFuel(long fuel)
{
    if (fuel <= 0)
    {
        return 0;
    }
    long computedFuel = fuel / 3 - 2;

    if (computedFuel <= 0)
    {
        return 0;
    }

    return computedFuel + getFuel(computedFuel);
}