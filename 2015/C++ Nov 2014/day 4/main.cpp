#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <openssl/md5.h>



void day4PartOne(std::string fileName);


int main()
{
    day4PartOne("")
    return 0;
}

void day4PartOne(std::string testName)
{
    std::string line{};

    int count{0};
    int i = 0;
    std::string str;

       while(true && i < 100000)
       {
            str = std::to_string(i);
            //str.insert(0,5-str.length(),'0');
            std::string testString = testName+str;
            answer = md5(testString);
            i++;
       }


    std::cout << "Answer to Day 5 part one: "<< count << "\n";

}

