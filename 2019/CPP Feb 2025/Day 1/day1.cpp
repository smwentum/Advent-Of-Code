#include <iostream>
#include <fstream>
#include <vector>

void partOne(std::string fileName);
void partTwo(std::string fileName);
int getNewValue(int oldValue);

int main()
{
    partOne("../textfiles/day1final.txt");

    return 0;
}

void partOne(std::string fileName)
{
    // read the lines
    std::ifstream textFile(fileName);
    int num;
    std::vector<int> vals;

    while (textFile >> num)
    {
        std::cout << num << std::endl;
        vals.push_back(num);
    }

    int s{0};
    for (int v : vals)
    {
        s += getNewValue(v);
    }

    std::cout << "Day 1: part: " << s << std::endl;
}

int getNewValue(int oldValue)
{
    oldValue /= 3;
    oldValue -= 2;
    return oldValue;
}