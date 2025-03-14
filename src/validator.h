#ifndef __VALIDATOR_H_INCLUDED__
#define __VALIDATOR_H_INCLUDED__

#include <sstream>

class Validator
{
private:
    std::vector<std::string> &todos_ref;

public:
    Validator(std::vector<std::string> &todos) : todos_ref(todos) {}

    bool in_range(int item_number)
    {
        return item_number >= 1 && item_number <= todos_ref.size();
    }

    int valid_integer(std::string item_number_str)
    {
        int item_number;
        std::stringstream ss;
        ss << item_number_str;
        ss >> item_number;
        return (ss.fail()) ? -1 : item_number;
    }
};

#endif