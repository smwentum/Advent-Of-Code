#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void partOne(std::string fileName);

int main(void)
{
    std::string fileName = "../TestFiles/day2final.txt";
    partOne(fileName);


}


void partOne(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    long sum{0};
    std::vector<int> codes;

    //std::cout << "in part one";
    if (file.is_open())
    {
        //std::cout << "File open";
        while (std::getline(file, line,','))
        {

            codes.push_back(std::stoi(line));
            //std::cout << std::endl << i << ". " << line << std::endl;

        }

        codes[1] = 12;
        codes[2] = 2;

        for(size_t i = 0; i  < codes.size(); i+=4)
        {
            int v1 = codes[codes[i+1]];
            int v2 = codes[codes[i+2]];

            if(codes[i] == 99)
            {
                break;
            }

            switch(codes[i])
            {
                case 1:

                    codes[codes[i+3]] = v1 + v2;
                    break;
                case 2:
                    codes[codes[i+3]] = v1 * v2;
                    break;
            }

        }
        std::cout << "Day two part one: " << codes[0] << std::endl;
    }
}