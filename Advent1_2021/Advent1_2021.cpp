//
//
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    std::ifstream s("SonarOutput.txt");
    try
    {
        if (!s.is_open())
            throw std::exception("Program failed to open file");

        int i;
        std::vector<unsigned> v;
        std::string str;

        while (!s.eof())
        {
            std::getline(s, str);
            i = std::stoi(str, nullptr);
            if (i < 0)
                throw std::exception("Found negative number in SonarOutput");

            v.push_back(i);
        }
        s.close();

        unsigned counter = 0;
        i = -1;
        for (unsigned new_i : v)
        {
            if (i != -1)
            {
                if (new_i > i) ++counter;
            }
            i = new_i;
        }

        std::cout << "Counter: " << counter << std::endl;
    }
    catch (const std::exception& error)
    {
        std::cout << error.what() << std::endl << "Exiting program";
        exit(1);
    }
    return 0;
}