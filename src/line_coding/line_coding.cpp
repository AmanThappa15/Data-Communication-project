
#include "../line_coding.h"
#include <stdexcept>

std::vector<int> encodeNRZL(const std::string& data)
{
    std::vector<int> signal;

    for (char bit : data)
    {
        if (bit == '0')
            signal.push_back(-1);
        else if (bit == '1')
            signal.push_back(1);
        else
            throw std::invalid_argument("Input must contain only 0 and 1");
    }

    return signal;
}

std::vector<int> encodeNRZI(const std::string& data)
{
    std::vector<int> signal;
    int level = -1;

    for (char bit : data)
    {
        if (bit != '0' && bit != '1')
            throw std::invalid_argument("Input must contain only 0 and 1");

        if (bit == '1')
            level = -level;

        signal.push_back(level);
    }

    return signal;
}

