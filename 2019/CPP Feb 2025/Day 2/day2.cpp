#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "day2.h"

int main()
{
    std::string fileName{"../textFiles/day2final.txt"};
    partOne(fileName);
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
        //make sure to read the whole problem statement
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