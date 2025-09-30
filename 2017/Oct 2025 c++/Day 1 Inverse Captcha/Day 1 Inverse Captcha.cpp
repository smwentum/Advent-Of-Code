#include <iostream>
#include <fstream>
#include <sstream>

int main()
{



    int sum = 0; 
    std::ifstream inFIle;
    inFIle.open("Day1.txt");
    std::stringstream strStream;
    strStream << inFIle.rdbuf();
    std::string str = strStream.str()+ strStream.str()[0];
    //std::cout << str;
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            sum += (int)(str[i] - '0');
        }
    }

    std::cout << "Day 1 Part 1: " << sum << std::endl;
}
