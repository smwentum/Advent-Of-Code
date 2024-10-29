#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void dayTwoPart1(std::string fileName);
void dayTwoPartTwo(std::string fileName);

class Dimensions
{
    int m_length {};
    int m_width {};
    int m_height {};

    public:
        Dimensions(int l, int w, int h)
        {
            m_length = l;
            m_width = w;
            m_height = h;
        }
        int getSurfaceArea()
        {
            return 2*m_length*m_width + 2*m_length*m_height+ 2*m_width*m_height;
        }
        int getMinArea()
        {
           return std::min(m_length*m_width, std::min(m_length*m_height,m_width*m_height));
        }
        int productOfDimensions()
        {
            return m_length*m_width*m_height;
        }
        int getMinPerimeteter()
        {
            return 2 * std::min(m_length+m_width, std::min(m_length+m_height,m_width+m_height));
        }
};

int main()
{
    dayTwoPart1("../test/day2final.txt");
    dayTwoPartTwo("../test/day2final.txt");
    return 0;
}

std::vector<std::string> stringSplit(std::string str, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();

    std::string token;
    std::vector<std::string> res;

    while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
        token = str.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (str.substr (pos_start));
    //std::cout << res << "\n";
    return res;
}

void dayTwoPart1(std::string fileName)
{
    std::string line{};
    std::ifstream inFile(fileName);

    std::vector<Dimensions> dimensions;
    int sum{};
    while(std::getline(inFile,line))
    {
       //std::cout << line << "\n";
       std::vector<std::string> tokens =   stringSplit(line,"x");
       //std::cout <<"tokens: " << tokens[0]  //<< " " << tokens[1] << " " <<tokens[2]
       //<< "\n";
       Dimensions d = Dimensions(std::stoi(tokens[0]), std::stoi(tokens[1]),std::stoi(tokens[2]) );
       sum += d.getSurfaceArea()+d.getMinArea();
       //std::cout << max;
    }

    std::cout << "Day Two part 1: "<< sum << "\n";

}



void dayTwoPartTwo(std::string fileName)
{
    std::string line{};
    std::ifstream inFile(fileName);

    std::vector<Dimensions> dimensions;
    int sum{};
    while(std::getline(inFile,line))
    {
       //std::cout << line << "\n";
       std::vector<std::string> tokens =   stringSplit(line,"x");
       //std::cout <<"tokens: " << tokens[0]  //<< " " << tokens[1] << " " <<tokens[2]
       //<< "\n";
       Dimensions d = Dimensions(std::stoi(tokens[0]), std::stoi(tokens[1]),std::stoi(tokens[2]) );
       sum += d.productOfDimensions() + d.getMinPerimeteter();
       //std::cout << max;
    }

    std::cout << "Day Two part 2: "<< sum << "\n";

}

