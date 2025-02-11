#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "day3.h"

int main()
{
    std::string fileName{"../textFiles/day3final.txt"};
    partOne(fileName);
}

std::vector<std::string> getDirections(std::string fileName)
{
    std::ifstream file(fileName);
    std::string direction{};
    std::vector<std::string> directions{};
    std::string tok{};

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            direction += line;
        }

        file.close();
        std::cout << direction << std::endl;
        std::istringstream ss(direction);
        while (std::getline(ss, tok, ','))
        {
            std::cout << tok << std::endl;
            directions.push_back(tok);
        }
    }
    else
    {
        std::cout << "unable to open file" << std::endl;
    }

    return directions;
}

void partOne(std::string fileName)
{
    std::vector<std::string> directions =  getDirections(fileName);
}