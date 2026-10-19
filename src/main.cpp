
#include <iostream>
#include <string>
#include <vector>

#include "data/data_generator.h"
#include "pallindrome/pallindrome.h"
#include "line_coding.h"

int main()
{
    int length = 16;

    std::string data = generateData(length);
    std::string fourZeros = generateDataWithZeros(length, 4);
    std::string eightZeros = generateDataWithZeros(length, 8);

    std::cout << "Random data: " << data << '\n';
    std::cout << "Data with four zeros: " << fourZeros << '\n';
    std::cout << "Data with eight zeros: " << eightZeros << '\n';

    std::string palindrome = longestPalindrome(data);
    std::cout << "Longest palindrome: " << palindrome << '\n';
    std::cout << "Palindrome length: " << palindrome.length() << '\n';

    std::string testData = "10110010";

    std::vector<int> nrzl = encodeNRZL(testData);
    std::vector<int> nrzi = encodeNRZI(testData);

    std::cout << "\nTest data: " << testData << '\n';

    std::cout << "NRZ-L: ";
    for (int level : nrzl)
        std::cout << level << ' ';
    std::cout << '\n';

    std::cout << "NRZ-I: ";
    for (int level : nrzi)
        std::cout << level << ' ';
    std::cout << '\n';

    return 0;
}
