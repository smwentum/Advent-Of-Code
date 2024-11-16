#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<vector>

void dayOnePartOne(std::string fileName);
void dayOnePartTwo(std::string fileName);

int main()
{

    dayOnePartOne("../textfiles/day1final.txt");
    dayOnePartTwo("../textfiles/day1final.txt");


}


void dayOnePartOne(std::string fileName)
{
    std::ifstream file(fileName);

    std::string str;

    std::set<int> lst;

    while(std::getline(file,str))
    {
        int x =  std::stoi(str);
        if( lst.count(2020 - x) == 1)
        {
            std::cout << "Day 1 part 1: " << (2020 -x)*x << "\n";
            break;
        }
        else
        {
            lst.insert(x);
        }
    }
}


void dayOnePartTwo(std::string fileName)
{
    std::ifstream file(fileName);

    std::string str;

    std::vector<int> vect;

    while(std::getline(file,str))
    {
        vect.push_back(std::stoi(str));
    }

    for(int i = 0; i < (int) vect.size();i++)
    {
        for(int j = i+1; j < (int) vect.size();j++)
        {
            for(int k = j+1; k < (int)vect.size(); k++)
            {
                if(vect[i] +vect[j]+ vect[k] == 2020)
                {
                    std::cout <<"Day 1 Part 2: " << vect[i]*vect[j]*vect[k] << "\n";
                }
            }
        }
    }
}