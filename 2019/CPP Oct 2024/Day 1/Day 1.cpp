#include <iostream>
#include <fstream>
#include <vector> 
#include <string>

using std::ifstream;
using std::string; 
using std::cout;
using std::endl;

int getValue(string val)
{
   int value =  std::stoi(val);
   value /= 3; 
   value -=2;
   return value;
}

int main() 
{
    string fileName = "final.txt"; 
    std::ifstream file(fileName);
    std::string str;
    long long int sum = 0; 
    int value {0};

    while(std::getline(file,str))
    {
        value = getValue(str);
        //cout  << str << ": " << value << endl;
        sum += value;
    }

    cout << "Part 1: " << sum << endl;


}

