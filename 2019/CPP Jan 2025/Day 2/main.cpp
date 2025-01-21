#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void partOne(std::string fileName);
void partTwo(std::string fileName);

int main(void)
{
    std::string fileName = "../TestFiles/day2final.txt";

    partOne(fileName);
    partTwo(fileName);
}

void partOne(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    long sum{0};
    std::vector<int> codes;

    // std::cout << "in part one";
    if (file.is_open())
    {
        // std::cout << "File open";
        while (std::getline(file, line, ','))
        {

            codes.push_back(std::stoi(line));
            // std::cout << std::endl << i << ". " << line << std::endl;
        }

        codes[1] = 12;
        codes[2] = 2;

        for (size_t i = 0; i < codes.size(); i += 4)
        {
            int v1 = codes[codes[i + 1]];
            int v2 = codes[codes[i + 2]];

            if (codes[i] == 99)
            {
                break;
            }

            switch (codes[i])
            {
            case 1:

                codes[codes[i + 3]] = v1 + v2;
                break;
            case 2:
                codes[codes[i + 3]] = v1 * v2;
                break;
            }
        }
        std::cout << "Day two part one: " << codes[0] << std::endl;
    }
}

void partTwo(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    long sum{0};
    std::vector<int> codes1;
    std::vector<int> codes;

    // std::cout << "in part one";
    if (file.is_open())
    {
        // std::cout << "File open";
        while (std::getline(file, line, ','))
        {

            codes1.push_back(std::stoi(line));
            // std::cout << std::endl << i << ". " << line << std::endl;
        }


        for (int noun = 0; noun < 100; noun++)
        {
            for (int verb = 0; verb < 100; verb++)
            {
                codes = codes1;
                codes[1] = noun;
                codes[2] = verb;

                for (size_t i = 0; i < codes.size(); i += 4)
                {
                    int v1 = codes[codes[i + 1]];
                    int v2 = codes[codes[i + 2]];

                    if (codes[i] == 99)
                    {
                        break;
                    }

                    switch (codes[i])
                    {
                        case 1:

                            codes[codes[i + 3]] = v1 + v2;
                            break;
                        case 2:
                            codes[codes[i + 3]] = v1 * v2;
                            break;
                    }
                }

                if(codes[0] == 19690720)
                {
                    std::cout << "Day two part two: " << 100*noun+verb << std::endl;
                }
            }
        }
    }
}