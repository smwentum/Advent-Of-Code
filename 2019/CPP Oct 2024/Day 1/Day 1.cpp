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


int getValueP2(int value)
{
   value /= 3; 
   value -=2;
   return value;
}

int getValueP2(string val)
{
   int sum = 0;
   int value =  std::stoi(val);

   while(value > 0)
   {
     value = getValueP2(value); 
   
     if(value > 0)
     {
        //cout << value << endl;
        sum += value;
     }
     else
     {
        break;
     } 
   }    
   
   return sum;
}

int main() 
{
    string fileName = "final.txt"; 
    std::ifstream file(fileName);
    std::string str;
    long long int sumPart1 = 0; 
    long long int sumPart2 = 0; 
    

    while(std::getline(file,str))
    {

        //cout  << str << ": " << value << endl;
        sumPart1 +=  getValue(str);
        //cout << str << " "<< getValueP2(str) << endl;
        sumPart2 +=  getValueP2(str);
    }

    cout << "Part 1: " << sumPart1 << endl;
    cout << "Part 2: " << sumPart2 << endl;



}

