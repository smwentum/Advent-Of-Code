#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void partOneDayOne(std::string fileName);
void partOneDayTwo(std::string fileName);


int main()
{
    partOneDayOne("../test/day1final1.txt");
    partOneDayTwo("../test/day1final1.txt");
    return 0;
}


void partOneDayOne(std::string fileName)
{
    int count {};
    std::string line;
    std::ifstream infile(fileName);

    if(std::getline(infile,line))
    {
        //std::cout << line << "\n";
        for( int i = 0; i < line.length();i++)
        {
            if(line[i] == '(')
            {
                count++;
            }
            else if(line[i] == ')')
            {
                count--;
            }
        }
        std::cout <<"day 1 part 1: "<< count <<std::endl;
    }


}


void partOneDayTwo(std::string fileName)
{
    int count {};
    std::string line;
    std::ifstream infile(fileName);

    if(std::getline(infile,line))
    {
        //std::cout << line << "\n";
        for( int i = 0; i < line.length();i++)
        {
            if(line[i] == '(')
            {
                count++;
            }
            else if(line[i] == ')')
            {
                count--;
                if(count <0)
                {
                    std::cout <<"day 1 part 2: " << i+ 1 <<std::endl;
                    break;
                }
            }
        }

    }


}