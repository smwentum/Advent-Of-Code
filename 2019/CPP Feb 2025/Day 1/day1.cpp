#include <iostream>
#include <fstream>
#include <vector>

void partOne(std::string fileName);
void partTwo(std::string fileName);
int getNewValue(int oldValue);
int getNewValuePt2(int oldValue);

int main()
{
    partOne("../textfiles/day1final.txt");
    partTwo("../textfiles/day1final.txt");
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
        // std::cout << num << std::endl;
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

void partTwo(std::string fileName)
{
    // read the lines
    std::ifstream textFile(fileName);
    int num;
    std::vector<int> vals;

    while (textFile >> num)
    {
        // std::cout << num << std::endl;
        vals.push_back(num);
    }

    int s{0};
    // std::cout << getNewValuePt2(1969) << std::endl;
    for (int v : vals)
    {
        s += getNewValuePt2(v);
    }

    std::cout << "Day 1 part 2: " << s << std::endl;
}

int getNewValuePt2(int oldValue)
{
    if (oldValue < 1)
    {
        return 0;
    }
    int v = getNewValue(oldValue);
    // std::cout << v << std::endl;
    if (v <= 0)
    {
        return 0;
    }
    return v + getNewValuePt2(v);
}