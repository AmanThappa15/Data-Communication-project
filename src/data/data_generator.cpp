
#include "data_generator.h"
#include <random>
#include <string>
#include <algorithm>

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
    data.replace(start, zeroCount, zeroCount, '0');

    return data;
}

std::string longestPalindrome(const std::string& data)
{
    if (data.empty())
        return "";

    int bestStart = 0;
    int bestLength = 1;

    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int type = 0; type < 2; type++)
        {
            int left = i;
            int right = i + type;

            while (left >= 0 &&
                   right < (int)data.size() &&
                   data[left] == data[right])
            {
                int len = right - left + 1;

                if (len > bestLength)
                {
                    bestStart = left;
                    bestLength = len;
                }

                left--;
                right++;
            }
        }
    }

    return data.substr(bestStart, bestLength);
}

