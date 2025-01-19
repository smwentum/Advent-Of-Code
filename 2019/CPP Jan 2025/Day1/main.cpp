#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("../TextFiles/day1final.txt");
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
    }
}