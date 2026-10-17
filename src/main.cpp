
#include <iostream>
#include <string>
#include "data/data_generator.h"

int main()
{
    int length = 16;

    std::string data = generateData(length);
    std::string fourZeros = generateDataWithZeros(length, 4);
    std::string eightZeros = generateDataWithZeros(length, 8);

    std::cout << "Random data: " << data << '\n';
    std::cout << "Data with four zeros: " << fourZeros << '\n';
    std::cout << "Data with eight zeros: " << eightZeros << '\n';
    std::cout << "Longest palindrome: "
              << longestPalindrome(data) << '\n';

    return 0;
}

