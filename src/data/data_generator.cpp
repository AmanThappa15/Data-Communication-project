
#include "data_generator.h"
#include <random>
#include <string>

std::string generateData(int length)
{
    if (length <= 0)
        return "";

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> bit(0, 1);

    std::string data;
    data.reserve(length);

    for (int i = 0; i < length; i++)
        data += char('0' + bit(gen));

    return data;
}
std::string generateDataWithZeros(int length, int zeroCount)
{
    if (length <= 0 || zeroCount <= 0 || zeroCount > length)
        return "";

    std::string data = generateData(length);

    int start = (length - zeroCount) / 2;

    if (start > 0)
        data[start - 1] = '1';

    if (start + zeroCount < length)
        data[start + zeroCount] = '1';

    data.replace(start, zeroCount, zeroCount, '0');

    return data;
}
