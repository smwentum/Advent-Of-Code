#include <iostream>
#include <set>
#include <fstream>
#include <sstream>


void Day3PartOne(std::string fileName);

int main()
{

    Day3PartOne("../test/day3final.txt");
    return 0;

}

void Day3PartOne(std::string fileName)
{
    std::string line{};
    std::ifstream inFile(fileName);
    int startX = 0;
    int startY = 0;

    std::set<std::pair<int,int>> set;
    set.insert(std::pair<int,int>(0,0));
    if(std::getline(inFile,line))
    {

        for(int i = 0; i <(int)line.size();i++)
        {


            if(line[i] == '^')
            {
                startY++;
            }else if(line[i] == 'v')
            {
                startY--;
            }
            else if(line[i] == '>')
            {
                startX++;
            }else
            {
                startX--;
            }

            set.insert(std::pair<int,int>(startX,startY)) ;
        }
    }







    std::cout << "Day 3 part 1: " << set.size() << "\n";


}