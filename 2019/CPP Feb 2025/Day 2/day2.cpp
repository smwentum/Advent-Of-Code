#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "day2.h"

int main()
{
    std::string fileName{"../textFiles/day2final.txt"};
    partOne(fileName);
    partTwo(fileName);
}

void partOne(std::string fileName)
{
    std::ifstream file{fileName};

    if (file.is_open())
    {
        std::string line{};
        std::vector<int> codes{};
        std::string tok{};
        while (std::getline(file, line))
        {
            std::stringstream ss{line};

            while (std::getline(ss, tok, ','))
            {
                codes.push_back(std::stoi(tok));
            }
        }
        int currentPos{0};
        // make sure to read the whole problem statement
        codes[1] = 12;
        codes[2] = 2;

        while (codes[currentPos] != 99)
        {
            int a{codes[codes[currentPos + 1]]};
            int b{codes[codes[currentPos + 2]]};
            if (codes[currentPos] == 1)
            {
                codes[codes[currentPos + 3]] = a + b;
            }
            else if (codes[currentPos] == 2)
            {
                codes[codes[currentPos + 3]] = a * b;
            }
            currentPos += 4;
        }
        std::cout << "day 2 part one: " << codes[0] << std::endl;
    }
    else
    {
        std::cout << "file won't open" << std::endl;
    }
}

void partTwo(std::string fileName)
{
    std::ifstream file{fileName};

    if (file.is_open())
    {
        std::string line{};
        std::vector<int> codes{};
        std::string tok{};
        while (std::getline(file, line))
        {
            std::stringstream ss{line};

            while (std::getline(ss, tok, ','))
            {
                codes.push_back(std::stoi(tok));
            }
        }

        int noun{0};
        int verb{0};
        for (; noun <= 100; noun++)
        {
            for (; verb <= 100; verb++)
            {
                if (getAnswerForPartTwo(codes, noun, verb))
                {
                    std::cout << "Day 2 part 2: " << noun * 100 + verb << std::endl;
                    return;
                }
            }
        }
    }
    else
    {
        std::cout << "file won't open" << std::endl;
    }
}

bool getAnswerForPartTwo(std::vector<int> codes, int noun, int verb)
{
    int currentPos{0};
    while (codes[currentPos] != 99)
    {
        int a{codes[codes[currentPos + 1]]};
        int b{codes[codes[currentPos + 2]]};
        if (codes[currentPos] == 1)
        {
            codes[codes[currentPos + 3]] = a + b;
        }
        else if (codes[currentPos] == 2)
        {
            codes[codes[currentPos + 3]] = a * b;
        }
        currentPos += 4;
    }
    return codes[0] == 19690720;
}