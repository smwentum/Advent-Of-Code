#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "day4.h"

int main()
{
    partOne("../textFiles/day4final.txt");
}

void partOne(std::string fileName)
{
    std::ifstream fs{fileName};
    std::string line{};
    std::string tok{};
    int a{};
    int b{};
    int count{0};
    if (fs.is_open())
    {
        if (std::getline(fs, line))
        {
            std::stringstream ss{line};

            if (std::getline(ss, tok, '-'))
            {
                // std::cout << tok << std::endl;
                a = std::stoi(tok);
            }
            // std::cout << a << std::endl;
            if (std::getline(ss, tok, '-'))
            {
                b = std::stoi(tok);
            }
            for (int i = a; i <= b; i++)
            {
                if (isPossiblePassword(i))
                {
                    count++;
                }
            }
            std::cout << "Day 4 part one: " << count << std::endl;
        }
    }
    else
    {
        std::cout << "file couldn't be opened" << std::endl;
    }
}

bool isPossiblePassword(int i)
{
    std::string s{std::to_string(i)};
    bool isDup{false};
    for (size_t i = 0; i < s.length() - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            return false;
        }
        if (s[i] == s[i + 1])
        {
            isDup = true;
        }
    }
    if (!isDup)
    {
        return false;
    }
    return true;
}