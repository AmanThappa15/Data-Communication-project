#include "data_generator.h"
#include <random>

std::string generateData(int length)
{
    std::string data;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 1);

    for (int i = 0; i < length; i++)
    {
        data += char('0' + distribution(generator));
    }

    return data;
}
