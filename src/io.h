#ifndef __IO_H_INCLUDED__
#define __IO_H_INCLUDED__

#include <iostream>
#include <limits>
#include <string>

class IO
{
private:
    std::streamsize n = std::numeric_limits<std::streamsize>::max();
    char delim = '\n';

public:
    std::string get_line()
    {
        std::string input;
        std::cin.ignore(n, delim);
        std::getline(std::cin, input);
        return input;
    }

    void wait_till_enter()
    {
        std::cout << "\nPress Enter to continue...";
        get_line();
    }
};

#endif