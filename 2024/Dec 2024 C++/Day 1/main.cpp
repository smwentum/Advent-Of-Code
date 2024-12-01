#include <algorithm>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector>
#include <math.h>

void partOne(std::string fileName);

int main()
{
    partOne("../textfiles/day1.txt");
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



// void partOne(std::string fileName)
// {

//     std::ifstream infile(fileName);
//     std::vector<int> l1; 
//     std::vector<int> l2;
//     //read in the file
//     long a, b;
//     while (infile >> a >> b)
//     {
//         l1.push_back(a);
//         l2.push_back(b);
//     }
//     std::sort(l1.begin(),l1.end());
//     std::sort(l2.begin(),l2.end());
    
//     long sum = 0;
//     for(int i =0 ; i < (int)l1.size();i++)
//     {
//         sum += abs(l1[i]-l2[i]);
//     }
//     std::cout << "Day One part one: " << sum << "\n";

// }

