#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

#include "day3.h"

int main()
{
    std::string fileName{ "../textFiles/day3final.txt" };
    partOne(fileName);
}

std::vector<std::vector<std::string>> getDirections(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<std::vector<std::string>> directions{};
    std::vector<std::string> direction{};
    std::string tok{};

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            direction.push_back(line);
        }

        file.close();
        // std::cout << direction << std::endl;
        for (auto d : direction)
        {
            std::istringstream ss(d);
            std::vector<std::string> currentLine;
            while (std::getline(ss, tok, ','))
            {
                // std::cout << tok << std::endl;
                currentLine.push_back(tok);
            }
            directions.push_back(currentLine);
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
    std::vector<std::vector<std::string>> directions = getDirections(fileName);
    std::set<std::tuple<int, int>> firstCable{ getAllPoints(directions[0]) };
    std::set<std::tuple<int, int>> secondCable{ getAllPoints(directions[1]) };
    std::set<std::tuple<int, int>> intersectingPoint{};

    std::set_intersection(firstCable.begin(), firstCable.end(),
        secondCable.begin(), secondCable.end(),
        std::inserter(intersectingPoint, intersectingPoint.begin()));

    int minDist = INT_MAX;

    for (auto ip : intersectingPoint)
    {
        int newVal{ std::abs(std::get<0>(ip)) + std::abs(std::get<1>(ip)) };
        if (newVal < minDist && !(std::get<0>(ip) == 0 && std::get<1>(ip) == 0))
        {
            minDist = newVal;
        }
    }
    std::cout << "Day 3 part one: " << minDist << std::endl;
}

std::set<std::tuple<int, int>> getAllPoints(std::vector<std::string> directions)
{
    int startX = 0;
    int startY = 0;
    int steps{ 0 };
    std::set<std::tuple<int, int>> dictLeftRight{};

    for (std::string dir : directions)
    {
        steps = std::stoi(dir.substr(1));
        switch (dir[0])
        {
        case 'R':
            for (int i = 1; i <= steps; i++)
            {
                dictLeftRight.insert(std::tuple<int, int>(startX + i, startY));
            }
            startX += steps;
            break;
        case 'L':
            for (int i = 1; i <= steps; i++)
            {
                dictLeftRight.insert(std::tuple<int, int>(startX - i, startY));
            }
            startX -= steps;
            break;
        case 'U':

            for (int i = 1; i <= steps; i++)
            {
                dictLeftRight.insert(std::tuple<int, int>(startX, startY - i));
            }
            startY -= steps;
            break;
        case 'D':
            for (int i = 1; i <= steps; i++)
            {
                dictLeftRight.insert(std::tuple<int, int>(startX, startY + i));
            }
            startY += steps;
            break;
        }
    }
    return dictLeftRight;
}