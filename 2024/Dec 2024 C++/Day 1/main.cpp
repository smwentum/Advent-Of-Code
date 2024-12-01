#include <algorithm>
#include <fstream>
#include <iostream> 
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>


void partOne(std::string fileName);
void partTwo(std::string fileName);

int main()
{
    partOne("../textfiles/day1.txt");
    partTwo("../textfiles/day1.txt");
}

void partOne(std::string fileName)
{

    std::ifstream infile(fileName);
    std::vector<int> l1; 
    std::vector<int> l2;
    //read in the file
    long a, b;
    while (infile >> a >> b)
    {
        l1.push_back(a);
        l2.push_back(b);
    }
    std::sort(l1.begin(),l1.end());
    std::sort(l2.begin(),l2.end());
    
    long sum = 0;
    for(int i =0 ; i < (int)l1.size();i++)
    {
        sum += abs(l1[i]-l2[i]);
    }
    std::cout << "Day One part one: " << sum << "\n";

}



void partTwo(std::string fileName)
{

    std::ifstream infile(fileName);
    std::vector<int> l1; 
    std::vector<int> l2;
    //read in the file
    long a, b;
    while (infile >> a >> b)
    {
        l1.push_back(a);
        l2.push_back(b);
    }
    std::sort(l1.begin(),l1.end());
    std::sort(l2.begin(),l2.end());
    
    std::unordered_map<long,int> map; 

    long sum = 0;
    for(int i =0 ; i < (int)l2.size();i++)
    {
        if(map.find(l2[i]) != map.end())
        {
            map[l2[i]]+=1;
        }
        else
        {
            map[l2[i]] = 1;
        }
    }
    
    for(int i =0 ; i < (int)l2.size();i++)
    {
        if(map.find(l1[i]) != map.end())
        {
            sum += map[l1[i]] *l1[i]; 
        }

    }
    std::cout << "Day One part two: " << sum << "\n";

}

