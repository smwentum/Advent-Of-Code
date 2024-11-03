#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>



void day5partOne(std::string fileName);
bool hasThreeVowels(std::string line);
bool duplicateLetters(std::string line);
bool doesNotContainString(std::string line);

int main()
{
    day5partOne("../test/day5partOne.txt");
}

void day5partOne(std::string fileName)
{
    std::string line{};

    std::ifstream inFile(fileName);
    int count{0};
    while(std::getline(inFile,line))
    {
        bool hasThreeOrMoreVowels =  hasThreeVowels(line);
        bool dupLetters = duplicateLetters(line);
        bool doesntContainLetters = doesNotContainString(line);
        if(hasThreeOrMoreVowels && dupLetters && doesntContainLetters )
        {
            count++;
        }
    }

    std::cout << "Answer to Day 5 part one: "<< count << "\n";
}

bool hasThreeVowels(std::string line)
{
    std::string vowels = "aeiou";
    int count = {0};
    for(auto v: line)
    {
       if(v == 'a')
       {
         count++;
       }
       else if (v == 'e')
       {
         count++;
       }
       else if (v == 'i')
       {
         count++;
       }
       else if (v == 'o')
       {
         count++;
       }
       else if (v == 'u')
       {
         count++;
       }
    }
    return count > 2;
}

bool duplicateLetters(std::string line)
{
    for(int i = 0; i < (int)line.size()-1;i++)
    {
        if(line[i] == line[i+1])
        {
            return true;
        }
    }
    return false;
}

bool doesNotContainString(std::string line)
{
    if(line.find("ab") != std::string::npos)
    {
        return false;
    }
    if(line.find("cd") != std::string::npos)
    {
        return false;
    }

    if(line.find("pq") != std::string::npos)
    {
        return false;
    }

    if(line.find("xy") != std::string::npos)
    {
        return false;
    }
    return true;


}